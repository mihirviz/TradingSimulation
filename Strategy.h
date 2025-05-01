#ifndef STRATEGY.H
#define STRATEGY.H

class LimitOrder; // Forward declaration

class Strategy {
public:
    // Constructor
    Strategy();

    // Destructor
    ~Strategy();

    // Function to apply a strategy to a limit order
    virtual void apply(LimitOrder* order) = 0;
};

class TrendFollowingStrategy : public Strategy {
public:
    // Specific implementation of trend following
    void apply(LimitOrder* order) override;
};

class MeanReversionStrategy : public Strategy {
public:
    // Specific implementation of mean reversion
    void apply(LimitOrder* order) override;
};

#endif
