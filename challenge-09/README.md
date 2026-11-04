# Challenge 09: SEATSMART “Plan. Reserve. Manage.”

# Challenge Objective  
Your university is organising a technical event in an auditorium with 5 rows and 8 seats in each row. Develop a menu-driven C program called SEATSMART to manage seat reservations. The program must allow users to view seats, book or cancel an individual seat, reserve consecutive seats for a group, and view an occupancy report. You must use a two-dimensional array and separate user-defined functions for the major operations.

# Seating Rules and Representation
Use one 5 × 8 integer array. A value of 0 means Available and a value of 1 means Booked. At the beginning, all 40 seats are available. Individual row numbers must be 1–5 and seat numbers 1–8. A group size must be from 2–8. Validate each value before using it. For individual booking/cancellation, pass the user-entered 1-based row and seat values to the functions; validate and convert them to 0-based indices inside the function.

# Algorithm
1. Start
2. In main(), declare a local 2D integer array seats[ROWS][COLS] where ROWS = 5 and COLS = 8.
   * initializeSeats(seats) to set all 40 elements to 0 (Available).   
   * Repeat the do-while loop until choice is 6: 
   * Display the menu options (1 to 6) and read the user's choice.   
3. Using switch statement, 
* Choice 1 (Display): Call displaySeats(seats) to print the grid and legend.   
* Choice 2 (Book): Call bookSeat()   
* Choice 3 (Cancel): Call cancelSeat()
* Choice 4 (Group Reservation):groupSize (2–8). Call reserveGroup()
* Choice 5 (Report): Call displayReport() 
* Choice 6 (Exit):
4. Stop
