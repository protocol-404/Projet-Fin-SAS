#include "reservation.h"

struct Reservation reservations[MAX_RESERVATIONS];

int reservationCount = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayLogo() {
    printf(CYAN);
    printf("    ____             __        __   _______ __  _      _      \n");
    printf("   / __ \\___  ____  / /_____ _/ /  / ____(_) /_(_)____(_)___  \n");
    printf("  / / / / _ \\/ __ \\/ __/ __ `/ /  / /   / / __/ / ___/ / __ \\ \n");
    printf(" / /_/ /  __/ / / / /_/ /_/ / /  / /___/ / /_/ / /__/ / / / / \n");
    printf("/_____/\\___/_/ /_/\\__/\\__,_/_/   \\____/_/\\__/_/\\___/_/_/ /_/  \n");
    printf("\n");
    printf(RESET);
}

void displayMenu() {
    clearScreen();
    displayLogo();
    printf(YELLOW "╔════════════════════════════════════════════╗\n" RESET);
    printf(YELLOW "║     Dental Appointment Reservation System  ║\n" RESET);
    printf(YELLOW "╠════════════════════════════════════════════╣\n" RESET);
    printf(YELLOW "║ " WHITE "1. Add Reservation                         " YELLOW "║\n" RESET);
    printf(YELLOW "║ " WHITE "2. Display All Reservations                " YELLOW "║\n" RESET);
    printf(YELLOW "║ " WHITE "3. Update or Delete Reservation            " YELLOW "║\n" RESET);
    printf(YELLOW "║ " WHITE "4. Search Reservation                      " YELLOW "║\n" RESET);
    printf(YELLOW "║ " WHITE "5. Display Sorting Options                 " YELLOW "║\n" RESET);
    printf(YELLOW "║ " WHITE "6. Display Statistics                      " YELLOW "║\n" RESET);
    printf(YELLOW "║ " WHITE "7. Exit                                    " YELLOW "║\n" RESET);
    printf(YELLOW "╚════════════════════════════════════════════╝\n" RESET);
    printf("enter your choice: ");
}

void addReservation() {
    clearScreen();
    displayLogo();
    printf(BLUE "╔═══════════════════════════════╗\n" RESET);
    printf(BLUE "║    Adding New Reservation     ║\n" RESET);
    printf(BLUE "╚═══════════════════════════════╝\n\n" RESET);

    if (reservationCount >= MAX_RESERVATIONS) {
        printf(RED "the list it's full.\n" RESET);
        return;
    }

    struct Reservation newReservation;
    newReservation.id = reservationCount + 1;

    printf("enter first name: ");
    getchar();
    scanf("%[^\n]s", newReservation.firstName);

    printf("enter last name: ");
    getchar();
    scanf("%[^\n]s", newReservation.lastName);

    printf("enter phone number: ");
    scanf("%s", newReservation.phone);
    
    int validAge = 0;
    while (!validAge) {
        printf("enter age: ");
        if (scanf("%d", &newReservation.age) == 1 && newReservation.age > 5) {
            validAge = 1;
        } else {
            while (getchar() != '\n');
            printf(RED "error: pls enter a valid age (above 5).\n" RESET);
        }
    }

    strcpy(newReservation.status, "validated");

    int validDate = 0;
    while (!validDate) {
        int day, month, year;
        printf("enter date (DD/MM/YYYY): ");
        if (scanf("%d/%d/%d", &day, &month, &year) == 3) {
            if (month >= 1 && month <= 12 && 
                day >= 1 && day <= 31 && 
                year >= 2024 && year <= 2035) {
                newReservation.date.day = day;
                newReservation.date.month = month;
                newReservation.date.year = year;
                validDate = 1;
            }
        }
        if (!validDate) {
            printf(RED "pls enter a valid date (DD/MM/YYYY).\n" RESET);
            while (getchar() != '\n');
        }
    }

    reservations[reservationCount++] = newReservation;

    printf(GREEN "\n✔ reservation added successfully. ID: %d\n" RESET, newReservation.id);
    printf("\npress enter to continue...");
    getchar();
    getchar();
}

