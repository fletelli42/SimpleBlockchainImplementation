
# Simple Blockchain Implementation in C++

## Overview

This project is a simple implementation of a blockchain with basic wallet functionality. The blockchain contains blocks, where each block contains multiple transactions. Wallets can perform transactions, sending and receiving funds, which are then added to the blockchain.

## Features

1. **Basic Blockchain**: Create a blockchain and add blocks to it. Each block has a hash, a timestamp, and a list of transactions.

2. **Mining**: Blocks have a `mineBlock()` function that solves a proof-of-work problem.

3. **Wallets**: Wallets with unique IDs can send and receive funds.

4. **Transaction Validation**: Transactions are only valid if the wallet has sufficient balance.

5. **Blockchain Integrity Check**: Check if the blockchain is valid based on previous and current block hashes.

6. **Wallet Balance Notification**: After mining a block, wallet balances can be updated based on the transactions in the blockchain.

## How to Run

1. Compile all the `.cpp` files. If you have `g++`, you can compile by running: 
    ```bash
    g++ *.cpp -o blockchain
    ```
2. Execute the output file:
    ```bash
    ./blockchain
    ```

## Code Structure

1. `main.cpp`: The driver program that demonstrates blockchain and wallet functionalities.
2. `Blockchain.cpp` and `Blockchain.h`: Contains the `Blockchain` class that manages blocks and transactions.
3. `Block.cpp` and `Block.h`: Defines the `Block` class for individual blocks in the blockchain.
4. `Transaction.cpp` and `Transaction.h`: Contains the `Transaction` class that represents transactions between wallets.
5. `Wallet.cpp` and `Wallet.h`: Contains the `Wallet` class that can send funds and update balances.

## Recent Updates

- Added wallet functionality for sending and receiving funds.
- Wallets are notified and updated after each block is mined.
- Improved the integrity check for the blockchain.

## Dependencies

- C++ Standard Library
- OpenSSL for SHA-256 Hashing

---

Feel free to add or remove sections as you see fit!