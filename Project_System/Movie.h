#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string genre;
    static vector<Movie> movies;

public:
    Movie(string t = "", string g = "") : title(t), genre(g) {}

    string getTitle() { return title; }
    string getGenre() { return genre; }

    static void addMovie() {
        string t, g;
        cin.ignore();
        cout << "Enter movie title: ";
        getline(cin, t);
        cout << "Enter genre: ";
        getline(cin, g);
        movies.push_back(Movie(t, g));
        cout << "Movie added!\n";
    }

    static void showMovies() {
        cout << "\nMovies List:\n";
        if (movies.empty()) cout << "No movies added yet.\n";
        for (int i = 0; i < movies.size(); i++)
            cout << i << ". " << movies[i].title << " (" << movies[i].genre << ")\n";
    }

    static vector<Movie>& getAllMovies() { return movies; }
};

vector<Movie> Movie::movies;
