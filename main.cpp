#include <iostream>
#include "Blockchain.h"

int main() {
    Blockchain myBlockchain;

    Transaction tx1("Alice", "Bob", 50);
    Transaction tx2("Bob", "Charlie", 30);

    myBlockchain.createTransaction(tx1);
    myBlockchain.createTransaction(tx2);

    myBlockchain.minePendingTransactions();

    if (myBlockchain.isChainValid()) {
        std::cout << "Blockchain is valid.\n";
    } else {
        std::cout << "Blockchain is not valid!\n";
    }

    myBlockchain.printChain();

    return 0;
}
