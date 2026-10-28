#include <stdio.h>
int main() {
 int N;
 printf("Enter total number of tickets N (N must be 5<=N<=15) : ");
 scanf("%d", &N);
 while (N<5 || N>15) {
 printf("Invalid input. Please enter a number between 5 and 15: ");
 scanf("%d", &N);
 }
printf("\nEnter the ticket ID (from 1 to %d): \n", N);
 int i,ticketID[N];
for (int i = 0; i < N; i++) {
 do {
 printf("Enter ticket ID %d (1 to %d): ", i + 1, N);
 scanf("%d", &ticketID[i]);
 if (ticketID[i] < 1 || ticketID[i] > N) {
 printf("Out of range! Try again.\n");
}
}while (ticketID[i] < 1 || ticketID[i] > N);
}
printf("\nOriginal scan sequence\n");
 for(i=0; i<N; i++) {
   printf("%d ", ticketID[i]);
   }
printf("\nidentify the duplicate and the missing ticket ID\n");
 int duplicateID = -1, missingID = -1 ;
 for(int i=1; i<=N; i++) {
   int count = 0;
   for(int j=0; j<N; j++) {
     if(ticketID[j] == i ) {
     count++;
    }
  }
   if(count == 2 ) {
   duplicateID = i ;
   }
   if(count == 0) {
   missingID = i;
   }
 }
if (duplicateID == -1 || missingID == -1) {
   printf("Scan log is invalid,(record must contain only 1 dulpicate ID and 1 missing ID  )\n");
   return 0;
}
printf("\nDuplicate ID: %d\n", duplicateID);
printf("Missing ID: %d\n", missingID);
printf("\nCount the out of order tickets\n");
int outoforder = 0;
 for (int i = 0; i < N - 1; i++) {
   for (int j = i + 1; j < N; j++) {
     if (ticketID[i] > ticketID[j]) {
      outoforder++;
      printf("%d at postion %d , %d at postion %d\n", ticketID[i], i+1, ticketID[j], j+1);
      }
    }
  }
printf("Out-of-order pairs count: %d\n", outoforder);
printf("\npersonalised audit ticket\n");
int target,R,targetcount=0 ;
printf("Enter the last two numeric digits of your registration number: ");
scanf("%d", &R);
target=(R%N)+1;
printf("The target ID = %d\n", target);
for(int i = 0 ; i < N ; i++)
{
    if (ticketID[i] == target ){
        targetcount++;
       printf("Its postion at %d\n ", i+1);
}
}
printf("So the target occurrence count is %d\n", targetcount);
return 0;
}
