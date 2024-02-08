/*
The code below repeatedly prints random measurements representative of the
typical instances one might encounter using the Unified Prototyping Toolkit.
*/

#include "Arduino.h"
#include "Sensirion_UPT_Core.h"

Measurement createRandomMeasurement();
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

    Serial.printf("Showing Measurement:\n");
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
    measurement.signalType = static_cast<SignalType>(random(1, 15));

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
    case SignalType::RAW_VOC_INDEX:
    case SignalType::RAW_NOX_INDEX:
        measurement.dataPoint.value = random(1000, 10000);
        break;
    case SignalType::VOC_INDEX:
    case SignalType::NOX_INDEX:
        measurement.dataPoint.value = random(100, 1000);
        break;
    case SignalType::GAS_CONCENTRATION_VOLUME_PERCENTAGE:
        measurement.dataPoint.value = random(10, 150) / 10.0;
        break;
    default:
        measurement.dataPoint.value = 420;
    }

    return measurement;
}
