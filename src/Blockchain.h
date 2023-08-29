#pragma once
#include <vector>
#include "Block.h"
#include "Transaction.h"
#include "Wallet.h"

class Blockchain {
private:
    std::vector<Block> chain;  // Blockchain consisting of blocks
    std::vector<Transaction> pendingTransactions;  // Transactions waiting to be added to a block
    std::unordered_map<std::string, RSA*> publicKeyMap;  // Map of wallet IDs to their public keys

public:
    // Constructor to initialize blockchain with genesis block
    Blockchain();

    // Method to add a new transaction to pendingTransactions
    void createTransaction(Transaction transaction);

    // Method to mine pending transactions and add a new block to the blockchain
    void minePendingTransactions();

    // Method to validate if a block's hash is correct
    bool isBlockHashValid(const Block& block);

    // Method to validate if a transaction is valid
    bool isTransactionValid(const Transaction& tx);

    // Method to validate the integrity of the entire blockchain
    bool isChainValid();

    // Method to print the details of all blocks in the blockchain
    void printChain();

    // Method to notify all wallets about the state of the blockchain
    void notifyWallets(std::vector<Wallet*>& wallets);
};
