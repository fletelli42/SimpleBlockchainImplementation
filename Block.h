#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "Transaction.h"

class Block {
public:
    std::string prevHash;
    std::string blockHash;
    std::vector<Transaction> transactions;
    std::time_t timestamp;
    int nonce;
    int difficulty;

    Block(std::vector<Transaction> transactions, std::string prevHash, int difficulty);
    std::string mineBlock();
    std::string generateHash() const;
    std::string sha256(const std::string str) const;
};
