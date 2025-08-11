#ifndef SIGNAL_TYPE_H
#define SIGNAL_TYPE_H

namespace upt_core{

/**
 * @note RAW VOC and NOX values must be converted to index scale to have any
 * meaning. This is achieved with the Sensirion Gas Index Algorithm: see
 * https://github.com/Sensirion/gas-index-algorithm
 */
enum class SignalType {
    UNDEFINED,
    TEMPERATURE_DEGREES_CELSIUS,
    TEMPERATURE_DEGREES_FARENHEIT,
    RELATIVE_HUMIDITY_PERCENTAGE,
    CO2_PARTS_PER_MILLION,
    HCHO_PARTS_PER_BILLION,
    PM1P0_MICRO_GRAMM_PER_CUBIC_METER,
    PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
    PM4P0_MICRO_GRAMM_PER_CUBIC_METER,
    PM10P0_MICRO_GRAMM_PER_CUBIC_METER,
    RAW_VOC_INDEX,
    RAW_NOX_INDEX,
    VOC_INDEX,
    NOX_INDEX,
    VELOCITY_METERS_PER_SECOND,
    GAS_CONCENTRATION_VOLUME_PERCENTAGE
};

/**
 * @brief Get the unit of a SignalType.
 *  The "unit" refers to the physical unit of a SignalType.
 *  Note that signalsTypes may be unit-free.
 *
 * @return const char*
 *  e.g. "degC" for TEMPERATURE_DEGREES_CELSIUS
 */
const char *unitOf(SignalType signalType);

/**
 * @brief Get the quantity of a SignalType.
 *  The "quantity" refers to the name of a SignalType.
 *
 * @return const char*
 *  e.g. "T" for TEMPERATURE_DEGREES_CELSIUS
 */
const char *quantityOf(SignalType signalType);

} // end namespace

#endif /* SIGNAL_TYPE_H */
