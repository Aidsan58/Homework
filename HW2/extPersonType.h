#include <string>
#include "personType.h"
#include "dateType.h"
#include "addressType.h"

class extPersonType : public personType, public dateType, public addressType {
    public:
        bool isfamilyMember;
        bool isFriend;
        bool isBusinessAssociate;
        std::string extPhoneNumber;

        std::string getRelationship();

        std::string getPhoneNumber();


    extPersonType(bool isFamilyMember = false, bool isFriend = false, bool isBusinessAssociate = false, std::string phoneNumber = "1234567890"); // Constructs extPersonType with all boolean values set to false.
};

std::string extPersonType::getRelationship() { // This function returns whatever relation the individual in extPersonType is to the individual in personType.
    if (extPersonType::isfamilyMember == true) {
        return "family member";
    }
    if (extPersonType::isFriend == true) {
        return "friend";
    }
    if (extPersonType::isBusinessAssociate == true) {
        return "business associate";
    }
}

std::string extPersonType::getPhoneNumber() { // This function returns phoneNumber. To be used with print statements.
    return phoneNumber;
}