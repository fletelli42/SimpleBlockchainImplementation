#include "Block.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

// Constructor to initialize a Block with given transactions, previous hash, and difficulty level.
Block::Block(std::vector<Transaction> transactions, std::string prevHash, int difficulty) {
    this->transactions = transactions;
    this->prevHash = prevHash;
    this->timestamp = std::time(nullptr);
    this->difficulty = difficulty;
    this->nonce = 0;
    this->blockHash = mineBlock(); // Compute the block's hash
}

// Mining function to find a valid hash for the block based on the given difficulty
std::string Block::mineBlock() {
    std::string target(difficulty, '0');
    while (blockHash.substr(0, difficulty) != target) {
        nonce++;
        blockHash = generateHash();
    }
    return blockHash;
}

// Generate the hash of the block
std::string Block::generateHash() const {
    std::stringstream ss;
    ss << std::put_time(std::gmtime(&timestamp), "%Y-%m-%dT%H:%M:%S");
    for (const auto& tx : transactions) {
        ss << tx.sender << tx.receiver << tx.amount;
    }
    ss << prevHash << nonce;
    return sha256(ss.str());
}

// Compute SHA-256 hash for a given string
std::string Block::sha256(const std::string str) const {
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
