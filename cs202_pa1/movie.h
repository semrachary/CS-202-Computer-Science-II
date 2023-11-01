//Author: Semra Ozdemir
//Purpose: Constructing "Movie" class that contains IMDB information about each movie
//Description: 'title' refers to the movie name, 'genres[]' indicates the genres of the said movie, 'actors[]' lists 
//the main actors of the said movie, 'description' gives a brief description of the plot, 'director' contains the movie director, 
//'year' is when the movie was released, 'rating' is the IMDB score, 'metascore' is the Metacritic score, 'actorCount' contains a tally of 
//the actors, and 'genreCount' contains a tally of the genres.

#ifndef MOVIE_H
#define MOVIE_H

#include<iostream>
using namespace std;

#include<string>
#include<fstream> 

#define MAX_ACTORS 5
#define MAX_GENRES 4
#define MAX_MOVIES 500

class Movie{
    private:
        string title;
        string genres[MAX_GENRES];
        string actors[MAX_ACTORS];
        string description;
        string director;
        int year;
        double rating;
        int metascore;
        int actorCount;
        int genreCount;

    public:
        Movie();
        Movie(string, string[], string[], string, string, int, double, int, int, int);
        Movie(const Movie&);

        void setTitle(string);
        string getTitle();
        
        void addGenres(string);
        const string* getGenres() const;

        void addActors(string);
        string* getActors();
        
        void setDescription(string);
        string getDescription();

        void setDirector(string);
        string getDirector();

        void setYear(int);
        int getYear();

        void setRating(double);
        double getRating();

        void setMetascore(int);
        int getMetascore();

        int getActorCount();

        int getGenreCount();
        
        void displayMovieData();

};

#endif