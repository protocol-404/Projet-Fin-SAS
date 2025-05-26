#include "reservation_manager.h"
#include "ui.h"

// Global variables definition
struct Reservation reservations[MAX_RESERVATIONS];
int reservationCount = 0;

// Find next available ID
int findNextAvailableId() {
    return reservationCount + 1;
}

// Reassign IDs after deletion to maintain sequence
void reassignIds() {
    int i = 0;
    while (i < reservationCount) {
        reservations[i].id = i + 1;
        i++;
    }
}

void addReservation() {
    clearScreen();
    displayLogo();
    printCentered("╔═══════════════════════════════╗", BLUE);
    printCentered("║    Adding New Reservation     ║", BLUE);
    printCentered("╚═══════════════════════════════╝", BLUE);
    printCentered("", "");

    if (reservationCount >= MAX_RESERVATIONS) {
        printCentered("Reservation list is full. Cannot add more reservations.", RED);
        waitForEnter();
        return;
    }

    struct Reservation newReservation;
    newReservation.id = findNextAvailableId();
    
    // Get and validate first name
    int validName = 0;
    while (!validName) {
        getValidatedString("Enter first name: ", newReservation.firstName, MAX_NAME_LENGTH);
        
        if (isValidName(newReservation.firstName)) {
            validName = 1;
        } else {
            printCentered("Invalid name. Please use only letters and spaces.", RED);
        }
    }

    // Get and validate last name
    validName = 0;
    while (!validName) {
        getValidatedString("Enter last name: ", newReservation.lastName, MAX_NAME_LENGTH);
        
        if (isValidName(newReservation.lastName)) {
            validName = 1;
        } else {
            printCentered("Invalid name. Please use only letters and spaces.", RED);
        }
    }

    // Get and validate phone number
    int validPhone = 0;
    while (!validPhone) {
        getValidatedString("Enter phone number: ", newReservation.phone, 15);
        
        if (isValidPhone(newReservation.phone)) {
            validPhone = 1;
        } else {
            printCentered("Invalid phone number. Please use 8-14 digits.", RED);
        }
    }
    
    // Get and validate age
    newReservation.age = getValidatedInteger("Enter age (6-120): ", 6, 120);

    // Set default status
    stringCopy(newReservation.status, "validated");

    // Get and validate date
    int validDate = 0;
    while (!validDate) {
        int day, month, year;
        printCenteredPrompt("Enter date (DD/MM/YYYY): ");
        
        int scanResult = scanf("%d/%d/%d", &day, &month, &year);
        
        if (scanResult == EOF) {
            printf("\n");
            centerText("Input ended unexpectedly. Exiting program.");
            exit(1);
        } else if (scanResult == 3) {
            if (isValidDate(day, month, year)) {
                newReservation.date.day = day;
                newReservation.date.month = month;
                newReservation.date.year = year;
                validDate = 1;
            } else {
                printCentered("Invalid date. Please enter a valid date between 2024-2035.", RED);
                clearInputBuffer();
            }
        } else {
            printCentered("Invalid format. Please use DD/MM/YYYY format.", RED);
            clearInputBuffer();
        }
    }

    reservations[reservationCount++] = newReservation;

    printCentered("", "");
    printCentered("✔ Reservation added successfully!", GREEN);
    char idMsg[50];
    sprintf(idMsg, "Reservation ID: %d", newReservation.id);
    printCentered(idMsg, GREEN);
    printCentered("", "");
    safeWaitForEnter();
    
    waitForEnter();
}

void changeStatus() {
    clearScreen();
    displayLogo();
    printCentered("╔═══════════════════════════════╗", BLUE);
    printCentered("║   Update or Delete Reservation║", BLUE);
    printCentered("╚═══════════════════════════════╝", BLUE);
    printCentered("", "");
    
    if (reservationCount == 0) {
        printCentered("No reservations available.", RED);
        waitForEnter();
        return;
    }
    
    int id = getValidatedInteger("Enter reservation ID: ", 1, reservationCount);
    
    // Find reservation by ID
    int index = -1;
    int i = 0;
    while (i < reservationCount) {
        if (reservations[i].id == id) {
            index = i;
            break;
        }
        i++;
    }

    if (index == -1) {
        printCentered("Reservation not found.", RED);
        waitForEnter();
        return;
    }

    // Display current reservation
    printCentered("Current reservation:", WHITE);
    centerText("");
    displayReservation(reservations[index]);
    printf("\n");

    // Action menu
    printCentered("Choose an action:", WHITE);
    printCentered("1. Update Status", WHITE);
    printCentered("2. Delete Reservation", WHITE);
    printCentered("3. Back to main menu", WHITE);
    
    int choice = getValidatedInteger("Enter your choice: ", 1, 3);

    switch (choice) {
        case 1: {
            printCentered("Choose new status:", WHITE);
            printCentered("1. Validated", WHITE);
            printCentered("2. Canceled", WHITE);
            printCentered("3. Postponed", WHITE);
            printCentered("4. Treated", WHITE);
            printCentered("5. Back to menu", WHITE);
            
            int statusChoice = getValidatedInteger("Enter status choice: ", 1, 5);
            
            switch (statusChoice) {
                case 1:
                    stringCopy(reservations[index].status, "validated");
                    break;
                case 2:
                    stringCopy(reservations[index].status, "canceled");
                    break;
                case 3:
                    stringCopy(reservations[index].status, "postponed");
                    break;
                case 4:
                    stringCopy(reservations[index].status, "treated");
                    break;
                case 5:
                    return;
            }
            printCentered("Reservation status updated successfully!", GREEN);
            break;
        }
        case 2: {
            // Delete reservation by shifting all subsequent reservations
            i = index;
            while (i < reservationCount - 1) {
                reservations[i] = reservations[i + 1];
                i++;
            }
            reservationCount--;
            
            // Reassign IDs to maintain sequence
            reassignIds();
            
            printCentered("Reservation deleted successfully!", GREEN);
            break;
        }
        case 3:
            return;
    }
    
    waitForEnter();
}
