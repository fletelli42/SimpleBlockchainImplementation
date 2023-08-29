# README for Transaction.cpp

This file contains the implementation of the `Transaction` class, which is used for creating and managing transactions within a blockchain.

## Class Methods

### Constructor

- `Transaction(std::string sender, std::string receiver, float amount, int nonce)`: Initializes a new transaction with sender, receiver, amount of transaction, and a nonce.

### Signing Method

- `void sign(RSA* privateKey)`: Signs the transaction using the RSA private key. It creates a SHA-256 hash of the transaction data and then signs it. The signature and its length are stored as member variables of the class.

### Verification Methods

- `bool verify(RSA* publicKey) const`: Verifies the transaction's signature using the RSA public key. It creates a SHA-256 hash of the transaction data and then verifies the stored signature.

- `bool isValid(RSA* publicKey) const`: Checks the overall validity of the transaction, which includes verifying the signature and ensuring that the amount is greater than zero and the nonce is non-negative.

### Debugging Method

- `void debugPrintHash(unsigned char* hash, size_t length)`: Prints the hash in hexadecimal format for debugging purposes.

## Dependencies

- `Transaction.h`: The `Transaction` class is defined in this header file.
- OpenSSL: This is used for cryptographic functions, specifically SHA-256 for hashing and RSA for signing and verifying.

## Example Usage

```cpp
#include "Transaction.h"
#include <openssl/rsa.h>

int main() {
    // Create RSA key pairs for sender and receiver
    RSA *senderKey = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    RSA *receiverKey = RSA_generate_key(2048, RSA_F4, NULL, NULL);

    // Initialize a new transaction
    Transaction tx("senderID", "receiverID", 100.0, 1);

    // Sign the transaction
    tx.sign(senderKey);

    // Verify the transaction
    if (tx.isValid(senderKey)) {
        std::cout << "Transaction is valid.\n";
    } else {
        std::cout << "Transaction is invalid.\n";
    }

    // Clean up
    RSA_free(senderKey);
    RSA_free(receiverKey);

    return 0;
}
```

In this example, RSA key pairs are generated for the sender and the receiver. A transaction is then initialized, signed, and verified.