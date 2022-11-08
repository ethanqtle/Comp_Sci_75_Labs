#include <iostream>
/** This is a program that prompts the user to enter the number of students
 *   and each student’s name and score, and finally displays the name of the
 *   student with the highest score.
 */

using namespace std;

int main()
{
    int studentnumber;
    cout << "Input a number for the number of students you wish to have: " << endl;
    cin >> studentnumber;
    double score, highScore;
    string name, highScoreName;
    highScore = -1.0;
    highScoreName = "";

    //For loop repeating the input of a name and score based on the number of students
    for(int i=0; i < studentnumber; i++)
    {
        cout << "Input a name and score for the (number: ";
        cout << (i+1) << ") student you have: " << endl;
        cin >> name >> score;

        //If the current score is greater than the highScore, then the current score and name replace the high score and name respectively
        if(score > highScore)
        {
            highScore = score;
            highScoreName = name;
        }
    }
    cout << " Name of student: " << highScoreName << ", High score: " << highScore << endl;
    return 0;
}
