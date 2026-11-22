#include <stdio.h>

#define ZONES 5
#define DAYS 7

void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay);
void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays, int *totalExcess, int *spikeDays, int *alertDays);
void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES], int spikeByZone[ZONES], int alertByZone[ZONES]);
void rankZones(int excessByZone[ZONES]);
void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES]);

int main(void) {
int usage[ZONES][DAYS];
int dailyTarget[ZONES];
int excessByZone[ZONES] = {0};
int overLimitByZone[ZONES] = {0};
int spikeByZone[ZONES] = {0};
int alertByZone[ZONES] = {0};
int auditDone = 0;
int choice;

 inputWaterData(usage, dailyTarget);
do {
printf("\n1. Display Water Data\n");
printf("2. Generate Audit Report\n");
printf("3. Rank Zones by Excess\n");
printf("4. Conservation Actions\n");
printf("5. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
displayWaterData(usage, dailyTarget);
break;
case 2:
generateAuditReport(usage, dailyTarget, excessByZone, overLimitByZone, spikeByZone, alertByZone);
auditDone = 1;
break;
case 3:
if (auditDone==1) {
rankZones(excessByZone);
} else {
printf("Please generate the audit report (Option 2) first.\n");
}
break;
case 4:
if (auditDone==1) {
displayConservationActions(overLimitByZone, spikeByZone, excessByZone);
} else {
printf("Please generate the audit report (Option 2) first.\n");
}
break;
case 5:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please enter 1 to 5.\n");
break;
}} while (choice != 5);
    return 0;
}

void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]) {
int i, j;
for (i = 0; i < ZONES; i++) {
do {
printf("Enter daily target (100-50000) for ");
if (i == 0) printf("Academic Block: ");
else if (i == 1) printf("Hostel: ");
else if (i == 2) printf("Library: ");
else if (i == 3) printf("Cafeteria: ");
else if (i == 4) printf("Sports Complex: ");
scanf("%d", &dailyTarget[i]);
if (dailyTarget[i] < 100 || dailyTarget[i] > 50000) {
printf("Invalid target. Re-enter.\n");
}
} while (dailyTarget[i] < 100 || dailyTarget[i] > 50000);
}
printf("\n");
for (i = 0; i < ZONES; i++) {
for (j = 0; j < DAYS; j++) {
do {
printf("Enter reading (0-50000) for ");
if (i == 0) printf("Academic Block, Day %d: ", j + 1);
else if (i == 1) printf("Hostel, Day %d: ", j + 1);
else if (i == 2) printf("Library, Day %d: ", j + 1);
else if (i == 3) printf("Cafeteria, Day %d: ", j + 1);
else if (i == 4) printf("Sports Complex, Day %d: ", j + 1);
scanf("%d", &usage[i][j]);
if (usage[i][j] < 0 || usage[i][j] > 50000) {
printf("Invalid reading. Re-enter.\n");
}} while (usage[i][j] < 0 || usage[i][j] > 50000);
}printf("\n");}}

void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]) {
int i, j;

printf("\nZone            Day1  Day2  Day3  Day4  Day5  Day6  Day7  Target\n");
for (i = 0; i < ZONES; i++) {
if (i == 0) printf("%-15s", "Academic Block");
else if (i == 1) printf("%-15s", "Hostel");
else if (i == 2) printf("%-15s", "Library");
else if (i == 3) printf("%-15s", "Cafeteria");
else if (i == 4) printf("%-15s", "Sports Complex");
for (j = 0; j < DAYS; j++) {
printf(" %5d", usage[i][j]);
}printf(" %7d\n", dailyTarget[i]);
}}

void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay) {
int i, sum = 0, maxVal = *(zoneUsage + 0);
int maxDay = 1;
for (i = 0; i < DAYS; i++) {
int val = *(zoneUsage + i);
sum += val;
if (val > maxVal) {
maxVal = val;
maxDay = i + 1;
}}
*total = sum;
*average = (float)sum / DAYS;
*peakUsage = maxVal;
*peakDay = maxDay;
}

void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays, int *totalExcess, int *spikeDays, int *alertDays) {
int i,overCount = 0,excessSum = 0,spikeCount = 0,uniqueAlerts = 0;
for (i = 0; i < DAYS; i++) {
int curr = *(zoneUsage + i);
int over = 0;
int spike = 0;
if (curr > dailyTarget) {
over = 1;
overCount++;
excessSum += (curr - dailyTarget);}
if (i > 0) {
int previous = *(zoneUsage + (i - 1));
if (curr > previous * 1.40) {
spike = 1;
spikeCount++;
}}
if (over || spike) {
uniqueAlerts++;
}}
*overLimitDays = overCount;
*totalExcess = excessSum;
*spikeDays = spikeCount;
*alertDays = uniqueAlerts;
}

