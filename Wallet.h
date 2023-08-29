#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include "Transaction.h"

class Wallet {
public:
    std::string id;
    float balance;

    Wallet(std::string id);

    Transaction sendFunds(std::string receiver, float amount);
    void updateBalance(const std::vector<Transaction>& transactions);
};

#endif // WALLET_H
