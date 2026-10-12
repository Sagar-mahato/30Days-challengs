# Challenge 03: LOOPLAB "Repeat with logic. solve with precision."

# Problem Description
Create a C program called LOOPLAB to analyse daily expenses. Repeatedly read expense amounts until the user enters 0. For each positive amount, classify it using the rules below, update counts and totals, and finally display a summary. Use loops, conditional statements, arithmeticoperators, and variables. Do not use arrays, functions, or strings.

# Required Summary
Display: (a) number of valid expenses, (b) total of valid expenses, (c) count and total for Small, Medium, and Large expenses, and (d) average valid expense. If no valid expenses were entered, display a suitable message instead of dividing by zero.

# Special Logic Requirements
Keep accepting input until 0 is entered. • Negative values must not affect any count or total. • Do not include 0 in calculations. • Classify valid expenses using conditions. • Choose a suitable loop and be ready to explain your choice.

# Algorithm
 1.Start
 2. if while (true):
   a. Read expense.
   b. IF expense == 0,then exit the loop.
   c. otherwise, if expense > 0 then Increment count and Add the total expense
      then If expense < 100, Increment small count and Add to get the small totals.
      ELSE IF expense >= 100 && expense < 500 Increment medium count and Add to get the medium total.
      ELSE:Increment large count and  Add to get the large total.
   d. ELSE (expense < 0 || expense == 0):
      Print “Invalid input. Please enter a positive amount or 0 to quit."
      3. dispaly    
   (a) Number of valid expenses.
   (b) Total of valid expenses.
   (c) Count and total for Small, Medium, Large expenses
   (d) Average valid expense = overallTotal / overallCount
4. Stop
