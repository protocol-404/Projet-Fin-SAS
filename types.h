#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define MAX_RESERVATIONS 100
#define MAX_NAME_LENGTH 50

// Color codes for terminal output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Date structure
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

// Reservation structure
typedef struct Reservation {
    int id;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char phone[15];
    int age;
    char status[20];
    Date date;
} Reservation;

// Global variables (declared here, defined in reservation.c)
extern struct Reservation reservations[MAX_RESERVATIONS];
extern int reservationCount;

#endif
