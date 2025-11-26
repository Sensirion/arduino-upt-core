#include "SignalType.h"

namespace sensirion::upt::core{

const char *unitOf(SignalType signalType) {
    switch (signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
        return "degC";
    case SignalType::TEMPERATURE_DEGREES_FARENHEIT:
        return "degF";
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
    case SignalType::VELOCITY_METERS_PER_SECOND:
        return "m/s";
    case SignalType::RAW_VOC_INDEX:
        return "n/a";
    case SignalType::RAW_NOX_INDEX:
        return "n/a";
    case SignalType::VOC_INDEX:
        return ""; // VOC index is a unit free measure
    case SignalType::NOX_INDEX:
        return ""; // NOX index is a unit free measure
    case SignalType::GAS_CONCENTRATION_VOLUME_PERCENTAGE:
    case SignalType::H2_CONCENTRATION_VOLUME_PERCENTAGE:
        return "vol%";
    case SignalType::PRESSURE_MBAR:
        return "mbar";
    default:
        return "UNDEFINED";
    }
}

const char *quantityOf(SignalType signalType) {
    switch (signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
    case SignalType::TEMPERATURE_DEGREES_FARENHEIT:
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
    case SignalType::VELOCITY_METERS_PER_SECOND:
        return "VELOCITY";
    case SignalType::RAW_VOC_INDEX:
        return "RAW VOC";
    case SignalType::RAW_NOX_INDEX:
        return "RAW NOX";
    case SignalType::VOC_INDEX:
        return "VOC INDEX";
    case SignalType::NOX_INDEX:
        return "NOX INDEX";
    case SignalType::GAS_CONCENTRATION_VOLUME_PERCENTAGE:
        return "GAS CONC.";
    case SignalType::H2_CONCENTRATION_VOLUME_PERCENTAGE:
        return "H2 CONC.";
    case SignalType::PRESSURE_MBAR:
        return "PRESSURE";
    default:
        return "UNDEFINED";
    }
}

} // end namespace