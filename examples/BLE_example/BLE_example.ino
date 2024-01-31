/*
The code below repeatedly prints random measurements representative of the
typical instances one might encounter using the Unified Prototyping Toolkit,
when decoding BLE advertisements from Sensirion BLE Gadgets.
*/

#include "Arduino.h"
#include "Sensirion_UPT_Core.h"

static const uint16_t SENSIRION_BLE_COMPANY_ID = 54534;
std::string generateBLEAdvertisement(DataType dataType);
float randomMeasurement(SignalType signalType);

void setup() {
    Serial.begin(115200);
    while (!Serial)
        ;

    Serial.println(
        "Welcome to UPT Core BLE utility. We'll encode "
        "some Sensirion Sensor measurements to a suitable format for "
        "transmission via BLE advertisement.");
    delay(1000);
}

void loop() {
    // Select at random some Advertisement sample
    DataType someDataType = static_cast<DataType>(random(1, 20));
    std::string data = generateBLEAdvertisement(someDataType);

    delay(1000);
}

std::string generateBLEAdvertisement(DataType dataType) {

    SampleConfig sampleConfig = sampleConfigSelector[dataType];

    // Build ManufacturerData for a dummy measurement
    std::string data;
    /*
    Data contains:
    < companyID (2 bytes) | Sample Adv. Type (1 byte) | SampleType (1 byte) |
    Device ID (2 bytes) | Sample data (SampleConfig.sampleSizeBytes bytes) >

    For a total length l = 6 + SampleConfig.sampleSizeBytes bytes
    */
    // Fill with zeroes up to required size
    data.resize(6 + sampleConfig.sampleSizeBytes, (char)(0));
    // CompanyID
    data[0] = static_cast<uint8_t>(SENSIRION_BLE_COMPANY_ID >> 8);
    data[1] = static_cast<uint8_t>(SENSIRION_BLE_COMPANY_ID);
    // Sample types
    data[2] = sampleConfig.sensirionAdvertisementSampleType;
    data[3] = sampleConfig.sampleType;
    // Device ID
    uint16_t deviceID = random(1000);
    data[4] = static_cast<uint8_t>(deviceID >> 8);
    data[5] = static_cast<uint8_t>(deviceID);
    // Sample Data
    for (auto it = sampleConfig.sampleSlots.begin();
         it != sampleConfig.sampleSlots.end(); it++) {
        // Make up a random measurement
        float sampleValue = randomMeasurement(it->first);
        // Encode and place in data
        uint16_t encodedSample = it->second.encodingFunction(sampleValue);
        emplaceRawValue(data, 6 + it->second.offset, encodedSample);

        Serial.printf("New signal:\t%s %.1f %s\n", quantityOf(it->first),
                      sampleValue, unitOf(it->first));
    }
    return data;
}

float randomMeasurement(SignalType signalType) {
    switch (signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
        return random(-200, 300) / 10.;
        break;
    case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
        return random(1000) / 10.;
        break;
    case SignalType::CO2_PARTS_PER_MILLION:
        return random(450, 1500);
        break;
    case SignalType::HCHO_PARTS_PER_BILLION:
        return random(0, 50);
        break;
    case SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER:
        return random(150, 750);
        break;
    case SignalType::VELOCITY_METERS_PER_SECOND:
        return random(-100, 100) / 10.;
        break;
    case SignalType::VOC_INDEX:
    case SignalType::NOX_INDEX:
        return random(100, 1000);
        break;
    case SignalType::GAS_CONCENTRATION:
        return random(10, 150);
        break;
    default:
        return 420;
    }
}