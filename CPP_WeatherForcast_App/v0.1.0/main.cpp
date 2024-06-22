#include <iostream>

// Current preperation for eventual functionality
void searchbyCity(std::string city); // function declarations
void searchbyCountry(std::string country); // function declarations

int main()
{
    std::cout << "****************************\n";
    std::cout << "World Wide Weather Tracking\n";// title
    std::cout << "****************************\n\n";

    
    int user_input;
    std::string country;
    std::string city;

    std::cout << "1. Search by Country\n" << "2. Search by City\n";
    std::cin >> user_input;

    switch(user_input)
    {
        case 1: // search by country            
            std::cout << "Please Enter a Country to search for: \n";
            std::cin >> country;
            searchbyCountry(country);
            break;
        case 2: // search by city            
            std::cout << "Please enter a City to search for: \n";
            std::cin >> city;
            searchbyCity(city);
            break;
        default: // invalid input
            std::cout << "Invalid Input\n";
    }


    return 0;
}


void searchbyCity(std::string city) // functionality locations
{
    std::cout << "search by city!";

}


void searchbyCountry(std::string country) // functionality locations
{
    std::cout << "search by country!";

}