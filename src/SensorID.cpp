#include "SensorID.h"

std::string sensorName(SensorID sensorID) {
    switch (sensorID) {
    case SensorID::SCD4X:
        return "SCD4X";
    case SensorID::SFA3X:
        return "SFA3X";
    case SensorID::SEN44:
        return "SEN44";
    case SensorID::SHT4X:
        return "SHT4X";
    case SensorID::SVM4X:
        return "SVM4X";
    case SensorID::SAV45:
        return "SAV45";
    default:
        return "UNDEFINED";
    }
}
