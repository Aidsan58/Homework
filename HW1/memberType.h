#include <iostream>
#include <string>

class memberType {
    public:
        std::string memberName;
        std::string memberID;
        int booksBought;
        double amountSpent;

        memberType() {
            memberName = "Not specified";
            memberID = "Not specified";
            booksBought = 0;
            amountSpent = 0;
        }

        void setName() {
            std::string name;
            std::cout << "Please input the name of the member: " << std::endl;
            std::cin >> name;
            memberName = name;
        }

        std::string showName() {
                return memberName;
            }

        void setBooksBought() {
            int bought;
            std::cout << "Please input the number of books bought: " << std::endl;
            std::cin >> bought;
            booksBought = bought;
        }

        int showBooksBought() {
                return booksBought;
            }

        void setAmountSpent() {
            double spent;
            std::cout << "Please input the amount of money spent: " << std::endl;
            std::cin >> spent;
            amountSpent = spent;
        }

        double showAmountSpent() {
                return amountSpent;
            }
};