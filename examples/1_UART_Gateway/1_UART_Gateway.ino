/**
 * @file gateway_main.cpp
 * @brief Point d'entrée principal pour la passerelle du système Farm Data Relay System (FDRS) version 2.000.
 *
 * Développé par Timm Bogner (timmbogner@gmail.com) à Urbana, Illinois, USA.
 */

#include "fdrs_gateway_config.h"
#include <fdrs_gateway.h>

/**
 * @brief Fonction de configuration initiale.
 *
 * Initialise le système FDRS en appelant la fonction `beginFDRS`.
 */
void setup() {
    beginFDRS();
}

/**
 * @brief Boucle principale.
 *
 * Exécute continuellement la fonction `loopFDRS` pour maintenir le fonctionnement de la passerelle.
 */
void loop() {
    loopFDRS();
}
