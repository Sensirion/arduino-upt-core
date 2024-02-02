#ifndef _BLE_GADGET_TYPE_H_
#define _BLE_GADGET_TYPE_H_

/* List of supported Sensirion BLE Gadgets */
enum class BLEGadgetType {
    UNDEFINED,
    AQ_MINION,
    MYCO2,
    SHT40_GADGET,
    SHT43_GADGET, // SHT43 DB
    BLE_DIY_GADGET,
    HUMI_GADGET // SHT3X Gadget
};

/**
 * @brief get a short label corresponding to a BLEGadgetType
 */
const char *bleGadgetLabel(BLEGadgetType bleGadgetType);

/**
 * @brief map a Complete Local Name string (as received via BLE Adv.) to a
 * BLEGadgetType
 */
BLEGadgetType bleGadgetTypeFromCompleteLocalName(const char *completeLocalName);

#endif /* _BLE_GADGET_TYPE_H_ */
