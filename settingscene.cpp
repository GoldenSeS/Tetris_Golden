#include "settingscene.h"
#include "ui_settingscene.h"
#include <QDesktopWidget>
#include "database.h"
#include <QDebug>
#include <QFileDialog>
#include <QLineEdit>
#include <QColorDialog>
#include <QMouseEvent>
#include <QList>
#include <QSet>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include "profilemanager.h"
SettingScene::SettingScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingScene)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("TetrisSettingScene"));
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);
    this->setFixedSize(800,1000);
    ui->tabWidget->setCurrentIndex(0);
    ui->currentUserLabel->setWordWrap(true);
    ui->currentUserLabel->setText("当前用户：\n");
    //窗口放置在屏幕正中央
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);

    //返回按钮
    connect(ui->settingBackBtn,&QPushButton::clicked,this,[=](){
        //防止键位重复
        if(keyRepetition()){
            QMessageBox::critical(parent,"错误","键位重复!");
            return ;
        }
        saveSettingToDatabase();
        ui->tryListeningBtn->setText("试听");
        mediaPlayer->stop();
        emit settingSceneBack();
    });

    //重置选项按钮
    connect(ui->resetBtn,&QPushButton::clicked,this,[=](){
        setNumFromDefault();
    });

    //创建新用户按钮
    connect(ui->selectUserComboBox,&QComboBox::currentTextChanged,[=](){
        ui->currentUserLabel->setText("当前用户：\n"+ui->selectUserComboBox->currentText());
    });

    connect(ui->clearUserBtn,&QPushButton::clicked,this,[=](){
        fm.clearProfiles();
        ui->selectUserComboBox->clear();
    });

    mediaPlayer = new QMediaPlayer;

    // 连接选择文件按钮的clicked信号到槽函数，用于选择文件
    QObject::connect(ui->chooseMediaFileBtn, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(nullptr, "选择文件", "", "音频文件 (*.mp3 *.wav)");
        if (!fileName.isEmpty()) {
            ui->mediaLineEdit->setText(fileName);
            mediaPlayer->setMedia(QUrl::fromLocalFile(fileName));
        }
    });

    // 连接播放按钮的clicked信号到槽函数，用于播放/停止文件
    QObject::connect(ui->tryListeningBtn, &QPushButton::clicked, [&]() {
        if (mediaPlayer->state() != QMediaPlayer::PlayingState&&ui->mediaLineEdit->text()!="") {
            mediaPlayer->play();
            ui->tryListeningBtn->setText("暂停");
        } else {
            mediaPlayer->stop();
            ui->tryListeningBtn->setText("试听");

        }
    });

    // 连接音量滑动条的valueChanged信号到槽函数，用于设置音量
    QObject::connect(ui->mediaOptionBlock,&optionBlock::valueChanged,[=](){
        mediaPlayer->setVolume(ui->mediaOptionBlock->getNum());
    });

    // 连接添加新用户到存档
    connect(ui->newUserBtn, &QPushButton::clicked, [&]() {
        addNewProfile();
    });

    init();
    setNumFromDatabase();
}

void SettingScene::init(){

    ui->widthOptionBlock->setText("棋盘宽度");
    ui->widthOptionBlock->setlimit(10,5);
    ui->widthOptionBlock->setstep(1);

    ui->heightOptionBlock->setText("棋盘高度");
    ui->heightOptionBlock->setlimit(20,10);
    ui->heightOptionBlock->setstep(1);

    ui->fallingOptionBlock->setText("游戏速度");
    ui->fallingOptionBlock->setlimit(160,20);
    ui->fallingOptionBlock->setstep(10);

    ui->mediaOptionBlock->setText("游戏音乐");
    ui->mediaOptionBlock->setlimit(100,0);
    ui->mediaOptionBlock->setstep(10);
    ui->mediaLineEdit->setReadOnly(true);

    colorOptionBlk_Vector.append(ui->blockL_colorOptionBlock);
    colorOptionBlk_Vector.append(ui->blockO_colorOptionBlock);
    colorOptionBlk_Vector.append(ui->blockJ_colorOptionBlock);
    colorOptionBlk_Vector.append(ui->blockI_colorOptionBlock);
    colorOptionBlk_Vector.append(ui->blockT_colorOptionBlock);
    colorOptionBlk_Vector.append(ui->blockS_colorOptionBlock);
    colorOptionBlk_Vector.append(ui->blockZ_colorOptionBlock);

    QString blkName[7]=
    {
        "L","O","J","I","T","S","Z"
    };

    size_t cnt=0;
    for(auto i:colorOptionBlk_Vector){
        i->setText(QString("方块%1").arg(blkName[cnt]));
        ++cnt;
    }

    keyOptionBlk_Vector.append(ui->left_keyOptionBlock);
    keyOptionBlk_Vector.append(ui->right_keyOptionBlock);
    keyOptionBlk_Vector.append(ui->down_keyOptionBlock);
    keyOptionBlk_Vector.append(ui->spin_keyOptionBlock);
    keyOptionBlk_Vector.append(ui->pause_keyOptionBlock);

    QString keyName[5]=
    {
        "左移","右移","下降","旋转","暂停"
    };

    cnt=0;
    for(auto i:keyOptionBlk_Vector){
        connect(i,&keyOptionBlock::disableMouseControl,this,[=](){
            disableMouseClick(this);
        });
        connect(i,&keyOptionBlock::enableMouseControl,this,[=](){
            enableMouseClick(this);
        });
        i->setLabel(QString(keyName[cnt]));
        ++cnt;
    }
}

