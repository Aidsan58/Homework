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

    // This is because the variable names are the same in the constructor and the definition of the function.
    extPersonType(std::string extFirstName, std::string extLastName, bool isFamilyMember, bool isFriend, bool isBusinessAssociate, std::string phoneNumber) {
        this->extFirstName = extFirstName;
        this->extLastName = extLastName;
        this->isFamilyMember = isFamilyMember;
        this->isFriend = isFriend;
        this->isBusinessAssociate = isBusinessAssociate;
        this->extPhoneNumber = phoneNumber;
    }
    void extPersonTypeSet(std::string extFirstName, std::string extLastName, bool isFamilyMember, bool isFriend, bool isBusinessAssociate, std::string phoneNumber);
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

void extPersonType::extPersonTypeSet(std::string extFirstName, std::string extLastName, bool isFamilyMember, bool isFriend, bool isBusinessAssociate, std::string phoneNumber) {
        this->extFirstName = extFirstName;
        this->extLastName = extLastName;
        this->isFamilyMember = isFamilyMember;
        this->isFriend = isFriend;
        this->isBusinessAssociate = isBusinessAssociate;
        this->extPhoneNumber = phoneNumber;
}