#ifndef UI_H
#define UI_H

#include "types.h"
#include "utils.h"

// Screen and display functions
void clearScreen();
void displayLogo();
void displayMenu();
void displayReservation(struct Reservation res);
void displayAll();
void waitForEnter();

#endif
