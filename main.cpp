#include <iostream>
#include "Blockchain.h"
#include "Wallet.h"

int main() {
    Blockchain myBlockchain;
    std::vector<Wallet> wallets;

    Wallet alice("Alice");
    Wallet bob("Bob");
    Wallet charlie("Charlie");

    alice.balance = 100;
    bob.balance = 100;

    wallets.push_back(alice);
    wallets.push_back(bob);
    wallets.push_back(charlie);

    // Create new transactions
    Transaction tx1 = alice.sendFunds("Bob", 50);
    Transaction tx2 = bob.sendFunds("Charlie", 30);

    // Add transactions to the blockchain
    myBlockchain.createTransaction(tx1);
    myBlockchain.createTransaction(tx2);

    // Mine transactions into a new block
    myBlockchain.minePendingTransactions();

    // Notify wallets about the transactions
    myBlockchain.notifyWallets(wallets);

    // Validate the blockchain
    if (myBlockchain.isChainValid()) {
        std::cout << "Blockchain is valid.\n";
    } else {
        std::cout << "Blockchain is not valid!\n";
    }

    // Print the blockchain

    myBlockchain.printChain();
    // Print wallet balances
    for (const auto& wallet : wallets) {
        std::cout << "Wallet " << wallet.id << " has balance: " << wallet.balance << std::endl;
    }

    return 0;
}
