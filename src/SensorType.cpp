#include "SensorType.h"

const char *sensorLabel(SensorType sensorType) {
    switch (sensorType) {
    case SensorType::SCD4X:
        return "SCD4X";
    case SensorType::SFA3X:
        return "SFA3X";
    case SensorType::SEN44:
        return "SEN44";
    case SensorType::SHT4X:
        return "SHT4X";
    case SensorType::SVM4X:
        return "SVM4X";
    case SensorType::SAV45:
        return "SAV45";
    case SensorType::SEN5X:
        return "SEN5X";
    case SensorType::SCD30:
        return "SCD30";
    case SensorType::STC3X:
        return "STC3X";
    case SensorType::SGP41:
        return "SGP41";
    default:
        return "UNDEFINED";
    }
}
