#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H
#include "userprofile.h"
#include <QMap>
#include <QString>

class ProfileManager {
public:
    ProfileManager();
    ~ProfileManager();

    void addUserProfile(UserProfile *userProfile);
    void removeUserProfile(int userId);
    bool hasUserProfile(int userId);
    UserProfile* getUserProfile(int userId);
    QList<UserProfile*> getAllUserProfiles();
    void saveProfilesToFile(const QString& fileName) const;
    void loadProfilesFromFile(const QString& fileName);

private:
    QMap<int, UserProfile*> userProfiles;
};
#endif // PROFILEMANAGER_H
