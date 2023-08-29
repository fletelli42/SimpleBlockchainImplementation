#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>  // OpenSSL library for SHA-256 hashing

// Transaction Class to represent individual transactions
class Transaction {
public:
    std::string sender;    // Sender's address
    std::string receiver;  // Receiver's address
    float amount;          // Amount being transacted

    // Constructor to initialize a Transaction
    Transaction(std::string sender, std::string receiver, float amount) {
        this->sender = sender;
        this->receiver = receiver;
        this->amount = amount;
    }
};

// Block Class to represent individual blocks in the blockchain
class Block {
public:
    std::string prevHash;  // Previous block's hash
    std::string blockHash; // This block's hash
    std::vector<Transaction> transactions; // Transactions in this block
    std::time_t timestamp; // Block creation time
    int nonce;  // Nonce for mining
    int difficulty;  // Mining difficulty level

    // Constructor to initialize a Block
    Block(std::vector<Transaction> transactions, std::string prevHash, int difficulty) {
        this->transactions = transactions;
        this->prevHash = prevHash;
        this->timestamp = std::time(nullptr);
        this->difficulty = difficulty;
        this->nonce = 0;
        this->blockHash = mineBlock(); // Compute the block's hash
    }

    // Mining function to find suitable hash for the block
    std::string mineBlock() {
        std::string target(difficulty, '0');
        while (blockHash.substr(0, difficulty) != target) {
            nonce++;
            blockHash = generateHash();
        }
        return blockHash;
    }

    // Generate block hash from block content and nonce
   std::string sha256(const std::string str) const {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str.c_str(), str.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }

    // Generate block hash from block content and nonce
    std::string generateHash() const {
        std::stringstream ss;
        ss << std::put_time(std::gmtime(&timestamp), "%Y-%m-%dT%H:%M:%S");
        for (const auto& tx : transactions) {
            ss << tx.sender << tx.receiver << tx.amount;
        }
        ss << prevHash << nonce;
        return sha256(ss.str());
    }
};

// Blockchain Class to manage the chain and pending transactions
class Blockchain {
private:
    std::vector<Block> chain;  // The actual blockchain
    std::vector<Transaction> pendingTransactions;  // Pending transactions

public:
    // Constructor initializes Blockchain with a genesis block
    Blockchain() {
        std::vector<Transaction> emptyTransactions;  // Empty list for genesis block
        chain.emplace_back(emptyTransactions, "0", 2);  // Genesis Block
    }

    // Add new transaction to pending transactions
    void createTransaction(Transaction transaction) {
        pendingTransactions.push_back(transaction);
    }

    // Mine pending transactions into a new block and add it to the blockchain
    void minePendingTransactions() {
        Block newBlock(pendingTransactions, chain.back().blockHash, 2);
        chain.push_back(newBlock);
        pendingTransactions.clear();  // Clear pending transactions
    }

    // Validate the hash of a block
    bool isBlockHashValid(const Block& block) {
        return block.blockHash == block.generateHash();
    }

    // Validate a single transaction (basic check: amount > 0)
    bool isTransactionValid(const Transaction& tx) {
        return tx.amount > 0;
    }

    // Validate the integrity of the entire blockchain
    bool isChainValid() {
        for (int i = 1; i < chain.size(); ++i) {  // Start at 1, skipping the genesis block
            Block currBlock = chain[i];
            Block prevBlock = chain[i - 1];

            // Validate block hash
            if (!isBlockHashValid(currBlock)) {
                return false;
            }

            // Validate previous hash field
            if (currBlock.prevHash != prevBlock.blockHash) {
                return false;
            }

            // Validate each transaction in the block
            for (const auto& tx : currBlock.transactions) {
                if (!isTransactionValid(tx)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Function to print the blockchain
    void printChain() {
        for (const auto& block : chain) {
            std::cout << "Block Timestamp: " << block.timestamp << std::endl;
            std::cout << "Previous Hash: " << block.prevHash << std::endl;
            std::cout << "Block Hash: " << block.blockHash << std::endl;
            std::cout << "Transactions:" << std::endl;
            for (const auto& tx : block.transactions) {
                std::cout << "  Sender: " << tx.sender << " Receiver: " << tx.receiver << " Amount: " << tx.amount << std::endl;
            }
            std::cout << std::endl;
        }
    }
};

// Main function to test the blockchain
int main() {
    Blockchain myBlockchain;

    // Create new transactions
    Transaction tx1("Alice", "Bob", 50);
    Transaction tx2("Bob", "Charlie", 30);

    // Add transactions to the blockchain
    myBlockchain.createTransaction(tx1);
    myBlockchain.createTransaction(tx2);

    // Mine transactions into a new block
    myBlockchain.minePendingTransactions();

    // Validate the blockchain
    if (myBlockchain.isChainValid()) {
        std::cout << "Blockchain is valid.\n";
    } else {
        std::cout << "Blockchain is not valid!\n";
    }

    myBlockchain.printChain();

    return 0;
}
