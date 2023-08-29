#include "Wallet.h"
#include <iostream>  // Include iostream for std::cerr
#include <openssl/rand.h>
#include <openssl/pem.h>

Wallet::Wallet(std::string id) : id(id), balance(0.0f), privateKey(nullptr), publicKey(nullptr) {
    generateKeys();
}

Wallet::~Wallet() {
   if (privateKey) {
    RSA_free(privateKey);
    privateKey = nullptr;
}
if (publicKey) {
    RSA_free(publicKey);
    publicKey = nullptr;
}

}


void Wallet::generateKeys() {
    privateKey = RSA_new();
    BIGNUM* exponent = BN_new();
    BN_set_word(exponent, RSA_F4);  // Public exponent
    RSA_generate_key_ex(privateKey, 2048, exponent, nullptr);
    
    // Create a new RSA object for the public key and set its fields
    publicKey = RSA_new();
    RSA_set0_key(publicKey, BN_dup(RSA_get0_n(privateKey)), BN_dup(exponent), nullptr);
    
    // Free the exponent as it is duplicated in publicKey and privateKey
    BN_free(exponent);

    char *publicKeyStr = nullptr;
        BIO *bio = BIO_new(BIO_s_mem());
        PEM_write_bio_RSAPublicKey(bio, publicKey);
        size_t keylen = BIO_pending(bio);
        publicKeyStr = (char*)malloc(keylen + 1);
        BIO_read(bio, publicKeyStr, keylen);
        publicKeyStr[keylen] = 0;
        BIO_free_all(bio);


        free(publicKeyStr); // Don't forget to free allocated memory
}


Transaction Wallet::sendFunds(Wallet& receiver, float amount) {
    // Generate a nonce (for simplicity, this could be a random number)
    int nonce = 12345;  // Replace with your nonce generation logic

    Transaction tx(id, receiver.id, amount, nonce);
    tx.sign(privateKey);  // Sign the transaction
    std::cout << privateKey << std::endl;

    return tx;
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

void Wallet::printWalletData() const {
    std::cout << "Wallet ID: " << id << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    std::cout << "Public Key: " << publicKey << std::endl;
    // You can add more fields to print as necessary,
    // such as displaying a simplified form of the public key, etc.

    // Note: be careful about logging sensitive information such as private keys.
}

