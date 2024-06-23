#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

void searchbyCity(std::string city_name, int city, int is_country, int which_country); // function declarations
void searchbyCountry(int country); 
int fetchWeatherData(std::string url); 
int whichcity(std::string city_name);
int whichcountry(std::string city_name); 
int counter = 0; // counter for knowing which index to display 

int main()
{
    std::cout << "****************************\n";
    std::cout << "World Wide Weather Tracking\n";// title
    std::cout << "****************************\n\n";

    int user_input;
    int country;
    std::string city;

    std::cout << "1. Search by Country\n" << "2. Search by City\n";
    std::cin >> user_input;

    switch(user_input)
    {
        case 1: // search by country
            std::cout << "1. Australia\n";
            std::cout << "2. United States\n";
            std::cout << "3. China\n";
            std::cout << "4. United Kingdom\n";            
            std::cout << "Please Enter a Country to search for: \n";
            std::cin >> country;
            searchbyCountry(country);
            break;
        case 2: // search by city            
            std::cout << "Please enter a City to search for: \n";
            std::cin >> city;
            searchbyCity(city, whichcity(city), 0, whichcountry(city));
            break;
        default: // invalid input
            std::cout << "Invalid Input\n";
    }

    return 0;
}

void searchbyCity(std::string city_name, int city, int is_country, int which_country) // functionality locations
{
    std::cout << "Searching Weather Data for " << city_name << "\n";
    // country urls, 
    std::string australia_urls[] = {
        "https://api.open-meteo.com/v1/forecast?latitude=-33.8678&longitude=151.2073&hourly=temperature_2m&timezone=Australia%2FSydney", // Sydney
        "https://api.open-meteo.com/v1/forecast?latitude=-12.4611&longitude=130.8418&hourly=temperature_2m&timezone=Australia%2FSydney", // Darwin
        "https://api.open-meteo.com/v1/forecast?latitude=-37.814&longitude=144.9633&hourly=temperature_2m&timezone=Australia%2FSydney", // Melbourne
        "https://api.open-meteo.com/v1/forecast?latitude=-34.9287&longitude=138.5986&hourly=temperature_2m&timezone=Australia%2FSydney", // Adelaide
        "https://api.open-meteo.com/v1/forecast?latitude=-31.9522&longitude=115.8614&hourly=temperature_2m&timezone=Australia%2FSydney", // Perth
        "https://api.open-meteo.com/v1/forecast?latitude=-27.4679&longitude=153.0281&hourly=temperature_2m&timezone=Australia%2FSydney", // Brisbane
        "https://api.open-meteo.com/v1/forecast?latitude=-42.8794&longitude=147.3294&hourly=temperature_2m&timezone=Australia%2FSydney", // Hobart
        "https://api.open-meteo.com/v1/forecast?latitude=-35.2835&longitude=149.1281&hourly=temperature_2m&timezone=Australia%2FSydney" // Canberra
    };
    std::string usa_urls[] = {
        "https://api.open-meteo.com/v1/forecast?latitude=40.7143&longitude=-74.006&hourly=temperature_2m&timezone=Australia%2FSydney", // New York City
        "https://api.open-meteo.com/v1/forecast?latitude=34.0522&longitude=-118.2437&hourly=temperature_2m&timezone=Australia%2FSydney", // Los Angeles
        "https://api.open-meteo.com/v1/forecast?latitude=25.7743&longitude=-80.1937&hourly=temperature_2m&timezone=Australia%2FSydney", // Miami
        "https://api.open-meteo.com/v1/forecast?latitude=41.85&longitude=-87.65&hourly=temperature_2m&timezone=Australia%2FSydney" // Chicago
    };
    std::string china_urls[] = {
        "https://api.open-meteo.com/v1/forecast?latitude=29.5603&longitude=106.5577&hourly=temperature_2m&timezone=Australia%2FSydney", // Chongqing
        "https://api.open-meteo.com/v1/forecast?latitude=31.2222&longitude=121.4581&hourly=temperature_2m&timezone=Australia%2FSydney", // Shanghai
        "https://api.open-meteo.com/v1/forecast?latitude=39.9075&longitude=116.3972&hourly=temperature_2m&timezone=Australia%2FSydney", // Beijing
        "https://api.open-meteo.com/v1/forecast?latitude=30.6667&longitude=104.0667&hourly=temperature_2m&timezone=Australia%2FSydney", // Chengdu
        "https://api.open-meteo.com/v1/forecast?latitude=23.1167&longitude=113.25&hourly=temperature_2m&timezone=Australia%2FSydney", // Guangzhou
        "https://api.open-meteo.com/v1/forecast?latitude=22.2669&longitude=114.1788&hourly=temperature_2m&timezone=Australia%2FSydney", // Hong Kong
        "https://api.open-meteo.com/v1/forecast?latitude=22.2006&longitude=113.5461&hourly=temperature_2m&timezone=Australia%2FSydney" // Macau
    };
    std::string uk_urls[] = {
        "https://api.open-meteo.com/v1/forecast?latitude=51.5085&longitude=-0.1257&hourly=temperature_2m&timezone=Australia%2FSydney", // London
        "https://api.open-meteo.com/v1/forecast?latitude=53.4106&longitude=-2.9779&hourly=temperature_2m&timezone=Australia%2FSydney", // Liverpool
        "https://api.open-meteo.com/v1/forecast?latitude=53.4809&longitude=-2.2374&hourly=temperature_2m&timezone=Australia%2FSydney" // Manchester
    };

    switch(is_country)
    {
        case 0:
            // search for a specific city using our arrays
            switch(which_country)
            {
                // 0 = Australia
                // 1 = United States
                // 2 = China
                // 3 = United Kingdom
                case 0:
                    // use australia_urls[city]
                    std::cout << australia_urls[city] << "\n"; // Debug output to test url arrays work
                    break;
                case 1:
                    // use usa_urls[city]
                    std::cout << usa_urls[city] << "\n"; // Debug output to test url arrays work
                    break;
                case 2:
                    // use china_urls[city]
                    std::cout << china_urls[city] << "\n"; // Debug output to test url arrays work
                    break;
                case 3:
                    // use uk_urls[city]
                    std::cout << uk_urls[city] << "\n"; // Debug output to test url arrays work
                    break;
                default:
                    // something went wrong
                    break;
            }
            break;
        case 1:
            switch(which_country)
            {
                // 0 = Australia
                // 1 = United States
                // 2 = China
                // 3 = United Kingdom
                case 0:
                    // use australia_urls[counter]
                    std::cout << australia_urls[counter] << "\n"; // Debug output to test url arrays work
                    break;
                case 1:
                    // use usa_urls[counter]
                    std::cout << usa_urls[counter] << "\n"; // Debug output to test url arrays work
                    break;
                case 2:
                    // use china_urls[counter]
                    std::cout << china_urls[counter] << "\n"; // Debug output to test url arrays work
                    break;
                case 3:
                    // use uk_urls[counter]
                    std::cout << uk_urls[counter] << "\n"; // Debug output to test url arrays work
                    break;
                default:
                    // something went wrong
                    break;
            }
            break;
        default:
            // something has gone wrong if this happens
            break;
    }
    counter += 1; // use counter to determine which city we are searching for and what url to use
}

