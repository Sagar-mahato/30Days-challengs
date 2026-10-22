#include <stdio.h>
 
int main() {
    float sub1, sub2, sub3,sub4, sub5, total, average , percentage ;               
    printf("enter the marks of five subjects: ");                                  
    scanf("%f %f %f %f %f", &sub1, &sub2, &sub3, &sub4, &sub5);                   
    total = sub1 + sub2 + sub3 + sub4 + sub5;                                    
    average = total / 5;                                                        
    percentage = (total / 500) * 100;                                          
    printf("-------Results-------\n");                                        
    printf("total marks: %f\n", total);                                       
    printf("average marks: %f\n", average);                                 
    printf("percentage: %f\n", percentage);                                
    return 0;
}