void displayReservation(struct Reservation res) {
    printf("| %-3d | %-10s | %-10s | %-15s | %-3d | %-12s | %02d/%02d/%04d |\n",
           res.id, res.firstName, res.lastName, res.phone, res.age, res.status,
           res.date.day, res.date.month, res.date.year);
}

void displayAll() {
    clearScreen();
    displayLogo();
    printf(MAGENTA "╔═══════════════════════════════╗\n" RESET);
    printf(MAGENTA "║    All Reservations List      ║\n" RESET);
    printf(MAGENTA "╚═══════════════════════════════╝\n\n" RESET);

    if (reservationCount == 0) {
        printf(RED "nothing to display.\n" RESET);
    } else {
        printf("┌─────┬────────────┬────────────┬─────────────────┬─────┬──────────────┬──────────────┐\n");
        printf("│ ID  │ First Name │ Last Name  │ Phone           │ Age │ Status       │ Date         │\n");
        printf("├─────┼────────────┼────────────┼─────────────────┼─────┼──────────────┼──────────────┤\n");

        int i = 0;
        while (i < reservationCount) {
            displayReservation(reservations[i]);
            i++;
        }
        printf("└─────┴────────────┴────────────┴─────────────────┴─────┴──────────────┴──────────────┘\n");
    }

    printf("\npress enter to continue...");
    getchar();
    getchar();
}

void changeStatus() {
    int id;
    printf("enter reservation ID to update or delete: ");
    scanf("%d", &id);

    if (id < 1 || id > reservationCount) {
        printf(RED "no reservation found.\n" RESET);
        return;
    }

    int index = id - 1;
    displayReservation(reservations[index]);

    int choice;
    printf("Choose an action:\n");
    printf("1. Update\n");
    printf("2. Delete\n");
    printf("3. Back to menu\n");
    printf("enter your choice (1, 2, or 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int statusChoice;
            printf("choose new status:\n");
            printf("1. validated\n");
            printf("2. canceled\n");
            printf("3. postponed\n");
            printf("4. treated\n");
            printf("5. back to menu\n");
            printf("enter your choice: ");
            scanf("%d", &statusChoice);
            
            switch (statusChoice) {
                case 1:
                    strcpy(reservations[index].status, "validated");
                    break;
                case 2:
                    strcpy(reservations[index].status, "canceled");
                    break;
                case 3:
                    strcpy(reservations[index].status, "postponed");
                    break;
                case 4:
                    strcpy(reservations[index].status, "treated");
                    break;
                case 5:
                    return;
                default:
                    printf(RED "no status updated.\n" RESET);
                    return;
            }
            printf(GREEN "reservation updated successfully.\n" RESET);
            break;
        }
        case 2: {
            int i = index;
            while (i < reservationCount - 1) {
                reservations[i] = reservations[i + 1];
                reservations[i].id--;
                i++;
            }
            reservationCount--;
            printf(GREEN "reservation deleted successfully.\n" RESET);
            break;
        }
        case 3:
            return;
        default:
            printf(RED "no action taken.\n" RESET);
    }
}

void searchReservation() {
    char searchTerm[MAX_NAME_LENGTH];
    int searchId;
    int searchChoice;
    int found = 0;

    printf(BLUE "╔═══════════════════════════════╗\n" RESET);
    printf(BLUE "║       Search Reservation      ║\n" RESET);
    printf(BLUE "╚═══════════════════════════════╝\n\n" RESET);

    printf("1. search by ID\n");
    printf("2. search by Last Name\n");
    printf("enter your choice (1 or 2): ");
    scanf("%d", &searchChoice);

    switch(searchChoice) {
        case 1:
            printf("enter ID to search: ");
            scanf("%d", &searchId);
            int i = 0;
            while (i < reservationCount) {
                if (reservations[i].id == searchId) {
                    displayReservation(reservations[i]);
                    found = 1;
                    break;
                }
                i++;
            }
            break;
        case 2:
            printf("enter last name to search: ");
            scanf("%s", searchTerm);
            i = 0;
            while (i < reservationCount) {
                if (strcasecmp(reservations[i].lastName, searchTerm) == 0) {
                    displayReservation(reservations[i]);
                    found = 1;
                }
                i++;
            }
            break;
        default:
            printf(RED "invalid choice :( Returning to main menu.\n" RESET);
            return;
    }

    if (!found) {
        printf(RED "no reservations found.\n" RESET);
    }

    printf("\npress enter to continue...");
    getchar();
    getchar();
}

