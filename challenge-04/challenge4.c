#include <stdio.h>
int main(){
int expense,count=0,small= 0, medium=0,large=0,smalltotal=0,mediumtotal=0,largetotal=0,overalltotal = 0;
while (1)
{
printf("Enter your daily expenses one by one (enter 0 to stop):\n");
printf("Expense amount:");
scanf("%d", &expense);

if (expense == 0)
{
break;
}
else if (expense > 0)
{
count++;
overalltotal += expense;
if (expense < 100) {
small++;
smalltotal+= expense;}
else if ( expense >=100 && expense < 500){
medium++;
mediumtotal += expense;}
else if (expense >= 500) {
large++;
largetotal+=expense;}
}
else{
printf("Invalid input. Please enter a positive amount or 0 to quit.\n");}
}
printf("Expense Summary:\n");
printf("Number of valid expenses: %d\n", count);
printf("Total of valid expenses: %d\n", overalltotal);
printf("Small expenses (below 100): Count = %d, Total = %d\n", small, smalltotal);
printf("Medium expenses (100 to below 500): Count = %d, Total = %d\n", medium, mediumtotal);
printf("Large expenses (500 or more): Count = %d, Total = %d\n", large, largetotal);
printf("Average valid expense: %.2f\n", (float)overalltotal / count);

return 0;
}
