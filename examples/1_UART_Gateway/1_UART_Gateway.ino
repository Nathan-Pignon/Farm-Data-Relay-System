/**
 * @file gateway_main.cpp
 * @brief Main entry point for the Farm Data Relay System (FDRS) gateway version 2.000.
 *
 * Developed by Timm Bogner (timmbogner@gmail.com) in Urbana, Illinois, USA.
 */

#include "fdrs_gateway_config.h"
#include <fdrs_gateway.h>

/**
 * @brief Initial setup function.
 *
 * Initializes the FDRS system by calling the `beginFDRS` function.
 */
void setup() {
    beginFDRS();
}

/**
 * @brief Main loop.
 *
 * Continuously runs the `loopFDRS` function to maintain gateway operation.
 */
void loop() {
    loopFDRS();
}
