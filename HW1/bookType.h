#include <iostream>
#include <string>

class bookType {
    public:
        std::string title;
        std::string author;
        int numAuthors;
        std::string publisher;
        std::string ISBN;
        double copiesSold;
        double price;

        bookType() {
            title = "Not specified";
            author = "Not specified";
            numAuthors = -1;
            publisher = "Not specified";
            ISBN = "Not specified";
            copiesSold = -1;
            price = -1;
        }

        std::string showTitle() {
            return title;
        }

        void updateCopiesSold() {
           int updatedCopies;
            std::cout << "Please input how many copies have been sold: " << std::endl;
            std::cin >> updatedCopies;
            copiesSold = updatedCopies;
        }
};

int bookSearch(std::string inquiry, bookType arr[]) { // This function can search by either ISBN or title. First it searches by title, then by ISBN.
            for (int i = 0; i < 100; i++) {
                if (arr[i].title == inquiry || arr[i].ISBN == inquiry) {
                    std::cout << "The book you are searching for is located in this store." << std::endl;
                    return 0;
                }
    }
    std::cout << "The book you are searching for has not been located in this store." << std::endl;
    return 0;
}