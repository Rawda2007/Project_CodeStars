#pragma once
#include "Movie.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie;   
class Review;  

class User {
private:
    string username;
    string email;
    vector<Movie*> watchedMovies;
    static vector<User> users;

public:
    User(string u = "", string e = "") : username(u), email(e) {}
    string getUsername() { return username; }

    static void addUser() {
        string u, e;
        cout << "Enter username: "; cin >> u;
        cout << "Enter email: "; cin >> e;
        users.push_back(User(u, e));
        cout << "User added!\n";
    }

    static void showUsers() {
        cout << "\nUsers List:\n";
        if (users.empty()) cout << "No users added yet.\n";
        for (int i = 0; i < users.size(); i++)
            cout << i << ". " << users[i].username << " (" << users[i].email << ")\n";
    }

    void addWatchedMovie(Movie* movie) { watchedMovies.push_back(movie); }

    void showWatchedMovies() {
        cout << username << "'s watched movies:\n";
        if (watchedMovies.empty()) cout << "No watched movies yet.\n";
        for (int i = 0; i < watchedMovies.size(); i++)
            cout << i << ". " << watchedMovies[i]->getTitle()
            << " (" << watchedMovies[i]->getGenre() << ")\n";
    }

    static vector<User>& getAllUsers() { return users; }
};

vector<User> User::users;
