#include "Transaction.h"
#include <openssl/sha.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <iostream>
#include <iomanip> // for std::hex and std::setw

// Debugging function to print the hash
void debugPrintHash(unsigned char* hash, size_t length) {
    for (size_t i = 0; i < length; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    std::cout << std::endl;
}
// Constructor to initialize a Transaction

Transaction::Transaction(std::string sender, std::string receiver, float amount, int nonce)
    : sender(sender), receiver(receiver), amount(amount), nonce(nonce) {}

// Method to sign a transaction

void Transaction::sign(RSA* privateKey) {

    std::string dataToSign = sender + receiver + std::to_string(amount) + std::to_string(nonce);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(dataToSign.c_str()), dataToSign.size(), hash);


    unsigned char sign[RSA_size(privateKey)];  // Correct size for the signature
    unsigned int sLen;

    if (RSA_sign(NID_sha256, hash, SHA256_DIGEST_LENGTH, sign, &sLen, privateKey) != 1) {
        // Handle error.
        std::cout << "Signing failed.\n";
        return;
    }

    signature.assign(reinterpret_cast<char*>(sign), sLen);
    signatureLength = sLen;  // Store the signature length

    std::cout << "Signed successfully. Signature Length: " << signatureLength << "\n";
}


// Check overall validity of the transaction

bool Transaction::verify(RSA* publicKey) const {

    // Clear OpenSSL error stack
    ERR_clear_error();

    std::string dataToVerify = sender + receiver + std::to_string(amount) + std::to_string(nonce);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(dataToVerify.c_str()), dataToVerify.size(), hash);


    int ret = RSA_verify(NID_sha256, hash, SHA256_DIGEST_LENGTH, 
                     reinterpret_cast<const unsigned char*>(signature.data()), signatureLength, publicKey); // Use the stored length
    
    if (ret != 1) {
        unsigned long err = ERR_get_error();
        char *errStr = ERR_error_string(err, NULL);
        std::cout << "Error occurred during verification: " << errStr << std::endl;
        return false;
    }
    std::cout << "Verification successful.\n";
    return true;
}

bool Transaction::isValid(RSA* publicKey) const {
    if (nonce < 0 || !(amount > 0)) {
        return false;
    }

    return verify(publicKey);
}
