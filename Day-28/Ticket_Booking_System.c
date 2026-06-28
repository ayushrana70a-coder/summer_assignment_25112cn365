#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define SEATS_PER_ROW 6
#define FILE_NAME "theater.dat"
#define SEAT_PRICE 15.00 // Standard ticket flat rate

// Structure to track individual seat units
typedef struct {
    int row;
    int seatNum;
    int isBooked;
    char customerName[50];
} Seat;

// Function Prototypes
void initializeTheater();
void displaySeatingChart();
void bookTicket();
void cancelTicket();
void viewBookingDetails();
void menu();

int main() {
    // If the file doesn't exist, create and initialize it
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        initializeTheater();
    } else {
        fclose(fp);
    }
    
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n    CINEMA TICKET BOOKING SYSTEM    ");
        printf("\n====================================");
        printf("\n1. View Seating Availability Chart");
        printf("\n2. Book a Ticket");
        printf("\n3. Cancel a Booking Record");
        printf("\n4. View Ticket Reservation Details");
        printf("\n5. Reset Theater Map (Admin)");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displaySeatingChart(); break;
            case 2: bookTicket(); break;
            case 3: cancelTicket(); break;
            case 4: viewBookingDetails(); break;
            case 5: initializeTheater(); break;
            case 6: 
                printf("\nThank you for choosing our Cinema Network. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    }
}

// Generates an empty layout structure grid mapping onto the storage file
void initializeTheater() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        printf("\nCritical error setting up database records!\n");
        return;
    }

    Seat s;
    for (int i = 1; i <= ROWS; i++) {
        for (int j = 1; j <= SEATS_PER_ROW; j++) {
            s.row = i;
            s.seatNum = j;
            s.isBooked = 0;
            strcpy(s.customerName, "None");
            fwrite(&s, sizeof(Seat), 1, fp);
        }
    }
    fclose(fp);
    printf("\nTheater seating grid map configured/reset successfully.\n");
}

// Reads records sequentially to render a live seating layout map
void displaySeatingChart() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) return;

    Seat s;
    printf("\n============ STAGE / SCREEN ============\n\n");
    printf("         Seat Number Vector ->\n");
    printf("         [1]  [2]  [3]  [4]  [5]  [6]\n");
    printf("----------------------------------------\n");

    for (int i = 1; i <= ROWS; i++) {
        printf("Row %-3d  ", i);
        for (int j = 1; j <= SEATS_PER_ROW; j++) {
            fread(&s, sizeof(Seat), 1, fp);
            if (s.isBooked) {
                printf("[X]  "); // "X" denotes standard booked reservation allocation
            } else {
                printf("[O]  "); // "O" denotes an empty, available choice slot
            }
        }
        printf("\n");
    }
    printf("\nLegend: [O] Available   [X] Reserved\n");
    fclose(fp);
}

// Books a specific row and seat index combination
void bookTicket() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) return;

    int targetRow, targetSeat, found = 0;
    Seat s;

    displaySeatingChart();
    printf("\nEnter Requested Row Number (1-%d): ", ROWS);
    scanf("%d", &targetRow);
    printf("Enter Requested Seat Number (1-%d): ", SEATS_PER_ROW);
    scanf("%d", &targetSeat);

    if (targetRow < 1 || targetRow > ROWS || targetSeat < 1 || targetSeat > SEATS_PER_ROW) {
        printf("\nInvalid selection boundaries coordinates! Please retry inside parameters.\n");
        fclose(fp);
        return;
    }

    // Mathematical formula to skip straight to the selected seat profile block offset
    long int offset = ((targetRow - 1) * SEATS_PER_ROW + (targetSeat - 1)) * sizeof(Seat);
    fseek(fp, offset, SEEK_SET);
    fread(&s, sizeof(Seat), 1, fp);

    if (s.isBooked) {
        printf("\nReservation Failed: That seat is already booked by another customer!\n");
    } else {
        getchar(); // Clear buffer newline trailing trace
        printf("Enter Passenger / Customer Full Name: ");
        fgets(s.customerName, sizeof(s.customerName), stdin);
        s.customerName[strcspn(s.customerName, "\n")] = 0;
        
        s.isBooked = 1;

        // Jump back to update that specific structural segment frame
        fseek(fp, offset, SEEK_SET);
        fwrite(&s, sizeof(Seat), 1, fp);

        printf("\n========================================");
        printf("\n        RESERVATION CONFIRMED           ");
        printf("\n========================================");
        printf("\n Passenger : %s", s.customerName);
        printf("\n Location  : Row %d, Seat %d", s.row, s.seatNum);
        printf("\n Total Cost: $%.2f", SEAT_PRICE);
        printf("\n========================================\n");
    }
    fclose(fp);
}

// Cancels a booking and frees up the seat slot index
void cancelTicket() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) return;

    int targetRow, targetSeat;
    Seat s;

    printf("\nEnter Reserved Row Number to Cancel: ");
    scanf("%d", &targetRow);
    printf("Enter Reserved Seat Number to Cancel: ");
    scanf("%d", &targetSeat);

    if (targetRow < 1 || targetRow > ROWS || targetSeat < 1 || targetSeat > SEATS_PER_ROW) {
        printf("\nInvalid map input boundary vectors.\n");
        fclose(fp);
        return;
    }

    long int offset = ((targetRow - 1) * SEATS_PER_ROW + (targetSeat - 1)) * sizeof(Seat);
    fseek(fp, offset, SEEK_SET);
    fread(&s, sizeof(Seat), 1, fp);

    if (!s.isBooked) {
        printf("\nOperation Aborted: This seat is already empty.\n");
    } else {
        printf("\nCancelling reservation held by: %s\n", s.customerName);
        s.isBooked = 0;
        strcpy(s.customerName, "None");

        fseek(fp, offset, SEEK_SET);
        fwrite(&s, sizeof(Seat), 1, fp);
        printf("Ticket released successfully. Refund balance scheduled processing.\n");
    }
    fclose(fp);
}

// Search and extract registration profile allocation tags
void viewBookingDetails() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) return;

    int targetRow, targetSeat;
    Seat s;

    printf("\nEnter Row Number to check: ");
    scanf("%d", &targetRow);
    printf("Enter Seat Number to check: ");
    scanf("%d", &targetSeat);

    if (targetRow < 1 || targetRow > ROWS || targetSeat < 1 || targetSeat > SEATS_PER_ROW) {
        printf("\nInput configuration is out of range.\n");
        fclose(fp);
        return;
    }

    long int offset = ((targetRow - 1) * SEATS_PER_ROW + (targetSeat - 1)) * sizeof(Seat);
    fseek(fp, offset, SEEK_SET);
    fread(&s, sizeof(Seat), 1, fp);

    if (s.isBooked) {
        printf("\n--- Seat Details ---");
        printf("\nPosition   : Row %d, Seat %d", s.row, s.seatNum);
        printf("\nStatus     : Reserved / Occupied");
        printf("\nBooked By  : %s\n", s.customerName);
    } else {
        printf("\nPosition   : Row %d, Seat %d", s.row, s.seatNum);
        printf("\nStatus     : Vacant / Available for checkout\n");
    }
    fclose(fp);
}