# Challenge 08: GRIDWATCH “Traverse the Grid. Detect the Risk.”

# Challenge Objective
Campus security has divided a high-traffic area into an N × N grid. Each cell stores a risk score from a sensor: 0 means no risk and 100 means the highest risk. You must build a C program called GRIDWATCH that traverses the grid in different ways to identify risky zones and recommend a response. This is not just a maximum-value problem: your solution must correctly analyse rows, columns, diagonals, boundaries, and neighbouring cells.

# Input Rules
Read N (3 ≤ N ≤ 6), then read N × N integer risk scores from 0 to 100. Ask the user for a warning threshold T (1 ≤ T ≤ 100). If any input is outside its permitted range, ask for that value again. Use one square two-dimensional array.

# Required Grid Traversals
1. Row traversal: calculate each row total and identify all row numbers with the highest total.
2. Column traversal: calculate each column total and identify all column numbers with the highest total.
3. Full-grid traversal: find the highest risk score, display every position where it occurs, and count how many cells have a score greater than or equal to T.
4. Diagonal traversal: calculate the main diagonal sum (top-left to bottom-right) and the secondary diagonal sum (top-right to bottom-left). If both sums are equal, report that the diagonal totals are balanced.
5. Boundary traversal: calculate the total of all boundary cells. Count each boundary cell exactly once, including corners.
6. Neighbour traversal: identify every local hotspot. A hotspot must be an interior cell whose value is strictly greater than its top, bottom, left, and right neighbours, and is also greater than or equal to T. Diagonal neighbours do not count.
7. Decision using conditions: display CRITICAL if at least one local hotspot exists; otherwise display WARNING if at least N cells meet or exceed T; otherwise display NORMAL.

# Algorithm
1. Start 
2. Input N until a valid value  (3<=N<=6)  is entered.
3. Input all N × N risk scores, ensuring each score is between 0 and 100.
4. Input threshold T, ensuring 1 <= T <=100.
5. Calculate the total of each row and determine the highest row total.
6. Calculate the total of each column and determine the highest column total.
7. Traverse the entire grid to:
  * Find the highest risk score.
  * Display all positions where it occurs.
8. Count cells whose value is greater than or equal to T.
   * Calculate:
    1. Main diagonal sum (top-left to bottom-right).
    2. Secondary diagonal sum (top-right to bottom-left).
   * Compare both sums and report whether they are balanced.
9. Traverse the boundary cells and calculate the total boundary risk.
10. Check all interior cells for local hotspots:
   * Cell value must be greater than top, bottom, left, and right neighbours.
   * Cell value must also be greater than or equal to T.
11. Apply decision rules:
   * If at least one hotspot exists : CRITICAL
   * Else if threshold count >= N : WARNING
   * Else : NORMAL
12. Stop 
