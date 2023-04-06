#include "SignalType.h"

std::string unitOf(SignalType signalType) {
    switch (signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
        return "degC";
    case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
        return "%";
    case SignalType::CO2_PARTS_PER_MILLION:
        return "ppm";
    case SignalType::HCHO_PARTS_PER_BILLION:
        return "ppb";
    case SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER:
        return "μg/m3";
    case SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER:
        return "μg/m3";
    case SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER:
        return "μg/m3";
    case SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER:
        return "μg/m3";
    case SignalType::VOC_INDEX:
        return ""; // VOC index is a unit free measure
    case SignalType::NOX_INDEX:
        return ""; // NOX index is a unit free measure
    default:
        return "UNDEFINED";
    }
}

std::string quantityOf(SignalType signalType) {
    switch (signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
        return "T";
    case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
        return "RH";
    case SignalType::CO2_PARTS_PER_MILLION:
        return "CO2";
    case SignalType::HCHO_PARTS_PER_BILLION:
        return "HCHO";
    case SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER:
        return "PM1P0";
    case SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER:
        return "PM2P5";
    case SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER:
        return "PM4P0";
    case SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER:
        return "PM10P0";
    case SignalType::VOC_INDEX:
        return "VOC";
    case SignalType::NOX_INDEX:
        return "NOX";
    default:
        return "UNDEFINED";
    }
}
