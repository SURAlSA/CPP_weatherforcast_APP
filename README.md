# Weather Forecast

**Weather Forecast** is a C++ Terminal-Based Application designed to track and display worldwide weather data. It allows users to search weather information by country or city, providing temperature forecasts for the upcoming week. (Developed for Linux operating systems)

---

## Features

### Weather Data Search
- **Country Search**: Allows users to search for weather data by country.
- **City Search**: Enables searching weather data for cities within the selected country.
- **Temperature Forecast**: Displays the lowest and highest temperatures for the next 7 days.

### User Interaction
- **Interactive Menu**: Easy-to-navigate menu to choose between country and city searches.
- **Dynamic Data Retrieval**: Fetches weather data and displays it in a user-friendly format.

---

## Installation

1. **Install the required dependencies**:
   - Install the nlohmann JSON library:
     ```bash
     sudo apt-get install nlohmann-json3-dev
     ```

2. **Compile the code**:
   - Ensure your terminal is in the same directory as `main.cpp`.
   - Compile the app using `g++`:
     ```bash
     g++ main.cpp -o weatherforcast
     ```

3. **Launch the Weather Forecast App**:
   - Run the compiled application:
     ```bash
     ./weatherforcast
     ```

---

## Usage

### Example Output:

 % ./weatherforcast
****************************
World Wide Weather Tracking
****************************

1. Search by Country
2. Search by City
1
1. Australia
2. United States
3. China
4. United Kingdom
Please Enter a Country to search for: 
2
****************************
Weather Data for United States
****************************
Searching Weather Data for New York City
Weather Report

2025-03-01: Lowest Temperature: 4.2°C, Highest Temperature: 11.0°C
2025-03-02: Lowest Temperature: -7.6°C, Highest Temperature: 14.6°C
2025-03-03: Lowest Temperature: -7.2°C, Highest Temperature: -1.2°C
2025-03-04: Lowest Temperature: -4.7°C, Highest Temperature: 2.6°C
2025-03-05: Lowest Temperature: 0.9°C, Highest Temperature: 6.7°C
2025-03-06: Lowest Temperature: 6.8°C, Highest Temperature: 9.5°C
2025-03-07: Lowest Temperature: 0.4°C, Highest Temperature: 9.6°C

Searching Weather Data for Los Angeles
Weather Report

2025-03-01: Lowest Temperature: 11.5°C, Highest Temperature: 21.9°C
2025-03-02: Lowest Temperature: 11.2°C, Highest Temperature: 16.5°C
2025-03-03: Lowest Temperature: 10.9°C, Highest Temperature: 16.9°C
2025-03-04: Lowest Temperature: 10.3°C, Highest Temperature: 17.9°C
2025-03-05: Lowest Temperature: 11.5°C, Highest Temperature: 19.1°C
2025-03-06: Lowest Temperature: 10.5°C, Highest Temperature: 19.0°C
2025-03-07: Lowest Temperature: 9.9°C, Highest Temperature: 18.6°C

Searching Weather Data for Miami
Weather Report

2025-03-01: Lowest Temperature: 15.0°C, Highest Temperature: 25.1°C
2025-03-02: Lowest Temperature: 14.1°C, Highest Temperature: 27.1°C
2025-03-03: Lowest Temperature: 16.4°C, Highest Temperature: 26.7°C
2025-03-04: Lowest Temperature: 21.3°C, Highest Temperature: 23.3°C
2025-03-05: Lowest Temperature: 22.5°C, Highest Temperature: 24.5°C
2025-03-06: Lowest Temperature: 22.5°C, Highest Temperature: 25.9°C
2025-03-07: Lowest Temperature: 20.9°C, Highest Temperature: 29.6°C

Searching Weather Data for Chicago
Weather Report

2025-03-01: Lowest Temperature: -4.8°C, Highest Temperature: 14.3°C
2025-03-02: Lowest Temperature: -8.6°C, Highest Temperature: -3.3°C
2025-03-03: Lowest Temperature: -8.4°C, Highest Temperature: 2.9°C
2025-03-04: Lowest Temperature: 0.4°C, Highest Temperature: 4.2°C
2025-03-05: Lowest Temperature: 4.1°C, Highest Temperature: 11.9°C
2025-03-06: Lowest Temperature: -1.2°C, Highest Temperature: 8.4°C
2025-03-07: Lowest Temperature: -0.9°C, Highest Temperature: 5.2°C


---

## Author
- Zane Miller (Surai) - Creator and Maintainer - [GitHub](https://github.com/SURAlSA)
