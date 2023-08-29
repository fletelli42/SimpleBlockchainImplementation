#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include <openssl/rsa.h>
#include "Transaction.h"

class Wallet {
public:
    Wallet(std::string id);
    ~Wallet();  // Free RSA keys

    Transaction sendFunds(Wallet& receiver, float amount);

    void updateBalance(const std::vector<Transaction>& transactions);
    void printWalletData() const;

    std::string id;
    float balance;
    RSA* publicKey;   // Make it public or provide a getter method


private:
    RSA* privateKey;  // Private key for signing transactions
    void generateKeys();  // Generate RSA key pair
};

#endif // WALLET_H
