/**
 * @file fdrs_globals.h
 * @brief Configuration globale du système Farm Data Relay System (FDRS).
 *
 * Développé par Timm Bogner (timmbogner@gmail.com) à Urbana, Illinois, USA.
 */

#ifndef __FDRS_GLOBALS_h__
#define __FDRS_GLOBALS_h__

/// Niveau de débogage global.
#define GLOBAL_DBG_LEVEL 0

/// Identifiant SSID du réseau WiFi global.
#define GLOBAL_WIFI_SSID        "Your SSID"
/// Mot de passe du réseau WiFi global.
#define GLOBAL_WIFI_PASS        "Password"

/// Adresse IP du DNS primaire (par défaut : DNS principal de Google).
#define GLOBAL_DNS1_IPADDRESS    "8.8.8.8"
/// Adresse IP du DNS secondaire (par défaut : DNS secondaire de Google).
#define GLOBAL_DNS2_IPADDRESS    "8.8.4.4"

/// Adresse du serveur MQTT global.
#define GLOBAL_MQTT_ADDR "192.168.0.8"
/// Port du serveur MQTT global.
#define GLOBAL_MQTT_PORT 1883

//#define GLOBAL_MQTT_AUTH   // Décommenter pour activer l'authentification MQTT
/// Nom d'utilisateur MQTT global.
#define GLOBAL_MQTT_USER   "Your MQTT Username"
/// Mot de passe MQTT global.
#define GLOBAL_MQTT_PASS   "Your MQTT Password"

/// Topic MQTT pour les données.
#define GLOBAL_TOPIC_DATA    "fdrs/data"
/// Topic MQTT pour le statut.
#define GLOBAL_TOPIC_STATUS  "fdrs/status"
/// Topic MQTT pour les commandes.
#define GLOBAL_TOPIC_COMMAND "fdrs/command"

/// Règles de l'heure d'été : utiliser USDST pour les règles des États-Unis, EUDST pour l'Union Européenne.
#define GLOBAL_DST_RULE        USDST
/// Serveur de temps NTP.
#define GLOBAL_TIME_SERVER      "0.us.pool.ntp.org"
/// Décalage standard en heures par rapport à UTC.
#define GLOBAL_STD_OFFSET      (-6)
/// Décalage de l'heure d'été en heures par rapport à UTC.
#define GLOBAL_DST_OFFSET      (STD_OFFSET + 1)
/// Intervalle en minutes entre les requêtes NTP.
#define GLOBAL_TIME_FETCHNTP    60
/// Intervalle en minutes entre l'affichage de l'heure locale.
#define GLOBAL_TIME_PRINTTIME   15
/// Intervalle en minutes entre les envois de temps.
#define GLOBAL_TIME_SEND_INTERVAL 60

/// Fréquence porteuse LoRa en MHz.
#define GLOBAL_LORA_FREQUENCY 915.0
/// Facteur de diffusion LoRa.
#define GLOBAL_LORA_SF 7
/// Bande passante LoRa en kHz.
#define GLOBAL_LORA_BANDWIDTH 125.0
/// Dénominateur du taux de codage LoRa.
#define GLOBAL_LORA_CR 5
/// Mot de synchronisation LoRa.
#define GLOBAL_LORA_SYNCWORD 0x12
/// Intervalle entre les libérations de la mémoire tampon LoRa en ms.
#define GLOBAL_LORA_INTERVAL 5000

/// Préfixe d'adresse MAC.
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
  #warning "OLED current supported for only ESP32 or ESP8266."
  #undef USE_OLED
#endif

#endif // __FDRS_GLOBALS_h__
