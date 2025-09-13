bankAccount* setAccount() { // Returns a pointer to bankAccount. The type depends on user input which determines the return value
    std::cout << "What bank account do you wish to open?" << std::endl;
    std::cout << "Press 1 for service charge checking." << std::endl;
    std::cout << "Press 2 for no service charge checking." << std::endl;
    std::cout << "Press 3 for high interest checking." << std::endl;
    std::cout << "Press 4 for certificate of deposit account." << std::endl;
    std::cout << "Press 5 for savings account." << std::endl;
    std::cout << "Press 6 for high interest savings." << std::endl;

    int variable;
    std::cin >> variable; // user input

    if (variable == 1) {
        return new serviceChargeChecking(); // Memory is allocated when the program executes rather than at compile time, so the keyword 'new' is used
    }
    if (variable == 2) {
        return new noServiceChargeChecking();
    }
    if (variable == 3) {
        return new highInterestChecking();
    }
    if (variable == 4) {
        return new certificateOfDeposit();
    }
    if (variable == 5) {
        return new savingsAccount();
    }
    if (variable == 6) {
        return new highInterestSavings();
    }
    std::cout << "Option not available" << std::endl;
    return nullptr; // if the user didn't input a valid option the function returns a pointer pointing to nothing
}