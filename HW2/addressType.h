#include <iostream>
#include <string>

class addressType {
    public:
        std::string streetAddress;
        std::string city;
        std::string state;
        std::string zipCode;

        // Default constructor
    addressType(std::string street = "123 Whatever Street", std::string cityName = "Nottingham", std::string stateName = "Wisconsonia", std::string zip = "12345") {
        streetAddress = street;
        city = cityName;
        state = stateName;
        zipCode = zip;

    }

    void setAddress(std::string street, std::string cityName, std::string stateName, std::string zip);

};

void addressType::setAddress(std::string street, std::string cityName, std::string stateName, std::string zip) {
        streetAddress = street;
        city = cityName;
        state = stateName;
        zipCode = zip;
}