void searchbyCountry(int country) // functionality locations
{
    switch(country)
    {
        case 1:
            std::cout << "****************************\n";
            std::cout << "Weather Data for Australia\n";
            std::cout << "****************************\n";
            // list capital cities of Australia 
            searchbyCity("Sydney", 0, 1, 0); // index in our array, are we searching by country?, what country are we searching?
            searchbyCity("Darwin", 1, 1, 0);            
            searchbyCity("Melbourne", 2, 1, 0);
            searchbyCity("Adelaide", 3, 1, 0);
            searchbyCity("Perth", 4, 1, 0);
            searchbyCity("Brisbane", 5, 1, 0);
            searchbyCity("Hobart", 6, 1, 0);
            searchbyCity("Canberra", 7, 1, 0);
            break;
        case 2:
            std::cout << "****************************\n";
            std::cout << "Weather Data for United States\n";
            std::cout << "****************************\n";
            // probably just LA, NYC, Miami and Chicago
            searchbyCity("New York City",0, 1, 1);
            searchbyCity("Los Angeles",1, 1, 1);
            searchbyCity("Miami",2, 1, 1);
            searchbyCity("Chicago", 3, 1, 1); 
            break;
        case 3:
            std::cout << "****************************\n";
            std::cout << "Weather Data for China\n";
            std::cout << "****************************\n";
            // list top five biggest cities and include Hong Kong and Macau
            searchbyCity("Chongqing",0, 1, 2);
            searchbyCity("Shanghai",1, 1, 2);
            searchbyCity("Beijing",2, 1, 2);
            searchbyCity("Chengdu",3, 1, 2);
            searchbyCity("Guangzhou",4, 1, 2);
            searchbyCity("Hong Kong",5, 1, 2);
            searchbyCity("Macau",6, 1, 2);
            break;
        case 4:
            std::cout << "****************************\n";
            std::cout << "Weather Data for United Kingdom\n";
            std::cout << "****************************\n";
            // Liverpool, London, Manchester
            searchbyCity("London",0, 1, 3);
            searchbyCity("Liverpool",1, 1, 3);
            searchbyCity("Manchester",2, 1, 3);
            break;
        default:
            std::cout << "Error! Invalid Input!\n";
            break;
    }
}

