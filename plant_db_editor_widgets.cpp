#include "plant_db_editor_widgets.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>

#include <iostream>

/****************************
 * GROWTH PROPERTIES WIDGET *
 ****************************/
GrowthPropertiesWidget::GrowthPropertiesWidget(QWidget* parent, Qt::WindowFlags f):
    QWidget(parent, f)
{
    // Init UI elements
    m_max_height_dsb = new MyCustomFloatingPointSizeSpinBox();
    m_max_canopy_width_dsb = new MyCustomFloatingPointSizeSpinBox();
    m_max_root_size_dsb = new MyCustomFloatingPointSizeSpinBox();
    m_canopy_cb = new QCheckBox();
    m_canopy_cb->setChecked(true);

    init_layout();
    init_signals();
}

GrowthPropertiesWidget::~GrowthPropertiesWidget()
{
}

GrowthProperties GrowthPropertiesWidget::getProperties()
{
    return GrowthProperties (m_max_height_dsb->value(),
                             m_max_root_size_dsb->value(),
                             m_max_canopy_width_dsb->value());
}

void GrowthPropertiesWidget::setProperties(const GrowthProperties & p_properties)
{
    m_max_height_dsb->setValue(p_properties.max_height);
    m_max_canopy_width_dsb->setValue(p_properties.max_canopy_width);
    m_max_root_size_dsb->setValue(p_properties.max_root_size);
}

void GrowthPropertiesWidget::clear()
{
    m_max_height_dsb->clear();
    m_max_canopy_width_dsb->clear();
    m_max_root_size_dsb->clear();
}

