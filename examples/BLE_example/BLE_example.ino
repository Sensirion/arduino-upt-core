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
void decodeAndPrintBLEAdvertisement(const std::string &data);
void printMeasurement(const Measurement &);

void setup() {
    Serial.begin(115200);
    while (!Serial)
        ;

    Serial.println(
        "Welcome to UPT Core BLE utility. We'll encode and decode "
        "some Sensirion Sensor measurements to and from a suitable format for "
        "transmission via BLE advertisement.");
    delay(1000);
}

void loop() {
    // Select at random some Advertisement sample
    DataType someDataType = static_cast<DataType>(random(1, 20));
    std::string data = generateBLEAdvertisement(someDataType);
    
    // Let's decode it
    decodeAndPrintBLEAdvertisement(data);

    Serial.println();
    delay(5000);
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
    case SignalType::GAS_CONCENTRATION_VOLUME_PERCENTAGE:
        return random(10, 150) / 10.0;
        break;
    default:
        return 420;
    }
}

void decodeAndPrintBLEAdvertisement(const std::string &data) {
    /*
    Data contains:
    < companyID (2 bytes) | Sample Adv. Type (1 byte) | SampleType (1 byte) |
    Device ID (2 bytes) | Sample data (SampleConfig.sampleSizeBytes bytes) >

    For a total length l = 6 + SampleConfig.sampleSizeBytes bytes
    */
    DataType decodedDataType =
        getDataTypeFromSampleType(static_cast<uint8_t>(data[3]));
    SampleConfig sampleConfig = sampleConfigSelector[decodedDataType];

    // Extract data piece-by-piece, using SampleConfig
    for (auto it = sampleConfig.sampleSlots.begin();
         it != sampleConfig.sampleSlots.end(); it++) {
        Measurement measurement;
        measurement.signalType = it->first;

        measurement.dataPoint.t_offset = millis();
        uint16_t rawValue = it->second.decodingFunction(
            getRawValue(data, 6 + it->second.offset));
        measurement.dataPoint.value = static_cast<float>(rawValue);

        printMeasurement(measurement);
    }
}

void printMeasurement(const Measurement &measurement) {
    // Get device and platform description
    const char *platformDescr = devicePlatformLabel(
        measurement.metaData.platform, measurement.metaData.deviceType);
    const char *deviceDescr = deviceLabel(measurement.metaData.platform,
                                          measurement.metaData.deviceType);

    // Get deviceID in string representation
    char deviceIDDescr[64];
    if (measurement.metaData.platform == DevicePlatform::BLE) {
        sprintf(deviceIDDescr, "0x%llx", measurement.metaData.deviceID);
    } else {
        sprintf(deviceIDDescr, "%llu", measurement.metaData.deviceID);
    }

    Serial.printf("\nShowing decoded Measurement:\n");

    Serial.printf("  Data Point:\n");
    Serial.printf("    Measured at:\t%lus\n",
                  measurement.dataPoint.t_offset / 1000);
    Serial.printf("    Value:\t\t");
    switch (measurement.signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
    case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
    case SignalType::VELOCITY_METERS_PER_SECOND:
    case SignalType::GAS_CONCENTRATION_VOLUME_PERCENTAGE:
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

    /* MetaData skipped in this example as information for fields deviceID and
     * deviceType are not included in ManufacturerData */

    return;
}
