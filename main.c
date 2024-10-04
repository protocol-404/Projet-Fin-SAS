#include "reservation.h"

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addReservation();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                changeStatus();
                break;
            case 4:
                searchReservation();
                break;
            case 5:
                sortingData();
                break;
            case 6:
                statisticData();
                break;
            case 7:
                clearScreen();
                displayLogo();
                printf(GREEN "Thank you for using the Dental Appointment System!\n" RESET);
                printf(GREEN "Goodbye!\n" RESET);
                return 0;
            default:
                printf(RED "please try again.\n" RESET);
                printf("press enter to continue...");
                getchar();
                getchar();
        }
    }

    return 0;
}
