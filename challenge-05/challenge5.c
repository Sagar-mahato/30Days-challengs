#include <stdio.h>
#include <math.h>

int main()
{
int choice;
int start = 1;

while (start){
printf("\nEnter your choice to solve:\n");
printf("1. Linear equation\n");
printf("2. Factorial\n");
printf("3. Quadratic equation\n");
printf("4. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
if (choice < 1 || choice > 4) {
printf("Invalid input. Exiting.\n");
break;}
switch (choice)
{
case 1:
{
int a, b;
float x;
printf("To solve a linear equation (ax + b = 0)\n");
printf("Enter value of a and b: ");
scanf("%d %d", &a, &b);
if (a != 0){
x = (float)(-b) / a;
printf("The solution of the linear equation is x = %.2f\n", x);}
else if (a == 0 && b == 0){
printf("The equation has infinitely many solutions.\n");}
else{
printf("The equation has no solution.\n");}
break;
}
case 2:
{
int n,factorial = 1;
printf("To calculate factorial of a number\n");
printf("Enter a non-negative integer: ");
scanf("%d", &n);
if (n < 0 || n > 12) {
printf("Factorial is not defined for negative numbers or numbers greater than 12.\n");}
else {
for (int i = 1; i <= n; i++) {
factorial *= i; }
printf("Factorial of %d = %d\n", n, factorial); }
break; }
case 3:
{
float a, b, c, D, root1, root2;
printf("To solve a quadratic equation (ax^2 + bx + c = 0)\n");
printf("Enter coefficients a, b and c: ");
scanf("%f %f %f", &a, &b, &c);
if (a == 0) {
printf("Coefficient 'a' cannot be zero in a quadratic equation.\n");
break; }
D = (b * b) - (4 * a * c);
if (D > 0) {
root1 = ((-b) + sqrt(D)) / (2 * a);
root2 = ((-b) - sqrt(D)) / (2 * a);
printf("Roots are real and different.\n");
printf("Root 1 = %.2f\n", root1);
printf("Root 2 = %.2f\n", root2); }
else if (D == 0) {
root1 = root2 = (-b) / (2 * a);
printf("Roots are real and the same.\n");
printf("Root 1 = Root 2 = %.2f\n", root1); }
else {
printf("No real roots exist.\n"); }
break; }
case 4:
printf("Exiting the program.\n");
start = 0;
break;
}
}
return 0;
}
