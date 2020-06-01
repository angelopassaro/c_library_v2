#pragma once
// MESSAGE CERTIFICATE PACKING

#define MAVLINK_MSG_ID_CERTIFICATE 10000


typedef struct __mavlink_certificate_t {
 uint8_t device_id; /*<  Device id*/
 uint8_t public_key[32]; /*< [rad] Public key of device*/
 uint8_t public_key_cert[32]; /*< [rad] Public key of certificate*/
 uint8_t sign[32]; /*< [rad] Sign of Authority*/
} mavlink_certificate_t;

#define MAVLINK_MSG_ID_CERTIFICATE_LEN 97
#define MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN 97
#define MAVLINK_MSG_ID_10000_LEN 97
#define MAVLINK_MSG_ID_10000_MIN_LEN 97

#define MAVLINK_MSG_ID_CERTIFICATE_CRC 43
#define MAVLINK_MSG_ID_10000_CRC 43

#define MAVLINK_MSG_CERTIFICATE_FIELD_PUBLIC_KEY_LEN 32
#define MAVLINK_MSG_CERTIFICATE_FIELD_PUBLIC_KEY_CERT_LEN 32
#define MAVLINK_MSG_CERTIFICATE_FIELD_SIGN_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CERTIFICATE { \
    10000, \
    "CERTIFICATE", \
    4, \
    {  { "device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_certificate_t, device_id) }, \
         { "public_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 1, offsetof(mavlink_certificate_t, public_key) }, \
         { "public_key_cert", NULL, MAVLINK_TYPE_UINT8_T, 32, 33, offsetof(mavlink_certificate_t, public_key_cert) }, \
         { "sign", NULL, MAVLINK_TYPE_UINT8_T, 32, 65, offsetof(mavlink_certificate_t, sign) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CERTIFICATE { \
    "CERTIFICATE", \
    4, \
    {  { "device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_certificate_t, device_id) }, \
         { "public_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 1, offsetof(mavlink_certificate_t, public_key) }, \
         { "public_key_cert", NULL, MAVLINK_TYPE_UINT8_T, 32, 33, offsetof(mavlink_certificate_t, public_key_cert) }, \
         { "sign", NULL, MAVLINK_TYPE_UINT8_T, 32, 65, offsetof(mavlink_certificate_t, sign) }, \
         } \
}
#endif

/**
 * @brief Pack a certificate message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param device_id  Device id
 * @param public_key [rad] Public key of device
 * @param public_key_cert [rad] Public key of certificate
 * @param sign [rad] Sign of Authority
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_certificate_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t device_id, const uint8_t *public_key, const uint8_t *public_key_cert, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CERTIFICATE_LEN];
    _mav_put_uint8_t(buf, 0, device_id);
    _mav_put_uint8_t_array(buf, 1, public_key, 32);
    _mav_put_uint8_t_array(buf, 33, public_key_cert, 32);
    _mav_put_uint8_t_array(buf, 65, sign, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CERTIFICATE_LEN);
#else
    mavlink_certificate_t packet;
    packet.device_id = device_id;
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.public_key_cert, public_key_cert, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CERTIFICATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CERTIFICATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_LEN, MAVLINK_MSG_ID_CERTIFICATE_CRC);
}

/**
 * @brief Pack a certificate message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param device_id  Device id
 * @param public_key [rad] Public key of device
 * @param public_key_cert [rad] Public key of certificate
 * @param sign [rad] Sign of Authority
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_certificate_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t device_id,const uint8_t *public_key,const uint8_t *public_key_cert,const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CERTIFICATE_LEN];
    _mav_put_uint8_t(buf, 0, device_id);
    _mav_put_uint8_t_array(buf, 1, public_key, 32);
    _mav_put_uint8_t_array(buf, 33, public_key_cert, 32);
    _mav_put_uint8_t_array(buf, 65, sign, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CERTIFICATE_LEN);
#else
    mavlink_certificate_t packet;
    packet.device_id = device_id;
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.public_key_cert, public_key_cert, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CERTIFICATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CERTIFICATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_LEN, MAVLINK_MSG_ID_CERTIFICATE_CRC);
}

/**
 * @brief Encode a certificate struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param certificate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_certificate_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_certificate_t* certificate)
{
    return mavlink_msg_certificate_pack(system_id, component_id, msg, certificate->device_id, certificate->public_key, certificate->public_key_cert, certificate->sign);
}

/**
 * @brief Encode a certificate struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param certificate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_certificate_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_certificate_t* certificate)
{
    return mavlink_msg_certificate_pack_chan(system_id, component_id, chan, msg, certificate->device_id, certificate->public_key, certificate->public_key_cert, certificate->sign);
}

/**
 * @brief Send a certificate message
 * @param chan MAVLink channel to send the message
 *
 * @param device_id  Device id
 * @param public_key [rad] Public key of device
 * @param public_key_cert [rad] Public key of certificate
 * @param sign [rad] Sign of Authority
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_certificate_send(mavlink_channel_t chan, uint8_t device_id, const uint8_t *public_key, const uint8_t *public_key_cert, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CERTIFICATE_LEN];
    _mav_put_uint8_t(buf, 0, device_id);
    _mav_put_uint8_t_array(buf, 1, public_key, 32);
    _mav_put_uint8_t_array(buf, 33, public_key_cert, 32);
    _mav_put_uint8_t_array(buf, 65, sign, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE, buf, MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_LEN, MAVLINK_MSG_ID_CERTIFICATE_CRC);
#else
    mavlink_certificate_t packet;
    packet.device_id = device_id;
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.public_key_cert, public_key_cert, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE, (const char *)&packet, MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_LEN, MAVLINK_MSG_ID_CERTIFICATE_CRC);
#endif
}

/**
 * @brief Send a certificate message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_certificate_send_struct(mavlink_channel_t chan, const mavlink_certificate_t* certificate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_certificate_send(chan, certificate->device_id, certificate->public_key, certificate->public_key_cert, certificate->sign);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE, (const char *)certificate, MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_LEN, MAVLINK_MSG_ID_CERTIFICATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_CERTIFICATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_certificate_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t device_id, const uint8_t *public_key, const uint8_t *public_key_cert, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, device_id);
    _mav_put_uint8_t_array(buf, 1, public_key, 32);
    _mav_put_uint8_t_array(buf, 33, public_key_cert, 32);
    _mav_put_uint8_t_array(buf, 65, sign, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE, buf, MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_LEN, MAVLINK_MSG_ID_CERTIFICATE_CRC);
#else
    mavlink_certificate_t *packet = (mavlink_certificate_t *)msgbuf;
    packet->device_id = device_id;
    mav_array_memcpy(packet->public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->public_key_cert, public_key_cert, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->sign, sign, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE, (const char *)packet, MAVLINK_MSG_ID_CERTIFICATE_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_LEN, MAVLINK_MSG_ID_CERTIFICATE_CRC);
#endif
}
#endif

#endif

// MESSAGE CERTIFICATE UNPACKING


/**
 * @brief Get field device_id from certificate message
 *
 * @return  Device id
 */
static inline uint8_t mavlink_msg_certificate_get_device_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field public_key from certificate message
 *
 * @return [rad] Public key of device
 */
static inline uint16_t mavlink_msg_certificate_get_public_key(const mavlink_message_t* msg, uint8_t *public_key)
{
    return _MAV_RETURN_uint8_t_array(msg, public_key, 32,  1);
}

/**
 * @brief Get field public_key_cert from certificate message
 *
 * @return [rad] Public key of certificate
 */
static inline uint16_t mavlink_msg_certificate_get_public_key_cert(const mavlink_message_t* msg, uint8_t *public_key_cert)
{
    return _MAV_RETURN_uint8_t_array(msg, public_key_cert, 32,  33);
}

/**
 * @brief Get field sign from certificate message
 *
 * @return [rad] Sign of Authority
 */
static inline uint16_t mavlink_msg_certificate_get_sign(const mavlink_message_t* msg, uint8_t *sign)
{
    return _MAV_RETURN_uint8_t_array(msg, sign, 32,  65);
}

/**
 * @brief Decode a certificate message into a struct
 *
 * @param msg The message to decode
 * @param certificate C-struct to decode the message contents into
 */
static inline void mavlink_msg_certificate_decode(const mavlink_message_t* msg, mavlink_certificate_t* certificate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    certificate->device_id = mavlink_msg_certificate_get_device_id(msg);
    mavlink_msg_certificate_get_public_key(msg, certificate->public_key);
    mavlink_msg_certificate_get_public_key_cert(msg, certificate->public_key_cert);
    mavlink_msg_certificate_get_sign(msg, certificate->sign);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CERTIFICATE_LEN? msg->len : MAVLINK_MSG_ID_CERTIFICATE_LEN;
        memset(certificate, 0, MAVLINK_MSG_ID_CERTIFICATE_LEN);
    memcpy(certificate, _MAV_PAYLOAD(msg), len);
#endif
}
