#include "BLEProtocol.h"

namespace sensirion::upt::core{
std::map<DataType, SampleConfig> sampleConfigSelector = {
    {T_RH_V3,
     {.dataType = DataType::T_RH_V3,
      .downloadType = 0,
      .sampleType = 4,
      .sampleSizeBytes = 4,
      .sampleCountPerPacket = 4,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}}}}},
    {T_RH_V4,
     {.dataType = DataType::T_RH_V4,
      .downloadType = 5,
      .sampleType = 6,
      .sampleSizeBytes = 4,
      .sampleCountPerPacket = 4,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV2,
                        .decodingFunction = &decodeHumidityV2}}}}},
    {T_RH_VOC,
     {.dataType = DataType::T_RH_VOC,
      .downloadType = 1,
      .sampleType = 3,
      .sampleSizeBytes = 6,
      .sampleCountPerPacket = 3,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}}}}},
    {T_RH_CO2,
     {.dataType = DataType::T_RH_CO2,
      .downloadType = 9,
      .sampleType = 10,
      .sampleSizeBytes = 6,
      .sampleCountPerPacket = 3,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::CO2_PARTS_PER_MILLION,
                       {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}}}}},
    {T_RH_CO2_ALT,
     {.dataType = DataType::T_RH_CO2_ALT,
      .downloadType = 7,
      .sampleType = 8,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots =
          {
              {SignalType::TEMPERATURE_DEGREES_CELSIUS,
               {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                .offset = 0,
                .encodingFunction = &encodeTemperatureV1,
                .decodingFunction = &decodeTemperatureV1}},
              {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
               {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                .offset = 2,
                .encodingFunction = &encodeHumidityV1,
                .decodingFunction = &decodeHumidityV1}},
              {SignalType::CO2_PARTS_PER_MILLION,
               {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                .offset = 4,
                .encodingFunction = &encodeSimple,
                .decodingFunction = &decodeSimple}}
              // 2 Bytes reserved (ALT), not used, but bytes must be sent for
              // proper decoding of samples
          }}},
    {T_RH_CO2_PM25,
     {.dataType = DataType::T_RH_CO2_PM25,
      .downloadType = 11,
      .sampleType = 12,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::CO2_PARTS_PER_MILLION,
                       {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 6,
                        .encodingFunction = &encodePM2p5V1,
                        .decodingFunction = &decodePM2p5V1}}}}},
    {T_RH_VOC_PM25,
     {.dataType = DataType::T_RH_VOC_PM25,
      .downloadType = 15,
      .sampleType = 16,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 6,
                        .encodingFunction = &encodePM2p5V1,
                        .decodingFunction = &decodePM2p5V1}}}}},
    {T_RH_VOC_NOX,
     {.dataType = DataType::T_RH_VOC_NOX,
      .downloadType = 21,
      .sampleType = 22,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::NOX_INDEX,
                       {.signalType = SignalType::NOX_INDEX,
                        .offset = 6,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}}}}},
    {T_RH_VOC_NOX_PM25,
     {.dataType = DataType::T_RH_VOC_NOX_PM25,
      .downloadType = 23,
      .sampleType = 24,
      .sampleSizeBytes = 10,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::NOX_INDEX,
                       {.signalType = SignalType::NOX_INDEX,
                        .offset = 6,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 8,
                        .encodingFunction = &encodePMV2,
                        .decodingFunction = &decodePMV2}}}}},
    {T_RH_HCHO,
     {.dataType = DataType::T_RH_HCHO,
      .downloadType = 13,
      .sampleType = 14,
      .sampleSizeBytes = 6,
      .sampleCountPerPacket = 3,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::HCHO_PARTS_PER_BILLION,
                       {.signalType = SignalType::HCHO_PARTS_PER_BILLION,
                        .offset = 4,
                        .encodingFunction = &encodeHCHOV1,
                        .decodingFunction = &decodeHCHOV1}}}}},
    {T_RH_CO2_VOC_PM25_HCHO,
     {.dataType = DataType::T_RH_CO2_VOC_PM25_HCHO,
      .downloadType = 19,
      .sampleType = 20,
      .sampleSizeBytes = 12,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::CO2_PARTS_PER_MILLION,
                       {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 6,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 8,
                        .encodingFunction = &encodePM2p5V1,
                        .decodingFunction = &decodePM2p5V1}},
                      {SignalType::HCHO_PARTS_PER_BILLION,
                       {.signalType = SignalType::HCHO_PARTS_PER_BILLION,
                        .offset = 10,
                        .encodingFunction = &encodeHCHOV1,
                        .decodingFunction = &decodeHCHOV1}}}}},
    {T_RH_CO2_VOC_NOX_PM25,
     {.dataType = DataType::T_RH_CO2_VOC_NOX_PM25,
      .downloadType = 25,
      .sampleType = 26,
      .sampleSizeBytes = 12,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::CO2_PARTS_PER_MILLION,
                       {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 6,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::NOX_INDEX,
                       {.signalType = SignalType::NOX_INDEX,
                        .offset = 8,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 10,
                        .encodingFunction = &encodePMV2,
                        .decodingFunction = &decodePMV2}}}}},
    {T_RH_CO2_PM25_V2,
     {.dataType = DataType::T_RH_CO2_PM25_V2,
      .downloadType = 27,
      .sampleType = 28,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::CO2_PARTS_PER_MILLION,
                       {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 6,
                        .encodingFunction = &encodePMV2,
                        .decodingFunction = &decodePMV2}}}}},
    {T_RH_VOC_PM25_V2,
     {.dataType = DataType::T_RH_VOC_PM25_V2,
      .downloadType = 29,
      .sampleType = 30,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 6,
                        .encodingFunction = &encodePMV2,
                        .decodingFunction = &decodePMV2}}}}},
    {T_RH_CO2_VOC_PM25_HCHO_V2,
     {.dataType = DataType::T_RH_CO2_VOC_PM25_HCHO_V2,
      .downloadType = 30,
      .sampleType = 31,
      .sampleSizeBytes = 12,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 0,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}},
                      {SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                       {.signalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE,
                        .offset = 2,
                        .encodingFunction = &encodeHumidityV1,
                        .decodingFunction = &decodeHumidityV1}},
                      {SignalType::CO2_PARTS_PER_MILLION,
                       {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                        .offset = 4,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::VOC_INDEX,
                       {.signalType = SignalType::VOC_INDEX,
                        .offset = 6,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}},
                      {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                       {.signalType =
                            SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
                        .offset = 8,
                        .encodingFunction = &encodePMV2,
                        .decodingFunction = &decodePMV2}},
                      {SignalType::HCHO_PARTS_PER_BILLION,
                       {.signalType = SignalType::HCHO_PARTS_PER_BILLION,
                        .offset = 10,
                        .encodingFunction = &encodeHCHOV1,
                        .decodingFunction = &decodeHCHOV1}}}}},
    {PM10_PM25_PM40_PM100,
     {.dataType = DataType::PM10_PM25_PM40_PM100,
      .downloadType = 33,
      .sampleType = 34,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots =
          {{SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER,
            {.signalType = SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER,
             .offset = 0,
             .encodingFunction = &encodePMV2,
             .decodingFunction = &decodePMV2}},
           {SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
            {.signalType = SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
             .offset = 2,
             .encodingFunction = &encodePMV2,
             .decodingFunction = &decodePMV2}},
           {SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER,
            {.signalType = SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER,
             .offset = 4,
             .encodingFunction = &encodePMV2,
             .decodingFunction = &decodePMV2}},
           {SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER,
            {.signalType = SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER,
             .offset = 6,
             .encodingFunction = &encodePMV2,
             .decodingFunction = &decodePMV2}}}}},
    {CO2_DataType,
     {.dataType = DataType::CO2_DataType,
      .downloadType = 35,
      .sampleType = 36,
      .sampleSizeBytes = 2,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::CO2_PARTS_PER_MILLION,
                       {.signalType = SignalType::CO2_PARTS_PER_MILLION,
                        .offset = 0,
                        .encodingFunction = &encodeSimple,
                        .decodingFunction = &decodeSimple}}}}},
    {AV_T,
     {.dataType = DataType::AV_T,
      .downloadType = 37,
      .sampleType = 38,
      .sampleSizeBytes = 4,
      .sampleCountPerPacket = 4,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{SignalType::VELOCITY_METERS_PER_SECOND,
                       {.signalType = SignalType::VELOCITY_METERS_PER_SECOND,
                        .offset = 0,
                        .encodingFunction = &encodeVelocityV1,
                        .decodingFunction = &decodeVelocityV1}},
                      {SignalType::TEMPERATURE_DEGREES_CELSIUS,
                       {.signalType = SignalType::TEMPERATURE_DEGREES_CELSIUS,
                        .offset = 2,
                        .encodingFunction = &encodeTemperatureV1,
                        .decodingFunction = &decodeTemperatureV1}}}}}
    /* Add new SampleConfigs here */
};

