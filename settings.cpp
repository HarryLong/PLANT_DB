#include "settings.h"
#include <QDebug>
#include <QFile>
#include <fstream>
#include <iostream>

const std::string ConfigurationFileTags::_DB_PATH = "DB_LOCATION=";

const std::string Settings::_DB_FILE = load_db_location();
std::string Settings::load_db_location()
{
    // First try local configuration location
    std::string config_file;

    if(file_exists("/usr/local/etc/plantDB/plantdb.conf"))
        config_file = "/usr/local/etc/plantDB/plantdb.conf";
    else if(file_exists("/etc/plantDB/plantdb.conf"))
        config_file = "/etc/plantDB/plantdb.conf";
    else
    {
        qCritical() << "Could not find configuration file!";
        exit(1);
    }

    std::ifstream config_reader(config_file, std::ios_base::in);
    if(config_reader.fail())
    {
        qCritical() << "Failed to read config file: " << config_file.c_str();
        exit(1);
    }

    std::string line;
    while (std::getline(config_reader, line))
    {
        if(line.find(ConfigurationFileTags::_DB_PATH) != std::string::npos)
        {
            line.replace(0, ConfigurationFileTags::_DB_PATH.length(), "");
            if(file_exists(line))
            {
                return line;
            }
            qCritical() << "Database file not found: " << line.c_str();
            exit(1);
        }
        else
        {
            qCritical() << "Unknown config parameter: " << line.c_str();
        }
    }
    qCritical() << "Could not find database location descriptor in configuration file: " << config_file.c_str();
    exit(1);
}

bool Settings::file_exists(const std::string & path)
{
    std::ifstream file(path);
    return !file.fail();
}
