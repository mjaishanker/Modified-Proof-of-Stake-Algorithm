# Modified-Proof-of-Stake-Algorithm

A modified Proof fo Stake algorithm for a simple Cryptocurrency Blockchain. In PoS-based cryptocurrencies the creator of the next block is chosen via various combinations of random selection and wealth.

The original
Casper FFG consists of two layers:
1. The bottom layer is the tree of transactions.
2. The top layer is the sub-tree of checkpoints extracted from the tree of transactions.

With 10 given validators, the program, starting from the genesis node, runs the Proof-of-Stake (PoS)-based
voting 10 rounds, which yields 10 supermajority links. Which then outputs, the blockchain formed by the 10 supermajority links, which is a list of the
node/checkpoint numbers and the IDs of the validators who finalized each checkpoint.

* The output will display all the validators and each voting process.
* The voting process will print the sum of the deposit amounts, the validators who voted to go left or right and the current majority link.
