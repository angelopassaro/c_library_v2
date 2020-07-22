#pragma once
// MESSAGE CERTIFICATE_GCS PACKING

#define MAVLINK_MSG_ID_CERTIFICATE_GCS 10010

MAVPACKED(
typedef struct __mavlink_certificate_gcs_t {
 float start_time; /*<  Certified start of validity*/
 float end_time; /*<  Certified end of validity*/
 uint8_t seq_number; /*<  Certificate sequent number*/
 uint8_t device_id; /*<  Device id*/
 char device_name[20]; /*<  Name of machine*/
 char subject[20]; /*<  Name of certification authority*/
 char issuer[20]; /*<  Name of issuer*/
 uint8_t public_key[32]; /*< [rad] Public key of device*/
 uint8_t iv[16]; /*< [rad] Initial vector*/
 uint8_t sign[64]; /*< [rad] Sign of Authority*/
}) mavlink_certificate_gcs_t;

#define MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN 182
#define MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN 182
#define MAVLINK_MSG_ID_10010_LEN 182
#define MAVLINK_MSG_ID_10010_MIN_LEN 182

#define MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC 175
#define MAVLINK_MSG_ID_10010_CRC 175

#define MAVLINK_MSG_CERTIFICATE_GCS_FIELD_DEVICE_NAME_LEN 20
#define MAVLINK_MSG_CERTIFICATE_GCS_FIELD_SUBJECT_LEN 20
#define MAVLINK_MSG_CERTIFICATE_GCS_FIELD_ISSUER_LEN 20
#define MAVLINK_MSG_CERTIFICATE_GCS_FIELD_PUBLIC_KEY_LEN 32
#define MAVLINK_MSG_CERTIFICATE_GCS_FIELD_IV_LEN 16
#define MAVLINK_MSG_CERTIFICATE_GCS_FIELD_SIGN_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CERTIFICATE_GCS { \
    10010, \
    "CERTIFICATE_GCS", \
    10, \
    {  { "seq_number", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_certificate_gcs_t, seq_number) }, \
         { "device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_certificate_gcs_t, device_id) }, \
         { "device_name", NULL, MAVLINK_TYPE_CHAR, 20, 10, offsetof(mavlink_certificate_gcs_t, device_name) }, \
         { "subject", NULL, MAVLINK_TYPE_CHAR, 20, 30, offsetof(mavlink_certificate_gcs_t, subject) }, \
         { "issuer", NULL, MAVLINK_TYPE_CHAR, 20, 50, offsetof(mavlink_certificate_gcs_t, issuer) }, \
         { "public_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 70, offsetof(mavlink_certificate_gcs_t, public_key) }, \
         { "iv", NULL, MAVLINK_TYPE_UINT8_T, 16, 102, offsetof(mavlink_certificate_gcs_t, iv) }, \
         { "start_time", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_certificate_gcs_t, start_time) }, \
         { "end_time", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_certificate_gcs_t, end_time) }, \
         { "sign", NULL, MAVLINK_TYPE_UINT8_T, 64, 118, offsetof(mavlink_certificate_gcs_t, sign) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CERTIFICATE_GCS { \
    "CERTIFICATE_GCS", \
    10, \
    {  { "seq_number", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_certificate_gcs_t, seq_number) }, \
         { "device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_certificate_gcs_t, device_id) }, \
         { "device_name", NULL, MAVLINK_TYPE_CHAR, 20, 10, offsetof(mavlink_certificate_gcs_t, device_name) }, \
         { "subject", NULL, MAVLINK_TYPE_CHAR, 20, 30, offsetof(mavlink_certificate_gcs_t, subject) }, \
         { "issuer", NULL, MAVLINK_TYPE_CHAR, 20, 50, offsetof(mavlink_certificate_gcs_t, issuer) }, \
         { "public_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 70, offsetof(mavlink_certificate_gcs_t, public_key) }, \
         { "iv", NULL, MAVLINK_TYPE_UINT8_T, 16, 102, offsetof(mavlink_certificate_gcs_t, iv) }, \
         { "start_time", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_certificate_gcs_t, start_time) }, \
         { "end_time", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_certificate_gcs_t, end_time) }, \
         { "sign", NULL, MAVLINK_TYPE_UINT8_T, 64, 118, offsetof(mavlink_certificate_gcs_t, sign) }, \
         } \
}
#endif

