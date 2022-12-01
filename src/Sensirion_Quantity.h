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

#ifndef SENSIRION_QUANTITY_H
#define SENSIRION_QUANTITY_H

#include <string>

enum class Quantity {
    UNDEFINED,
    TEMPERATURE, // typical Unit: degrees C
    HUMIDITY, // typical Unit: percent relative humidity
    CO2, // parts per million
    HCHO, // parts per billion
    PM1P0, // micro_gramm_per_cubic_meter
    PM2P5, // micro_gramm_per_cubic_meter
    PM4P0, // micro_gramm_per_cubic_meter
    PM10P0, // micro_gramm_per_cubic_meter
    VOC_INDEX, // None
    NOX // None?
};

const std::string quantityString[] = {
    "UNDEFINED", "T",   "RH", "CO2", "HCHO",
    "PM1P0", "PM2P5", "PM10P0", "PM4P0", "VOC", "NOx"
};

std::string getQuantityString(Quantity quantity) {
    return quantityString[static_cast<int>(quantity)];
}

#endif /* SENSIRION_QUANTITY_H */