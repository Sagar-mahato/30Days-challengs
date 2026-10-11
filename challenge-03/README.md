# Challenge 03: Smartcart "Calculate. Check. Decide."

# Problem Description
A student is purchasing items from an online store. Read the purchase amount, customer type (1 = Student, 2 = Regular Customer),and delivery distance in kilometres. Determine the discount and delivery charge using conditional statements. Display the purchase amount, discount amount, amount after discount, delivery charge, and final payable amount.

# Program Objectives
* Apply if, else if, else, relational/logical operators, and arithmetic expressions to solve a multi-condition decision-making problem.

# Algorithm
1. Start
2. Read customer type, purchase amount, delivery distance.
3. * If (type == 1 )
   then If amt >= 2000 then discount rate = 0.15 , otherwise , discount rate = 0.10 .
   * If (type == 2 )
   then If amt >= 3000 then discount rate = 0.08 , otherwise discount rate = 0.0
   * Otherwise, print "Invalid customer type entered." .
4. * If distance <= 5, charges = 40
   * otherwise if distance > 5 and distance <= 15, then charges = 70
   * Otherwise , charges = 100 
5. Display amount, discount amount , amount after discount, delivery charges, and final payable amount.
6. Stop
