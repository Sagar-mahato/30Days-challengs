# Challenge 04: LOOPLAB "Repeat with logic. solve with precision."

# Problem Description
Create a C program called LOOPLAB to analyze daily expenses. Repeatedly read expense amounts until the user enters 0. For each positive amount, classify it using the rules below, update counts and totals, and finally display a summary. Use loops, conditional statements, arithmetic operators, and variables. Do not use arrays, functions, or strings.

# Required Summary
Display: (a) number of valid expenses, (b) total of valid expenses, (c) count and total for Small, Medium, and Large expenses, and (d) average valid expense. If no valid expenses were entered, display a suitable message instead of dividing by zero.

# Special Logic Requirements
Keep accepting input until 0 is entered. • Negative values must not affect any count or total. • Do not include 0 in calculations. • Classify valid expenses using conditions. • Choose a suitable loop and be ready to explain your choice.

# Algorithm
1. Start
2. while (true):
   * Read expense.
   * IF expense == 0,then exit the loop.
   * otherwise, if expense > 0 then Increment count and Add the total expense
   * then If expense < 100, Increment small count and Add to get the small expenses totals.
   * ELSE IF expense >= 100 && expense < 500,Increment medium count and Add to get the medium expenses total.
   * ELSE:Increment large count and  Add to get the large expenses total.
   * ELSE,Print “Invalid input. Please enter a positive amount or 0 to quit.
3.  Dispaly summary 
   * Number of valid expenses.
   * total of valid expenses.
   * Count and total for Small, Medium, Large expenses
   * Average valid expense = overallTotal / overallCount
4. Stop
   
