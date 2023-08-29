#include "Blockchain.h"
#include "Wallet.h"
#include <iostream>

// Constructor to initialize a Blockchain with the Genesis Block
Blockchain::Blockchain() {
    std::vector<Transaction> emptyTransactions;  // Empty list for genesis block
    chain.emplace_back(emptyTransactions, "0", 2);  // Genesis Block
}

// Create a transaction and add it to the list of pending transactions
void Blockchain::createTransaction(Transaction transaction) {
    pendingTransactions.push_back(transaction);
}

// Mine pending transactions into a new block and add it to the blockchain
void Blockchain::minePendingTransactions() {
    Block newBlock(pendingTransactions, chain.back().blockHash, 2);
    chain.push_back(newBlock);
    pendingTransactions.clear();  // Clear pending transactions
}

// Check if a block's hash is valid
bool Blockchain::isBlockHashValid(const Block& block) {
    return block.blockHash == block.generateHash();
}

// Check if a transaction is valid
bool Blockchain::isTransactionValid(const Transaction& tx) {
    return tx.amount > 0;
}

// Check the validity of the entire blockchain
bool Blockchain::isChainValid() {
    for (int i = 1; i < chain.size(); ++i) {
        Block currBlock = chain[i];
        Block prevBlock = chain[i - 1];

        if (!isBlockHashValid(currBlock)) {
            return false;
        }

        if (currBlock.prevHash != prevBlock.blockHash) {
            return false;
        }

        for (const auto& tx : currBlock.transactions) {
            RSA* publicKey = publicKeyMap[tx.sender];  // Retrieve publicKey based on tx.sender
            if (!tx.isValid(publicKey)) {
                return false;
            }
        }
    }
    return true;
}

// Display the details of the entire blockchain
void Blockchain::printChain() {
    for (const auto& block : chain) {
        std::cout << "Block Timestamp: " << block.timestamp << std::endl;
        std::cout << "Previous Hash: " << block.prevHash << std::endl;
        std::cout << "Block Hash: " << block.blockHash << std::endl;
        std::cout << "Transactions:" << std::endl;

        for (const auto& tx : block.transactions) {
            std::cout << "  Sender: " << tx.sender << " Receiver: " << tx.receiver << " Amount: " << tx.amount << std::endl;
        }

        std::cout << "Nonce: " << block.nonce << std::endl;  // Display the nonce
        std::cout << std::endl;
    }
}

// Notify wallets with updated transactions and balances
void Blockchain::notifyWallets(std::vector<Wallet*>& wallets) {
    for (auto& wallet : wallets) {
        publicKeyMap[wallet->id] = wallet->publicKey;  // Store the public key in the map
        for (auto& block : chain) {
            wallet->updateBalance(block.transactions);
        }
    }
}
