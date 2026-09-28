#include <stdio.h>
int main ()
{
  int d,m ;                                           //d=distane,m=mileage
  float a,b,c;                                        //a= fuel price,b=fuel required,c= total fuel cost

                                                      //asking vaules by user of distance, mileage, fuel price 
  printf("ENTER THE DISTANCE (Kilometer):\n");
  scanf("%d", &d);
  printf("ENTER THE MILEAGE (Kilometer/liter):\n");
  scanf("%d", &m);
  printf("ENTER THE FUEL PRICE (Per Liter):\n");
  scanf("%f", &a);

                                                      //doing calculation for fuel required and total fuel cost
  b=d/m;
  c=b*a;

                                                     //printing the values of fuel required and total fuel cost
 
 printf("THE FUEL REQUIERD:%f\n", b);
 printf("THE TOTAL FUEL COST:%f\n", c);

 return 0;
}

  
