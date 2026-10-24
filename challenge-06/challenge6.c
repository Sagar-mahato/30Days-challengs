#include <stdio.h>
int main(){
int N ;
while (1){

printf("Enter the total no reading (N between 5 and 12) (enter -1 to exit) :");
scanf("%d", &N);

if (N>=5 && N<=12)
{
// Input readings with validation
int i, a[N];
for(i=0;i<N;i++){
 do{
 printf("Enter reading %d (0-1000): ", i + 1);
 scanf("%d", &a[i]);
 } while (a[i] < 0 || a[i] > 1000);
}
// 1. Display original readings
printf("\nOriginal readings\n");
for(i=0;i<N;i++){
 printf("%d ", a[i]);
}
printf("\n");
// 2. Calculate sum, average, min, and max
int sum=0,min=a[0],max=a[0];
for(i=0;i<N;i++){
sum+=a[i];
if(a[i] < min)
min=a[i];
else if (a[i] > max )
max=a[i];
}
printf("\nThe sum of the readings: %d\n", sum);
printf("The average of the reading: %.2f\n", (float)sum/N);
printf("The maximum value : %d\n", max);
printf("The minimum value : %d\n", min);
// 3. Find Second-Largest Distinct Value
int secondlargest=-1;
for (i=0;i<N;i++){
if (a[i] != max){
 if (a[i] > secondlargest)
 secondlargest = a[i];}
}
if (secondlargest == -1)
printf("\nNo second largest distinct value exists.\n");
else
printf("\nSecond largest distinct value = %d\n", secondlargest);
// 4. Count Local Peaks
int peakcount=0;
for (i=1;i<N-1;i++){
if (a[i]>a[i-1] && a[i]>a[i+1])
peakcount++;
}
printf("\n Number of local peaks:%d\n", peakcount);
// 5. Find Longest Strictly Increasing Contiguous Run
int run=1,longestrun=1;
for(i = 1; i < N; i++){
if(a[i] > a[i-1]){
run++;
if(run > longestrun)
longestrun = run;}
else{
run = 1;
}
}
printf("\nLongest increasing contiguous run length = %d\n",longestrun);
// 6. Rotate array
int K;
printf("\nEnter K for rotation: ");
scanf("%d", &K);
K%=N;
if (K<0)
K+=N;
for (i=0;i<K;i++){
int temp = a[N-1];
for (int j =N-1;j>0;j--)
{
a[j] = a[j  - 1];
}
a[0] = temp;
}
printf("\nRotated array:\n");
for (i = 0; i < N; i++){
printf("%d ", a[i]);}
printf("\n");
// 7. Calculate D and count divisible values
int R,count=0;
printf("\nEnter the last two numeric digits of your registration number: ");
scanf("%d", &R);
int D=(R%9)+1;
for (i=0;i<N;i++){
if (a[i]%D==0){
count++;
}
}
printf("\nD = %d", D);
printf("\nCount divisible by D = %d\n", count);
}
else if (N==-1)
{ break;}
else
printf ("Invalid input, enter again.\n");
}
return 0;
}
