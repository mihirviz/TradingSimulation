#include "limit_order3.h"

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

    // Sample stock prices for calculating EMA
    std::vector<double> prices = {100, 101, 102, 103, 102, 101, 104, 106, 105, 108};
    int period = 5;

    double ema = calculateEMA(prices, period);
    std::cout << "Calculated EMA for the last " << period << " periods: " << ema << "\n";

    // Generate auto orders based on EMA
    generateAutoOrders("EMA");
}

double Strategy::calculateEMA(const std::vector<double>& prices, int period) {
    if (prices.size() < period) return 0.0;  // Not enough data

    double multiplier = 2.0 / (period + 1);
    double ema = prices[0];

    for (size_t i = 1; i < prices.size(); ++i) {
        ema = ((prices[i] - ema) * multiplier) + ema;
    }
    return ema;
}

void Strategy::applySupertrendStrategy() {
    std::cout << "Supertrend Strategy selected.\n";

    // Sample stock high, low, close data
    std::vector<double> highs = {102, 103, 104, 105, 107};
    std::vector<double> lows = {100, 101, 102, 103, 104};
    std::vector<double> closes = {101, 102, 103, 104, 106};
    int period = 3;

    bool supertrend = checkSupertrend(highs, lows, closes, period);
    std::cout << "Supertrend is " << (supertrend ? "UP (Bullish)" : "DOWN (Bearish)") << "\n";

    // Generate auto orders based on Supertrend
    generateAutoOrders("Supertrend");
}

bool Strategy::checkSupertrend(const std::vector<double>& highs, const std::vector<double>& lows, const std::vector<double>& closes, int period) {
    // Simplified Supertrend logic: we’ll just check if the last close is above the average of highs and lows
    if (closes.size() < period || highs.size() < period || lows.size() < period) return false;

    double sumHighs = 0, sumLows = 0;
    for (int i = 0; i < period; ++i) {
        sumHighs += highs[i];
        sumLows += lows[i];
    }

    double averageHighLow = (sumHighs + sumLows) / (2 * period);
    return closes.back() > averageHighLow;  // Bullish if last close is above average
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

