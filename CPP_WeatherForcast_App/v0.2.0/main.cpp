#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <map>
#include <vector>

// Current preperation for eventual functionality
void searchbyCity(std::string city, int is_country); // function declarations
void searchbyCountry(int country); // function declarations
int fetchWeatherData(std::string url); // function declarations

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
            searchbyCity(city, 0);
            break;
        default: // invalid input
            std::cout << "Invalid Input\n";
    }


    return 0;
}


void searchbyCity(std::string city, int is_country) // functionality locations
{
    std::cout << "Searching Weather Data for " << city << "\n";
    // country urls, 
    std::string australia_urls[] = {"https://api.open-meteo.com/v1/forecast?latitude=-33.8678&longitude=151.2073&hourly=temperature_2m&timezone=Australia%2FSydney", // Sydney
                                    "https://api.open-meteo.com/v1/forecast?latitude=-12.4611&longitude=130.8418&hourly=temperature_2m&timezone=Australia%2FSydney", // Darwin
                                    "https://api.open-meteo.com/v1/forecast?latitude=-37.814&longitude=144.9633&hourly=temperature_2m&timezone=Australia%2FSydney", // Melbourne
                                    "https://api.open-meteo.com/v1/forecast?latitude=-34.9287&longitude=138.5986&hourly=temperature_2m&timezone=Australia%2FSydney", // Adelaide
                                    "https://api.open-meteo.com/v1/forecast?latitude=-31.9522&longitude=115.8614&hourly=temperature_2m&timezone=Australia%2FSydney", // Perth
                                    "https://api.open-meteo.com/v1/forecast?latitude=-27.4679&longitude=153.0281&hourly=temperature_2m&timezone=Australia%2FSydney", // Brisbane
                                    "https://api.open-meteo.com/v1/forecast?latitude=-42.8794&longitude=147.3294&hourly=temperature_2m&timezone=Australia%2FSydney", // Hobart
                                    "https://api.open-meteo.com/v1/forecast?latitude=-35.2835&longitude=149.1281&hourly=temperature_2m&timezone=Australia%2FSydney" // Canberra
                                    };
    std::string usa_urls[] = {"https://api.open-meteo.com/v1/forecast?latitude=40.7143&longitude=-74.006&hourly=temperature_2m&timezone=Australia%2FSydney", // New York City
                              "https://api.open-meteo.com/v1/forecast?latitude=34.0522&longitude=-118.2437&hourly=temperature_2m&timezone=Australia%2FSydney", // Los Angeles
                              "https://api.open-meteo.com/v1/forecast?latitude=25.7743&longitude=-80.1937&hourly=temperature_2m&timezone=Australia%2FSydney", // Miami
                              "https://api.open-meteo.com/v1/forecast?latitude=41.85&longitude=-87.65&hourly=temperature_2m&timezone=Australia%2FSydney" // Chicago
                                };
    std::string china_urls[] = {"https://api.open-meteo.com/v1/forecast?latitude=29.5603&longitude=106.5577&hourly=temperature_2m&timezone=Australia%2FSydney", // Chongqing
                                "https://api.open-meteo.com/v1/forecast?latitude=31.2222&longitude=121.4581&hourly=temperature_2m&timezone=Australia%2FSydney", // Shanghai
                                "https://api.open-meteo.com/v1/forecast?latitude=39.9075&longitude=116.3972&hourly=temperature_2m&timezone=Australia%2FSydney", // Beijing
                                "https://api.open-meteo.com/v1/forecast?latitude=30.6667&longitude=104.0667&hourly=temperature_2m&timezone=Australia%2FSydney", // Chengdu
                                "https://api.open-meteo.com/v1/forecast?latitude=23.1167&longitude=113.25&hourly=temperature_2m&timezone=Australia%2FSydney", // Guangzhou
                                "https://api.open-meteo.com/v1/forecast?latitude=22.2669&longitude=114.1788&hourly=temperature_2m&timezone=Australia%2FSydney", // Hong Kong
                                "https://api.open-meteo.com/v1/forecast?latitude=22.2006&longitude=113.5461&hourly=temperature_2m&timezone=Australia%2FSydney", // Macau
                                };
    std::string uk_urls[] = {"https://api.open-meteo.com/v1/forecast?latitude=51.5085&longitude=-0.1257&hourly=temperature_2m&timezone=Australia%2FSydney", // London
                             "https://api.open-meteo.com/v1/forecast?latitude=53.4106&longitude=-2.9779&hourly=temperature_2m&timezone=Australia%2FSydney", // Liverpool
                             "https://api.open-meteo.com/v1/forecast?latitude=53.4809&longitude=-2.2374&hourly=temperature_2m&timezone=Australia%2FSydney", // Manchester
    
                            };
    std::map<std::string, std::vector<std::string>> countries;

    // country lists
    countries["Australia"] = {"Sydney", "Darwin", "Melbourne", "Adelaide", "Perth", "Brisbane", "Hobart", "Canberra"}; 
    countries["United States"] = {"New York City", "Los Angeles", "Miami", "Chicago"};
    countries["China"] = {"Chongqing", "Shanghai", "Beijing", "Chengdu", "Guangzhou", "Hong Kong", "Macau"};
    countries["United Kingdom"] = {"London", "Liverpool", "Manchester"};
    
    switch(is_country)
    {
        case 0:
            // search for a specific city using our arrays
            break;
        case 1:
            // logic to implement is if city in country, 
            // use that countries urls starting from [counter] (0)
            break;
        default:
            // something has gone wrong if this happens
            break;

    };
    // test url arrays work
    //std::cout << australia_urls[counter] << "\n";                                
    counter +=1; // use counter to determine which city we are searching for and what url to use

}


void searchbyCountry(int country) // functionality locations
{
    switch(country)
    {
        case 1:
            std::cout << "****************************\n";
            std::cout << "Weather Data for Australia\n";
            std::cout << "****************************\n";
            //list capital cities of Australia 
            searchbyCity("Sydney", 1);
            searchbyCity("Darwin", 1);            
            searchbyCity("Melbourne", 1);
            searchbyCity("Adelaide", 1);
            searchbyCity("Perth", 1);
            searchbyCity("Brisbane", 1);
            searchbyCity("Hobart", 1);
            searchbyCity("Canberra", 1);
            break;
        case 2:
            std::cout << "****************************\n";
            std::cout << "Weather Data for United States\n";
            std::cout << "****************************\n";
            // probably just LA, NYC, Miami and Chicago
            searchbyCity("New York City", 1);
            searchbyCity("Los Angeles", 1);
            searchbyCity("Miami", 1);
            searchbyCity("Chicago", 1); 
            break;
        case 3:
            std::cout << "****************************\n";
            std::cout << "Weather Data for China\n";
            std::cout << "****************************\n";
            // list top five biggest cities and include Hong Kong and Macau
            searchbyCity("Chongqing", 1);
            searchbyCity("Shanghai", 1);
            searchbyCity("Beijing", 1);
            searchbyCity("Chengdu", 1);
            searchbyCity("Guangzhou", 1);
            searchbyCity("Hong Kong", 1);
            searchbyCity("Macau", 1);
            break;
        case 4:
            std::cout << "****************************\n";
            std::cout << "Weather Data for United Kingdom\n";
            std::cout << "****************************\n";
            // Liverpool, London, Manchester
            searchbyCity("London", 1);
            searchbyCity("Liverpool", 1);
            searchbyCity("Manchester", 1);
            break;
        default:
            std::cout << "Error! Invalid Input!\n";
            break;
    }
        

}