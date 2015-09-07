#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

// CONFIGURATION HEADERS
class SettingsFileTags{
public:
    static const std::string _DB_PATH;
};

static std::string _DB_FILE = "";

class Settings{
public:
    const static std::string _DB_FILE;

    static std::string load_db_location();

private:
    static bool file_exists(const std::string & path);
};




#endif // SETTINGS_H
