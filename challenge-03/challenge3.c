#include <stdio.h>
int main()
{
int type, charges;
float amt, discount, discount_amt = 0.0, amt_after_discount=0.0, distance, payable_amt = 0.0;
printf("Enter Customer Type (1 = Student, 2 = Regular Customer): ");
scanf("%d", &type);
printf("Enter Purchase Amount : ");
scanf("%f", &amt);
printf("Enter Delivery Distance (in km): ");
scanf("%f", &distance);
 if (type == 1) {
    if (amt >= 2000)
       discount = 0.15;
    else
       discount = 0.10;
}
else if (type == 2){
    if (amt >= 3000)
       discount = 0.08;
    else
       discount = 0;
}
else{
       printf("Invalid customer type entered.\n");}
if (distance <= 5){
       charges = 40;}
else if (distance > 5 && distance <= 15){
        charges = 70.0;}
else{
        charges = 100.0;}
discount_amt = amt * discount;
amt_after_discount = amt - discount_amt;
payable_amt = amt_after_discount + charges;

printf("Purchase Amount       : %.2f\n", amt);
printf("Discount Amount       : %.2f\n", discount_amt);
printf("Amount After Discount : %.2f\n", amt_after_discount);
printf("Delivery Charge       : %.d\n", charges);
printf("Final Payable Amount  : %.2f\n", payable_amt);

return 0;
}
