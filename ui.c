#include "ui.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayLogo() {
    printCentered("    ____             __        __   _______ __  _      _      ", CYAN);
    printCentered("   / __ \\___  ____  / /_____ _/ /  / ____(_) /_(_)____(_)___  ", CYAN);
    printCentered("  / / / / _ \\/ __ \\/ __/ __ `/ /  / /   / / __/ / ___/ / __ \\ ", CYAN);
    printCentered(" / /_/ /  __/ / / / /_/ /_/ / /  / /___/ / /_/ / /__/ / / / / ", CYAN);
    printCentered("/_____/\\___/_/ /_/\\__/\\__,_/_/   \\____/_/\\__/_/\\___/_/_/ /_/  ", CYAN);
    printCentered("", "");
}

void displayMenu() {
    clearScreen();
    displayLogo();
    printCentered("╔════════════════════════════════════════════╗", YELLOW);
    printCentered("║     Dental Appointment Reservation System  ║", YELLOW);
    printCentered("╠════════════════════════════════════════════╣", YELLOW);
    printCentered("║  1. Add Reservation                        ║", YELLOW);
    printCentered("║  2. Display All Reservations               ║", YELLOW);
    printCentered("║  3. Update or Delete Reservation           ║", YELLOW);
    printCentered("║  4. Search Reservation                     ║", YELLOW);
    printCentered("║  5. Display Sorting Options                ║", YELLOW);
    printCentered("║  6. Display Statistics                     ║", YELLOW);
    printCentered("║  7. Exit                                   ║", YELLOW);
    printCentered("╚════════════════════════════════════════════╝", YELLOW);
    centerText("Enter your choice: ");
    printf("Enter your choice: ");
}

void displayReservation(struct Reservation res) {
    printf("| %-3d | %-10s | %-10s | %-15s | %-3d | %-12s | %02d/%02d/%04d |\n",
           res.id, res.firstName, res.lastName, res.phone, res.age, res.status,
           res.date.day, res.date.month, res.date.year);
}

void waitForEnter() {
    safeWaitForEnter();
}

void displayAll() {
    clearScreen();
    displayLogo();
    printCentered("╔═══════════════════════════════╗", MAGENTA);
    printCentered("║    All Reservations List      ║", MAGENTA);
    printCentered("╚═══════════════════════════════╝", MAGENTA);
    printCentered("", "");

    if (reservationCount == 0) {
        printCentered("No reservations to display.", RED);
    } else {
        centerText("");
        printf("┌─────┬────────────┬────────────┬─────────────────┬─────┬──────────────┬──────────────┐\n");
        centerText("");
        printf("│ ID  │ First Name │ Last Name  │ Phone           │ Age │ Status       │ Date         │\n");
        centerText("");
        printf("├─────┼────────────┼────────────┼─────────────────┼─────┼──────────────┼──────────────┤\n");

        int i = 0;
        while (i < reservationCount) {
            centerText("");
            displayReservation(reservations[i]);
            i++;
        }
        centerText("");
        printf("└─────┴────────────┴────────────┴─────────────────┴─────┴──────────────┴──────────────┘\n");
    }

    printf("\n");
    waitForEnter();
}