/**
 * @brief Pack a certificate_gcs message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq_number  Certificate sequent number
 * @param device_id  Device id
 * @param device_name  Name of machine
 * @param subject  Name of certification authority
 * @param issuer  Name of issuer
 * @param public_key [rad] Public key of device
 * @param iv [rad] Initial vector
 * @param start_time  Certified start of validity
 * @param end_time  Certified end of validity
 * @param sign [rad] Sign of Authority
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_certificate_gcs_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t seq_number, uint8_t device_id, const char *device_name, const char *subject, const char *issuer, const uint8_t *public_key, const uint8_t *iv, float start_time, float end_time, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN];
    _mav_put_float(buf, 0, start_time);
    _mav_put_float(buf, 4, end_time);
    _mav_put_uint8_t(buf, 8, seq_number);
    _mav_put_uint8_t(buf, 9, device_id);
    _mav_put_char_array(buf, 10, device_name, 20);
    _mav_put_char_array(buf, 30, subject, 20);
    _mav_put_char_array(buf, 50, issuer, 20);
    _mav_put_uint8_t_array(buf, 70, public_key, 32);
    _mav_put_uint8_t_array(buf, 102, iv, 16);
    _mav_put_uint8_t_array(buf, 118, sign, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN);
#else
    mavlink_certificate_gcs_t packet;
    packet.start_time = start_time;
    packet.end_time = end_time;
    packet.seq_number = seq_number;
    packet.device_id = device_id;
    mav_array_memcpy(packet.device_name, device_name, sizeof(char)*20);
    mav_array_memcpy(packet.subject, subject, sizeof(char)*20);
    mav_array_memcpy(packet.issuer, issuer, sizeof(char)*20);
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.iv, iv, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CERTIFICATE_GCS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC);
}

/**
 * @brief Pack a certificate_gcs message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq_number  Certificate sequent number
 * @param device_id  Device id
 * @param device_name  Name of machine
 * @param subject  Name of certification authority
 * @param issuer  Name of issuer
 * @param public_key [rad] Public key of device
 * @param iv [rad] Initial vector
 * @param start_time  Certified start of validity
 * @param end_time  Certified end of validity
 * @param sign [rad] Sign of Authority
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_certificate_gcs_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t seq_number,uint8_t device_id,const char *device_name,const char *subject,const char *issuer,const uint8_t *public_key,const uint8_t *iv,float start_time,float end_time,const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN];
    _mav_put_float(buf, 0, start_time);
    _mav_put_float(buf, 4, end_time);
    _mav_put_uint8_t(buf, 8, seq_number);
    _mav_put_uint8_t(buf, 9, device_id);
    _mav_put_char_array(buf, 10, device_name, 20);
    _mav_put_char_array(buf, 30, subject, 20);
    _mav_put_char_array(buf, 50, issuer, 20);
    _mav_put_uint8_t_array(buf, 70, public_key, 32);
    _mav_put_uint8_t_array(buf, 102, iv, 16);
    _mav_put_uint8_t_array(buf, 118, sign, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN);
#else
    mavlink_certificate_gcs_t packet;
    packet.start_time = start_time;
    packet.end_time = end_time;
    packet.seq_number = seq_number;
    packet.device_id = device_id;
    mav_array_memcpy(packet.device_name, device_name, sizeof(char)*20);
    mav_array_memcpy(packet.subject, subject, sizeof(char)*20);
    mav_array_memcpy(packet.issuer, issuer, sizeof(char)*20);
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.iv, iv, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CERTIFICATE_GCS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC);
}

/**
 * @brief Encode a certificate_gcs struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param certificate_gcs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_certificate_gcs_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_certificate_gcs_t* certificate_gcs)
{
    return mavlink_msg_certificate_gcs_pack(system_id, component_id, msg, certificate_gcs->seq_number, certificate_gcs->device_id, certificate_gcs->device_name, certificate_gcs->subject, certificate_gcs->issuer, certificate_gcs->public_key, certificate_gcs->iv, certificate_gcs->start_time, certificate_gcs->end_time, certificate_gcs->sign);
}

/**
 * @brief Encode a certificate_gcs struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param certificate_gcs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_certificate_gcs_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_certificate_gcs_t* certificate_gcs)
{
    return mavlink_msg_certificate_gcs_pack_chan(system_id, component_id, chan, msg, certificate_gcs->seq_number, certificate_gcs->device_id, certificate_gcs->device_name, certificate_gcs->subject, certificate_gcs->issuer, certificate_gcs->public_key, certificate_gcs->iv, certificate_gcs->start_time, certificate_gcs->end_time, certificate_gcs->sign);
}

/**
 * @brief Send a certificate_gcs message
 * @param chan MAVLink channel to send the message
 *
 * @param seq_number  Certificate sequent number
 * @param device_id  Device id
 * @param device_name  Name of machine
 * @param subject  Name of certification authority
 * @param issuer  Name of issuer
 * @param public_key [rad] Public key of device
 * @param iv [rad] Initial vector
 * @param start_time  Certified start of validity
 * @param end_time  Certified end of validity
 * @param sign [rad] Sign of Authority
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_certificate_gcs_send(mavlink_channel_t chan, uint8_t seq_number, uint8_t device_id, const char *device_name, const char *subject, const char *issuer, const uint8_t *public_key, const uint8_t *iv, float start_time, float end_time, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN];
    _mav_put_float(buf, 0, start_time);
    _mav_put_float(buf, 4, end_time);
    _mav_put_uint8_t(buf, 8, seq_number);
    _mav_put_uint8_t(buf, 9, device_id);
    _mav_put_char_array(buf, 10, device_name, 20);
    _mav_put_char_array(buf, 30, subject, 20);
    _mav_put_char_array(buf, 50, issuer, 20);
    _mav_put_uint8_t_array(buf, 70, public_key, 32);
    _mav_put_uint8_t_array(buf, 102, iv, 16);
    _mav_put_uint8_t_array(buf, 118, sign, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE_GCS, buf, MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC);
#else
    mavlink_certificate_gcs_t packet;
    packet.start_time = start_time;
    packet.end_time = end_time;
    packet.seq_number = seq_number;
    packet.device_id = device_id;
    mav_array_memcpy(packet.device_name, device_name, sizeof(char)*20);
    mav_array_memcpy(packet.subject, subject, sizeof(char)*20);
    mav_array_memcpy(packet.issuer, issuer, sizeof(char)*20);
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.iv, iv, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE_GCS, (const char *)&packet, MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC);
#endif
}

/**
 * @brief Send a certificate_gcs message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_certificate_gcs_send_struct(mavlink_channel_t chan, const mavlink_certificate_gcs_t* certificate_gcs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_certificate_gcs_send(chan, certificate_gcs->seq_number, certificate_gcs->device_id, certificate_gcs->device_name, certificate_gcs->subject, certificate_gcs->issuer, certificate_gcs->public_key, certificate_gcs->iv, certificate_gcs->start_time, certificate_gcs->end_time, certificate_gcs->sign);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE_GCS, (const char *)certificate_gcs, MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC);
#endif
}

#if MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_certificate_gcs_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t seq_number, uint8_t device_id, const char *device_name, const char *subject, const char *issuer, const uint8_t *public_key, const uint8_t *iv, float start_time, float end_time, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, start_time);
    _mav_put_float(buf, 4, end_time);
    _mav_put_uint8_t(buf, 8, seq_number);
    _mav_put_uint8_t(buf, 9, device_id);
    _mav_put_char_array(buf, 10, device_name, 20);
    _mav_put_char_array(buf, 30, subject, 20);
    _mav_put_char_array(buf, 50, issuer, 20);
    _mav_put_uint8_t_array(buf, 70, public_key, 32);
    _mav_put_uint8_t_array(buf, 102, iv, 16);
    _mav_put_uint8_t_array(buf, 118, sign, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE_GCS, buf, MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC);
#else
    mavlink_certificate_gcs_t *packet = (mavlink_certificate_gcs_t *)msgbuf;
    packet->start_time = start_time;
    packet->end_time = end_time;
    packet->seq_number = seq_number;
    packet->device_id = device_id;
    mav_array_memcpy(packet->device_name, device_name, sizeof(char)*20);
    mav_array_memcpy(packet->subject, subject, sizeof(char)*20);
    mav_array_memcpy(packet->issuer, issuer, sizeof(char)*20);
    mav_array_memcpy(packet->public_key, public_key, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->iv, iv, sizeof(uint8_t)*16);
    mav_array_memcpy(packet->sign, sign, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CERTIFICATE_GCS, (const char *)packet, MAVLINK_MSG_ID_CERTIFICATE_GCS_MIN_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN, MAVLINK_MSG_ID_CERTIFICATE_GCS_CRC);
#endif
}
#endif

#endif

// MESSAGE CERTIFICATE_GCS UNPACKING


/**
 * @brief Get field seq_number from certificate_gcs message
 *
 * @return  Certificate sequent number
 */
