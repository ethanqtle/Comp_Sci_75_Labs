
// C++ Movie Data  Write a program that uses a structure named MovieData to store the following information
// about a movie:TitleDirectorYear ReleasedRunning Time (in minutes)The program should create two MovieData
// variables, store values in their members, and pass each one, in turn, to a function that displays the 
// information about the movie in a clearly formatted manner.

// Chat GPT solution

#include <iostream>
#include <string>

using namespace std;

// Define a struct to store movie data
struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime;
};

// Function to display movie data
void displayMovieData(MovieData movie) {
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Running Time: " << movie.runningTime << " minutes" << endl;
    cout << endl;
}

int main() {
    // Create two MovieData variables and store values in their members
    MovieData movie1 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142};
    MovieData movie2 = {"The Godfather", "Francis Ford Coppola", 1972, 175};

    // Pass each MovieData variable to the displayMovieData function
    displayMovieData(movie1);
    displayMovieData(movie2);

    return 0;
}
