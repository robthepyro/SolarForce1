//Autogenerated by MAVGenerate.py Python script. No need to edit.
// MESSAGE BMS_DATA PACKING

#define MAVLINK_MSG_ID_BMS_DATA 150

typedef struct __mavlink_bms_data_t
{
 uint32_t batteryEnergyIn; ///< battery energy in
 uint32_t batteryEnergyOut; ///< battery energy out
 uint16_t packVoltage; ///< pack voltage of battery
 uint16_t current; ///< current of battery
 uint16_t currentLimit; ///< current of battery
 uint16_t dischargeLimit; ///< dischargeLimit of battery
 uint16_t DOD; ///< discharge depth
 uint16_t capacity; ///< battery capacity
 uint16_t packResistance; ///< packResistance
 uint8_t fault_flags; ///< bits of the faults from the BMS
 uint8_t maxVoltage; ///< max voltage of a cell
 uint8_t maxVoltageID; ///< ID of the cell with maxVoltage
 uint8_t minVoltage; ///< min voltage of a cell
 uint8_t minVoltageID; ///< ID of the cell with minVoltage
 uint8_t SOC; ///< state of charge
 uint8_t SOH; ///< state of charge
 uint8_t minTempID; ///< minimum temp ID
 uint8_t minTemp; ///< minimum temperature
 uint8_t temperature; ///< temperature
 uint8_t maxTemp; ///< max temperature
 uint8_t maxTempID; ///< maximum temperature ID
 uint8_t minRes; ///< minimum resistance
 uint8_t minResID; ///< minimum resistance ID
 uint8_t maxRes; ///< max resistance
 uint8_t maxResID; ///< maximum resistance ID
 uint8_t system_status; ///< System status flag, see MAV_STATE ENUM
 uint8_t mavlink_version; ///< MAVLink version
} mavlink_bms_data_t;

#define MAVLINK_MSG_ID_BMS_DATA_LEN 40
#define MAVLINK_MSG_ID_150_LEN 40

#define MAVLINK_MSG_ID_BMS_DATA_CRC 160
#define MAVLINK_MSG_ID_150_CRC 160



