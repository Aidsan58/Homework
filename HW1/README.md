a. Some of the characteristics of a book are the title, author(s),
publisher, ISBN, price, and year of publication. Design a class
bookType that defines the book as an ADT.
i. Each object of the class bookType can hold the following
information about a book: title, up to four authors, publisher,
ISBN, price, and number of copies in stock. To keep track of
the number of authors, add another member variable.
ii. Include the member functions to perform the various operations on objects of type bookType. For example, the usual
operations that can be performed on the title are to show the
title, set the title, and check whether a title is the same as the
actual title of the book. Similarly, the typical operations that
can be performed on the number of copies in stock are to
show the number of copies in stock, set the number of copies
in stock, update the number of copies in stock, and return
the number of copies in stock. Add similar operations for the
publisher, ISBN, book price, and authors. Add the appropriate constructors and a destructor (if one is needed).
b. Write the definitions of the member functions of the class bookType.
c. Write a program that uses the class bookType and tests various
operations on the objects of the class bookType. Declare an array of
100 components of type bookType. Some of the operations that you
should perform are to search for a book by its title, search by ISBN,
and update the number of copies of a book.

13. In this exercise, you will design a class memberType.
a. Each object of memberType can hold the name of a person, member ID, number of books bought, and amount spent.
b. Include the member functions to perform the various operations
on the objects of memberType—for example, modify, set, and show
a person’s name. Similarly, update, modify, and show the number
of books bought and the amount spent.
c. Add the appropriate constructors.
d. Write the definitions of the member functions of memberType.
e. Write a program to test various operations of your class memberType.

14. Using the classes designed in Programming Exercises 12 and 13, write a
program to simulate a bookstore. The bookstore has two types of customers: those who are members of the bookstore and those who buy
books from the bookstore only occasionally. Each member has to pay
a $10 yearly membership fee and receives a 5% discount on each book
purchased. For each member, the bookstore keeps track of the number of books purchased and the total amount spent. For every eleventh
book that a member buys, the bookstore takes the average of the total
amount of the last 10 books purchased, applies this amount as a discount, and then resets the total amount spent to 0. Write a program that
can process up to 1,000 book titles and 500 members. Your program
should contain a menu that gives the user different choices to effectively
run the program; in other words, your program should be user driven.