// PP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ctime>

struct validators {
    int validatorID, depositAmmount, vote;
};

int rand50();

int main()
{
    std::vector<validators> validator;

    for (int i = 0; i < 10; i++) {
        validator.push_back(validators());
        validator[i].validatorID = i;
    }

    validator[0].depositAmmount = 500;
    validator[1].depositAmmount = 100;
    validator[2].depositAmmount = 300;
    validator[3].depositAmmount = 250;
    validator[4].depositAmmount = 150;
    validator[5].depositAmmount = 500;
    validator[6].depositAmmount = 600;
    validator[7].depositAmmount = 350;
    validator[8].depositAmmount = 200;
    validator[9].depositAmmount = 150;

    for (int i = 0; i < validator.size(); i++) {
        std::cout << "Validator ID: " << validator[i].validatorID << " ; Deposit Ammount: " << validator[i].depositAmmount << std::endl;
    }
    std::cout << std::endl;

    srand(time(NULL));

    int numOfVotes = 0, n = 0, totalDepositAmount = 3100, halfOfTotalDeposit = 1550;
    std::vector<int> validatorsForLeft, validatorsForRight, supermajorityLinks;
    supermajorityLinks.push_back(n);
    while (supermajorityLinks.size() < 11) {
        int numOfVotesLeft = 0, numOfVotesRight = 0, sumDepositLeft = 0, sumDepositRight = 0;

        for (int i = 0; i < validator.size(); i++) {
            int prob1;
            prob1 = rand50();
            if (prob1 == 0) {
                numOfVotesLeft++;
                validator[i].vote = 0;
                sumDepositLeft += validator[i].depositAmmount;
                validatorsForLeft.push_back(validator[i].validatorID);
            }
            else if (prob1 == 1) {
                numOfVotesRight++;
                validator[i].vote = 1;
                sumDepositRight += validator[i].depositAmmount;
                validatorsForRight.push_back(validator[i].validatorID);
            }
        }
        std::cout << "Number of Votes to Left Child: " << numOfVotesLeft << std::endl;
        std::cout << "Number of Votes to Right Child: " << numOfVotesRight << std::endl;
        std::cout << "Sum of Deposit Ammount to Left: " << sumDepositLeft << std::endl;
        std::cout << "Sum of Deposit Ammount to Right: " << sumDepositRight << std::endl;

        if (sumDepositLeft > halfOfTotalDeposit) {
            std::cout << "Super-majority votes are for left child of checkpoint" << std::endl;
            std::cout << "Printing validator IDs who voted for left child of checkpoint" << std::endl;
            for (std::vector<int>::const_iterator i = validatorsForLeft.begin(); i != validatorsForLeft.end(); ++i)
                std::cout << *i << ' ';
            std::cout << std::endl;
            n = 2 * n + 1;
            supermajorityLinks.push_back(n);
        }
        else if (sumDepositRight > halfOfTotalDeposit) {
            std::cout << "Super-majority votes are for right child of checkpoint" << std::endl;
            std::cout << "Printing validator IDs who voted for right child of checkpoint" << std::endl;
            for (std::vector<int>::const_iterator i = validatorsForRight.begin(); i != validatorsForRight.end(); ++i)
                std::cout << *i << ' ';
            std::cout << std::endl;
            n = 2 * n + 2;
            supermajorityLinks.push_back(n);
        }
        //std::cout << "Size of super majority link: " << supermajorityLinks.size() << std::endl;
        int j = 0;
        std::cout << "Printing current super-majority links " <<  std::endl;
        for (std::vector<int>::const_iterator i = supermajorityLinks.begin(); i != supermajorityLinks.end(); ++i) {
            if(j == supermajorityLinks.size() - 1)
                std::cout << *i << ' ';
            else
                std::cout << *i << "->";
            j++;
        }
        std::cout << std::endl;

        validatorsForLeft.clear();
        validatorsForRight.clear();
        std::cout << std::endl;
        numOfVotes++;
    }
}

int rand50()
{
    return rand() & 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