int whichcity(std::string city_name) 
{
    int specified_city;
    if(city_name == "Sydney" || city_name == "New York" || city_name == "Chongqing" || city_name == "London")
    {
        specified_city = 0;
    }
    else if(city_name == "Darwin" || city_name == "Los Angeles" || city_name == "Shanghai" || city_name == "Liverpool")
    {
        specified_city = 1;
    }
    else if(city_name == "Melbourne" || city_name == "Miami" || city_name == "Beijing" || city_name == "Manchester")
    {
        specified_city = 2;
    }
    else if(city_name == "Adelaide" || city_name == "Chicago" || city_name == "Chengdu")
    {
        specified_city = 3;
    }
    else if(city_name == "Perth" || city_name == "Guangzhou")
    {
        specified_city = 4;
    }
    else if(city_name == "Brisbane" || city_name == "Hong Kong")
    {
        specified_city = 5;
    }
    else if(city_name == "Hobart" || city_name == "Macau")
    {
        specified_city = 6;
    }
    else if(city_name == "Canberra")
    {
        specified_city = 7;
    }
    else
    {
        std::cout << "City Not Found";
        specified_city = -1; // Add an error value
    }
    return specified_city;
}

int whichcountry(std::string city_name)
{
    int country;

    if(city_name == "Sydney" || city_name == "Darwin" || city_name == "Melbourne" || city_name == "Adelaide" || city_name == "Perth" || city_name == "Brisbane" || city_name == "Hobart" || city_name == "Canberra")
    {
        country = 0;
    }
    else if(city_name == "New York" || city_name == "Los Angeles" || city_name == "Miami" || city_name == "Chicago")
    {
        country = 1;
    }
    else if(city_name == "Chongqing" || city_name == "Shanghai" || city_name == "Beijing" || city_name == "Chengdu" || city_name == "Guangzhou" || city_name == "Hong Kong" || city_name == "Macau")
    {
        country = 2;
    }
    else if(city_name == "London" || city_name == "Liverpool" || city_name == "Manchester")
    {
        country = 3;
    }
    else
    {
        // something went wrong
        country = -1; // Add an error value
    }
    return country;
}
