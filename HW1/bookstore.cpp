#include "memberType.h"
#include "bookType.h"

void memberBookPurchase(int index, memberType memberList[], bookType bookList[]) {
    bool purchasing = true;
    char response;
    while (purchasing == true) {
        std::cout << "Would you like to purchase a book? y or n" << std::endl;
        std::cin >> response;
        if (response == 'n') {
        purchasing = false;
        continue;
    }
        std::string book;
        int location;
        std::cout << "Please enter the book you are purchasing: " << std::endl;
        std::cin >> book;
        bool exists;
        exists = bookSearch(book, bookList);
        if (exists == false) {
            continue;
        }
        
        for (int k = 0; k < 1000; k++) {
            if (bookList[k].title == book ||bookList[k].ISBN == book) {
                location = k;
                break;
            }
        }

        std::cout << "The price of this book is" << bookList[location].price << std::endl;
        memberList[index].booksBought += 1;
    if (memberList[index].booksBought == 11) { // This operation checks to see if 11 books have been bought by a member. If it returns true, the discount is applied.
                bookList[location].price = memberList[index].amountSpent / 10;
                std::cout << "You have spent " << memberList[index].amountSpent << " dollars." << std::endl;
                memberList[index].amountSpent = 0; // Resets the amount spent so we can continue to discount for every 11th book purchased.
                memberList[index].booksBought = 0;
                continue;
            }
        
        memberList[index].amountSpent += bookList[location].price;
        std::cout << "You have spent " << memberList[index].amountSpent << " dollars." << std::endl;
        

        continue;
    }
    
    
   
}

void regularBookPurchase(bookType bookList[]) {
    bool purchasing = true;
    char response;
    while (purchasing == true) {
        std::cout << "Would you like to purchase a book? y or n" << std::endl;
        std::cin >> response;
        if (response == 'n') {
        purchasing = false;
        continue;
    }
        std::string book;
        int location;
        std::cout << "Please enter the book you are purchasing: " << std::endl;
        std::cin >> book;
        bool exists;
        exists = bookSearch(book, bookList);
        if (exists == false) {
            continue;
        }
        
        for (int k = 0; k < 1000; k++) {
            if (bookList[k].title == book ||bookList[k].ISBN == book) {
                location = k;
                break;
            }
        }

        std::cout << "The price of this book is" << bookList[location].price << std::endl;
        std::cout << "You have spent " << bookList[location].price << " dollars." << std::endl;
        

        continue;
    }
}
   

int main() {

    /*
    bookType bookList[100];
    bookList[67].title = "C++ Programming";
    std::cout << "The title of this book is " << bookList[67].showTitle() << "." << std::endl;

    bookSearch("C++ Programming", bookList);
    bookSearch("Phenomenology of Spirit", bookList);


    memberType myMember;
    myMember.setName();

    std::cout << "The name of the member is " << myMember.showName() << "." << std::endl;
    */

    bookType bookList[1000];
    memberType memberList[500];
    char answer;
    int j = 0;

    std::cout << "Welcome. Do you wish to claim a membership? Each member has to pay a $10 yearly membership fee and receives a 5 percent discount on each book purchased. y or n" << std::endl;
    std::cin >> answer;
    if (answer == 'y') { // If the user answers yes, they are added to the memberList roster, and charged ten dollars.
        memberList[j].setName();
        memberList[j].amountSpent += 10;
        std::cout << "Successfully added user to member list." << std::endl;
        memberBookPurchase(j, memberList, bookList);
        j += 1;
    }

    if (answer == 'n') { // If the user answers yes, they are added to the memberList roster, and charged ten dollars.
        regularBookPurchase(bookList);
    }

    std::cout << "Thank you for shopping." << std::endl;

    return 0;
}