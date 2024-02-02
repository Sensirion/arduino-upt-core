#include "BLEGadgetType.h"
#include <Arduino.h>

const char *bleGadgetLabel(BLEGadgetType bleGadgetType) {
    switch (bleGadgetType) {
    case BLEGadgetType::AQ_MINION:
        return "AQ-Minion";
    case BLEGadgetType::MYCO2:
        return "MyCO2";
    case BLEGadgetType::SHT40_GADGET:
        return "SHT40-Gadget";
    case BLEGadgetType::SHT43_GADGET:
        return "SHT43-DB";
    case BLEGadgetType::BLE_DIY_GADGET:
    case BLEGadgetType::HUMI_GADGET:
        return "n/a";
    default:
        return "n/a";
    }
}

BLEGadgetType
bleGadgetTypeFromCompleteLocalName(const char *completeLocalName) {
    size_t inBufSize = strlen(completeLocalName);
    if (strncmp(completeLocalName, "AQ Minion", inBufSize) == 0) {
        return BLEGadgetType::AQ_MINION;
    } else if (strncmp(completeLocalName, "MyCO2", inBufSize) == 0) {
        return BLEGadgetType::MYCO2;
    } else if (strncmp(completeLocalName, "SHT40 Gadget", inBufSize) == 0) {
        return BLEGadgetType::SHT40_GADGET;
    } else if (strncmp(completeLocalName, "SHT43 DB", inBufSize) == 0) {
        return BLEGadgetType::SHT43_GADGET;
    } else if (strncmp(completeLocalName, "sensi", inBufSize) == 0 ||
               strncmp(completeLocalName, "S", inBufSize) == 0) {
        return BLEGadgetType::BLE_DIY_GADGET;
    } else if (strncmp(completeLocalName, "Smart Humigadget", inBufSize) == 0) {
        return BLEGadgetType::HUMI_GADGET;
    } else {
        return BLEGadgetType::UNDEFINED;
    }
}