void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES], int spikeByZone[ZONES], int alertByZone[ZONES]) {
int i;
for (i = 0; i < ZONES; i++) {
int total, peakUsage, peakDay;
float average;
int overLimitDays, totalExcess, spikeDays, alertDays;

calculateZoneStats(&usage[i][0], &total, &average, &peakUsage, &peakDay);
detectWaterAlerts(&usage[i][0], dailyTarget[i], &overLimitDays, &totalExcess, &spikeDays, &alertDays);
if (i == 0) printf("\nZone: Academic Block\n");
else if (i == 1) printf("\nZone: Hostel\n");
else if (i == 2) printf("\nZone: Library\n");
else if (i == 3) printf("\nZone: Cafeteria\n");
else if (i == 4) printf("\nZone: Sports Complex\n");
printf(" Weekly Total: %d L\n", total);
printf("Daily Average: %.2f L\n", average);
printf("Highest Consumption: %d L on Day %d\n", peakUsage, peakDay);
printf("Over-Limit Days: %d\n", overLimitByZone[i]);
printf("Total Excess: %d L\n", excessByZone[i]);
printf("Sudden-Spike Days: %d\n", spikeByZone[i]);
printf("Unique Alert Days: %d\n", alertByZone[i]);
}}
void rankZones(int excessByZone[ZONES]) {
int z, i, maxExcess = excessByZone[0];
for (z = 1; z < ZONES; z++) {
if (excessByZone[z] > maxExcess) {
maxExcess = excessByZone[z];
}}
printf("\nZone(s) with greatest total excess (%d L):\n", maxExcess);
for (z = 0; z < ZONES; z++) {
if (excessByZone[z] == maxExcess) {
if (z == 0) printf("  Academic Block\n");
else if (z == 1) printf("  Hostel\n");
else if (z == 2) printf("  Library\n");
else if (z == 3) printf("  Cafeteria\n");
else if (z == 4) printf("  Sports Complex\n");
}}
printf("\nRanking (Highest to Lowest Excess):\n");
for (z = 0; z < ZONES; z++) {
int rank = 1;
for (i = 0; i < ZONES; i++) {
if (excessByZone[i] > excessByZone[z]) {
rank++;
}}
if (z == 0) printf("  Rank %d: %-15s (%d L)\n", rank, "Academic Block", excessByZone[z]);
else if (z == 1) printf("  Rank %d: %-15s (%d L)\n", rank, "Hostel", excessByZone[z]);
else if (z == 2) printf("  Rank %d: %-15s (%d L)\n", rank, "Library", excessByZone[z]);
else if (z == 3) printf("  Rank %d: %-15s (%d L)\n", rank, "Cafeteria", excessByZone[z]);
else if (z == 4) printf("  Rank %d: %-15s (%d L)\n", rank, "Sports Complex", excessByZone[z]);
}}
void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES]) {
for (int i = 0; i < ZONES; i++) {
int alertDays = 0;
if (i == 0) printf("\nZone: Academic Block (Excess: %d L)\n", excessByZone[i]);
else if (i == 1) printf("\nZone: Hostel (Excess: %d L)\n", excessByZone[i]);
else if (i == 2) printf("\nZone: Library (Excess: %d L)\n", excessByZone[i]);
else if (i == 3) printf("\nZone: Cafeteria (Excess: %d L)\n", excessByZone[i]);
else if (i == 4) printf("\nZone: Sports Complex (Excess: %d L)\n", excessByZone[i]);
if (spikeByZone[i] > 0) {
printf("  - Check for a leak or unexpected use around the flagged days.\n");
alertDays += spikeByZone[i];}
if (overLimitByZone[i] >= 3) {
printf("  - Prioritise a water audit and reduction plan.\n");
alertDays += overLimitByZone[i];
} else if (overLimitByZone[i] == 1 || overLimitByZone[i] == 2) {
printf("  - Monitor those days and inspect taps or valves.\n");
alertDays += overLimitByZone[i];
}
if (alertDays == 0 && overLimitByZone[i] == 0 && spikeByZone[i] == 0) {
printf("  - Maintain current good practices.\n");
}}}

