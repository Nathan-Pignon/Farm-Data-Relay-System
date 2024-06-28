/**
 * @file gateway_config.h
 * @brief Configuration de la passerelle du système Farm Data Relay System (FDRS).
 */

// FARM DATA RELAY SYSTEM
//
// GATEWAY CONFIGURATION

/// Adresse de cette passerelle.
#define UNIT_MAC           0x01

/// Adresse du voisin ESP-NOW #1.
#define ESPNOW_NEIGHBOR_1  0x00
/// Adresse du voisin ESP-NOW #2.
#define ESPNOW_NEIGHBOR_2  0x02
/// Adresse du voisin LoRa #1.
#define LORA_NEIGHBOR_1    0x00
/// Adresse du voisin LoRa #2.
#define LORA_NEIGHBOR_2    0x03

// Interfaces
#define USE_ESPNOW
//#define USE_LORA
//#define USE_WIFI  // Provoquera des erreurs si utilisé avec ESP-NOW. Utilisez un lien série à la place !
//#define USE_ETHERNET

// Routage
// Options: sendESPNowNbr(1 ou 2); sendESPNowPeers(); sendLoRaNbr(1 ou 2); broadcastLoRa(); sendSerial(); sendMQTT();
/// Action de routage pour ESPNOWG.
#define ESPNOWG_ACT    sendSerial();
/// Action de routage pour LORAG.
#define LORAG_ACT      sendSerial();
/// Action de routage pour SERIAL.
#define SERIAL_ACT     sendESPNowNbr(2); sendESPNowPeers(); sendLoRaNbr(2); broadcastLoRa();
/// Action de routage pour MQTT.
#define MQTT_ACT
/// Action de routage pour INTERNAL.
#define INTERNAL_ACT   sendSerial();
/// Action de routage pour ESPNOW1.
#define ESPNOW1_ACT
/// Action de routage pour ESPNOW2.
#define ESPNOW2_ACT    sendSerial();
/// Action de routage pour LORA1.
#define LORA1_ACT
/// Action de routage pour LORA2.
#define LORA2_ACT      sendSerial();

// Configuration LoRa
/// Module RadioLib utilisé.
#define RADIOLIB_MODULE SX1276
/// Broche SS pour LoRa.
#define LORA_SS    18
/// Broche RST pour LoRa.
#define LORA_RST   14
/// Broche DIO pour LoRa.
#define LORA_DIO   26
/// Broche BUSY pour LoRa.
#define LORA_BUSY  33
//#define USE_SX126X

/// Puissance TX de LoRa en dBm.
#define LORA_TXPWR 17

//#define CUSTOM_SPI
/// Broche SCK pour SPI LoRa.
#define LORA_SPI_SCK  5
/// Broche MISO pour SPI LoRa.
#define LORA_SPI_MISO 19
/// Broche MOSI pour SPI LoRa.
#define LORA_SPI_MOSI 27

/// Active le débogage USB-Série.
#define FDRS_DEBUG
//#define DBG_LEVEL 0    // 0 pour un minimum de messages, 1 pour le dépannage, 2 pour le développement

// I2C - OLED ou RTC
/// Broche SDA pour I2C.
#define I2C_SDA 4
/// Broche SCL pour I2C.
#define I2C_SCL 15

// OLED -- Affiche les messages de débogage de la console sur un OLED I²C SSD1306
///#define USE_OLED
/// En-tête pour OLED.
#define OLED_HEADER "FDRS"
/// Intervalle de changement de page pour OLED en secondes.
#define OLED_PAGE_SECS 30
/// Broche RST pour OLED.
#define OLED_RST 16

// RTC - I2C
// #define USE_RTC_DS3231
// #define RTC_ADDR 0x57
// #define USE_RTC_DS1307
// #define RTC_ADDR 0x68

// Broches de l'interface de données UART (ESP32 uniquement)
//#define RXD2 14
//#define TXD2 15

//#define USE_LR  // Utiliser le mode ESP-NOW LR (ESP32 uniquement)

// Crédits WiFi et MQTT -- Ces paramètres remplaceront les paramètres globaux
//#define WIFI_SSID   "Your SSID"
//#define WIFI_PASS   "Your Password"

// Utiliser une adresse IP statique pour les connexions WiFi
// #define USE_STATIC_IPADDRESS
// #define HOST_IPADDRESS      "192.168.0.100"
// #define GW_IPADDRESS        "192.168.0.1"
// #define SUBNET_ADDRESS      "255.255.255.0"
// #define DNS1_IPADDRESS      "192.168.0.1"
// #define DNS2_IPADDRESS      "192.168.0.2"

// Paramètres MQTT
// #define MQTT_ADDR   "192.168.0.8"
// #define MQTT_PORT   1883 // Le port MQTT par défaut est 1883
// #define MQTT_AUTH   // Activer l'authentification MQTT
// #define MQTT_USER   "Your MQTT Username"
// #define MQTT_PASS   "Your MQTT Password"
// #define TOPIC_DATA    "fdrs/data"
// #define TOPIC_STATUS  "fdrs/status"
// #define TOPIC_COMMAND "fdrs/command"

// Paramètres de l'heure NTP pour les passerelles
/// Règles de l'heure d'été : utiliser USDST pour les règles des États-Unis, EUDST pour l'Union Européenne.
#define DST_RULE        USDST
/// Serveur de temps NTP.
#define TIME_SERVER       "0.us.pool.ntp.org"
/// Décalage standard en heures par rapport à UTC.
#define STD_OFFSET      (-6)
/// Décalage de l'heure d'été en heures par rapport à UTC.
#define DST_OFFSET      (STD_OFFSET + 1)
/// Intervalle en minutes entre les requêtes NTP.
#define TIME_FETCHNTP     60
/// Intervalle en minutes entre l'affichage de l'heure locale dans le débogage.
#define TIME_PRINTTIME    15
/// Intervalle en minutes entre les envois de temps aux appareils distants.
#define TIME_SEND_INTERVAL 10