static inline uint8_t mavlink_msg_certificate_gcs_get_seq_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field device_id from certificate_gcs message
 *
 * @return  Device id
 */
static inline uint8_t mavlink_msg_certificate_gcs_get_device_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field device_name from certificate_gcs message
 *
 * @return  Name of machine
 */
static inline uint16_t mavlink_msg_certificate_gcs_get_device_name(const mavlink_message_t* msg, char *device_name)
{
    return _MAV_RETURN_char_array(msg, device_name, 20,  10);
}

/**
 * @brief Get field subject from certificate_gcs message
 *
 * @return  Name of certification authority
 */
static inline uint16_t mavlink_msg_certificate_gcs_get_subject(const mavlink_message_t* msg, char *subject)
{
    return _MAV_RETURN_char_array(msg, subject, 20,  30);
}

/**
 * @brief Get field issuer from certificate_gcs message
 *
 * @return  Name of issuer
 */
static inline uint16_t mavlink_msg_certificate_gcs_get_issuer(const mavlink_message_t* msg, char *issuer)
{
    return _MAV_RETURN_char_array(msg, issuer, 20,  50);
}

/**
 * @brief Get field public_key from certificate_gcs message
 *
 * @return [rad] Public key of device
 */
static inline uint16_t mavlink_msg_certificate_gcs_get_public_key(const mavlink_message_t* msg, uint8_t *public_key)
{
    return _MAV_RETURN_uint8_t_array(msg, public_key, 32,  70);
}

