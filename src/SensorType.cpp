#include "SensorType.h"

const char *sensorLabel(SensorType sensorType) {
    switch (sensorType) {
    case SensorType::SCD4X:
        return "SCD4X";
    case SensorType::SFA3X:
        return "SFA3X";
    case SensorType::SVM4X:
        return "SVM4X";
    case SensorType::SVM41:
        return "SVM41";
    case SensorType::SHT4X:
        return "SHT4X";
    case SensorType::SAV45:
        return "SAV45";
    case SensorType::SEN5X:
        return "SEN5X";
    case SensorType::SEN50:
        return "SEN50";
    case SensorType::SEN54:
        return "SEN54";
    case SensorType::SEN55:
        return "SEN55";
    case SensorType::SCD30:
        return "SCD30";
    case SensorType::STC3X:
        return "STC3X";
    case SensorType::STC31:
        return "STC31";
    case SensorType::SGP4X:
        return "SGP4X";
    case SensorType::SGP41:
        return "SGP41";
    case SensorType::SEN66:
        return "SEN66";
    case SensorType::STCC4:
        return "STCC4";
    default:
        return "UNDEFINED";
    }
}
