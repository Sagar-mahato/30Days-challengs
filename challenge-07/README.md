# Challenge 07: TICKET TRACE “Scan. Detect. Verify.”

# Challenge Objective
A campus event uses ticket IDs from 1 to N. The scanner records N entries, but one ticket ID is missing and another ticket ID has been scanned twice. Your job is to audit the scan log, identify the missing and duplicate IDs, and measure how far the scan sequence is out of order. Plan your logic before writing code.

# Detailed Requirements
1. Display the original scan sequence.
2. Identify the duplicated ticket ID and the missing ticket ID. Do not sort the sequence and do not use a second array.
3. Count the out-of-order pairs. A pair of positions (i, j) is out of order when i < j and ticket[i] > ticket[j]. Count each pair of positions once. Equal values do not count as out of order.
4. Find your personalised audit ticket. Let R be the last two numeric digits of your registration number. Calculate Target = (R % N) + 1. Display the target ID, all its one-based positions in the original sequence, and its occurrence count.
5. If N or any ticket ID is outside its allowed range, ask for that value again. If the completed sequence does not contain exactly one missing ID and one duplicated ID, display an invalid-log message.
6. Use only a one-dimensional array, loops (including nested loops), and conditional statements. Do not use a second array, sorting functions, or hard coded outputs.

# Algorithm
1. Start
2. Read N (the total number of tickets).
3. While N < 5 or N > 15, display an error message and ask for N again.
4. Input N ticket IDs into the array ticketID[].
5. For each ticket ID:
   * If the ID is less than 1 or greater than N, display an error message and ask for the ID again.
6. Display the original scan sequence.
7. Find the duplicate and missing IDs:
8. For each ID from 1 to N:
   * Count its occurrences in the array.
   * If count = 2, store it as duplicateID.
   * If count = 0, store it as missingID.
   * Display the duplicate ID and missing ID.
9. If either duplicateID or missingID is not found:
   * Display "Scan log is invalid".
   * Stop the program.
10. Count out-of-order pairs:
   * Compare every ticket ID with entries to its right.
   * If ticketID[i] > ticketID[j], increment the out-of-order counter.
   * Display the pair.
11. Display the total number of out-of-order pairs.
12. Input the last two digits of the registration number R.
    * Calculate: Target = (R % N) + 1
    * Display the target ID.
14. Search the array for the target ID:
    * Display every position where it occurs.
    * Count its occurrences.
    * Display the occurrence count of the target ID.
15. Stop


