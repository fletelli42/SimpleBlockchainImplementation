# README for Blockchain.cpp

This file contains the implementation of the `Blockchain` class, which is essential for creating and managing a blockchain.

## Class Methods

### Constructor

- `Blockchain()`: Initializes a new blockchain with the Genesis Block. The Genesis Block is the first block in the blockchain, and it is hardcoded with an empty transaction list and a previous hash of "0".

### Transaction Methods

- `void createTransaction(Transaction transaction)`: Adds a new transaction to the list of pending transactions.

- `void minePendingTransactions()`: Mines all the pending transactions into a new block and adds it to the blockchain. After mining, the list of pending transactions is cleared.

### Validation Methods

- `bool isBlockHashValid(const Block& block)`: Validates a block's hash. It checks if the block's hash is equal to the hash generated from its content.

- `bool isTransactionValid(const Transaction& tx)`: Validates a transaction. It checks if the transaction amount is greater than 0.

- `bool isChainValid()`: Validates the entire blockchain. It checks the following for each block in the chain:
  - The current block's hash is valid.
  - The current block's previous hash matches the hash of the previous block.
  - All transactions in the current block are valid.

### Display Method

- `void printChain()`: Displays the details of the entire blockchain. For each block, it prints the timestamp, previous hash, block hash, transactions, and nonce.

### Notification Method

- `void notifyWallets(std::vector<Wallet*>& wallets)`: Notifies all wallets with updated transactions and balances. It updates the public key map and recalculates the balance for each wallet based on the transactions in the blockchain.

## Dependencies

- `Block.h`: The `Blockchain` class uses the `Block` class to create and manage blocks in the blockchain.
- `Transaction.h`: The `Transaction` class is used to create transactions that are added to the blocks.
- `Wallet.h`: The `Wallet` class is used to manage the wallets that create and sign transactions.

## Usage

The `Blockchain` class is essential for creating and managing a blockchain. To use this class, create a `Blockchain` object and use its methods to create transactions, mine pending transactions, validate the blockchain, and notify wallets with updated transactions and balances.

```cpp
#include "Blockchain.h"
#include "Wallet.h"

int main() {
    // Create a new blockchain
    Blockchain blockchain;

    // Create wallets
    Wallet wallet1;
    Wallet wallet2;

    // Create transactions
    Transaction tx1(wallet1.publicKey, wallet2.publicKey, 10);
    wallet1.signTransaction(tx1);

    Transaction tx2(wallet2.publicKey, wallet1.publicKey, 5);
    wallet2.signTransaction(tx2);

    // Add transactions to the blockchain
    blockchain.createTransaction(tx1);
    blockchain.createTransaction(tx2);

    // Mine pending transactions
    blockchain.minePendingTransactions();

    // Notify wallets with updated transactions and balances
    std::vector<Wallet*> wallets = {&wallet1, &wallet2};
    blockchain.notifyWallets(wallets);

    // Print the entire blockchain
    blockchain.printChain();

    return 0;
}
```

In this example, two wallets are created, and two transactions are created and signed by the respective wallets. The transactions are added to the blockchain, and then the pending transactions are mined into a new block. Finally, the wallets are notified with updated transactions and balances, and the entire blockchain is printed.