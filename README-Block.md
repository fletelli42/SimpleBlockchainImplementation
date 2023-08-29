# Block.cpp README

## Overview
This C++ file, `Block.cpp`, implements a Block class to represent a block in a blockchain. The Block class includes various member functions and data members for managing transactions, generating hashes, and maintaining the blockchain's integrity.

## Dependencies
- `<sstream>`
- `<iomanip>`
- `<openssl/sha.h>`

## Class Functions and Members

### Constructor
```cpp
Block::Block(std::vector<Transaction> transactions, std::string prevHash, int difficulty)
```
The constructor initializes a Block object with the following parameters:

- `transactions`: A vector of transactions for the block.
- `prevHash`: The hash of the previous block in the blockchain.
- `difficulty`: The difficulty level for mining (used to compute nonce).

### Public Member Functions

#### mineBlock()
```cpp
std::string Block::mineBlock()
```
This function performs mining on the block by finding a nonce that makes the block's hash begin with a specific number of leading zeros. The number of leading zeros is determined by the block's difficulty level.

#### generateHash()
```cpp
std::string Block::generateHash() const
```
Generates a hash for the block using the SHA-256 algorithm. This includes the timestamp, transactions, previous hash, and the current nonce.

#### sha256()
```cpp
std::string Block::sha256(const std::string str) const
```
Computes the SHA-256 hash for a given string.

### Private Member Variables

- `std::vector<Transaction> transactions`: Stores the transactions for the block.
- `std::string prevHash`: Stores the hash of the previous block.
- `time_t timestamp`: Stores the time the block was created.
- `int difficulty`: Stores the difficulty level for mining.
- `int nonce`: Stores the nonce used in mining.
- `std::string blockHash`: Stores the hash of the block.

## Additional Information
This implementation uses the OpenSSL library for SHA-256 hashing. Make sure to install OpenSSL before running the code.

## Example Usage
```cpp
std::vector<Transaction> someTransactions;
std::string previousHash = "some_previous_hash";
int difficultyLevel = 3;

Block newBlock(someTransactions, previousHash, difficultyLevel);
```

## Note
This README assumes that a `Transaction` class exists and is used for the `transactions` vector. The `Transaction` class should have members like `sender`, `receiver`, and `amount`.
  
## Authors
- [Your Name]
  
## License
This project is licensed under the MIT License. See the [LICENSE.md](LICENSE.md) file for details.