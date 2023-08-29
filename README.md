# Simple Blockchain Implementation in C++

## Overview

This C++ program demonstrates a simplified implementation of a blockchain. It uses the SHA-256 hashing algorithm for creating block hashes and includes functionalities for transaction handling and blockchain validation.

## Classes Explained

### Transaction Class

- `sender`: The address of the sender
- `receiver`: The address of the receiver
- `amount`: Amount of currency being sent

#### Constructor
Initializes a new Transaction object.

### Block Class

- `prevHash`: Hash of the previous block
- `blockHash`: Hash of this block
- `transactions`: Vector holding transactions
- `timestamp`: Block creation time in UNIX timestamp
- `nonce`: Arbitrary value used for mining
- `difficulty`: The difficulty level for mining

#### Constructor
Initializes a new Block object and mines it immediately.

#### `mineBlock()`
Mines the block by finding a hash that meets the required difficulty level. 

#### `generateHash()`
Generates the hash of the block based on its contents and the nonce.

### Blockchain Class

- `chain`: Vector holding the blockchain
- `pendingTransactions`: Vector holding pending transactions

#### Constructor
Initializes with a genesis block.

#### `createTransaction()`
Adds a new transaction to pending transactions.

#### `minePendingTransactions()`
Mines the pending transactions into a new block.

#### `isBlockHashValid()`
Validates the hash of a block.

#### `isTransactionValid()`
Validates individual transactions.

#### `isChainValid()`
Validates the integrity of the entire blockchain.

## Compilation Instructions

Make sure you have OpenSSL installed on your system for the SHA-256 hashing.

```bash
g++ main.cpp -o blockchain -lssl -lcrypto
```

## Running the Program

Execute the compiled program:

```bash
./blockchain
```

This will:

1. Create a blockchain with a genesis block.
2. Add new transactions from Alice to Bob and from Bob to Charlie.
3. Mine these transactions into a new block.
4. Validate the blockchain.
5. Print the blockchain to the console.

## Limitations

- Does not include cryptographic proof for transactions.
- Simplified for educational purposes; not to be used in production.

## Future Scope

- Adding peer-to-peer network functionality.
- Introduce cryptographic proof for transactions.
- Enhance the validation checks for each transaction and block.
