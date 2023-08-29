#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "Transaction.h"

class Block {
public:
    std::string prevHash;  // Hash of the previous block
    std::string blockHash; // Hash of the current block
    std::vector<Transaction> transactions; // List of transactions in this block
    std::time_t timestamp; // Timestamp for when this block was created
    int nonce;  // Nonce used for mining
    int difficulty;  // The difficulty level for mining this block

    // Constructor to initialize a block with transactions, previous hash, and difficulty
    Block(std::vector<Transaction> transactions, std::string prevHash, int difficulty);

    // Method to mine the block by finding a nonce that satisfies the difficulty
    std::string mineBlock();

    // Method to generate the hash of the block's contents
    std::string generateHash() const;

    // Utility method to perform SHA-256 hashing
    std::string sha256(const std::string str) const;
};
