#include "ui.h"
#include "reservation_manager.h"
#include "search_sort.h"
#include "statistics.h"

int main() {
    int choice;

    while (1) {
        displayMenu();
        choice = getValidatedInteger("", 1, 7);
        
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
                printCentered("Thank you for using the Dental Appointment System!", GREEN);
                printCentered("Have a great day!", GREEN);
                printCentered("Goodbye!", GREEN);
                return 0;
        }
    }

    return 0;
}
