#pragma once
#include <vector>
#include "Block.h"
#include "Transaction.h"
#include "Wallet.h"

class Blockchain {
private:
    std::vector<Block> chain;
    std::vector<Transaction> pendingTransactions;
    std::unordered_map<std::string, RSA*> publicKeyMap; // New map for public keys


public:
    Blockchain();
    void createTransaction(Transaction transaction);
    void minePendingTransactions();
    bool isBlockHashValid(const Block& block);
    bool isTransactionValid(const Transaction& tx);
    bool isChainValid();
    void printChain();
    void notifyWallets(std::vector<Wallet*>& wallets);
};
