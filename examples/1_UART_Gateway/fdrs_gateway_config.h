/**
 * @file gateway_config.h
 * @brief Configuration for the Farm Data Relay System (FDRS) gateway.
 */

// FARM DATA RELAY SYSTEM
//
// GATEWAY CONFIGURATION

/// Address of this gateway.
#define UNIT_MAC           0x01

/// Address of ESP-NOW neighbor #1.
#define ESPNOW_NEIGHBOR_1  0x00
/// Address of ESP-NOW neighbor #2.
#define ESPNOW_NEIGHBOR_2  0x02
/// Address of LoRa neighbor #1.
#define LORA_NEIGHBOR_1    0x00
/// Address of LoRa neighbor #2.
#define LORA_NEIGHBOR_2    0x03

// Interfaces
#define USE_ESPNOW
//#define USE_LORA
//#define USE_WIFI  // Will cause errors if used with ESP-NOW. Use a serial link instead!
//#define USE_ETHERNET

// Routing
// Options: sendESPNowNbr(1 or 2); sendESPNowPeers(); sendLoRaNbr(1 or 2); broadcastLoRa(); sendSerial(); sendMQTT();
/// Routing action for ESPNOWG.
#define ESPNOWG_ACT    sendSerial();
/// Routing action for LORAG.
#define LORAG_ACT      sendSerial();
/// Routing action for SERIAL.
#define SERIAL_ACT     sendESPNowNbr(2); sendESPNowPeers(); sendLoRaNbr(2); broadcastLoRa();
/// Routing action for MQTT.
#define MQTT_ACT
/// Routing action for INTERNAL.
#define INTERNAL_ACT   sendSerial();
/// Routing action for ESPNOW1.
#define ESPNOW1_ACT
/// Routing action for ESPNOW2.
#define ESPNOW2_ACT    sendSerial();
/// Routing action for LORA1.
#define LORA1_ACT
/// Routing action for LORA2.
#define LORA2_ACT      sendSerial();

// LoRa Configuration
/// RadioLib module used.
#define RADIOLIB_MODULE SX1276
/// SS pin for LoRa.
#define LORA_SS    18
/// RST pin for LoRa.
#define LORA_RST   14
/// DIO pin for LoRa.
#define LORA_DIO   26
/// BUSY pin for LoRa.
#define LORA_BUSY  33
//#define USE_SX126X

/// LoRa TX power in dBm.
#define LORA_TXPWR 17

//#define CUSTOM_SPI
/// SCK pin for LoRa SPI.
#define LORA_SPI_SCK  5
/// MISO pin for LoRa SPI.
#define LORA_SPI_MISO 19
/// MOSI pin for LoRa SPI.
#define LORA_SPI_MOSI 27

/// Enable USB-Serial debugging.
#define FDRS_DEBUG
//#define DBG_LEVEL 0    // 0 for minimal messages, 1 for troubleshooting, 2 for development

// I2C - OLED or RTC
/// SDA pin for I2C.
#define I2C_SDA 4
/// SCL pin for I2C.
#define I2C_SCL 15

// OLED -- Displays console debug messages on an I²C SSD1306 OLED
///#define USE_OLED
/// Header for OLED.
#define OLED_HEADER "FDRS"
/// OLED page change interval in seconds.
#define OLED_PAGE_SECS 30
/// RST pin for OLED.
#define OLED_RST 16

// RTC - I2C
// #define USE_RTC_DS3231
// #define RTC_ADDR 0x57
// #define USE_RTC_DS1307
// #define RTC_ADDR 0x68

// UART data interface pins (ESP32 only)
//#define RXD2 14
//#define TXD2 15

//#define USE_LR  // Use ESP-NOW LR mode (ESP32 only)

// WiFi and MQTT credentials -- These settings will override global settings
//#define WIFI_SSID   "Your SSID"
//#define WIFI_PASS   "Your Password"

// Use a static IP address for WiFi connections
// #define USE_STATIC_IPADDRESS
// #define HOST_IPADDRESS      "192.168.0.100"
// #define GW_IPADDRESS        "192.168.0.1"
// #define SUBNET_ADDRESS      "255.255.255.0"
// #define DNS1_IPADDRESS      "192.168.0.1"
// #define DNS2_IPADDRESS      "192.168.0.2"

// MQTT settings
// #define MQTT_ADDR   "192.168.0.8"
// #define MQTT_PORT   1883 // Default MQTT port is 1883
// #define MQTT_AUTH   // Enable MQTT authentication
// #define MQTT_USER   "Your MQTT Username"
// #define MQTT_PASS   "Your MQTT Password"
// #define TOPIC_DATA    "fdrs/data"
// #define TOPIC_STATUS  "fdrs/status"
// #define TOPIC_COMMAND "fdrs/command"

// NTP time settings for gateways
/// Daylight saving time rules: use USDST for US rules, EUDST for European Union.
#define DST_RULE        USDST
/// NTP time server.
#define TIME_SERVER       "0.us.pool.ntp.org"
/// Standard offset in hours from UTC.
#define STD_OFFSET      (-6)
/// Daylight saving time offset in hours from UTC.
#define DST_OFFSET      (STD_OFFSET + 1)
/// Interval in minutes between NTP requests.
#define TIME_FETCHNTP     60
/// Interval in minutes between local time display in debugging.
#define TIME_PRINTTIME    15
/// Interval in minutes between time broadcasts to remote devices.
#define TIME_SEND_INTERVAL 10
