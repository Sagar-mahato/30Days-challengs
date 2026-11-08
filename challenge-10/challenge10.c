#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]){
printf("\nInput Environmental Readings\n");
for (int i = 0; i < ZONES; i++){
if (i == 0)
printf("\nZone %d. Academic block:\n", i + 1);
else if (i == 1)
printf("\nZone %d. Hostel:\n", i + 1);
else if (i == 2)
printf("\nZone %d. Libary:\n", i + 1);
else if (i == 3)
printf("\nZone %d. cafeteria:\n", i + 1);
else
printf("\nZone %d. Sports Area:\n", i + 1);
for (int j = 0; j < DAYS; j++){
do {
printf("\nDay %d\ntemperature (10-50 C):", j + 1);
scanf("%f", &temp[i][j]);
if (temp[i][j] < 10 || temp[i][j] > 50){
printf("Invalid temperature. Please enter a value between 10 and 50.\n");
}
} while (temp[i][j] < 10 || temp[i][j] > 50);
do {
printf("\nDay %d\nhumidity (0-100):", j + 1);
scanf("%f", &humidity[i][j]);
if (humidity[i][j] < 0 || humidity[i][j] > 100){
printf("Invalid humidity. Please enter a value between 0 and 100.\n");}
} while (humidity[i][j] < 0 || humidity[i][j] > 100);
do {
printf("\nDay %d\nAQI (0-500):", j + 1);
scanf("%d", &aqi[i][j]);
if (aqi[i][j] < 0 || aqi[i][j] > 500){
printf("Invalid AQI. Please enter a value between 0 and 500.\n");}
} while (aqi[i][j] < 0 || aqi[i][j] > 500);
}}
printf("\nData input complete.\n");
}
void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]){
printf("\nCampus Environmental Data\n");
for (int i = 0; i < ZONES; i++){
if (i == 0)
printf("\nZone %d. Academic block:\n", i + 1);
else if (i == 1)
printf("\nZone %d. Hostel:\n", i + 1);
else if (i == 2)
printf("\nZone %d. Library:\n", i + 1);
else if (i == 3)
printf("\nZone %d. Cafeteria:\n", i + 1);
else if (i == 4)
printf("\nZone %d. Sports Area:\n", i + 1);
printf("\nMatrix   Day1  Day2   Day3   Day4   Day5   Day6   Day7\n");
printf("Temperature (C):");
for (int j = 0; j < DAYS; j++){
printf("  %.2f", temp[i][j]);
}
printf("\nHumidity (%%):");
for (int j = 0; j < DAYS; j++){
printf("  %.2f", humidity[i][j]);
}
printf("\nAQI:");
for (int j = 0; j < DAYS; j++){
printf("  %d", aqi[i][j]);
}
printf("\n");
}
}
void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]){
for (int i = 0; i < ZONES; i++){
float sumtemp = 0, sumhumidity = 0, sumaqi = 0;
for (int j = 0; j < DAYS; j++){
sumtemp += temp[i][j];
sumhumidity += humidity[i][j];
sumaqi += aqi[i][j];
}
avgTemp[i] = sumtemp / DAYS;
avgHumidity[i] = sumhumidity / DAYS;
avgAQI[i] = sumaqi / DAYS;
}}
void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS],int aqi[ZONES][DAYS], int riskDays[ZONES]){
printf("\nRisk Zone Detection\n");
for (int i = 0; i < ZONES; i++){
int count = 0;
int flagged[DAYS] = {0};
for (int j = 0; j < DAYS; j++){
if (temp[i][j]> 35.0 || humidity[i][j] > 80 || aqi[i][j] > 150 ){
count++;
flagged[j] = 1;
}}
riskDays[i] = count ;
printf("Zone %d: Total Risk Days: %d\n", i + 1, count);
if (count > 0){
printf("Risk Days: ");
for (int j = 0; j < DAYS; j++){
if (flagged[j] == 1){
printf("Day %d ", j + 1);
}}
printf("\n");
}}}
void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES],float avgAQI[ZONES], float greenIndex[ZONES]){
for (int i = 0; i < ZONES; i++){
float aqiscore = 100.0 -(avgAQI[i] / 5);
if (aqiscore < 0) {
aqiscore = 0;}
float tdiff;
if (avgTemp[i] > 25) { tdiff = avgTemp[i] - 25; }
else { tdiff = 25 - avgTemp[i]; }
float tempscore = 100.0 - (4 * tdiff);
if (tempscore < 0) {
tempscore = 0;}
float hdiff;
if (avgHumidity[i] >50) { hdiff = avgHumidity[i] - 50; }
else { hdiff = 50 - avgHumidity[i]; }
float humidityscore = 100.0 - ( 2 * hdiff);
if (humidityscore < 0) {
humidityscore = 0;}
greenIndex[i] = (0.4 * aqiscore) +(0.3 * tempscore) + (0.3 * humidityscore) ;
}}
void displayRanking(float greenIndex[ZONES]){
printf("\nGreen Index Ranking\n");
int rank[ZONES];
for (int i = 0; i < ZONES; i++){
int r =1;
for (int j = 0; j < ZONES; j++){
if (greenIndex[j] > greenIndex[i]){
r++;}}
rank[i] = r;
}
for (int r = 1 ; r<= ZONES; r++){
for (int i =0; i< ZONES; i++){
if (rank[i] == r){
printf("Rank %d: Zone %d (Academic block) - Green Index: %.2f\n", r, i + 1, greenIndex[i]);
}}}}
void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], int riskDays[ZONES]){
printf("\nRecommendations\n");
for (int i = 0; i < ZONES; i++){
printf("\nZone %d:\n", i + 1);
int risk=0;
if (avgTemp[i] > 35.0){
printf ("Suggest shaded or green cover");
risk=1; }
if (avgAQI[i]>150){
printf("Suggest reducing vehicle idling or improving ventilation");
risk=1;}
if (avgHumidity[i] > 80){
printf("Suggest checking ventilation or stagnant water sources");
risk=1;}
if (risk==0){
if (riskDays[i] > 0){
printf("Review individual day readings for specific issues.");}
else{
printf("Continue regular monitoring ");}}}
printf("\n");}
int main() {
float temp[ZONES][DAYS], humidity[ZONES][DAYS];
float avgTemp[ZONES], avgHumidity[ZONES], avgAQI[ZONES];
int riskDays[ZONES],aqi[ZONES][DAYS];
float greenIndex[ZONES];
int choice, dataready = 0;
do {
printf("\nEnvironmental Monitoring System\n");
printf("1. Input Data\n");
printf("2. Display Data\n");
printf("3. Zone-wise Averages\n");
printf("4. Risk Zone Detection\n");
printf("5. Green Index Calculation and Ranking\n");
printf("6. Recommendations\n");
printf("7. Exit\n");
printf("\nEnter your choice 1-7: ");
scanf("%d"                  , &choice);
switch (choice) {
case 1:
inputData(temp, humidity, aqi);
dataready = 1;
break;
case 2:
if (dataready==1) {
displayData(temp, humidity, aqi);
} else {
printf("Please input data first.\n");
}
break;
case 3:
 if (dataready==1) {
calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
printf("\nZone-wise Averages\n");
for (int i = 0; i < ZONES; i++) {
printf("Zone %d: Avg Temp: %.2f C, Avg Humidity: %.2f %%, Avg AQI: %.2f\n", i + 1, avgTemp[i], avgHumidity[i], avgAQI[i]);}
} else {
printf("Please input data first.\n");}
break;
case 4:
if (dataready==1) {
detectRiskZones(temp, humidity, aqi, riskDays);
} else {
printf("Please input data first.\n");}
break;
case 5:
if(dataready==0){
printf("Please input data first.\n");
} else {
calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
computeGreenIndex(avgTemp, avgHumidity, avgAQI, greenIndex);
displayRanking(greenIndex);
}
break;
case 6:
if(dataready==0){
printf("Please input data first.\n");
} else {
calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
detectRiskZones(temp, humidity, aqi, riskDays);
displayRecommendations(avgTemp, avgHumidity, avgAQI, riskDays);}
break;
case 7:
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please enter a number between 1 and 7.\n");
}
}while (choice != 7 || choice < 1 || choice > 7);
return 0;
}