void GrowthPropertiesWidget::init_layout()
{
    QGridLayout * main_layout = new QGridLayout;

    int row(0);

    // Max monthly vertical growth
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Max height: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max_height_dsb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("Cm"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Canopy width checkbox
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Does plant have a canopy (shade projection): "),0,Qt::AlignLeft);
        h_layout->addWidget(m_canopy_cb,0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Max monthly canopy growth
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Max canopy width: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max_canopy_width_dsb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("Cm"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Max root size: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max_root_size_dsb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("Cm"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }

    setLayout(main_layout);
}

void GrowthPropertiesWidget::set_canopy_width_input_enabled(bool checked)
{
    m_max_canopy_width_dsb->setEnabled(checked);

    if(!checked)
        m_max_canopy_width_dsb->setValue(.0);
}

void GrowthPropertiesWidget::init_signals()
{
    connect(m_canopy_cb, SIGNAL(clicked(bool)), this, SLOT(set_canopy_width_input_enabled(bool)));
}

/****************************
 * AGEING PROPERTIES WIDGET *
 ****************************/
AgeingPropertiesWidget::AgeingPropertiesWidget(QWidget* parent, Qt::WindowFlags f) :
    m_start_of_decline_sb(new MyAgeSpinBox),
    m_max_age_sb(new MyAgeSpinBox)
{
    init_layout();
}

AgeingPropertiesWidget::~AgeingPropertiesWidget()
{

}

AgeingProperties AgeingPropertiesWidget::getProperties()
{
    return AgeingProperties(m_start_of_decline_sb->value(),
                            m_max_age_sb->value());
}

void AgeingPropertiesWidget::setProperties(const AgeingProperties & p_properties)
{
    m_start_of_decline_sb->setValue(p_properties.start_of_decline);
    m_max_age_sb->setValue(p_properties.max_age);
}

void AgeingPropertiesWidget::clear()
{
    m_start_of_decline_sb->clear();
    m_max_age_sb->clear();
}

void AgeingPropertiesWidget::init_layout()
{
    QGridLayout * main_layout = new QGridLayout;

     int row(0);

     // Start of decline
     {
         QHBoxLayout * h_layout = new QHBoxLayout();
         h_layout->addWidget(new QLabel("Start of decline: "),0,Qt::AlignLeft);
         h_layout->addWidget(m_start_of_decline_sb,0,Qt::AlignRight);
         h_layout->addWidget(new QLabel("months"),0,Qt::AlignRight);
         main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
     }
     // Max age
     {
         QHBoxLayout * h_layout = new QHBoxLayout();
         h_layout->addWidget(new QLabel("Maximum age: "),0,Qt::AlignLeft);
         h_layout->addWidget(m_max_age_sb,0,Qt::AlignRight);
         h_layout->addWidget(new QLabel("months"),0,Qt::AlignRight);
         main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
     }
     setLayout(main_layout);
}

/**********************************
 * ILLUMINATION PROPERTIES WIDGET *
 **********************************/
IlluminationPropertiesWidget::IlluminationPropertiesWidget(QWidget* parent, Qt::WindowFlags f) :
    m_prime_illumination_start_sb(new My24HourSpinBox),
    m_prime_illumination_end_sb(new My24HourSpinBox),
    m_min_illumination_sb(new My24HourSpinBox),
    m_max_illumination_sb(new My24HourSpinBox)
{
    init_layout();
}

IlluminationPropertiesWidget::~IlluminationPropertiesWidget()
{
}

IlluminationProperties IlluminationPropertiesWidget::getProperties()
{
    return IlluminationProperties(Range(m_prime_illumination_start_sb->value(),m_prime_illumination_end_sb->value()),
                                      m_min_illumination_sb->value(), m_max_illumination_sb->value());
}

void IlluminationPropertiesWidget::setProperties(const IlluminationProperties & p_properties)
{
    m_prime_illumination_start_sb->setValue(p_properties.prime_illumination.first);
    m_prime_illumination_end_sb->setValue(p_properties.prime_illumination.second);

    m_min_illumination_sb->setValue(p_properties.min_illumination);
    m_max_illumination_sb->setValue(p_properties.max_illumination);
}

void IlluminationPropertiesWidget::clear()
{
    m_prime_illumination_start_sb->clear();
    m_prime_illumination_end_sb->clear();
    m_min_illumination_sb->clear();
    m_max_illumination_sb->clear();
}

void IlluminationPropertiesWidget::init_layout()
{
    QGridLayout * main_layout = new QGridLayout;

    int row(0);

    // Illumination configuration
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Start of prime illumination: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_prime_illumination_start_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel(" hours"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("End of prime illumination: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_prime_illumination_end_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel(" hours"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }

    // Sensitivity configuration
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Minimum illumination: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_min_illumination_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel(" hours"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Maximum illumination: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max_illumination_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel(" hours"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }

    setLayout(main_layout);
}

/***********************************
 * SOIL HUMIDITY PROPERTIES WIDGET *
 ***********************************/
SoilHumidityPropertiesWidget::SoilHumidityPropertiesWidget(QWidget* parent, Qt::WindowFlags f) :
    m_prime_humidity_start_sb(new MyHumiditySpinBox),
    m_prime_humidity_end_sb(new MyHumiditySpinBox),
    m_min_humidity_sb(new MyHumiditySpinBox),
    m_max_humidity_sb(new MyHumiditySpinBox)
{
    init_layout();
}

SoilHumidityPropertiesWidget::~SoilHumidityPropertiesWidget()
{

}

SoilHumidityProperties SoilHumidityPropertiesWidget::getProperties()
{
    return SoilHumidityProperties(Range(m_prime_humidity_start_sb->value(), m_prime_humidity_end_sb->value()),
                                      m_min_humidity_sb->value(), m_max_humidity_sb->value());
}

void SoilHumidityPropertiesWidget::setProperties(const SoilHumidityProperties & p_properties)
{
    m_prime_humidity_start_sb->setValue(p_properties.prime_soil_humidity.first);
    m_prime_humidity_end_sb->setValue(p_properties.prime_soil_humidity.second);
    m_min_humidity_sb->setValue(p_properties.min_soil_humidity);
    m_max_humidity_sb->setValue(p_properties.max_soil_humidity);
}

void SoilHumidityPropertiesWidget::clear()
{
    m_prime_humidity_start_sb->clear();
    m_prime_humidity_end_sb->clear();
    m_min_humidity_sb->clear();
    m_max_humidity_sb->clear();
}

void SoilHumidityPropertiesWidget::init_layout()
{
    QGridLayout * main_layout = new QGridLayout;

    int row(0);

    // Start of prime
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Start of prime humidity: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_prime_humidity_start_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("mm"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // End of prime
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("End of prime humidity: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_prime_humidity_end_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("mm"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Drought Sensitivity
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Minimum humidity: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_min_humidity_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("mm"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Flood Sensitivity
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Maximum humidity: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max_humidity_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("mm"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    setLayout(main_layout);
}

/*********************************
 * TEMPERATURE PROPERTIES WIDGET *
 *********************************/
TemperaturePropertiesWidget::TemperaturePropertiesWidget(QWidget* parent, Qt::WindowFlags f) :
    m_prime_temp_start_sb(new MyTemperatureSpinBox),
    m_prime_temp_end_sb(new MyTemperatureSpinBox),
    m_min_temp_sb(new MyTemperatureSpinBox),
    m_max_temp_sb(new MyTemperatureSpinBox)
{
    init_layout();
}

TemperaturePropertiesWidget::~TemperaturePropertiesWidget()
{

}

TemperatureProperties TemperaturePropertiesWidget::getProperties()
{
    return TemperatureProperties(Range(m_prime_temp_start_sb->value(), m_prime_temp_end_sb->value()),
                                     m_min_temp_sb->value(), m_max_temp_sb->value());
}

void TemperaturePropertiesWidget::setProperties(const TemperatureProperties & p_properties)
{
    m_prime_temp_start_sb->setValue(p_properties.prime_temp.first);
    m_prime_temp_end_sb->setValue(p_properties.prime_temp.second);
    m_min_temp_sb->setValue(p_properties.min_temp);
    m_max_temp_sb->setValue(p_properties.max_temp);
}

void TemperaturePropertiesWidget::clear()
{
    m_prime_temp_start_sb->clear();
    m_prime_temp_end_sb->clear();
    m_min_temp_sb->clear();
    m_max_temp_sb->clear();
}

void TemperaturePropertiesWidget::init_layout()
{
    QGridLayout * main_layout = new QGridLayout;

    int row(0);

    // Start of prime
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Start of prime temperature: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_prime_temp_start_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("degrees celcius"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // End of prime
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("End of prime temperature: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_prime_temp_end_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("degrees celcius"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Drought Sensitivity
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Minimum temperature: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_min_temp_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("degrees celcius"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Flood Sensitivity
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Maximum temperature: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max_temp_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel("degrees celcius"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    setLayout(main_layout);
}

/*****************************
 * SLOPE PROPERTIES WIDGET *
 *****************************/
SlopePropertiesWidget::SlopePropertiesWidget(QWidget* parent, Qt::WindowFlags f) :
    m_start_of_decline(new QSpinBox),
    m_max(new QSpinBox)
{
    m_start_of_decline->setRange(0,90);
    m_start_of_decline->setValue(0);

    m_max->setRange(0,90);
    m_max->setValue(0);

    init_layout();
}

SlopePropertiesWidget::~SlopePropertiesWidget()
{

}

SlopeProperties SlopePropertiesWidget::getProperties()
{
    return SlopeProperties(m_start_of_decline->value(), m_max->value());
}

void SlopePropertiesWidget::setProperties(const SlopeProperties & p_properties)
{
    m_start_of_decline->setValue(p_properties.start_of_decline);
    m_max->setValue(p_properties.max);
}

void SlopePropertiesWidget::clear()
{
    m_start_of_decline->clear();
    m_max->clear();
}

void SlopePropertiesWidget::init_layout()
{
    QGridLayout * main_layout = new QGridLayout;

    int row(0);

    // Start of decline
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Start of decline: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_start_of_decline,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel(" Degrees"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Sensitivity
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Max: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel(" Degrees"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    setLayout(main_layout);
}

/*****************************
 * SEEDING PROPERTIES WIDGET *
 *****************************/
#define MIN_SEEDING_DISTANCE 1
#define MAX_SEEDING_DISTANCE 100

#define MIN_SEEDS 0
#define MAX_SEEDS 5000

SeedingPropertiesWidget::SeedingPropertiesWidget(QWidget* parent, Qt::WindowFlags f )
{
    m_max_seeding_distance_sb = new QSpinBox();
    m_max_seeding_distance_sb->setRange(MIN_SEEDING_DISTANCE, MAX_SEEDING_DISTANCE);

    m_seed_count_sb = new QSpinBox();
    m_seed_count_sb->setRange(MIN_SEEDS, MAX_SEEDS);

    init_layout();
}

SeedingPropertiesWidget::~SeedingPropertiesWidget()
{

}

SeedingProperties SeedingPropertiesWidget::getProperties()
{
    return SeedingProperties(m_max_seeding_distance_sb->value(), m_seed_count_sb->value());
}

void SeedingPropertiesWidget::setProperties(const SeedingProperties & p_properties)
{
    m_max_seeding_distance_sb->setValue(p_properties.max_seed_distance);
    m_seed_count_sb->setValue(p_properties.seed_count);
}

void SeedingPropertiesWidget::clear()
{
    m_max_seeding_distance_sb->clear();
    m_seed_count_sb->clear();
}

void SeedingPropertiesWidget::init_layout()
{
    QGridLayout * main_layout = new QGridLayout;

    int row(0);

    // Start of prime
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Max Seeding Distance:: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_max_seeding_distance_sb,0,Qt::AlignRight);
        h_layout->addWidget(new QLabel(" Meters"),0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    // Sensitivity
    {
        QHBoxLayout * h_layout = new QHBoxLayout();
        h_layout->addWidget(new QLabel("Annual seed count: "),0,Qt::AlignLeft);
        h_layout->addWidget(m_seed_count_sb,0,Qt::AlignRight);
        main_layout->addLayout(h_layout,row++,0,1,1,Qt::AlignLeft);
    }
    setLayout(main_layout);
}
