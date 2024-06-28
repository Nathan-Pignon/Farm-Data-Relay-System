/**
 * @file fdrs_globals.h
 * @brief Global configuration for the Farm Data Relay System (FDRS).
 *
 * Developed by Timm Bogner (timmbogner@gmail.com) in Urbana, Illinois, USA.
 */

#ifndef __FDRS_GLOBALS_h__
#define __FDRS_GLOBALS_h__

/// Global debug level.
#define GLOBAL_DBG_LEVEL 0

/// Global WiFi network SSID.
#define GLOBAL_WIFI_SSID        "Your SSID"
/// Global WiFi network password.
#define GLOBAL_WIFI_PASS        "Password"

/// Primary DNS IP address (default: Google's primary DNS).
#define GLOBAL_DNS1_IPADDRESS    "8.8.8.8"
/// Secondary DNS IP address (default: Google's secondary DNS).
#define GLOBAL_DNS2_IPADDRESS    "8.8.4.4"

/// Global MQTT server address.
#define GLOBAL_MQTT_ADDR "192.168.0.8"
/// Global MQTT server port.
#define GLOBAL_MQTT_PORT 1883

//#define GLOBAL_MQTT_AUTH   // Uncomment to enable MQTT authentication
/// Global MQTT username.
#define GLOBAL_MQTT_USER   "Your MQTT Username"
/// Global MQTT password.
#define GLOBAL_MQTT_PASS   "Your MQTT Password"

/// MQTT topic for data.
#define GLOBAL_TOPIC_DATA    "fdrs/data"
/// MQTT topic for status.
#define GLOBAL_TOPIC_STATUS  "fdrs/status"
/// MQTT topic for commands.
#define GLOBAL_TOPIC_COMMAND "fdrs/command"

/// Daylight saving time rules: use USDST for US rules, EUDST for European Union.
#define GLOBAL_DST_RULE        USDST
/// NTP time server.
#define GLOBAL_TIME_SERVER      "0.us.pool.ntp.org"
/// Standard offset in hours from UTC.
#define GLOBAL_STD_OFFSET      (-6)
/// Daylight saving time offset in hours from UTC.
#define GLOBAL_DST_OFFSET      (STD_OFFSET + 1)
/// Interval in minutes between NTP requests.
#define GLOBAL_TIME_FETCHNTP    60
/// Interval in minutes between local time displays.
#define GLOBAL_TIME_PRINTTIME   15
/// Interval in minutes between time broadcasts.
#define GLOBAL_TIME_SEND_INTERVAL 60

/// LoRa carrier frequency in MHz.
#define GLOBAL_LORA_FREQUENCY 915.0
/// LoRa spreading factor.
#define GLOBAL_LORA_SF 7
/// LoRa bandwidth in kHz.
#define GLOBAL_LORA_BANDWIDTH 125.0
/// LoRa coding rate denominator.
#define GLOBAL_LORA_CR 5
/// LoRa sync word.
#define GLOBAL_LORA_SYNCWORD 0x12
/// Interval between LoRa buffer releases in ms.
#define GLOBAL_LORA_INTERVAL 5000

/// MAC address prefix.
#define MAC_PREFIX  0xAA, 0xBB, 0xCC, 0xDD, 0xEE

#if defined(USE_OLED) || defined(USE_RTC_DS3231) || defined(USE_RTC_DS1307)
    #define USE_I2C
#endif

#if defined(USE_RTC_DS3231) || defined(USE_RTC_DS1307)
  #define USE_RTC
#endif

#if defined(USE_GPS) && defined(ESP8266)
  #error "For ESP8266 only one UART has both Tx and Rx capabilities. GPS not supported for ESP8266"
#endif

#if defined(USE_ETHERNET) && !defined(ESP32)
  #error "Ethernet only supported for ESP32."
#endif

#if defined(USE_OLED) && (!defined(ESP32) && !defined(ESP8266))
  #warning "OLED currently supported only for ESP32 or ESP8266."
  #undef USE_OLED
#endif

#endif // __FDRS_GLOBALS_h__
