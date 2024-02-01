#ifndef _BLE_GADGET_TYPE_H_
#define _BLE_GADGET_TYPE_H_

enum class BLEGadgetType {
    UNDEFINED,
    SHT43DB,
    MYCO2,
    BLEDIYGADGET,
};

/**
 * @brief get a short label corresponding to a BLEGadgetType
 */
const char *bleGadgetLabel(BLEGadgetType bleGadgetType);

#endif /* _BLE_GADGET_TYPE_H_ */