void SettingScene::disableMouseClick(QWidget *widget)
{
    widget->setMouseTracking(true);
    widget->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    QList<QWidget*> children = widget->findChildren<QWidget*>();
    foreach(QWidget* child, children) {
        disableMouseClick(child);
    }
}

void SettingScene::enableMouseClick(QWidget *widget)
{
    widget->setMouseTracking(false);
    widget->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    QList<QWidget*> children = widget->findChildren<QWidget*>();
    foreach(QWidget* child, children) {
        enableMouseClick(child);
    }
}

void SettingScene::setNumFromDatabase(){
    ui->widthOptionBlock->setNum(GAME_WIDTH);
    ui->heightOptionBlock->setNum(GAME_HEIGHT);
    ui->fallingOptionBlock->setNum(REFRESHING_RATE);
    ui->mediaLineEdit->setText(MEDIAFILE);
    ui->mediaOptionBlock->setNum(MEDIAVOLUME);

    size_t cnt=1;
    for(auto i:colorOptionBlk_Vector){
        i->setColor(blockcolor[cnt]);
        ++cnt;
    }

    cnt=0;
    for(auto i:keyOptionBlk_Vector){
        i->setKey(KEYSETTING[cnt]);
        ++cnt;
    }

}

void SettingScene::setNumFromDefault(){
    ui->widthOptionBlock->setNum(10);
    ui->heightOptionBlock->setNum(20);
    ui->fallingOptionBlock->setNum(100);
    ui->mediaOptionBlock->setNum(50);
    ui->mediaLineEdit->setText("");

    QColor defaultblockcolor[10]={
        Qt::white,//空棋盘颜色
        QColor("#3795D9"),//方块1颜色
        QColor("#F0CA2E"),//方块2颜色
        QColor("#88258B"),//方块3颜色
        QColor("#F56816"),//方块4颜色
        QColor("#2A51B6"),//方块5颜色
        QColor("#61B532"),//方块6颜色
        QColor("#BE1D23"),//方块7颜色
        Qt::white,
        Qt::gray//固定方块颜色
    };

    Qt::Key defaultkeysetting[5]{
        Qt::Key_Left,
                Qt::Key_Right,
                Qt::Key_Down,
                Qt::Key_Up,
                Qt::Key_Escape
    };

    size_t cnt=1;
    for(auto i:colorOptionBlk_Vector){
        i->setColor(defaultblockcolor[cnt]);
        ++cnt;
    }

    cnt=0;
    for(auto i:keyOptionBlk_Vector){
        i->setKey(defaultkeysetting[cnt]);
        ++cnt;
    }
}

void SettingScene::saveSettingToDatabase(){
    GAME_WIDTH=ui->widthOptionBlock->getNum();
    GAME_HEIGHT=ui->heightOptionBlock->getNum();
    REFRESHING_RATE=ui->fallingOptionBlock->getNum();
    MEDIAFILE=ui->mediaLineEdit->text();
    MEDIAVOLUME=ui->mediaOptionBlock->getNum();

    size_t cnt=1;
    for(auto i:colorOptionBlk_Vector){
        blockcolor[cnt]=i->getColor();
        ++cnt;
    }

    cnt=0;
    for(auto i:keyOptionBlk_Vector){
        KEYSETTING[cnt]=i->getKey();
        ++cnt;
    }

    USER_ID = ui->selectUserComboBox->currentIndex();

    debugDatabase();
}

bool SettingScene::keyRepetition(){
    QSet<Qt::Key> tem_set;
    for(auto i:keyOptionBlk_Vector){
        tem_set.insert(i->getKey());
    }
    return tem_set.size()<5;
}

void SettingScene::addNewProfile(){
    QString name = QInputDialog::getText(this,"新用户","请输入新用户昵称:", QLineEdit::Normal,"admin");
    if(name.size()>=10||name.size()<1){
        QMessageBox::critical(this,"错误","字数限制(<10)!");
        return;
    }
    for(auto i:fm.getAllUserProfiles()){
        if(i->getUserName()==name){
            QMessageBox::critical(this,"错误","昵称已被占用");
            return;
        }
    }
    UserProfile* temp = new UserProfile(fm.getProfilesNum(),name);
    fm.addUserProfile(temp);
    ui->selectUserComboBox->addItem(name);
    ui->selectUserComboBox->setCurrentIndex(fm.getProfilesNum()-1);
//    fm.debugProfilesOutput();
}

SettingScene::~SettingScene()
{
    delete ui;
}
