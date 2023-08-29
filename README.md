# Simple Blockchain in C++

This code base provides a minimal implementation of a blockchain in C++.

## Features

1. **Transaction Management**: Handles transactions between different addresses.
2. **Block Creation**: Allows for the addition of new blocks to the blockchain.
3. **Blockchain Validation**: Validates the integrity of the blockchain.
4. **Basic Proof-of-Work (PoW)**: Implements a basic PoW algorithm for mining new blocks.
5. **Modular Code**: The code is divided into separate files for easy maintenance and readability.

## Prerequisites

- C++11 or later
- OpenSSL Library for SHA-256 Hashing

## Components

### Transaction

This class represents a transaction in the blockchain. It includes:

- Sender's address
- Receiver's address
- Amount being transacted

### Block

This class represents a block in the blockchain. Each block contains:

- The hash of the previous block (except for the Genesis block)
- A list of transactions
- A timestamp indicating when the block was created
- A nonce and difficulty level for mining
- The hash of the block itself

### Blockchain

This class manages the blockchain and includes features for:

- Creating transactions
- Mining new blocks
- Validating the integrity of the blockchain

## Setup and Compilation

1. Clone this repository.
2. Navigate to the project directory.
3. Compile the code using `g++`:

    ```bash
    g++ main.cpp Block.cpp Blockchain.cpp Transaction.cpp -o blockchain -lcrypto
    ```

    This assumes that you have OpenSSL installed (`-lcrypto` links against the OpenSSL crypto library).

## Execution

Run the compiled output:

```bash
./blockchain
```

## Output

The program will:

- Create a new blockchain
- Add some transactions to the pending transaction list
- Mine these transactions into a new block
- Validate the blockchain
- Print the entire blockchain

## License

This project is open source, under the MIT License.

## Contributions

Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you'd like to change.

## Acknowledgements

- The OpenSSL library for providing the SHA-256 hash function.

---

This README provides a basic outline and can be extended based on additional features, usage instructions, or other relevant information as the project grows.