#include "search_sort.h"
#include "ui.h"

void searchReservation() {
    clearScreen();
    displayLogo();
    printCentered("╔═══════════════════════════════╗", BLUE);
    printCentered("║       Search Reservation      ║", BLUE);
    printCentered("╚═══════════════════════════════╝", BLUE);
    printCentered("", "");

    if (reservationCount == 0) {
        printCentered("No reservations available to search.", RED);
        waitForEnter();
        return;
    }

    printCentered("Search Options:", WHITE);
    printCentered("1. Search by ID", WHITE);
    printCentered("2. Search by Last Name", WHITE);
    printCentered("3. Back to main menu", WHITE);
    
    int searchChoice = getValidatedInteger("Enter your choice: ", 1, 3);
    int found = 0;

    switch(searchChoice) {
        case 1: {
            int searchId = getValidatedInteger("Enter ID to search: ", 1, 999);
            int i = 0;
            while (i < reservationCount) {
                if (reservations[i].id == searchId) {
                    printCentered("Reservation Found:", GREEN);
                    centerText("");
                    displayReservation(reservations[i]);
                    found = 1;
                    break;
                }
                i++;
            }
            break;
        }
        case 2: {
            char searchTerm[MAX_NAME_LENGTH];
            getValidatedString("Enter last name to search: ", searchTerm, MAX_NAME_LENGTH);
            
            printCentered("Search Results:", GREEN);
            centerText("");
            printf("┌─────┬────────────┬────────────┬─────────────────┬─────┬──────────────┬──────────────┐\n");
            centerText("");
            printf("│ ID  │ First Name │ Last Name  │ Phone           │ Age │ Status       │ Date         │\n");
            centerText("");
            printf("├─────┼────────────┼────────────┼─────────────────┼─────┼──────────────┼──────────────┤\n");
            
            int i = 0;
            while (i < reservationCount) {
                if (stringCompareIgnoreCase(reservations[i].lastName, searchTerm) == 0) {
                    centerText("");
                    displayReservation(reservations[i]);
                    found = 1;
                }
                i++;
            }
            
            if (found) {
                centerText("");
                printf("└─────┴────────────┴────────────┴─────────────────┴─────┴──────────────┴──────────────┘\n");
            }
            break;
        }
        case 3:
            return;
    }

    if (!found) {
        printCentered("No reservations found matching your search.", RED);
    }

    printf("\n");
    waitForEnter();
}

void sortingByName() {
    struct Reservation temp;

    int i = 0;
    while (i < reservationCount - 1) {
        int j = 0;
        while (j < reservationCount - i - 1) {
            if (stringCompare(reservations[j].firstName, reservations[j + 1].firstName) > 0) {
                temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    printCentered("Reservations sorted by first name.", GREEN);
}

void sortingByStatus() {
    struct Reservation temp;

    int i = 0;
    while (i < reservationCount - 1) {
        int j = 0;
        while (j < reservationCount - i - 1) {
            if (stringCompare(reservations[j].status, reservations[j + 1].status) > 0) {
                temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    printCentered("Reservations sorted by status.", GREEN);
}

// Native date comparison function
int compareDates(Date date1, Date date2) {
    if (date1.year != date2.year) {
        return date1.year - date2.year;
    }
    if (date1.month != date2.month) {
        return date1.month - date2.month;
    }
    return date1.day - date2.day;
}

void sortingByDate() {
    struct Reservation temp;

    int i = 0;
    while (i < reservationCount - 1) {
        int j = 0;
        while (j < reservationCount - i - 1) {
            if (compareDates(reservations[j].date, reservations[j + 1].date) > 0) {
                temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    printCentered("Reservations sorted by date.", GREEN);
}

void sortingData() {
    if (reservationCount == 0) {
        clearScreen();
        displayLogo();
        printCentered("No reservations available to sort.", RED);
        waitForEnter();
        return;
    }

    clearScreen();
    displayLogo();
    printCentered("╔═══════════════════════════════╗", BLUE);
    printCentered("║         Sorting Options       ║", BLUE);
    printCentered("╚═══════════════════════════════╝", BLUE);
    printCentered("", "");

    printCentered("Sorting Options:", WHITE);
    printCentered("1. Sort by First Name", WHITE);
    printCentered("2. Sort by Status", WHITE);
    printCentered("3. Sort by Date", WHITE);
    printCentered("4. Back to main menu", WHITE);

    int choice = getValidatedInteger("Enter your choice: ", 1, 4);

    switch (choice) {
        case 1:
            sortingByName();
            displayAll();
            break;
        case 2:
            sortingByStatus();
            displayAll();
            break;
        case 3:
            sortingByDate();
            displayAll();
            break;
        case 4:
            return;
    }
}
