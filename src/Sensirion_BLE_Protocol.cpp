#include "Sensirion_BLE_Protocol.h"

std::map<DataType, SampleConfig> sampleConfigSelector = {
    {T_RH_V3,
     {.dataType = DataType::T_RH_V3,
      .downloadType = 0,
      .sampleType = 4,
      .sampleSizeBytes = 4,
      .sampleCountPerPacket = 4,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}}}}},
    {T_RH_V4,
     {.dataType = DataType::T_RH_V4,
      .downloadType = 5,
      .sampleType = 6,
      .sampleSizeBytes = 4,
      .sampleCountPerPacket = 4,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV2}}}}},
    {T_RH_VOC,
     {.dataType = DataType::T_RH_VOC,
      .downloadType = 1,
      .sampleType = 3,
      .sampleSizeBytes = 6,
      .sampleCountPerPacket = 3,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::VOC,
                       {.unit = Unit::VOC,
                        .offset = 4,
                        .converterFunction = &convertSimple}}}}},
    {T_RH_CO2,
     {.dataType = DataType::T_RH_CO2,
      .downloadType = 9,
      .sampleType = 10,
      .sampleSizeBytes = 6,
      .sampleCountPerPacket = 3,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}}}}},
    {T_RH_CO2_ALT,
     {.dataType = DataType::T_RH_CO2_ALT,
      .downloadType = 7,
      .sampleType = 8,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}}}}},
    {T_RH_CO2_PM25,
     {.dataType = DataType::T_RH_CO2_PM25,
      .downloadType = 11,
      .sampleType = 12,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 6,
                        .converterFunction = &convertPM2p5V1}}}}},
    {T_RH_VOC_PM25,
     {.dataType = DataType::T_RH_VOC_PM25,
      .downloadType = 15,
      .sampleType = 16,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::VOC,
                       {.unit = Unit::VOC,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 6,
                        .converterFunction = &convertPM2p5V1}}}}},
    {T_RH_VOC_NOX,
     {.dataType = DataType::T_RH_VOC_NOX,
      .downloadType = 21,
      .sampleType = 22,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::VOC,
                       {.unit = Unit::VOC,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::NOX,
                       {.unit = Unit::NOX,
                        .offset = 6,
                        .converterFunction = &convertSimple}}}}},
    {T_RH_VOC_NOX_PM25,
     {.dataType = DataType::T_RH_VOC_NOX_PM25,
      .downloadType = 23,
      .sampleType = 24,
      .sampleSizeBytes = 20,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::VOC,
                       {.unit = Unit::VOC,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::NOX,
                       {.unit = Unit::NOX,
                        .offset = 6,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 8,
                        .converterFunction = &convertPMV2}}}}},
    {T_RH_HCHO,
     {.dataType = DataType::T_RH_HCHO,
      .downloadType = 13,
      .sampleType = 14,
      .sampleSizeBytes = 6,
      .sampleCountPerPacket = 3,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::HCHO,
                       {.unit = Unit::HCHO,
                        .offset = 4,
                        .converterFunction = &convertHCHOV1}}}}},
    {T_RH_CO2_VOC_PM25_HCHO,
     {.dataType = DataType::T_RH_CO2_VOC_PM25_HCHO,
      .downloadType = 19,
      .sampleType = 20,
      .sampleSizeBytes = 12,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::VOC,
                       {.unit = Unit::VOC,
                        .offset = 6,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 8,
                        .converterFunction = &convertPM2p5V1}},
                      {Unit::HCHO,
                       {.unit = Unit::HCHO,
                        .offset = 10,
                        .converterFunction = &convertHCHOV1}}}}},
    {T_RH_CO2_VOC_NOX_PM25,
     {.dataType = DataType::T_RH_CO2_VOC_NOX_PM25,
      .downloadType = 25,
      .sampleType = 26,
      .sampleSizeBytes = 12,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::VOC,
                       {.unit = Unit::VOC,
                        .offset = 6,
                        .converterFunction = &convertSimple}},
                      {Unit::NOX,
                       {.unit = Unit::NOX,
                        .offset = 8,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 10,
                        .converterFunction = &convertPMV2}}}}},
    {T_RH_CO2_PM25_V2,
     {.dataType = DataType::T_RH_CO2_PM25_V2,
      .downloadType = 27,
      .sampleType = 28,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 6,
                        .converterFunction = &convertPMV2}}}}},
    {T_RH_VOC_PM25_V2,
     {.dataType = DataType::T_RH_VOC_PM25_V2,
      .downloadType = 29,
      .sampleType = 30,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 2,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 6,
                        .converterFunction = &convertPMV2}}}}},
    {T_RH_CO2_VOC_PM25_HCHO_V2,
     {.dataType = DataType::T_RH_CO2_VOC_PM25_HCHO_V2,
      .downloadType = 30,
      .sampleType = 31,
      .sampleSizeBytes = 12,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::T,
                       {.unit = Unit::T,
                        .offset = 0,
                        .converterFunction = &convertTemperatureV1}},
                      {Unit::RH,
                       {.unit = Unit::RH,
                        .offset = 2,
                        .converterFunction = &convertHumidityV1}},
                      {Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 4,
                        .converterFunction = &convertSimple}},
                      {Unit::VOC,
                       {.unit = Unit::VOC,
                        .offset = 6,
                        .converterFunction = &convertSimple}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 8,
                        .converterFunction = &convertPMV2}},
                      {Unit::HCHO,
                       {.unit = Unit::HCHO,
                        .offset = 10,
                        .converterFunction = &convertHCHOV1}}}}},
    {PM10_PM25_PM40_PM100,
     {.dataType = DataType::PM10_PM25_PM40_PM100,
      .downloadType = 33,
      .sampleType = 34,
      .sampleSizeBytes = 8,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::PM1P0,
                       {.unit = Unit::PM1P0,
                        .offset = 0,
                        .converterFunction = &convertPMV2}},
                      {Unit::PM2P5,
                       {.unit = Unit::PM2P5,
                        .offset = 2,
                        .converterFunction = &convertPMV2}},
                      {Unit::PM4P0,
                       {.unit = Unit::PM4P0,
                        .offset = 4,
                        .converterFunction = &convertPMV2}},
                      {Unit::PM10,
                       {.unit = Unit::PM10,
                        .offset = 6,
                        .converterFunction = &convertPMV2}}}}},
    {CO2_DataType,
     {.dataType = DataType::CO2_DataType,
      .downloadType = 35,
      .sampleType = 36,
      .sampleSizeBytes = 2,
      .sampleCountPerPacket = 1,
      .sensirionAdvertisementSampleType = 0,
      .sampleSlots = {{Unit::CO2,
                       {.unit = Unit::CO2,
                        .offset = 0,
                        .converterFunction = &convertSimple}}}}}
    /* Add new SampleConfigs here */
};

// Converter functions
uint16_t convertSimple(float value) {
    return static_cast<uint16_t>(value + 0.5f);
}

uint16_t convertTemperatureV1(float value) {
    return static_cast<uint16_t>((((value + 45) / 175) * 65535) + 0.5f);
}

uint16_t convertHumidityV1(float value) {
    return static_cast<uint16_t>(((value / 100) * 65535) + 0.5f);
}

uint16_t convertHumidityV2(float value) {
    return static_cast<uint16_t>((((value + 6.0) * 65535) / 125.0) + 0.5f);
}

uint16_t convertPM2p5V1(float value) {
    return static_cast<uint16_t>(((value / 1000) * 65535) + 0.5f);
}

uint16_t convertPMV2(float value) {
    return static_cast<uint16_t>((value * 10) + 0.5f);
}

uint16_t convertHCHOV1(float value) {
    return static_cast<uint16_t>((value * 5) + 0.5f);
}
/* Define new converter function here */