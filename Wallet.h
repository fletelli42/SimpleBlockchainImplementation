#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include <openssl/rsa.h>
#include "Transaction.h"

class Wallet {
public:
    Wallet(std::string id); // Constructor with wallet ID
    ~Wallet();  // Destructor to free RSA keys

    // Method to send funds to another wallet
    Transaction sendFunds(Wallet& receiver, float amount);

    // Method to update the balance of this wallet based on blockchain transactions
    void updateBalance(const std::vector<Transaction>& transactions);

    // Method to print wallet details
    void printWalletData() const;

    std::string id; // Wallet ID
    float balance; // Wallet balance
    RSA* publicKey; // Public key of the wallet for verification

private:
    RSA* privateKey;  // Private key for signing transactions
    void generateKeys();  // Method to generate RSA key pair
};

#endif // WALLET_H
