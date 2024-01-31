/*
 * Copyright (c) 2022, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef BLE_PROTOCOL_H
#define BLE_PROTOCOL_H

#include "Arduino.h"
#include "SignalType.h"
#include <map>

/**
 * Refer to
 * https://github.com/Sensirion/arduino-ble-gadget/blob/master/documents/00-Sensirion_BLE_communication_protocol.pdf
 * for the general BLE sample transmission strategy.
 *
 * Common definitions:
 *  --  DataType: identifies the structure & contents of ManufacturerData field
 *      in BLE Advertisement
 *  --  Sample: set of measurements, typically retrived simultaneously from a
 *      sensor. Made up of several SampleSlots.
 *  --  Data: array of bytes containing the Company ID, Sample Adv. Type, Sample
 *      Type, and Sample. See diagram in Sect 2 "BLE Advertisement" in document
 *      linked above
 */

enum DataType {
    UNDEFINED,
    T_RH_V3,
    T_RH_V4,
    T_RH_VOC,
    T_RH_CO2,
    T_RH_CO2_ALT,
    T_RH_CO2_PM25,
    T_RH_VOC_PM25,
    T_RH_VOC_NOX,
    T_RH_VOC_NOX_PM25,
    T_RH_HCHO,
    T_RH_CO2_VOC_PM25_HCHO,
    T_RH_CO2_VOC_NOX_PM25,
    T_RH_CO2_PM25_V2,
    T_RH_VOC_PM25_V2,
    T_RH_CO2_VOC_PM25_HCHO_V2,
    PM10_PM25_PM40_PM100,
    CO2_DataType,
    AV_T,
    /* Add new DataType here. Don't forget to add corresponding
    SampleConfig in BLEProtocol.cpp */
};

// Encoding functions
uint16_t encodeSimple(float value);
uint16_t encodeTemperatureV1(float value);
uint16_t encodeHumidityV1(float value);
uint16_t encodeHumidityV2(float value);
uint16_t encodePM2p5V1(float value);
uint16_t encodePMV2(float value);
uint16_t encodeHCHOV1(float value);
uint16_t encodeVelocityV1(float value);
/* Declare new encoding function here, define in
 * BLEProtocol.cpp */

void emplaceRawValue(std::string &manufacturerData, uint8_t offset,
                     uint16_t rawValue);

struct SampleSlot {
    SignalType signalType;
    size_t offset;
    uint16_t (*encodingFunction)(float value);
};

// Sample configuration data
struct SampleConfig {
    DataType dataType;
    uint16_t downloadType;
    uint8_t sampleType; // Maps 1-to-1 to DataType
    size_t sampleSizeBytes;
    size_t sampleCountPerPacket;
    uint8_t sensirionAdvertisementSampleType;
    std::map<SignalType, SampleSlot> sampleSlots;
};

extern std::map<DataType, SampleConfig> sampleConfigSelector;

#endif /* BLE_PROTOCOL_H */