// Converter functions
uint16_t encodeSimple(float value) {
    return static_cast<uint16_t>(value + 0.5f);
}

uint16_t encodeTemperatureV1(float value) {
    return static_cast<uint16_t>((((value + 45) / 175) * 65535) + 0.5f);
}

uint16_t encodeHumidityV1(float value) {
    return static_cast<uint16_t>(((value / 100) * 65535) + 0.5f);
}

uint16_t encodeHumidityV2(float value) {
    return static_cast<uint16_t>((((value + 6.0) * 65535) / 125.0) + 0.5f);
}

uint16_t encodePM2p5V1(float value) {
    return static_cast<uint16_t>(((value / 1000) * 65535) + 0.5f);
}

uint16_t encodePMV2(float value) {
    return static_cast<uint16_t>((value * 10) + 0.5f);
}

uint16_t encodeHCHOV1(float value) {
    return static_cast<uint16_t>((value * 5) + 0.5f);
}

uint16_t encodeVelocityV1(float value) {
    return static_cast<uint16_t>((value / 1024) * 65535 + 0.5f);
}
/* Define new encoding function here */

float decodeSimple(uint16_t rawValue) { return static_cast<float>(rawValue); }

float decodeTemperatureV1(uint16_t rawValue) {
    return -45.0f + ((175.0f * static_cast<float>(rawValue)) / 65535);
}

