#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <openssl/rsa.h>

class Transaction {
public:
    std::string sender; // Sender's wallet ID
    std::string receiver; // Receiver's wallet ID
    float amount; // Amount of money transferred
    std::string signature; // Digital signature for this transaction
    int nonce; // Nonce for transaction, can be used for security or versioning
    unsigned int signatureLength; // Length of the digital signature

    // Constructor to initialize the transaction
    Transaction(std::string sender, std::string receiver, float amount, int nonce);

    // Method to sign the transaction with the sender's private key
    void sign(RSA* privateKey);

    // Method to verify the transaction using the sender's public key
    bool verify(RSA* publicKey) const;

    // Method to check overall validity of the transaction
    bool isValid(RSA* publicKey) const;
};

#endif // TRANSACTION_H
