#ifndef PLANT_PROPERTIES_H
#define PLANT_PROPERTIES_H

#include <QString>

typedef std::pair<int,int> Range;

class AgeingProperties {
public:
    AgeingProperties(const AgeingProperties & other);
    AgeingProperties(); //TMP
    AgeingProperties(int p_start_of_decline,
                     int p_max_age);

    const int start_of_decline;
    const int max_age;
};

//---------------------------------------------------------------------------

class GrowthProperties {
public:
    GrowthProperties(const GrowthProperties& other);
    GrowthProperties(); //TMP
    GrowthProperties( float p_max_height, float p_max_root_size,
                      float p_max_canopy_width);

    const float max_height; // cm per month
    const float max_root_size; // cm per month
    const float max_canopy_width; // cm per month
};

//---------------------------------------------------------------------------

class IlluminationProperties {
public:
    IlluminationProperties(const IlluminationProperties & other);
    IlluminationProperties(); //TMP
    IlluminationProperties( Range p_prime_illumination,
                            int p_min_illumination, int p_max_illumination);

    const Range prime_illumination;
    const int min_illumination;
    const int max_illumination;
};

//---------------------------------------------------------------------------

class SoilHumidityProperties {
public:
    SoilHumidityProperties(const SoilHumidityProperties & other);
    SoilHumidityProperties(); //TMP
    SoilHumidityProperties( Range p_prime_soil_humidity,
                            int p_min_soil_humidity,
                            int p_max_soil_humidity);

    const Range prime_soil_humidity;
    const int min_soil_humidity;
    const int max_soil_humidity;
};

//---------------------------------------------------------------------------

class TemperatureProperties {
public:
    TemperatureProperties(const TemperatureProperties & other);
    TemperatureProperties(); //TMP
    TemperatureProperties( Range p_prime_temp,
                            int p_min_temp,
                            int p_max_temp);

    const Range prime_temp;
    const int min_temp;
    const int max_temp;
};

//---------------------------------------------------------------------------

class SeedingProperties {
public:
    SeedingProperties(const SeedingProperties & other);
    SeedingProperties(); //TMP
    SeedingProperties( int p_max_seed_distance,
                       int p_max_seeds);

    const int max_seed_distance;
    const int seed_count;
};

//---------------------------------------------------------------------------

class SpecieProperties{
public:
    SpecieProperties();

    SpecieProperties(const SpecieProperties & other);

    SpecieProperties(QString name,
                    AgeingProperties ageing_properties,
                    GrowthProperties growth_properties,
                    IlluminationProperties illumination_properties,
                    SoilHumidityProperties soil_humidity_properties,
                    TemperatureProperties temperature_properties,
                    SeedingProperties seeding_properties);

    SpecieProperties(QString name, int id,
                    AgeingProperties ageing_properties,
                    GrowthProperties growth_properties,
                    IlluminationProperties illumination_properties,
                    SoilHumidityProperties soil_humidity_properties,
                    TemperatureProperties temperature_properties,
                    SeedingProperties seeding_properties);

//    SpecieProperties & operator=(const SpecieProperties & other);

    int specie_id;
    QString specie_name;
    AgeingProperties ageing_properties;
    GrowthProperties growth_properties;
    IlluminationProperties illumination_properties;
    SoilHumidityProperties soil_humidity_properties;
    TemperatureProperties temperature_properties;
    SeedingProperties seeding_properties;
};


#endif
