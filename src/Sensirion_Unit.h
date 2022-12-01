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

#ifndef SENSIRION_UNIT_H
#define SENSIRION_UNIT_H

#include "Sensirion_Quantity.h"

enum class Unit {
    UNDEFINED,
    DEGREES_CELSIUS,
    RELATIVE_HUMIDITY_PERCENTAGE,
    PARTS_PER_MILLION,
    PARTS_PER_BILLION,
    MICRO_GRAMM_PER_CUBIC_METER,
    NONE
};

const std::string unitString[] = {
    "UNDEFINED",   "degC",           "%RH",         "ppm",      "ppb",
    "μg/m3", ""};

std::string getUnitString(Unit unit) {
    return unitString[static_cast<int>(unit)];
}

Unit getDefaultUnit(Quantity quantity) {
    switch(quantity) {
        case Quantity::TEMPERATURE:
            return Unit::DEGREES_CELSIUS;
        case Quantity::HUMIDITY:
            return Unit::RELATIVE_HUMIDITY_PERCENTAGE;
        case Quantity::CO2:
            return Unit::PARTS_PER_MILLION;
        case Quantity::HCHO:
            return Unit::PARTS_PER_BILLION;
        case Quantity::PM1P0:
            return Unit::MICRO_GRAMM_PER_CUBIC_METER;
        case Quantity::PM2P5:
            return Unit::MICRO_GRAMM_PER_CUBIC_METER;
        case Quantity::PM4P0:
            return Unit::MICRO_GRAMM_PER_CUBIC_METER;
        case Quantity::PM10P0:
            return Unit::MICRO_GRAMM_PER_CUBIC_METER;
        case Quantity::VOC_INDEX:
            return Unit::NONE;
        default:
            return Unit::UNDEFINED;
    }
}

#endif /* SENSIRION_UNIT_H */

