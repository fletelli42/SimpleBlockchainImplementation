#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <openssl/rsa.h>

class Transaction {
public:
    std::string sender;
    std::string receiver;
    float amount;
    std::string signature;
    int nonce;
    unsigned int signatureLength;  // Add this line



    Transaction(std::string sender, std::string receiver, float amount, int nonce);
    void sign(RSA* privateKey);  // Sign the transaction
    bool verify(RSA* publicKey) const;  // Verify the transaction
    bool isValid(RSA* publicKey) const;  // Check overall validity

};

#endif // TRANSACTION_H
