// 1. Movie Data  Write a program that uses a structure named MovieData to store the 
// following information about a movie:TitleDirectorYear ReleasedRunning Time
// (in minutes)The program should create two MovieData variables, store values in 
// their members, and pass each one, in turn, to a function that displays the 
// information about the movie in a clearly formatted manner.
// 
// 2. Movie Profit  Modify  the  program  written  for  Programming  Challenge  1
//   (Movie  Data)  to  include  two additional members that hold the movie’s
//  production costs and first-year revenues. Modify the function that displays
//  the movie data to display the title, director, release year, running time,
//  and first year’s profit or loss.

// Chat GPT solution to Chap 11.2 
#include <iostream>
#include <string>
using namespace std;

// Define the MovieData structure
struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime;
    double productionCosts;
    double firstYearRevenue;
};

// Function to display movie information
void displayMovieInfo(const MovieData& movie) {
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Running Time (in minutes): " << movie.runningTime << endl;
    double profit = movie.firstYearRevenue - movie.productionCosts;
    cout << "First Year Profit/Loss: $" << profit << endl;
}

int main() {
    // Create two MovieData variables and store values in their members
    MovieData movie1 = {"The Godfather", "Francis Ford Coppola", 1972, 175, 6e6, 245e6};
    MovieData movie2 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142, 2.5e7, 28.3e6};

    // Pass each movie to the displayMovieInfo function
    cout << "Movie 1:\n";
    displayMovieInfo(movie1);
    cout << endl;

    cout << "Movie 2:\n";
    displayMovieInfo(movie2);
    cout << endl;

    return 0;
}
