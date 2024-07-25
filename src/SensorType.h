#ifndef SENSOR_TYPE_H
#define SENSOR_TYPE_H

/* X stands for any sensor version in a family, ie. SHT4X can be assigned to any
 * sensor in Sensirion's SHT4 series of sensors. */
enum class SensorType {
    UNDEFINED,
    SCD4X,
    SFA3X,
    SVM4X,
    SVM41,
    SHT4X,
    SAV45,
    SEN5X,
    SEN50,
    SEN54,
    SEN55,
    SCD30,
    STC3X,
    STC31,
    SGP4X,
    SGP41,
    SEN66
};

/**
 * @brief obtain a label for the sensor type, eg. "SCD4X"
 */
const char *sensorLabel(SensorType sensorType);

#endif /* SENSOR_TYPE_H */
