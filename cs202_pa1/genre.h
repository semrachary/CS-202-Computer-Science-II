//Author: Semra Ozdemir
//Purpose: Constructing "Genre" class that stores arrays of movies belonging to a specific genre
//Description: "genreOfObject" refers to the genre of the entire object, "moviesOfGenre[]" contains the movies belonging to the said genre, 
//and "numMoviesInGenre" indicates the number of movies that belong to the said genre

#ifndef GENRE_H
#define GENRE_H

#include<iostream>
using namespace std;
#include<fstream> 
#include "movie.h"


class Genre{
    private:
        string genreOfObject;
        Movie moviesOfGenre[MAX_MOVIES];
        int numMoviesInGenre;
   
    public:
        Genre();
        Genre(string);
        Genre(const Genre&);

        void setGenreOfObject(string);

        void update(Movie*);

        string getGenreOfObject();

        void addMoviesToGenre(Movie);
        Movie* getMoviesOfGenre();

        void setNumMoviesInGenre(int);
        int getNumMoviesInGenre();

        void swap(int , int);


        void displayGenreData();
        
};

#endif