#include "limit_order.h"

// Implementation of Strategy class
void Strategy::execute() {
    int strategyOption;
    std::cout << "Pick a strategy:\n";
    std::cout << "1. EMA\n";
    std::cout << "2. Supertrend\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> strategyOption;

    switch(strategyOption) {
        case 1:
            applyEMAStrategy();
            break;
        case 2:
            applySupertrendStrategy();
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
    }
}

void Strategy::applyEMAStrategy() {
    std::cout << "EMA Strategy selected.\n";
    // Placeholder: Logic for EMA will be implemented here
    generateAutoOrders("EMA");
}

void Strategy::applySupertrendStrategy() {
    std::cout << "Supertrend Strategy selected.\n";
    // Placeholder: Logic for Supertrend will be implemented here
    generateAutoOrders("Supertrend");
}

void Strategy::generateAutoOrders(const std::string& strategy) {
    std::cout << "Generating automatic orders based on the " << strategy << " strategy...\n";
    // Logic to generate auto orders goes here
}

// Implementation of SelectPrice class
void SelectPrice::execute() {
    double price;
    std::cout << "Enter the price for the Limit Order: ";
    std::cin >> price;

    placeOrderAtPrice(price);
}

void SelectPrice::placeOrderAtPrice(double price) {
    std::cout << "Placing limit order at price: " << price << "\n";
    // Logic to place an order at the entered price
}

// User interface implementation
void userInterface() {
    int option;
    LimitOrder* order = nullptr;

    std::cout << "Welcome to the Limit Order Menu.\n";
    std::cout << "Please pick an option:\n";
    std::cout << "1. Strategy\n";
    std::cout << "2. Select Price\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> option;

    if (option == 1) {
        order = new Strategy();
    } else if (option == 2) {
        order = new SelectPrice();
    } else {
        std::cout << "Invalid option. Please try again.\n";
        return;
    }

    // Execute the selected order type (Strategy or Select Price)
    order->execute();

    // Clean up dynamically allocated memory
    delete order;
}
