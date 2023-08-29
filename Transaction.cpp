#include "Transaction.h"

Transaction::Transaction(std::string sender, std::string receiver, float amount) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
}
