Using classes, design an online address book to keep track of the names,
addresses, phone numbers, and dates of birth of family members, close
friends, and certain business associates. Your program should be able to
handle a maximum of 500 entries.

a. Define a class addressType that can store a street address, city, state,
and ZIP code. Use the appropriate functions to print and store the
address. Also, use constructors to automatically initialize the member
variables.
b. Define a class extPersonType using the class personType (as defined
in Example 10-10, Chapter 10), the class dateType (as designed in this
chapter’s Programming Exercise 2), and the class addressType. Add a
member variable to this class to classify the person as a family member,
friend, or business associate. Also, add a member variable to store the
phone number. Add (or override) the functions to print and store the
appropriate information. Use constructors to automatically initialize the
member variables.
c. Define the class addressBookType using the previously defined
classes. An object of the type addressBookType should be able to process a maximum of 500 entries.
The program should perform the following operations:
I. Load the data into the address book from a disk.
II. Sort the address book by last name.
III. Search for a person by last name.
IV. Print the address, phone number, and date of birth (if it exists) of a given
person.
V. Print the names of the people whose birthdays are in a given month.
VI. Print the names of all the people between two last names.
VII. Depending on the user’s request, print the names of all family members,
friends, or business associates