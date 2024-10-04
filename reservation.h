#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RESERVATIONS 100
#define MAX_NAME_LENGTH 50

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Reservation {
    int id;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char phone[15];
    int age;
    char status[20];
    Date date;
} Reservation;

extern struct Reservation reservations[MAX_RESERVATIONS];
extern int reservationCount;

void clearScreen();
void displayLogo();
void displayMenu();
void addReservation();
void displayAll();
void changeStatus();
void searchReservation();
void statisticData();
void sortingData();

#endif
