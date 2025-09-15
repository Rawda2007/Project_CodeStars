#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Users.h"
#include "Movie.h"
using namespace std;

class Review {
private:
    User* user;
    Movie* movie;
    string text;
    int rating;
    static vector<Review> reviews;

public:
    Review(User* u, Movie* m, string t, int r) : user(u), movie(m), text(t), rating(r) {}

    static void addReview(vector<User>& users, vector<Movie>& movies) {
        if (users.empty() || movies.empty()) {
            cout << "No users or movies available!\n";
            return;
        }

        int uIndex, mIndex;
        cout << "Select user index:\n";
        for (int i = 0; i < users.size(); i++)
            cout << i << ". " << users[i].getUsername() << endl;
        cin >> uIndex;

        cout << "Select movie index:\n";
        for (int i = 0; i < movies.size(); i++)
            cout << i << ". " << movies[i].getTitle() << endl;
        cin >> mIndex;

        cin.ignore();
        string text;
        int rating;
        cout << "Enter review text: "; getline(cin, text);
        cout << "Enter rating (1-5): "; cin >> rating;

        reviews.push_back(Review(&users[uIndex], &movies[mIndex], text, rating));
        cout << "Review added!\n";
    }

    static void showReviews() {
        cout << "\nAll Reviews:\n";
        if (reviews.empty()) { cout << "No reviews yet.\n"; return; }
        for (auto& r : reviews)
            cout << r.user->getUsername() << " reviewed " << r.movie->getTitle()
            << " | Rating: " << r.rating << " | " << r.text << endl;
    }
};

vector<Review> Review::reviews;
