#include "genre.h"

Genre::Genre(){
        genreOfObject = "NONE";
        moviesOfGenre[MAX_MOVIES];
        numMoviesInGenre = 0;
}

Genre::Genre(string s){
        genreOfObject = s;
}

Genre::Genre(const Genre& org){
        genreOfObject = org.genreOfObject;
        for(int i = 0; i < org.numMoviesInGenre; i++){
                moviesOfGenre[i] = org.moviesOfGenre[i];
        }
       numMoviesInGenre = org.numMoviesInGenre;
}

void Genre::update(Movie* ordered){

        for(int i=0; i<numMoviesInGenre; i++)
                moviesOfGenre[i]=ordered[i];
}


void Genre::swap(int i, int j)
{
        Movie temp=moviesOfGenre[i];
        moviesOfGenre[i]=moviesOfGenre[j];
        moviesOfGenre[j]=temp;
}


void Genre::setGenreOfObject(string s){
        genreOfObject = s;
}
        
string Genre::getGenreOfObject(){
        return genreOfObject;
}

void Genre::addMoviesToGenre(Movie t){
        moviesOfGenre[numMoviesInGenre] = t;
        numMoviesInGenre++;
}

Movie* Genre::getMoviesOfGenre(){
        return moviesOfGenre;
}

void Genre::setNumMoviesInGenre(int n){
        numMoviesInGenre = n;
}

int Genre::getNumMoviesInGenre(){
        return numMoviesInGenre;
}

void Genre::displayGenreData(){
        cout<<"Genre: "<<genreOfObject<<endl;
        for(int i = 0; i < numMoviesInGenre; i++){
                moviesOfGenre[i].displayMovieData();
        }
}
