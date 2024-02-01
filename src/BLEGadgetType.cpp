#include "BLEGadgetType.h"

const char *bleGadgetLabel(BLEGadgetType bleGadgetType) {
    switch (bleGadgetType) {
    case BLEGadgetType::SHT43DB:
        return "SHT43 DB";
    case BLEGadgetType::MYCO2:
        return "MyCO2";
    case BLEGadgetType::BLEDIYGADGET:
        return "BLE DIY Gadget";
    default:
        return "UNDEFINED";
    }
}
