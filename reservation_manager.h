#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "types.h"
#include "utils.h"

// Core reservation management functions
void addReservation();
void changeStatus();
int findNextAvailableId();
void reassignIds();

#endif
