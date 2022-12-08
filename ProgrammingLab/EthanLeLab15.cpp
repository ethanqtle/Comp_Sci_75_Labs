#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

class GuessNumGame
{
private:
    int secretNum;
    int level;
    int maxNum;
    int numGuess;
    int maxNumGuess;
    bool gameComplete;

    const int MAX_LEVEL = 5;

    int calcMaxNum()
    {
        return pow(10, level + 1);
    }

    int genNewSecretNum()
    {
        // generate 32 bits random number
        // rand() return only 16 bits value
        // since RAND_MAX == 0xFFFF
        unsigned int rand32bit;
        rand32bit = (rand() << 16) | (rand() & 0xFFFF);
        return (rand32bit % maxNum) + 1;
    }

public:
    GuessNumGame()
    {
        newGame(0);
    }

    void initGame()
    {
        srand(time(NULL));
    }

    bool newGame(int newLevel)
    {
        bool setLevelStatus;
        setLevelStatus = setLevel(newLevel);
        gameComplete = false;
        numGuess = 0;
        secretNum = genNewSecretNum();
        maxNumGuess = calcMaxNumGuess();
        return setLevelStatus;
    }

    string tryGuess(int num)
    {
        numGuess++;
        if (num == secretNum)
        {
            gameComplete = true;
            return "you've won"; // match found
        }
        else if (numGuessLeft() > 0)
        {
            if (num > secretNum)
            {
                return "too high"; // too high
            }
            else //  if (num < secretNum)
            //       num == secretNum already covered
            {
                return "too low"; // too low
            }
        }
        else
        {
            gameComplete = true;
            return "you've lost";
        }
    }

    int numGuessLeft()
    {
        return maxNumGuess - numGuess;
    }

    bool isGameDone()
    {
        return gameComplete;
    }

    bool setLevel(int newLevel)
    {
        if (newLevel >= 0 && newLevel <= MAX_LEVEL)
        {
            level = newLevel;
            maxNum = calcMaxNum();
            return true;
        }
        return false;
    }

    int getLevel()
    {
        return level;
    }

    int getMaxNum()
    {
        return maxNum;
    }

    int getMaxNumGuess()
    {
        return maxNumGuess;
    }

    int getMaxLevel()
    {
        return MAX_LEVEL;
    }

    int calcMaxNumGuess()
    {
        double maxNumGuess = ceil(log(maxNum) / log(2));
        return static_cast<int>(maxNumGuess);
    }
};

int main()
{
    GuessNumGame myGame;
    int gameLevel;

    // setup random generator to generate different number everytime
    myGame.initGame();

    do
    {
        cout << "Please pick a level (0-" << myGame.getMaxLevel() << ")\n";
        cin >> gameLevel;
    } while (!myGame.newGame(gameLevel));

    while (!myGame.isGameDone())
    {
        int guess;
        cout << "Please pick a number between (1-" << myGame.getMaxNum() << ")\n";
        cin >> guess;
        string result = myGame.tryGuess(guess);
        cout << result << endl;
        if (!myGame.isGameDone())
        {
            cout << "You have " << setw(2) << myGame.numGuessLeft() << " guess left\n";
        }
    }
    return 0;
}
