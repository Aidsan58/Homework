#ifndef LEDGER_H
#define LEDGER_H

class ledger {
    public:
    double value;
    enum class TransactionType { WITHDRAWAL, DEPOSIT, CHECK };
    TransactionType type;

    ledger(); // default constructor
    ledger(int size);


    void insertEnd(int insertItem, double value, enum TransactionType type);
    //Function to insert insertItem at the end of
    //the list. Note that this is an abstract function.
    //Postcondition: list[length] = insertItem; and length++;
    // If the list is full, an appropriate
    // message is displayed.

    ledger(int size = 100);
    //Constructor
    //Creates an array of the size specified by the
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array,
    // length = 0, and maxSize = size;
    ledger (const ledger& otherList);
    //Copy constructor
    //virtual ~ledger();
    //Destructor
    //Deallocate the memory occupied by the array.
    protected:
    int *list; //array to hold the list elements
    int length; //variable to store the length of the list
    int maxSize; //variable to store the maxi

};

#endif