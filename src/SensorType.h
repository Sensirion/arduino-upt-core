#ifndef SENSOR_TYPE_H
#define SENSOR_TYPE_H
#include "DeviceType.h"

/* X stands for any sensor version in a family, ie. SHT4X can be assigned to any
 * sensor in Sensirion's SHT4 series of sensors. */
struct SensorType {
    static const DeviceType SCD4X;
    static const DeviceType SFA3X;
    static const DeviceType SFA40;
    static const DeviceType SVM4X;
    static const DeviceType SVM41;
    static const DeviceType SHT4X;
    static const DeviceType SAV45;
    static const DeviceType SEN5X;
    static const DeviceType SEN50;
    static const DeviceType SEN54;
    static const DeviceType SEN55;
    static const DeviceType SCD30;
    static const DeviceType STC3X;
    static const DeviceType STC31;
    static const DeviceType SGP4X;
    static const DeviceType SGP41;
    static const DeviceType SEN66;
    static const DeviceType STCC4;
};

#endif /* SENSOR_TYPE_H */
