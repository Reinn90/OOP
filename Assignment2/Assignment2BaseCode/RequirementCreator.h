/*
 * Randomly creates customer requirements
 * to be entered into the app for package calculation
 */

#ifndef REQUIREMENTCREATOR
#define REQUIREMENTCREATOR

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

class RequirementCreator
{
private:
    int requirementNumber;
    int roomId;
    int gameNoRequired;
    int budget;
    string roomName;

    vector<int> actualGame;
    vector<RequirementCreator> generatedReq;

public:
    RequirementCreator() {}

    RequirementCreator(int b, string r, vector<int> g)
    {
        budget = b;
        roomName = r;
        for (int i = 0; i < g.size(); i++)
        {
            actualGame.push_back(g[i]);
        }
    }

    void generateHotel();
    void generateGames();
    void generateBudget();

    void createCustomerBundle();

    void writeBundle()
    {

        ofstream fout;

        fout.open("generatedRequirements.txt");
        if (fout.fail())
        {
            cout << "Output file opening failed.\n";
            exit(1);
        }

        for (const RequirementCreator i : generatedReq)
        {
            fout << i.budget << "," << i.roomName
                 << " [";

        
            for (int j = 0; j < i.actualGame.size(); j++)
            {
                fout << i.actualGame[j];

                if (j < i.actualGame.size() - 1)
                    fout << ",";
            }

            fout << "]" << endl;
        }

        fout.close();
    }
};

void RequirementCreator::createCustomerBundle()
{
    // generate random number between 100-150
    requirementNumber = rand() % 51 + 100;
    // debug - DELETE
    cout << "Number of requirements to be generated: " << requirementNumber << endl;

    int cId = 0;
    for (int i = 0; i < requirementNumber; i++)
    {

        generateHotel();
        generateGames();
        generateBudget();

        cout << "Customer No " << cId << ": "
             << budget << " " << roomName << " [";

        for (int i = 0; i < actualGame.size(); i++)
        {
            cout << actualGame[i];
            if (i < actualGame.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;

        cId++;

        generatedReq.push_back(RequirementCreator(budget, roomName, actualGame));
        actualGame.clear();
    }
}

void RequirementCreator::generateHotel()
{

    // generate random number between 0,1,2
    roomId = rand() % 3;

    // set the room name
    switch (roomId)
    {
    case 0:
        roomName = "Regular";
        break;

    case 1:
        roomName = "Bronze";
        break;

    case 2:
        roomName = "Gold";
        break;
    }
}

void RequirementCreator::generateGames()
{
    // how many number of games to watch between 1-15
    gameNoRequired = rand() % NUMBEROFGAMES + 1;

    vector<bool> games;
    // create a boolean array of zeroes
    for (int i = 0; i < 15; i++)
    {
        games.push_back(false);
    }

    // according to the random generate number of games to watch
    for (int i = 0; i < gameNoRequired; i++)
    {
        int index = rand() % games.size();
        // set that index to 1
        games[index] = true;
    }

    // actual games array
    for (int i = 0; i < games.size(); i++)
    {
        if (games[i] == true)
        {
            actualGame.push_back(i);
        }
    }
}

void RequirementCreator::generateBudget()
{
    int low, high; // budget range

    for (int i = 0; i < actualGame.size(); i++)
    {
        // If the games include the opening ceremony,
        // randomly generate the budget
        // between 4500+150*number-of-games to 7500+150*number-of-games.
        if (actualGame[i] == 0)
        {
            low = 4500 + 150 * actualGame.size();
            high = 7500 + 150 * actualGame.size();

            budget = rand() % (high - low + 1) + low;
            break;
        }

        //  If the games include the closing ceremony,
        //  randomly generate the budget
        // between 3800+150*number-of-games to 6800+150*number-of-games.
        else if (actualGame[i] == 14)
        {
            low = 3800 + 150 * actualGame.size();
            high = 6800 + 150 * actualGame.size();

            budget = rand() % (high - low + 1) + low;
            break;
        }
        // Otherwise, randomly generate the budget
        // between 3250+150*number-ofgames to 5250+150*number-of-games.
        else
        {
            low = 3250 + 150 * actualGame.size();
            high = 5250 + 150 * actualGame.size();

            budget = rand() % (high - low + 1) + low;
            break;
        }
    }
}

#endif