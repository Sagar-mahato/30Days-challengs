# Challenge 05: EQUATION SOLVER+ "Choose. Calculate. Repeat."

# Problem Description
Create a menu-driven C program that lets a user choose a mathematical operation. After each operation, display the menu again. The program must stop only when the user selects Exit.

# Menu Options
* 1 Solve a linear equation (ax + b = 0) : Calculate x, or identify no solution / infinitely many solutions.
* 2 Calculate factorial (n!) : Calculate factorial using a loop. Accept integers from 0 to 12 only.
* 3 Solve a quadratic equation (ax² + bx + c = 0) : Use the discriminant to identify the type of roots and calculate real roots.
* 4 Exit : Display a closing message and terminate the program.
  
# Algorithm
1. Start
2. Create a While loop for showing the menu-driven that let the user choice the operation to be preformed until user choice to exit.
     1. linear equation
     2. factorial
     3. quadratic equation
     4. exit
3. if choice < 1 or choice > 4 , exit from the loop.
4. Inside While loop use a switch case (choice) statements to performed each operation.
   1. if choice=1 , to solve the linear equation (ax + b = 0) . Read a and b value .
        * if a != 0 , x=-b/a . display x value.
        * if a=0 and b=0, display equation has infinitely many solution .
        * if a=0 and b!=0, display no solution.
   2. if choice = 2, to calculate factorial (n!) . Read n
        * if n<0 or n>12 . display invalid input.
        * otherwise , calculate factorial . display factorial.
        * And if n=0 then display factorial = 1.
   3. if choice=3 , to solve a quadratic equation (ax^2 + bx + c = 0). Read a , b and c. calculate discriminant (D) = (b*b) - 4*a*c .
      * if a=0 , display its a not quadratic equation.
      * if D>0 , root1= -b + sqrt(D)/2*a and root2= -b + sqrt(D)/2*a . display root are real and different , display root1 and root2.
      * if D=0 , root1=root2= -b /2*a . display roots are real and same , display root1.
      * if D<0 , display no real roots exist.
   4.  if choice=4 , Exit the loop , display exiting the program.
   5.  Stop 

