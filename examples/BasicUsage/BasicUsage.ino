/*
The code below repeatedly prints random measurements representative of the
typical instances one might encounter using the Unified Prototyping Toolkit.
*/

#include "Arduino.h"
#include "Sensirion_UPT_Core.h"

Measurement createRandomMeasurement();
void printMeasurement(const Measurement &);
Measurement dummyMeasurement;

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(1000);

    Serial.println("======================================");
    Serial.println("--------------------------------------");
    Serial.println("Default Measurement:");
    Serial.println("--------------------------------------");
    printMeasurement(dummyMeasurement);

    Serial.println("\n======================================\n");
}

void loop() {
    delay(1000);
    dummyMeasurement = createRandomMeasurement();
    printMeasurement(dummyMeasurement);
}

Measurement createRandomMeasurement() {
    Measurement measurement;

    // Metadata
    if (random(2)) { // I2C Sensor
        measurement.metaData.platform = DevicePlatform::WIRED;
        uint64_t deviceID = 0;
        // Serial No. for i2c sensors typically is a 48-bit value
        for (int i = 0; i < 48; i++) {
            deviceID = deviceID | (random(2) << i);
        }
        measurement.metaData.deviceID = deviceID;
        measurement.metaData.deviceType.sensorType =
            static_cast<SensorType>(random(1, 16));
    } else { // BLE Gadget
        measurement.metaData.platform = DevicePlatform::BLE;
        uint64_t deviceID = 0;
        // MAC address of a BLE device typically is a 64-bit value
        for (int i = 0; i < 64; i++) {
            deviceID = deviceID | (random(2) << i);
        }
        measurement.metaData.deviceID = deviceID;
        measurement.metaData.deviceType.bleGadgetType =
            static_cast<BLEGadgetType>(random(1, 7));
    }

    // SignalType
    measurement.signalType = static_cast<SignalType>(random(1, 13));

    // DataPoint
    measurement.dataPoint.t_offset = random(10 * 1000 * 1000);
    switch (measurement.signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
        measurement.dataPoint.value = random(-200, 300) / 10.;
        break;
    case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
        measurement.dataPoint.value = random(1000) / 10.;
        break;
    case SignalType::CO2_PARTS_PER_MILLION:
        measurement.dataPoint.value = random(450, 1500);
        break;
    case SignalType::HCHO_PARTS_PER_BILLION:
        measurement.dataPoint.value = random(0, 50);
        break;
    case SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER:
        measurement.dataPoint.value = random(150, 750);
        break;
    case SignalType::VELOCITY_METERS_PER_SECOND:
        measurement.dataPoint.value = random(-100, 100) / 10.;
        break;
    case SignalType::VOC_INDEX:
    case SignalType::NOX_INDEX:
        measurement.dataPoint.value = random(100, 1000);
        break;
    case SignalType::GAS_CONCENTRATION:
        measurement.dataPoint.value = random(10, 150);
        break;
    default:
        measurement.dataPoint.value = 420;
    }

    return measurement;
}

void printMeasurement(const Measurement &measurement) {
    // Get device and platform descriptive labels
    const char *platformLbl = devicePlatformLabel(
        measurement.metaData.platform, measurement.metaData.deviceType);
    const char *deviceLbl = deviceLabel(measurement.metaData.platform,
                                          measurement.metaData.deviceType);

    // Get deviceID in string representation
    char deviceIDStr[64];
    if (measurement.metaData.platform == DevicePlatform::BLE) {
        sprintf(deviceIDStr, "0x%llx", measurement.metaData.deviceID);
    } else {
        sprintf(deviceIDStr, "%llu", measurement.metaData.deviceID);
    }

    Serial.printf("\nShowing Measurement:\n");

    Serial.printf("  Data Point:\n");
    Serial.printf("    Measured at:\t%lus\n",
                  measurement.dataPoint.t_offset / 1000);
    Serial.printf("    Value:\t\t");
    switch (measurement.signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
    case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
    case SignalType::VELOCITY_METERS_PER_SECOND:
        Serial.printf("%.1f\n", measurement.dataPoint.value);
        break;
    case SignalType::CO2_PARTS_PER_MILLION:
    case SignalType::HCHO_PARTS_PER_BILLION:
    case SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::VOC_INDEX:
    case SignalType::NOX_INDEX:
    case SignalType::GAS_CONCENTRATION:
        Serial.printf("%i\n", static_cast<int>(measurement.dataPoint.value));
        break;
    default:
        Serial.printf("%i\n", static_cast<int>(measurement.dataPoint.value));
        break;
    }

    Serial.printf("  SignalType:\n");
    Serial.printf("    Physical Quantity:\t%s\n",
                  quantityOf(measurement.signalType));
    Serial.printf("    Units:\t\t%s\n", unitOf(measurement.signalType));

    Serial.printf("  Metadata:\n");
    Serial.printf("    Platform:\t\t%s\n", platformLbl);
    Serial.printf("    deviceID:\t\t%s\n", deviceIDStr);
    Serial.printf("    Device Type:\t%s\n", deviceLbl);

    return;
}
