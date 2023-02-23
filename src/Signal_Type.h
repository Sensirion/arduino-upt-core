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

#ifndef SIGNAL_TYPE_H
#define SIGNAL_TYPE_H

#include <string>

enum class SignalType {
  UNDEFINED,
  TEMPERATURE_DEGREES_CELSIUS,
  RELATIVE_HUMIDITY_PERCENTAGE,
  CO2_PARTS_PER_MILLION,
  HCHO_PARTS_PER_BILLION,
  PM1P0_MICRO_GRAMM_PER_CUBIC_METER,
  PM2P5_MICRO_GRAMM_PER_CUBIC_METER,
  PM4P0_MICRO_GRAMM_PER_CUBIC_METER,
  PM10P0_MICRO_GRAMM_PER_CUBIC_METER,
  VOC_INDEX,
  NOX_INDEX
};

/**
 * @brief Get the unit of a SignalType.
 *  The "unit" refers to the physical unit of a SignalType.
 *  Note that signalsTypes may be unit-free.
 *
 * @return std::string
 *  e.g. "degC" for TEMPERATURE_DEGREES_CELSIUS
 */
std::string unitOf(SignalType signalType);

/**
 * @brief Get the quantity of a SignalType.
 *  The "quantity" refers to the name of a SignalType.
 *
 * @return std::string
 *  e.g. "T" for TEMPERATURE_DEGREES_CELSIUS
 */
std::string quantityOf(SignalType signalType);

#endif /* SIGNAL_TYPE_H */
