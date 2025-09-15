#include <iostream>
#include "Users.h"
#include "Movie.h"
#include "Review.h"
using namespace std;
void format()
{
	cout << "press any key to continue...";
	system("pause>0");
    system("cls");

}
int main() {
    int choice;

    do {
        cout << "\n--- IEEEMDB Main Menu ---\n";
        cout << "1. Add User\n";
        cout << "2. Show Users\n";
        cout << "3. Add Movie\n";
        cout << "4. Show Movies\n";
        cout << "5. Add Watched Movie to User\n";
        cout << "6. Show User's Watched Movies\n";
        cout << "7. Add Review\n";
        cout << "8. Show All Reviews\n";
        cout << "9. Exit\nChoice: ";
        cin >> choice;
		system("cls");
        switch (choice) {
        case 1: User::addUser(); format(); break;
        case 2: User::showUsers(); format(); break;
        case 3: Movie::addMovie(); format(); break;
        case 4: Movie::showMovies(); format(); break;
        case 5: {
            User::showUsers();
            int uIndex, mIndex;
            cout << "Select user index: "; cin >> uIndex;
            Movie::showMovies();
            cout << "Select movie index: "; cin >> mIndex;
            if (uIndex >= 0 && uIndex < User::getAllUsers().size() &&
                mIndex >= 0 && mIndex < Movie::getAllMovies().size())
                User::getAllUsers()[uIndex].addWatchedMovie(&Movie::getAllMovies()[mIndex]);
            else cout << "Invalid index!\n";
            format();
            break;
        }
        case 6: {
            User::showUsers();
            int uIndex; cout << "Select user index: "; cin >> uIndex;
            if (uIndex >= 0 && uIndex < User::getAllUsers().size())
                User::getAllUsers()[uIndex].showWatchedMovies();
            else cout << "Invalid index!\n";
            format();
            break;
        }
        case 7: Review::addReview(User::getAllUsers(), Movie::getAllMovies());
            format(); break;
        case 8: Review::showReviews(); format(); break;
        case 9: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
