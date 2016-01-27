#include "plant_properties.h"


AgeingProperties::AgeingProperties(const AgeingProperties & other):
    start_of_decline(other.start_of_decline),
    max_age(other.max_age)
{

}

AgeingProperties::AgeingProperties():
    start_of_decline(0),
    max_age(0)
{

}

AgeingProperties::AgeingProperties(int p_start_of_decline,
                                   int p_max_age) :
    start_of_decline(p_start_of_decline),
    max_age(p_max_age)
{

}

//---------------------------------------------------------------------------

GrowthProperties::GrowthProperties(const GrowthProperties& other) :
    max_height(other.max_height),
    max_root_size(other.max_root_size),
    max_canopy_width(other.max_canopy_width)
{

}

GrowthProperties::GrowthProperties( ) :
            max_height(0),
            max_root_size(0),
            max_canopy_width(0)
{

}

GrowthProperties::GrowthProperties( float p_max_height, float p_max_root_size,
                                    float p_max_canopy_width) :
            max_height(p_max_height),
            max_root_size(p_max_root_size),
            max_canopy_width(p_max_canopy_width)
{

}

//---------------------------------------------------------------------------

IlluminationProperties::IlluminationProperties(const IlluminationProperties & other) :
    prime_illumination(other.prime_illumination),
    min_illumination(other.min_illumination),
    max_illumination(other.max_illumination)
{

}
IlluminationProperties::IlluminationProperties( ) :
    prime_illumination(0,0),
    min_illumination(0),
    max_illumination()
{

}

IlluminationProperties::IlluminationProperties( Range p_prime_illumination,
                                                int p_min_illumination, int p_max_illumination) :
    prime_illumination(p_prime_illumination),
    min_illumination(p_min_illumination),
    max_illumination(p_max_illumination)
{

}

//---------------------------------------------------------------------------

SoilHumidityProperties::SoilHumidityProperties(const SoilHumidityProperties & other) :
    prime_soil_humidity(other.prime_soil_humidity),
    min_soil_humidity(other.min_soil_humidity),
    max_soil_humidity(other.max_soil_humidity)
{

}

SoilHumidityProperties::SoilHumidityProperties( ):
    prime_soil_humidity(0,0),
    min_soil_humidity(0),
    max_soil_humidity(0)
{

}

SoilHumidityProperties::SoilHumidityProperties( Range p_prime_soil_humidity,
                                                int p_min_soil_humidity,
                                                int p_max_soil_humidity):
    prime_soil_humidity(p_prime_soil_humidity),
    min_soil_humidity(p_min_soil_humidity),
    max_soil_humidity(p_max_soil_humidity)
{

}

//---------------------------------------------------------------------------

TemperatureProperties::TemperatureProperties(const TemperatureProperties & other) :
    prime_temp(other.prime_temp),
    min_temp(other.min_temp),
    max_temp(other.max_temp){}

TemperatureProperties::TemperatureProperties( ):
    prime_temp(0,0),
    min_temp(0),
    max_temp(0){}

TemperatureProperties::TemperatureProperties( Range p_prime_temp,
                                              int p_min_temp,
                                              int p_max_temp):
    prime_temp(p_prime_temp),
    min_temp(p_min_temp),
    max_temp(p_max_temp){}


//---------------------------------------------------------------------------

SeedingProperties::SeedingProperties(const SeedingProperties & other) :
    max_seed_distance(other.max_seed_distance),
    seed_count(other.seed_count){}

SeedingProperties::SeedingProperties():
    max_seed_distance(0),
    seed_count(0)
{

}

SeedingProperties::SeedingProperties( int p_max_seed_distance,
                                      int p_max_seeds):
    max_seed_distance(p_max_seed_distance),
    seed_count(p_max_seeds){}

//---------------------------------------------------------------------------

SlopeProperties::SlopeProperties(const SlopeProperties & other) :
    start_of_decline(other.start_of_decline),
    max(other.max){}


SlopeProperties::SlopeProperties():
    start_of_decline(0),
    max(0) {}

SlopeProperties::SlopeProperties( int p_start_of_decline,
                                  int p_max) :
    start_of_decline(p_start_of_decline),
    max(p_max) {}

//---------------------------------------------------------------------------

SpecieProperties::SpecieProperties(const SpecieProperties & other) :
    specie_id(other.specie_id),
    specie_name(other.specie_name),
    ageing_properties(other.ageing_properties),
    growth_properties(other.growth_properties),
    illumination_properties(other.illumination_properties),
    soil_humidity_properties(other.soil_humidity_properties),
    temperature_properties(other.temperature_properties),
    seeding_properties(other.seeding_properties),
    slope_properties(other.slope_properties)
{}


SpecieProperties::SpecieProperties()
{

}

SpecieProperties::SpecieProperties(QString name,
                                   AgeingProperties ageing_properties,
                                   GrowthProperties growth_properties,
                                   IlluminationProperties illumination_properties,
                                   SoilHumidityProperties soil_humidity_properties,
                                   TemperatureProperties temperature_properties,
                                   SeedingProperties seeding_properties,
                                   SlopeProperties slope_properties) :
    SpecieProperties(name,0,ageing_properties,growth_properties,illumination_properties,soil_humidity_properties,temperature_properties,seeding_properties,
                     slope_properties)
{

}

SpecieProperties::SpecieProperties(QString name, int id,
                                   AgeingProperties ageing_properties,
                                   GrowthProperties growth_properties,
                                   IlluminationProperties illumination_properties,
                                   SoilHumidityProperties soil_humidity_properties,
                                   TemperatureProperties temperature_properties,
                                   SeedingProperties seeding_properties,
                                   SlopeProperties slope_properties) :
    specie_id(id), specie_name(name),
    ageing_properties(ageing_properties),
    growth_properties(growth_properties),
    illumination_properties(illumination_properties),
    soil_humidity_properties(soil_humidity_properties),
    temperature_properties(temperature_properties),
    seeding_properties(seeding_properties),
    slope_properties(slope_properties)
{}

//SpecieProperties::SpecieProperties & operator=(const SpecieProperties & other)
//{

//}