float decodeHumidityV1(uint16_t rawValue) {
    return (100.0f * static_cast<float>(rawValue)) / 65535;
}

float decodeHumidityV2(uint16_t rawValue) {
    return (125.0f * static_cast<float>(rawValue)) / 65535 - 6.0f;
}

float decodePM2p5V1(uint16_t rawValue) {
    return (1000.0f * static_cast<float>(rawValue)) / 65535;
}

float decodePMV2(uint16_t rawValue) {
    return static_cast<float>(rawValue) / 10.0f;
}

float decodeHCHOV1(uint16_t rawValue) {
    return static_cast<float>(rawValue) / 5.0f;
}

float decodeVelocityV1(uint16_t rawValue) {
    return rawValue * 1024.0 / 65535.0;
}
/* Define new decoding function here */

void emplaceRawValue(std::string &data, uint8_t offset, uint16_t rawValue) {
    if (offset + sizeof(uint16_t) <= data.size()) {
        data[offset] = static_cast<uint8_t>(rawValue);
        data[offset + 1] = static_cast<uint8_t>(rawValue >> 8);
    }
}

uint16_t getRawValue(const std::string &data, uint8_t offset) {
    uint16_t rawValue = 0;
    if (offset + sizeof(uint16_t) <= data.size()) {
        rawValue =
            static_cast<uint16_t>(static_cast<uint16_t>(data[offset + 1]) << 8 |
                                  static_cast<uint8_t>(data[offset]));
    }
    return rawValue;
}

DataType getDataTypeFromSampleType(uint8_t sampleType) {
    // Look through config selector for a matching entry.
    for (auto it = sampleConfigSelector.begin();
         it != sampleConfigSelector.end(); it++) {
        if (it->second.sampleType == sampleType) {
            return it->first;
        }
    }
    return DataType::UNDEFINED;
}
} // end namespace
