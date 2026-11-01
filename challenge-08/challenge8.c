#include <stdio.h>
int main(){
int N;
printf("Enter the grid size (3 <= N <= 6):");
scanf("%d", &N);
while ( N < 3 || N > 6){
printf("Invalid input , Again enter the grid size : ");
scanf("%d", &N);
}
printf ("\nEnter the risk score (from 0(no risk) to 100( highest risk) )\n");           
int i,j,risk[N][N];
for(i=0;i<N;i++){
for(j=0;j<N;j++){
do {
printf("Enter score [%d][%d]: ", i, j);
scanf("%d", &risk[i][j]);
if (risk[i][j] < 0 || risk[i][j] > 100)
printf("Invalid score! Enter 0 to 100.\n");
} while (risk[i][j] < 0 || risk[i][j] > 100);
}
}
int T;
printf("Enter the warning threshold T (from 1 to 100 ): ");
scanf("%d", &T);
while ( T < 1 ||  T > 100){
printf("Invalid input , Again enter the grid size : ");
scanf("%d", &T);
}
printf("\n Grid \n");
for(i=0;i<N;i++){
for(j=0;j<N;j++){
printf(" %d ", risk[i][j]);
}
printf("\n");
}
printf("\n1.Row Traveral\n");
int row=0,rowmax=0;
for(int i=0;i<N;i++){
row=0;
for(int j=0;j<N;j++){
row+=risk[i][j];}
printf("Row %d total : %d \n", i+1, row);
if (row>rowmax)
rowmax = row;}
printf(" Highest row total = %d\n", rowmax);
for(int i=0;i<N;i++){
row=0;
for(int j=0;j<N;j++){
row+=risk[i][j];}
if (row==rowmax)
printf("Highest row number(s): %d \n", i+1);
}
printf("\n2.Column Traveral\n");
int col=0,colmax=0;
for(int j=0;j<N;j++){
col=0;
for(int i=0;i<N;i++){
col+=risk[i][j];}
printf("Column %d total : %d \n", j+1, col);
if (col>colmax)
colmax = col;}
printf("Highest column total = %d\n", colmax);
for(int j=0;j<N;j++){
col=0;
for(int i=0;i<N;i++){
col+=risk[i][j];}
if (col==colmax)
printf("Highest column number(s): %d \n", j+1);
}
printf("\n3.Full Grid Traversal\n");
int highest = risk[0][0], count=0;
for (int i = 0; i < N; i++){
for (int j = 0; j < N; j++){
if (risk[i][j] > highest)
highest = risk[i][j];
if (risk[i][j] >= T)
count++;}}
printf("Highest risk score = %d\n", highest);
printf("Position of highest score:\n");
for (int i=0;i<N;i++){
for (int j=0;j<N;j++){
if (risk[i][j] == highest)
printf("(%d, %d)\n", i + 1, j + 1);}}
printf("Cells meeting threshold = %d\n", count);
printf("\n4.Diagonal traversal\n");
int maindiag=0,secdiag=0;
for (int i=0;i<N;i++){
maindiag += risk[i][i];
secdiag += risk[i][N-1-i];
}
printf("Main diagonal sum = %d\n", maindiag);
printf("Secondary diagonal sum = %d\n", secdiag);
if (maindiag == secdiag)
printf("Diagonal totals are balanced.\n");
else
printf("Diagonal totals are not balanced.\n");
printf("\n5.Boundary Traversal\n");
int boundary = 0;
for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
if(i == 0 || i == N-1 || j == 0 || j == N-1){
boundary += risk[i][j];}
}}
printf("Boundary sum = %d\n", boundary);
printf("\n6.Neighbor Traversal\n");
int hotspot=0;
for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
if(risk[i][j]>=T&&risk[i][j]>risk[i-1][j]&&risk[i][j]>risk[i+1][j]&&risk[i][j]>risk[i][j-1]&&risk[i][j]>risk[i][j+1]){{
printf("Hotspot at (%d, %d) and risk score %d\n", i+1, j+1, risk[i][j]);
hotspot++;
}}}}
if(hotspot==0)
printf("No hotspot found\n");
printf("\n7.Decision Making\n");
if (hotspot>0)
printf("CRITICAL\n");
else if (count>=N)
printf("WARNING\n");
else {
printf("NORMAL\n");
}
return 0;
}
