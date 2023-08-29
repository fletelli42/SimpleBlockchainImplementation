#pragma once
#include <string>

class Transaction {
public:
    std::string sender;
    std::string receiver;
    float amount;

    Transaction(std::string sender, std::string receiver, float amount);
};
