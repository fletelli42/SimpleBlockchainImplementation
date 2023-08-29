#include "Wallet.h"

Wallet::Wallet(std::string id) : id(id), balance(0.0f) {}

Transaction Wallet::sendFunds(std::string receiver, float amount) {
    if (balance >= amount) {
        return Transaction(id, receiver, amount);
    } else {
        throw std::runtime_error("Insufficient balance");
    }
}


void Wallet::updateBalance(const std::vector<Transaction>& transactions) {
    for (const auto& tx : transactions) {
        if (tx.sender == id) {
            balance -= tx.amount;
        }
        if (tx.receiver == id) {
            balance += tx.amount;
        }
    }
}
