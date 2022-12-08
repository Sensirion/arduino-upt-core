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

#ifndef QUANTITY_H
#define QUANTITY_H

#include "Signal_Type.h"
#include <string>

std::string getQuantityString(SignalType signalType) {
  switch (signalType) {
  case SignalType::TEMPERATURE_DEGREES_CELSIUS:
    return "T";
  case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
    return "RH";
  case SignalType::CO2_PARTS_PER_MILLION:
    return "CO2";
  case SignalType::HCHO_PARTS_PER_BILLION:
    return "HCHO";
  case SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER:
    return "PM1P0";
  case SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER:
    return "PM2P5";
  case SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER:
    return "PM4P0";
  case SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER:
    return "PM10P0";
  case SignalType::VOC_INDEX:
    return "VOC";
  case SignalType::NOX_INDEX:
    return "NOX";
  default:
    return "UNDEFINED";
  }
}

#endif /* QUANTITY_H */