# CHALLENGE 06: PATTERN DETECTIVE.“Read the Data. Find the Pattern.”

# Problem Description
A smart-campus activity monitor records the number of visits over several time slots. Your task is to write a C program that studies the sequence, finds meaningful patterns, and then rotates the data for a cyclic report. The important part is to plan the logic before coding and to handle unusual cases correctly.

# Mission 
Read N activity readings into a one-dimensional array and complete every task below. N must be between 5 and 12 inclusive. Each reading must be an integer from 0 to 1000 inclusive. If N or a reading is invalid, ask again until valid input is entered.

# Pattern Detective Tasks
1. Display the original readings in the order entered.
2. Calculate the sum and average, then identify the minimum and maximum readings.
3. Find the second-largest DISTINCT value. Repeated copies of the maximum do not count as the second-largest value. If no second-largest distinct value exists, display a clear message. 
4. Count the local peaks. A local peak is an interior element that is strictly greater than both its immediate neighbours. The first and last elements cannot be peaks.
5. Find the length of the longest strictly increasing contiguous run. The values must be next to each other in the original array. If no increase occurs, the longest run has length 1.
6. Ask for an integer K and rotate the array right by K positions. Positive K rotates right; negative K rotates left. The program must work when the magnitude of K is greater than N. Do not use a second array.
7. Let R be the last two numeric digits of your registration number. Calculate D = (R % 9) + 1, then count how many values in the rotated array are exactly divisible by D. Display D and the count.

# Algorithm
1. start
2. Read N until the user enters -1.
 * If N-1, terminate the program.
 * If N is not between 5 and 12, display an error message and repeat.
 * Repeat until user enters -1:
3. Create an array a[N].
 * Input readings:
 * For each reading, validate that it is between 0 and 1000.
 * If invalid, ask for the value again.
4. Display all original readings.
5. Calculate:
 * Sum of readings.
 * Average of readings.
 * Maximum value.
 * Minimum value.
6. Find the second-largest distinct value:
  *Identify the maximum value.
  *Find the largest value different from the maximum.
  *If none exists, display a suitable message.
7. Count local peaks:
 * For each element except the first and last:
 * If the current value is greater than both neighbors, count it as a peak.
8. Find the longest strictly increasing contiguous run:
 * Compare each element with the previous one.
 * Count consecutive increasing values.
 * Store the maximum run length.
9. Rotate the array:
 * Input rotation value K.
 * Normalize K using K mod N.
 * Rotate the array to the right by K positions.
 * Display the rotated array.
10. Calculate : D
 * Read R value  
 * D=(R%9)+1
 * count elements divisible by D
 * Display:
 * Value of D
 * Count of values divisible by D
11. Stop

