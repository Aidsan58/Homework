#include <string>

class extPersonType {
    public:
        bool isfamilyMember;
        bool isFriend;
        bool isBusinessAssociate;
        std::string phoneNumber;




    extPersonType(bool isFamilyMember = false, bool isFriend = false, bool isBusinessAssociate = false, std::string phoneNumber = "1234567890");
};

