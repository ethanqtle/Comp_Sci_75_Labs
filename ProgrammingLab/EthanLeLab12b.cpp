#include <iostream>
#include <string>
using namespace std;

struct MovieData
{
    string title;
    string director;
    int yearRelease;
    int runningTime;
};

void displayMovieInfo(const MovieData &);

int main()
{
    MovieData topGun, blackPanther;

    topGun = {
        "Top Gun: Maverick",
        "Joseph Kosinki",
        2022,

        // 2 hours 11 min
        2 * 60 + 11};

    blackPanther = {
        "Black Panther: Wakanda Forever",
        "Ryan Coogler",
        2022,
        // 2 hours 41
        2 * 60 + 41};

    displayMovieInfo(topGun);
    displayMovieInfo(blackPanther);
    return 0;
}

void displayMovieInfo(const MovieData &movie)
{
    cout << endl
         << "===================================" 
         << endl;
    cout << "Title " << movie.title << endl;
    cout << "Director " << movie.director << endl;
    cout << "Year Released " << movie.yearRelease << endl;
    cout << "Running Time (in minutes) " << movie.runningTime << endl;
    cout << "===================================" << endl;
}
