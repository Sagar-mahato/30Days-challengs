# CHALLENGE 10: ECOGUARD “Monitor. Analyse. Act.”

# Challenge Objective
The university wants to understand environmental conditions across its campus and identify areas that may need attention. Develop a menu-driven C program that analyses seven days of temperature, humidity, and Air Quality Index (AQI) readings from five campus zones. Your program must turn the readings into a clear risk report, a Green Index ranking, and practical recommendations.

# Problem Statement
The campus is divided into five zones: 1 Academic Block, 2 Hostel, 3 Library, 4 Cafeteria, and 5 Sports Area. For each zone, record three environmental parameters for seven days. Store the readings in three separate two-dimensional arrays. The system must analyse the data through user-defined functions and help you to identify where an environmental improvement could make the greatest difference.
  
# Algorithm
1. Start 
2. Display the main menu.
3. Read the user's choice.
4. If the choice is Input Data:
 * Input temperature, humidity, and AQI for each zone and day.
 * Validate all inputs.
5. If the choice is Display Data:
 * Display the stored environmental data for all zones.
6. If the choice is Zone-wise Averages:
 * Calculate average temperature, humidity, and AQI for each zone.
 * Display the averages.
7. If the choice is Risk Zone Detection:
 * Check each day's readings.
 * Mark a day as risky if:
 * Temperature > 35°C, or
 * Humidity > 80%, or
 * AQI > 150.
 * Count and display total risk days.
8. If the choice is Green Index Calculation and Ranking:
 * Calculate average values.
 * Compute Green Index using AQI, temperature, and humidity scores.
 * Rank all zones according to their Green Index.
9. If the choice is Recommendations:
 * Analyze average values and risk days.
 * Display suitable recommendations.
10. If the choice is Exit, terminate the program.
11. Stop


