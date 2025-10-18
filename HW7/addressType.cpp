#include "addressType.h"

void addressType::setAddress(std::string street, std::string cityName, std::string stateName, std::string zip) {
        streetAddress = street;
        city = cityName;
        state = stateName;
        zipCode = zip;
}