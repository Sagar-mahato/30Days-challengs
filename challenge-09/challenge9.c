#include <stdio.h>
#define ROWS 5
#define COLS 8
void initializeSeats(int seats[ROWS][COLS]);
void displaySeats(int seats[ROWS][COLS]);
int bookSeat(int seats[ROWS][COLS], int row, int col);
int cancelSeat(int seats[ROWS][COLS], int row, int col);
int reserveGroup(int seats[ROWS][COLS], int groupSize);
void displayReport(int seats[ROWS][COLS]);
int main() {
int seats[ROWS][COLS];
int choice, row, col, groupSize,result;
initializeSeats(seats);
do {
printf("\nMenu:\n");
printf("1. Display seats\n");
printf("2. Book one seat\n");
printf("3. Cancel booking\n");
printf("4. Group resevation (size must be 2-8)\n");
printf("5. Occupancy report\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
displaySeats(seats);
break;
case 2:
printf("Enter row (1-5) and column (1-8) to book: ");
scanf("%d %d", &row, &col);
if (bookSeat(seats,row,col)){
printf("Seat booked successfully.\n");
displaySeats(seats);
} else {
printf("Booking failed. Seat is already booked or invalid.\n");
}
break;
case 3:
printf("Enter row (1-5)and column (1-8)to cancel booking: ");
scanf("%d %d", &row, &col);
if (cancelSeat(seats, row, col)) {
printf("Booking canceled successfully.\n");
displaySeats(seats);
} else {
printf("Cancellation failed. invalid seat or seat not booked.\n");
}
break;
case 4:
printf("Enter group size (2-8): ");
scanf("%d", &groupSize);
if (groupSize < 2 || groupSize > 8) {
printf("Invalid group size. Please enter a size between 2 and 8.\n");
} else {
if (reserveGroup(seats, groupSize)) {
printf("Group reservation successful.\n");
displaySeats(seats);
} else {
printf("Group reservation failed.\n");
}
}
break;
case 5:
displayReport(seats);
break;
case 6:
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please choice an option between 1 and 6.\n");
}
} while (choice != 6);
return 0;
}
void initializeSeats(int seats[ROWS][COLS]) {
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
seats[i][j] = 0;
}}}
void displaySeats(int seats[ROWS][COLS]){
int i, j;
printf("\nSeating Layout\n");
printf("0 = Available, 1 = Booked\n\n");
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
printf("%d ", seats[i][j]);
}
printf("\n");
}
}
int bookSeat(int seats[ROWS][COLS], int row, int col){
if(row < 1 || row > ROWS || col < 1 || col > COLS){
printf("Invalid seat selection. Please choose a valid row and column.\n");
return 0;
}
int r=row-1;
int c=col-1;
if(seats[r][c] == 0){
seats[r][c] = 1;
return 1;
} else {
    printf("Seat is already booked.\n");
    return 0;
}
}
int cancelSeat(int seats[ROWS][COLS], int row, int col) {
if(row < 1 || row > ROWS || col < 1 || col > COLS){
printf("Invalid seat selection. Please choose a valid row and column.\n");
return 0;
}
int r=row-1;
int c=col-1;
if(seats[r][c] == 1){
seats[r][c] = 0;
return 1;
} else {
printf("Seat is not booked.\n");
return 0;
}}
int reserveGroup(int seats[ROWS][COLS], int groupSize){
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j <= COLS - groupSize; j++) {
int available = 1;
for (int k = 0; k < groupSize; k++) {
if (seats[i][j + k] == 1) {
available = 0;
break;
} }
if (available) {
for (int k = 0; k < groupSize; k++) {
seats[i][j + k] = 1;
}
printf("Group of %d seats reserved at row %d, starting from column %d.\n", groupSize, i + 1, j + 1);
return 1;
}}}
return 0;
}
void displayReport(int seats[ROWS][COLS]) {
int totalSeats = ROWS * COLS;
int bookedSeats = 0,rowbookedcount= 0,highest=0,highestRow=0;
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
if (seats[i][j] == 1) {
bookedSeats++;
rowbookedcount++;}
}
if (rowbookedcount > highest) {
    highest = rowbookedcount;
    highestRow = i+1;
}
}
printf("\nTotal seats: %d\n", totalSeats);
printf("Booked seats: %d\n", bookedSeats);
printf("Available seats: %d\n", totalSeats - bookedSeats);
printf("Occupancy percentage: %.2f%%\n", (bookedSeats / (float)totalSeats) * 100.0);
printf("Highest booked row: %d with %d seats booked\n", highestRow, highest);
}