void statisticData() {
    clearScreen();
    displayLogo();
    printf(BLUE "╔══════════════════════════════════════╗\n" RESET);
    printf(BLUE "║               Statistics             ║\n" RESET);
    printf(BLUE "╚══════════════════════════════════════╝\n\n" RESET);

    if (reservationCount == 0) {
        printf(RED "no reservations to calculate statistics.\n" RESET);
        return;
    } 

    int totalAge = 0;
    int ageGroups[3] = {0};
    int validCount = 0, canceledCount = 0, postponedCount = 0, treatedCount = 0;

    for (int i = 0; i < reservationCount; i++) {
        totalAge += reservations[i].age;

        if (reservations[i].age <= 18) {
            ageGroups[0]++;
        } else if (reservations[i].age <= 35) {
            ageGroups[1]++;
        } else {
            ageGroups[2]++;
        }

        if (strcmp(reservations[i].status, "validated") == 0) {
            validCount++;
        } else if (strcmp(reservations[i].status, "canceled") == 0) {
            canceledCount++;
        } else if (strcmp(reservations[i].status, "postponed") == 0) {
            postponedCount++;
        } else if (strcmp(reservations[i].status, "treated") == 0) {
            treatedCount++;
        }
    }

    float averageAge = (float)totalAge / (float)reservationCount;

    printf("Age Statistics:\n");
    printf("average age: %.2f\n", averageAge);
    printf("age groups:\n");
    printf("0-18 years: %d\n", ageGroups[0]);
    printf("19-35 years: %d\n", ageGroups[1]);
    printf("36+ years: %d\n", ageGroups[2]);

    printf("\nStatus Statistics:\n");
    printf("Total Reservations: %d\n", reservationCount);
    printf("Validated: %d\n", validCount);
    printf("Canceled: %d\n", canceledCount);
    printf("Postponed: %d\n", postponedCount);
    printf("Treated: %d\n", treatedCount);

    printf("\npress enter to continue...");
    getchar();
    getchar();
}

void sortingByName() {
    struct Reservation temp;

    int i = 0;
    while (i < reservationCount - 1) {
        int j = 0;
        while (j < reservationCount - i - 1) {
            if (strcmp(reservations[j].firstName, reservations[j + 1].firstName) > 0) {
                temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    printf(GREEN "rservations sorted by name.\n" RESET);
}

void sortingByStatus() {
    struct Reservation temp;

    int i = 0;
    while (i < reservationCount - 1) {
        int j = 0;
        while (j < reservationCount - i - 1) {
            if (strcmp(reservations[j].status, reservations[j + 1].status) > 0) {
                temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    printf(GREEN "reservations sorted by status.\n" RESET);
}

void sortingData() {
    if (reservationCount == 0) {
        printf(RED "no reservations to display.\n" RESET);
        return;
    }

    clearScreen();
    displayLogo();
    printf(BLUE "╔═══════════════════════════════╗\n" RESET);
    printf(BLUE "║         Sorting Options       ║\n" RESET);
    printf(BLUE "╚═══════════════════════════════╝\n\n" RESET);

    printf("1. Sort by Name\n");
    printf("2. Sort by Status\n");
    printf("3. Back to main menu\n\n");
    printf("enter your choice: ");

    int choice;
    scanf("%d", &choice);

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
            return;
        default:
            printf(RED "no sorting performed.\n" RESET);
            return;
    }
}