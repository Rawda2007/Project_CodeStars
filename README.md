# IEEEMDB - Personal Movie Diary & Social Platform

## Project Description
IEEEMDB is a console-based application that allows users to:
- Add and manage users.
- Add and manage movies.
- Track watched movies per user.
- Write and view reviews and ratings.
- Suggest movies based on watched history.
This is a simplified version of a personal movie diary and social network.

## Functional Requirements
1. Add a new user.
2. Add a new movie.
3. Show list of users.
4. Show list of movies.
5. Add a watched movie to a user.
6. Show user's watched movies.
7. Add a review for a movie by a user.
8. Show all reviews.
9. Suggest movies based on watched history.

## Non-Functional Requirements
1. Fast response time for adding and displaying data.
2. User-friendly console interface.
3. Scalable design to allow adding more features in the future.

## Data Model
- **User:** username, email, watchedMovies (relation with Movie)
- **Movie:** title, genre
- **Review:** user → movie, text, rating

**Relationships:**
- A User can watch multiple Movies.
- A User can write multiple Reviews for Movies.
- Each Review belongs to one User and one Movie.

## High-Level Architecture
The system consists of three main components:
1. **User Management:** manages users and their watched movies.
2. **Movie Management:** manages movies data.
3. **Review Management:** handles reviews and ratings.
[Web/Mobile App] --HTTP--> [API Server] --SQL--> [Database]

## API
- POST /users (register user)
- GET /movies (search movies)
- POST /movies/{id}/reviews (add review)
 
> ![Architecture Diagram]("architecture.png")

## Deep Dives
1. **Scalability:** Using vectors is fine for small data, but for large-scale users/movies, a database is needed.
2. **Data Consistency:** Deleting a movie requires cleaning pointers from User's watched list.
3. **Performance:** Movie suggestions currently use linear search, which can be improved with indexing or maps.

## How to Run
1. Open the project in your IDE (Visual Studio, Code::Blocks, etc.).
2. Build the project.
3. Run the executable.
4. Use the menu to add users, movies, reviews, and view suggestions.


