# README for Wallet.cpp

This file contains the implementation of the `Wallet` class, which is used for creating and managing a wallet within a blockchain environment.

## Class Methods

### Constructor and Destructor

- `Wallet(std::string id)`: Initializes a new Wallet with an ID, a balance of zero, and generates RSA key pairs.
- `~Wallet()`: Destructor that frees the allocated RSA key pairs.

### Key Generation

- `void generateKeys()`: Generates an RSA key pair for the wallet. Public and private keys are stored as members of the wallet object.

### Transaction Creation

- `Transaction sendFunds(Wallet& receiver, float amount)`: Creates a new transaction, signs it with the wallet's private key, and returns it.

### Balance Update

- `void updateBalance(const std::vector<Transaction>& transactions)`: Updates the wallet's balance based on the transactions passed as an argument. If the wallet is a sender in a transaction, the amount is deducted. If the wallet is a receiver, the amount is added.

### Printing Wallet Data

- `void printWalletData() const`: Prints the wallet's ID, current balance, and public key.

## Dependencies

- `Wallet.h`: The `Wallet` class is defined in this header file.
- OpenSSL: This is used for generating RSA key pairs.
- iostream: This is used for outputting debug information.

## Example Usage

```cpp
#include "Wallet.h"
#include "Transaction.h"

int main() {
    Wallet alice("Alice");
    Wallet bob("Bob");

    // Alice sends funds to Bob
    Transaction tx = alice.sendFunds(bob, 50.0);

    // Update balances
    std::vector<Transaction> txList = {tx};
    alice.updateBalance(txList);
    bob.updateBalance(txList);

    // Print wallet data
    alice.printWalletData();
    bob.printWalletData();

    return 0;
}
```

In this example, two wallets are created for Alice and Bob. Alice then sends funds to Bob. Both their balances are updated, and finally, their wallet data is printed.