#define MAVLINK_MESSAGE_INFO_BMS_DATA { \
	"BMS_DATA", \
	27, \
	{  { "batteryEnergyIn", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_bms_data_t, batteryEnergyIn) }, \
         { "batteryEnergyOut", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_bms_data_t, batteryEnergyOut) }, \
         { "packVoltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_bms_data_t, packVoltage) }, \
         { "current", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_bms_data_t, current) }, \
         { "currentLimit", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_bms_data_t, currentLimit) }, \
         { "dischargeLimit", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_bms_data_t, dischargeLimit) }, \
         { "DOD", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_bms_data_t, DOD) }, \
         { "capacity", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_bms_data_t, capacity) }, \
         { "packResistance", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_bms_data_t, packResistance) }, \
         { "fault_flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_bms_data_t, fault_flags) }, \
         { "maxVoltage", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_bms_data_t, maxVoltage) }, \
         { "maxVoltageID", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_bms_data_t, maxVoltageID) }, \
         { "minVoltage", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_bms_data_t, minVoltage) }, \
         { "minVoltageID", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_bms_data_t, minVoltageID) }, \
         { "SOC", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_bms_data_t, SOC) }, \
         { "SOH", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_bms_data_t, SOH) }, \
         { "minTempID", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_bms_data_t, minTempID) }, \
         { "minTemp", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_bms_data_t, minTemp) }, \
         { "temperature", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_bms_data_t, temperature) }, \
         { "maxTemp", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_bms_data_t, maxTemp) }, \
         { "maxTempID", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_bms_data_t, maxTempID) }, \
         { "minRes", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_bms_data_t, minRes) }, \
         { "minResID", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_bms_data_t, minResID) }, \
         { "maxRes", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_bms_data_t, maxRes) }, \
         { "maxResID", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_bms_data_t, maxResID) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_bms_data_t, system_status) }, \
         { "mavlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_bms_data_t, mavlink_version) }, \
         } \
}


/**
 * @brief Pack a bms_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param fault_flags bits of the faults from the BMS
 * @param maxVoltage max voltage of a cell
 * @param maxVoltageID ID of the cell with maxVoltage
 * @param minVoltage min voltage of a cell
 * @param minVoltageID ID of the cell with minVoltage
 * @param packVoltage pack voltage of battery
 * @param current current of battery
 * @param currentLimit current of battery
 * @param dischargeLimit dischargeLimit of battery
 * @param batteryEnergyIn battery energy in
 * @param batteryEnergyOut battery energy out
 * @param SOC state of charge
 * @param DOD discharge depth
 * @param capacity battery capacity
 * @param SOH state of charge
 * @param minTempID minimum temp ID
 * @param minTemp minimum temperature
 * @param temperature temperature
 * @param maxTemp max temperature
 * @param maxTempID maximum temperature ID
 * @param packResistance packResistance
 * @param minRes minimum resistance
 * @param minResID minimum resistance ID
 * @param maxRes max resistance
 * @param maxResID maximum resistance ID
 * @param system_status System status flag, see MAV_STATE ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t fault_flags, uint8_t maxVoltage, uint8_t maxVoltageID, uint8_t minVoltage, uint8_t minVoltageID, uint16_t packVoltage, uint16_t current, uint16_t currentLimit, uint16_t dischargeLimit, uint32_t batteryEnergyIn, uint32_t batteryEnergyOut, uint8_t SOC, uint16_t DOD, uint16_t capacity, uint8_t SOH, uint8_t minTempID, uint8_t minTemp, uint8_t temperature, uint8_t maxTemp, uint8_t maxTempID, uint16_t packResistance, uint8_t minRes, uint8_t minResID, uint8_t maxRes, uint8_t maxResID, uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BMS_DATA_LEN];
	_mav_put_uint32_t(buf, 0, batteryEnergyIn);
	_mav_put_uint32_t(buf, 4, batteryEnergyOut);
	_mav_put_uint16_t(buf, 8, packVoltage);
	_mav_put_uint16_t(buf, 10, current);
	_mav_put_uint16_t(buf, 12, currentLimit);
	_mav_put_uint16_t(buf, 14, dischargeLimit);
	_mav_put_uint16_t(buf, 16, DOD);
	_mav_put_uint16_t(buf, 18, capacity);
	_mav_put_uint16_t(buf, 20, packResistance);
	_mav_put_uint8_t(buf, 22, fault_flags);
	_mav_put_uint8_t(buf, 23, maxVoltage);
	_mav_put_uint8_t(buf, 24, maxVoltageID);
	_mav_put_uint8_t(buf, 25, minVoltage);
	_mav_put_uint8_t(buf, 26, minVoltageID);
	_mav_put_uint8_t(buf, 27, SOC);
	_mav_put_uint8_t(buf, 28, SOH);
	_mav_put_uint8_t(buf, 29, minTempID);
	_mav_put_uint8_t(buf, 30, minTemp);
	_mav_put_uint8_t(buf, 31, temperature);
	_mav_put_uint8_t(buf, 32, maxTemp);
	_mav_put_uint8_t(buf, 33, maxTempID);
	_mav_put_uint8_t(buf, 34, minRes);
	_mav_put_uint8_t(buf, 35, minResID);
	_mav_put_uint8_t(buf, 36, maxRes);
	_mav_put_uint8_t(buf, 37, maxResID);
	_mav_put_uint8_t(buf, 38, system_status);
	_mav_put_uint8_t(buf, 39, 2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_DATA_LEN);
#else
	mavlink_bms_data_t packet;
	packet.batteryEnergyIn = batteryEnergyIn;
	packet.batteryEnergyOut = batteryEnergyOut;
	packet.packVoltage = packVoltage;
	packet.current = current;
	packet.currentLimit = currentLimit;
	packet.dischargeLimit = dischargeLimit;
	packet.DOD = DOD;
	packet.capacity = capacity;
	packet.packResistance = packResistance;
	packet.fault_flags = fault_flags;
	packet.maxVoltage = maxVoltage;
	packet.maxVoltageID = maxVoltageID;
	packet.minVoltage = minVoltage;
	packet.minVoltageID = minVoltageID;
	packet.SOC = SOC;
	packet.SOH = SOH;
	packet.minTempID = minTempID;
	packet.minTemp = minTemp;
	packet.temperature = temperature;
	packet.maxTemp = maxTemp;
	packet.maxTempID = maxTempID;
	packet.minRes = minRes;
	packet.minResID = minResID;
	packet.maxRes = maxRes;
	packet.maxResID = maxResID;
	packet.system_status = system_status;
	packet.mavlink_version = 2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BMS_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BMS_DATA_LEN, MAVLINK_MSG_ID_BMS_DATA_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif
}

/**
 * @brief Pack a bms_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fault_flags bits of the faults from the BMS
 * @param maxVoltage max voltage of a cell
 * @param maxVoltageID ID of the cell with maxVoltage
 * @param minVoltage min voltage of a cell
 * @param minVoltageID ID of the cell with minVoltage
 * @param packVoltage pack voltage of battery
 * @param current current of battery
 * @param currentLimit current of battery
 * @param dischargeLimit dischargeLimit of battery
 * @param batteryEnergyIn battery energy in
 * @param batteryEnergyOut battery energy out
 * @param SOC state of charge
 * @param DOD discharge depth
 * @param capacity battery capacity
 * @param SOH state of charge
 * @param minTempID minimum temp ID
 * @param minTemp minimum temperature
 * @param temperature temperature
 * @param maxTemp max temperature
 * @param maxTempID maximum temperature ID
 * @param packResistance packResistance
 * @param minRes minimum resistance
 * @param minResID minimum resistance ID
 * @param maxRes max resistance
 * @param maxResID maximum resistance ID
 * @param system_status System status flag, see MAV_STATE ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t fault_flags,uint8_t maxVoltage,uint8_t maxVoltageID,uint8_t minVoltage,uint8_t minVoltageID,uint16_t packVoltage,uint16_t current,uint16_t currentLimit,uint16_t dischargeLimit,uint32_t batteryEnergyIn,uint32_t batteryEnergyOut,uint8_t SOC,uint16_t DOD,uint16_t capacity,uint8_t SOH,uint8_t minTempID,uint8_t minTemp,uint8_t temperature,uint8_t maxTemp,uint8_t maxTempID,uint16_t packResistance,uint8_t minRes,uint8_t minResID,uint8_t maxRes,uint8_t maxResID,uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BMS_DATA_LEN];
	_mav_put_uint32_t(buf, 0, batteryEnergyIn);
	_mav_put_uint32_t(buf, 4, batteryEnergyOut);
	_mav_put_uint16_t(buf, 8, packVoltage);
	_mav_put_uint16_t(buf, 10, current);
	_mav_put_uint16_t(buf, 12, currentLimit);
	_mav_put_uint16_t(buf, 14, dischargeLimit);
	_mav_put_uint16_t(buf, 16, DOD);
	_mav_put_uint16_t(buf, 18, capacity);
	_mav_put_uint16_t(buf, 20, packResistance);
	_mav_put_uint8_t(buf, 22, fault_flags);
	_mav_put_uint8_t(buf, 23, maxVoltage);
	_mav_put_uint8_t(buf, 24, maxVoltageID);
	_mav_put_uint8_t(buf, 25, minVoltage);
	_mav_put_uint8_t(buf, 26, minVoltageID);
	_mav_put_uint8_t(buf, 27, SOC);
	_mav_put_uint8_t(buf, 28, SOH);
	_mav_put_uint8_t(buf, 29, minTempID);
	_mav_put_uint8_t(buf, 30, minTemp);
	_mav_put_uint8_t(buf, 31, temperature);
	_mav_put_uint8_t(buf, 32, maxTemp);
	_mav_put_uint8_t(buf, 33, maxTempID);
	_mav_put_uint8_t(buf, 34, minRes);
	_mav_put_uint8_t(buf, 35, minResID);
	_mav_put_uint8_t(buf, 36, maxRes);
	_mav_put_uint8_t(buf, 37, maxResID);
	_mav_put_uint8_t(buf, 38, system_status);
	_mav_put_uint8_t(buf, 39, 2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_DATA_LEN);
#else
	mavlink_bms_data_t packet;
	packet.batteryEnergyIn = batteryEnergyIn;
	packet.batteryEnergyOut = batteryEnergyOut;
	packet.packVoltage = packVoltage;
	packet.current = current;
	packet.currentLimit = currentLimit;
	packet.dischargeLimit = dischargeLimit;
	packet.DOD = DOD;
	packet.capacity = capacity;
	packet.packResistance = packResistance;
	packet.fault_flags = fault_flags;
	packet.maxVoltage = maxVoltage;
	packet.maxVoltageID = maxVoltageID;
	packet.minVoltage = minVoltage;
	packet.minVoltageID = minVoltageID;
	packet.SOC = SOC;
	packet.SOH = SOH;
	packet.minTempID = minTempID;
	packet.minTemp = minTemp;
	packet.temperature = temperature;
	packet.maxTemp = maxTemp;
	packet.maxTempID = maxTempID;
	packet.minRes = minRes;
	packet.minResID = minResID;
	packet.maxRes = maxRes;
	packet.maxResID = maxResID;
	packet.system_status = system_status;
	packet.mavlink_version = 2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BMS_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BMS_DATA_LEN, MAVLINK_MSG_ID_BMS_DATA_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif
}

/**
 * @brief Encode a bms_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bms_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bms_data_t* bms_data)
{
	return mavlink_msg_bms_data_pack(system_id, component_id, msg, bms_data->fault_flags, bms_data->maxVoltage, bms_data->maxVoltageID, bms_data->minVoltage, bms_data->minVoltageID, bms_data->packVoltage, bms_data->current, bms_data->currentLimit, bms_data->dischargeLimit, bms_data->batteryEnergyIn, bms_data->batteryEnergyOut, bms_data->SOC, bms_data->DOD, bms_data->capacity, bms_data->SOH, bms_data->minTempID, bms_data->minTemp, bms_data->temperature, bms_data->maxTemp, bms_data->maxTempID, bms_data->packResistance, bms_data->minRes, bms_data->minResID, bms_data->maxRes, bms_data->maxResID, bms_data->system_status);
}

/**
 * @brief Encode a bms_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bms_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bms_data_t* bms_data)
{
	return mavlink_msg_bms_data_pack_chan(system_id, component_id, chan, msg, bms_data->fault_flags, bms_data->maxVoltage, bms_data->maxVoltageID, bms_data->minVoltage, bms_data->minVoltageID, bms_data->packVoltage, bms_data->current, bms_data->currentLimit, bms_data->dischargeLimit, bms_data->batteryEnergyIn, bms_data->batteryEnergyOut, bms_data->SOC, bms_data->DOD, bms_data->capacity, bms_data->SOH, bms_data->minTempID, bms_data->minTemp, bms_data->temperature, bms_data->maxTemp, bms_data->maxTempID, bms_data->packResistance, bms_data->minRes, bms_data->minResID, bms_data->maxRes, bms_data->maxResID, bms_data->system_status);
}

/**
 * @brief Send a bms_data message
 * @param chan MAVLink channel to send the message
 *
 * @param fault_flags bits of the faults from the BMS
 * @param maxVoltage max voltage of a cell
 * @param maxVoltageID ID of the cell with maxVoltage
 * @param minVoltage min voltage of a cell
 * @param minVoltageID ID of the cell with minVoltage
 * @param packVoltage pack voltage of battery
 * @param current current of battery
 * @param currentLimit current of battery
 * @param dischargeLimit dischargeLimit of battery
 * @param batteryEnergyIn battery energy in
 * @param batteryEnergyOut battery energy out
 * @param SOC state of charge
 * @param DOD discharge depth
 * @param capacity battery capacity
 * @param SOH state of charge
 * @param minTempID minimum temp ID
 * @param minTemp minimum temperature
 * @param temperature temperature
 * @param maxTemp max temperature
 * @param maxTempID maximum temperature ID
 * @param packResistance packResistance
 * @param minRes minimum resistance
 * @param minResID minimum resistance ID
 * @param maxRes max resistance
 * @param maxResID maximum resistance ID
 * @param system_status System status flag, see MAV_STATE ENUM
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bms_data_send(mavlink_channel_t chan, uint8_t fault_flags, uint8_t maxVoltage, uint8_t maxVoltageID, uint8_t minVoltage, uint8_t minVoltageID, uint16_t packVoltage, uint16_t current, uint16_t currentLimit, uint16_t dischargeLimit, uint32_t batteryEnergyIn, uint32_t batteryEnergyOut, uint8_t SOC, uint16_t DOD, uint16_t capacity, uint8_t SOH, uint8_t minTempID, uint8_t minTemp, uint8_t temperature, uint8_t maxTemp, uint8_t maxTempID, uint16_t packResistance, uint8_t minRes, uint8_t minResID, uint8_t maxRes, uint8_t maxResID, uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BMS_DATA_LEN];
	_mav_put_uint32_t(buf, 0, batteryEnergyIn);
	_mav_put_uint32_t(buf, 4, batteryEnergyOut);
	_mav_put_uint16_t(buf, 8, packVoltage);
	_mav_put_uint16_t(buf, 10, current);
	_mav_put_uint16_t(buf, 12, currentLimit);
	_mav_put_uint16_t(buf, 14, dischargeLimit);
	_mav_put_uint16_t(buf, 16, DOD);
	_mav_put_uint16_t(buf, 18, capacity);
	_mav_put_uint16_t(buf, 20, packResistance);
	_mav_put_uint8_t(buf, 22, fault_flags);
	_mav_put_uint8_t(buf, 23, maxVoltage);
	_mav_put_uint8_t(buf, 24, maxVoltageID);
	_mav_put_uint8_t(buf, 25, minVoltage);
	_mav_put_uint8_t(buf, 26, minVoltageID);
	_mav_put_uint8_t(buf, 27, SOC);
	_mav_put_uint8_t(buf, 28, SOH);
	_mav_put_uint8_t(buf, 29, minTempID);
	_mav_put_uint8_t(buf, 30, minTemp);
	_mav_put_uint8_t(buf, 31, temperature);
	_mav_put_uint8_t(buf, 32, maxTemp);
	_mav_put_uint8_t(buf, 33, maxTempID);
	_mav_put_uint8_t(buf, 34, minRes);
	_mav_put_uint8_t(buf, 35, minResID);
	_mav_put_uint8_t(buf, 36, maxRes);
	_mav_put_uint8_t(buf, 37, maxResID);
	_mav_put_uint8_t(buf, 38, system_status);
	_mav_put_uint8_t(buf, 39, 2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, buf, MAVLINK_MSG_ID_BMS_DATA_LEN, MAVLINK_MSG_ID_BMS_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, buf, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif
#else
	mavlink_bms_data_t packet;
	packet.batteryEnergyIn = batteryEnergyIn;
	packet.batteryEnergyOut = batteryEnergyOut;
	packet.packVoltage = packVoltage;
	packet.current = current;
	packet.currentLimit = currentLimit;
	packet.dischargeLimit = dischargeLimit;
	packet.DOD = DOD;
	packet.capacity = capacity;
	packet.packResistance = packResistance;
	packet.fault_flags = fault_flags;
	packet.maxVoltage = maxVoltage;
	packet.maxVoltageID = maxVoltageID;
	packet.minVoltage = minVoltage;
	packet.minVoltageID = minVoltageID;
	packet.SOC = SOC;
	packet.SOH = SOH;
	packet.minTempID = minTempID;
	packet.minTemp = minTemp;
	packet.temperature = temperature;
	packet.maxTemp = maxTemp;
	packet.maxTempID = maxTempID;
	packet.minRes = minRes;
	packet.minResID = minResID;
	packet.maxRes = maxRes;
	packet.maxResID = maxResID;
	packet.system_status = system_status;
	packet.mavlink_version = 2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, (const char *)&packet, MAVLINK_MSG_ID_BMS_DATA_LEN, MAVLINK_MSG_ID_BMS_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, (const char *)&packet, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_BMS_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bms_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t fault_flags, uint8_t maxVoltage, uint8_t maxVoltageID, uint8_t minVoltage, uint8_t minVoltageID, uint16_t packVoltage, uint16_t current, uint16_t currentLimit, uint16_t dischargeLimit, uint32_t batteryEnergyIn, uint32_t batteryEnergyOut, uint8_t SOC, uint16_t DOD, uint16_t capacity, uint8_t SOH, uint8_t minTempID, uint8_t minTemp, uint8_t temperature, uint8_t maxTemp, uint8_t maxTempID, uint16_t packResistance, uint8_t minRes, uint8_t minResID, uint8_t maxRes, uint8_t maxResID, uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, batteryEnergyIn);
	_mav_put_uint32_t(buf, 4, batteryEnergyOut);
	_mav_put_uint16_t(buf, 8, packVoltage);
	_mav_put_uint16_t(buf, 10, current);
	_mav_put_uint16_t(buf, 12, currentLimit);
	_mav_put_uint16_t(buf, 14, dischargeLimit);
	_mav_put_uint16_t(buf, 16, DOD);
	_mav_put_uint16_t(buf, 18, capacity);
	_mav_put_uint16_t(buf, 20, packResistance);
	_mav_put_uint8_t(buf, 22, fault_flags);
	_mav_put_uint8_t(buf, 23, maxVoltage);
	_mav_put_uint8_t(buf, 24, maxVoltageID);
	_mav_put_uint8_t(buf, 25, minVoltage);
	_mav_put_uint8_t(buf, 26, minVoltageID);
	_mav_put_uint8_t(buf, 27, SOC);
	_mav_put_uint8_t(buf, 28, SOH);
	_mav_put_uint8_t(buf, 29, minTempID);
	_mav_put_uint8_t(buf, 30, minTemp);
	_mav_put_uint8_t(buf, 31, temperature);
	_mav_put_uint8_t(buf, 32, maxTemp);
	_mav_put_uint8_t(buf, 33, maxTempID);
	_mav_put_uint8_t(buf, 34, minRes);
	_mav_put_uint8_t(buf, 35, minResID);
	_mav_put_uint8_t(buf, 36, maxRes);
	_mav_put_uint8_t(buf, 37, maxResID);
	_mav_put_uint8_t(buf, 38, system_status);
	_mav_put_uint8_t(buf, 39, 2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, buf, MAVLINK_MSG_ID_BMS_DATA_LEN, MAVLINK_MSG_ID_BMS_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, buf, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif
#else
	mavlink_bms_data_t *packet = (mavlink_bms_data_t *)msgbuf;
	packet->batteryEnergyIn = batteryEnergyIn;
	packet->batteryEnergyOut = batteryEnergyOut;
	packet->packVoltage = packVoltage;
	packet->current = current;
	packet->currentLimit = currentLimit;
	packet->dischargeLimit = dischargeLimit;
	packet->DOD = DOD;
	packet->capacity = capacity;
	packet->packResistance = packResistance;
	packet->fault_flags = fault_flags;
	packet->maxVoltage = maxVoltage;
	packet->maxVoltageID = maxVoltageID;
	packet->minVoltage = minVoltage;
	packet->minVoltageID = minVoltageID;
	packet->SOC = SOC;
	packet->SOH = SOH;
	packet->minTempID = minTempID;
	packet->minTemp = minTemp;
	packet->temperature = temperature;
	packet->maxTemp = maxTemp;
	packet->maxTempID = maxTempID;
	packet->minRes = minRes;
	packet->minResID = minResID;
	packet->maxRes = maxRes;
	packet->maxResID = maxResID;
	packet->system_status = system_status;
	packet->mavlink_version = 2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, (const char *)packet, MAVLINK_MSG_ID_BMS_DATA_LEN, MAVLINK_MSG_ID_BMS_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_DATA, (const char *)packet, MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE BMS_DATA UNPACKING


/**
 * @brief Get field fault_flags from bms_data message
 *
 * @return bits of the faults from the BMS
 */
static inline uint8_t mavlink_msg_bms_data_get_fault_flags(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field maxVoltage from bms_data message
 *
 * @return max voltage of a cell
 */
static inline uint8_t mavlink_msg_bms_data_get_maxVoltage(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field maxVoltageID from bms_data message
 *
 * @return ID of the cell with maxVoltage
 */
static inline uint8_t mavlink_msg_bms_data_get_maxVoltageID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field minVoltage from bms_data message
 *
 * @return min voltage of a cell
 */
static inline uint8_t mavlink_msg_bms_data_get_minVoltage(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field minVoltageID from bms_data message
 *
 * @return ID of the cell with minVoltage
 */
static inline uint8_t mavlink_msg_bms_data_get_minVoltageID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field packVoltage from bms_data message
 *
 * @return pack voltage of battery
 */
static inline uint16_t mavlink_msg_bms_data_get_packVoltage(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field current from bms_data message
 *
 * @return current of battery
 */
static inline uint16_t mavlink_msg_bms_data_get_current(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field currentLimit from bms_data message
 *
 * @return current of battery
 */
static inline uint16_t mavlink_msg_bms_data_get_currentLimit(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field dischargeLimit from bms_data message
 *
 * @return dischargeLimit of battery
 */
static inline uint16_t mavlink_msg_bms_data_get_dischargeLimit(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field batteryEnergyIn from bms_data message
 *
 * @return battery energy in
 */
static inline uint32_t mavlink_msg_bms_data_get_batteryEnergyIn(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field batteryEnergyOut from bms_data message
 *
 * @return battery energy out
 */
static inline uint32_t mavlink_msg_bms_data_get_batteryEnergyOut(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field SOC from bms_data message
 *
 * @return state of charge
 */
static inline uint8_t mavlink_msg_bms_data_get_SOC(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field DOD from bms_data message
 *
 * @return discharge depth
 */
static inline uint16_t mavlink_msg_bms_data_get_DOD(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field capacity from bms_data message
 *
 * @return battery capacity
 */
static inline uint16_t mavlink_msg_bms_data_get_capacity(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field SOH from bms_data message
 *
 * @return state of charge
 */
static inline uint8_t mavlink_msg_bms_data_get_SOH(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field minTempID from bms_data message
 *
 * @return minimum temp ID
 */
static inline uint8_t mavlink_msg_bms_data_get_minTempID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Get field minTemp from bms_data message
 *
 * @return minimum temperature
 */
static inline uint8_t mavlink_msg_bms_data_get_minTemp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field temperature from bms_data message
 *
 * @return temperature
 */
static inline uint8_t mavlink_msg_bms_data_get_temperature(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field maxTemp from bms_data message
 *
 * @return max temperature
 */
static inline uint8_t mavlink_msg_bms_data_get_maxTemp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field maxTempID from bms_data message
 *
 * @return maximum temperature ID
 */
static inline uint8_t mavlink_msg_bms_data_get_maxTempID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field packResistance from bms_data message
 *
 * @return packResistance
 */
static inline uint16_t mavlink_msg_bms_data_get_packResistance(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field minRes from bms_data message
 *
 * @return minimum resistance
 */
static inline uint8_t mavlink_msg_bms_data_get_minRes(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field minResID from bms_data message
 *
 * @return minimum resistance ID
 */
static inline uint8_t mavlink_msg_bms_data_get_minResID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field maxRes from bms_data message
 *
 * @return max resistance
 */
static inline uint8_t mavlink_msg_bms_data_get_maxRes(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field maxResID from bms_data message
 *
 * @return maximum resistance ID
 */
static inline uint8_t mavlink_msg_bms_data_get_maxResID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field system_status from bms_data message
 *
 * @return System status flag, see MAV_STATE ENUM
 */
static inline uint8_t mavlink_msg_bms_data_get_system_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  38);
}

/**
 * @brief Get field mavlink_version from bms_data message
 *
 * @return MAVLink version
 */
static inline uint8_t mavlink_msg_bms_data_get_mavlink_version(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  39);
}

/**
 * @brief Decode a bms_data message into a struct
 *
 * @param msg The message to decode
 * @param bms_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_bms_data_decode(const mavlink_message_t* msg, mavlink_bms_data_t* bms_data)
{
#if MAVLINK_NEED_BYTE_SWAP
	bms_data->batteryEnergyIn = mavlink_msg_bms_data_get_batteryEnergyIn(msg);
	bms_data->batteryEnergyOut = mavlink_msg_bms_data_get_batteryEnergyOut(msg);
	bms_data->packVoltage = mavlink_msg_bms_data_get_packVoltage(msg);
	bms_data->current = mavlink_msg_bms_data_get_current(msg);
	bms_data->currentLimit = mavlink_msg_bms_data_get_currentLimit(msg);
	bms_data->dischargeLimit = mavlink_msg_bms_data_get_dischargeLimit(msg);
	bms_data->DOD = mavlink_msg_bms_data_get_DOD(msg);
	bms_data->capacity = mavlink_msg_bms_data_get_capacity(msg);
	bms_data->packResistance = mavlink_msg_bms_data_get_packResistance(msg);
	bms_data->fault_flags = mavlink_msg_bms_data_get_fault_flags(msg);
	bms_data->maxVoltage = mavlink_msg_bms_data_get_maxVoltage(msg);
	bms_data->maxVoltageID = mavlink_msg_bms_data_get_maxVoltageID(msg);
	bms_data->minVoltage = mavlink_msg_bms_data_get_minVoltage(msg);
	bms_data->minVoltageID = mavlink_msg_bms_data_get_minVoltageID(msg);
	bms_data->SOC = mavlink_msg_bms_data_get_SOC(msg);
	bms_data->SOH = mavlink_msg_bms_data_get_SOH(msg);
	bms_data->minTempID = mavlink_msg_bms_data_get_minTempID(msg);
	bms_data->minTemp = mavlink_msg_bms_data_get_minTemp(msg);
	bms_data->temperature = mavlink_msg_bms_data_get_temperature(msg);
	bms_data->maxTemp = mavlink_msg_bms_data_get_maxTemp(msg);
	bms_data->maxTempID = mavlink_msg_bms_data_get_maxTempID(msg);
	bms_data->minRes = mavlink_msg_bms_data_get_minRes(msg);
	bms_data->minResID = mavlink_msg_bms_data_get_minResID(msg);
	bms_data->maxRes = mavlink_msg_bms_data_get_maxRes(msg);
	bms_data->maxResID = mavlink_msg_bms_data_get_maxResID(msg);
	bms_data->system_status = mavlink_msg_bms_data_get_system_status(msg);
	bms_data->mavlink_version = mavlink_msg_bms_data_get_mavlink_version(msg);
#else
	memcpy(bms_data, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_BMS_DATA_LEN);
#endif
}
