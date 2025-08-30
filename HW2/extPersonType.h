#include <string>
#include "personType.h"
#include "dateType.h"
#include "addressType.h"

class extPersonType : public personType, public dateType, public addressType {
public:
    std::string extFirstName;
    std::string extLastName;
    bool isFamilyMember;
    bool isFriend;
    bool isBusinessAssociate;
    std::string extPhoneNumber;
    std::string getRelationship();
    std::string getPhoneNumber();


    // Default constructor
    extPersonType() {
        extFirstName = "";
        extLastName = "";
        isFamilyMember = false;
        isFriend = false;
        isBusinessAssociate = false;
        extPhoneNumber = "";
    }

    // Parameterized constructor
    extPersonType(std::string extFirstName, std::string extLastName,
                  bool isFamilyMember, bool isFriend, bool isBusinessAssociate,
                  std::string phoneNumber) {
        this->extFirstName = extFirstName;
        this->extLastName = extLastName;
        this->isFamilyMember = isFamilyMember;
        this->isFriend = isFriend;
        this->isBusinessAssociate = isBusinessAssociate;
        this->extPhoneNumber = phoneNumber;
    }
};


std::string extPersonType::getRelationship() { // This function returns whatever relation the individual in extPersonType is to the individual in personType.
    if (extPersonType::isFamilyMember == true) {
        return "family member";
    }
    if (extPersonType::isFriend == true) {
        return "friend";
    }
    if (extPersonType::isBusinessAssociate == true) {
        return "business associate";
    }
    return "none";
}

std::string extPersonType::getPhoneNumber() { // This function returns phoneNumber. To be used with print statements.
    return extPersonType::extPhoneNumber;
}