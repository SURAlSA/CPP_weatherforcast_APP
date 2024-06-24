import requests
from collections import defaultdict
from datetime import datetime
import os

# Step 1: Retrieve the JSON data from the URL
with open("url_file", "r") as file:
    url = file.read()
    
response = requests.get(url)

if response.status_code == 200:
    weather_data = response.json()
else:
    raise Exception(f"Failed to retrieve data: {response.status_code}")

# Step 2: Parse the JSON data
hourly_data = weather_data['hourly']
times = hourly_data['time']
temperatures = hourly_data['temperature_2m']

# Step 3: Organize data by day
daily_temperatures = defaultdict(list)

for time, temp in zip(times, temperatures):
    date = datetime.fromisoformat(time).date()
    daily_temperatures[date].append(temp)

# Step 4: Extract daily lowest and highest temperatures
readable_data = "Weather Report\n\n"

for date, temps in sorted(daily_temperatures.items()):
    lowest_temp = min(temps)
    highest_temp = max(temps)
    readable_data += f"{date}: Lowest Temperature: {lowest_temp}°C, Highest Temperature: {highest_temp}°C\n"

# Step 5: Write the formatted data to a file
output_file = 'formatted_weather_report'
with open(output_file, 'w') as file:
    file.write(readable_data)
os.remove("url_file")