/**
 * @brief Get field iv from certificate_gcs message
 *
 * @return [rad] Initial vector
 */
static inline uint16_t mavlink_msg_certificate_gcs_get_iv(const mavlink_message_t* msg, uint8_t *iv)
{
    return _MAV_RETURN_uint8_t_array(msg, iv, 16,  102);
}

/**
 * @brief Get field start_time from certificate_gcs message
 *
 * @return  Certified start of validity
 */
static inline float mavlink_msg_certificate_gcs_get_start_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field end_time from certificate_gcs message
 *
 * @return  Certified end of validity
 */
static inline float mavlink_msg_certificate_gcs_get_end_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field sign from certificate_gcs message
 *
 * @return [rad] Sign of Authority
 */
static inline uint16_t mavlink_msg_certificate_gcs_get_sign(const mavlink_message_t* msg, uint8_t *sign)
{
    return _MAV_RETURN_uint8_t_array(msg, sign, 64,  118);
}

/**
 * @brief Decode a certificate_gcs message into a struct
 *
 * @param msg The message to decode
 * @param certificate_gcs C-struct to decode the message contents into
 */
static inline void mavlink_msg_certificate_gcs_decode(const mavlink_message_t* msg, mavlink_certificate_gcs_t* certificate_gcs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    certificate_gcs->start_time = mavlink_msg_certificate_gcs_get_start_time(msg);
    certificate_gcs->end_time = mavlink_msg_certificate_gcs_get_end_time(msg);
    certificate_gcs->seq_number = mavlink_msg_certificate_gcs_get_seq_number(msg);
    certificate_gcs->device_id = mavlink_msg_certificate_gcs_get_device_id(msg);
    mavlink_msg_certificate_gcs_get_device_name(msg, certificate_gcs->device_name);
    mavlink_msg_certificate_gcs_get_subject(msg, certificate_gcs->subject);
    mavlink_msg_certificate_gcs_get_issuer(msg, certificate_gcs->issuer);
    mavlink_msg_certificate_gcs_get_public_key(msg, certificate_gcs->public_key);
    mavlink_msg_certificate_gcs_get_iv(msg, certificate_gcs->iv);
    mavlink_msg_certificate_gcs_get_sign(msg, certificate_gcs->sign);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN? msg->len : MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN;
        memset(certificate_gcs, 0, MAVLINK_MSG_ID_CERTIFICATE_GCS_LEN);
    memcpy(certificate_gcs, _MAV_PAYLOAD(msg), len);
#endif
}
