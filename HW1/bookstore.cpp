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
        std::cin.ignore();
        std::getline(std::cin, book);
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

        std::cout << "The price of this book is " << bookList[location].price << " dollars." << std::endl;
        memberList[index].booksBought += 1;
    if (memberList[index].booksBought == 11) { // This operation checks to see if 11 books have been bought by a member. If it returns true, the discount is applied.
                bookList[location].price = bookList[location].price - (memberList[index].amountSpent - 10) / 10;
                std::cout << "You have spent " << memberList[index].amountSpent << " dollars." << std::endl;
                memberList[index].amountSpent = 10; // Resets the amount spent so we can continue to discount for every 11th book purchased.
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
        std::cin.ignore();
        std::getline(std::cin, book);
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

        std::cout << "The price of this book is " << bookList[location].price << " dollars. Thank you for purchasing." << std::endl;
        

        continue;
    }
}
   

int main() {

    bookType bookList[1000];
    memberType memberList[500];
    char answer;
    int j = 0;

    bookList[1].title = "C++ Programming";
    bookList[1].price = 10;
    bookList[2].title = "Phenomenology of Spirit";
    bookList[2].price = 10;
    bookList[3].title = "To Kill a Mockingbird";
    bookList[3].price = 10;
    bookList[4].title = "Moby Dick";
    bookList[4].price = 10;
    bookList[5].title = "House of Leaves";
    bookList[5].price = 10;
    bookList[6].title = "The Sun Also Rises";
    bookList[6].price = 10;
    bookList[7].title = "War of the Worlds";
    bookList[7].price = 10;
    bookList[8].title = "Infinite Jest";
    bookList[8].price = 10;
    bookList[9].title = "Anna Karenina";
    bookList[9].price = 10;
    bookList[10].title = "The Lord of the Rings";
    bookList[10].price = 10;
    bookList[11].title = "Paper Towns";
    bookList[11].price = 10;


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