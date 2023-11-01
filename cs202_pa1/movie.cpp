#include "movie.h"

Movie::Movie(){
    title = "NONE";
    genres[MAX_GENRES];
    actors[MAX_ACTORS];
    description = "Description placeholder";
    director = "NONE";
    year = 0;
    rating = 0.0;
    metascore = 0;
    actorCount = 0;
    genreCount = 0;
}

Movie::Movie(string t, string g[MAX_GENRES], string a[MAX_ACTORS], string ds, string dr, int y, double r, int ms, int ac, int gc){
    title = t;
    for(int i=0; i<gc; i++)
    {
        genres[i]=g[i];
    }
    for(int i=0; i<ac; i++)
    {
        actors[i]=a[i];
    }
    description = ds;
    director = dr;
    year = y;
    rating = r;
    metascore = ms;
    actorCount = ac;
    genreCount = gc;
}

Movie::Movie(const Movie& org){
    title = org.title;
    for(int i=0; i<org.actorCount; i++){
        actors[i]=org.actors[i];
    }
    for(int i=0; i<org.genreCount; i++){
        genres[i]=org.genres[i];
    }
    description = org.description;
    director = org.director;
    year = org.year;
    rating = org.rating;
    metascore = org.metascore;
    actorCount = org.actorCount;
    genreCount = org.genreCount;
}

void Movie::setTitle(string t){
    title = t;
}
string Movie::getTitle(){
    return title;
};

void Movie::addGenres(string newG){
        genres[genreCount] = newG;
        genreCount++;
};

const string* Movie::getGenres() const{
    return genres;
}

void Movie::addActors(string newA){
    actors[actorCount] = newA;
    actorCount++;
}

string* Movie::getActors(){
    return actors;
}

void Movie::setDescription(string ds){
    description = ds;
}
string Movie::getDescription(){
    return description;
}

void Movie::setDirector(string dr){
    director = dr;
}
string Movie::getDirector(){
    return director;
}

void Movie::setYear(int y){
    year = y;
};
int Movie::getYear(){
    return year;
}

void Movie::setRating(double r){
    rating = r;
}
double Movie::getRating(){
    return rating;
}

void Movie::setMetascore(int ms){
    metascore = ms;
}
int Movie::getMetascore(){
    return metascore;
}

int Movie::getActorCount(){
    return actorCount;   
}

int Movie::getGenreCount(){
     return genreCount;
}

void Movie::displayMovieData(){
    cout<<title<<endl;
    cout<<"Director: "<<director<<endl;
    cout<<"Actors: ";
    for(int i = 0; i < actorCount; i++){
        if (i+1!=actorCount){
            cout<<actors[i]<<" * ";
        }
        else{
            cout<<actors[i];
        }
    }
    cout<<endl;
    cout<<"Year: "<<year<<" "<<"Rating: "<<rating<<" "<<"Meta Score: "<<metascore<<endl;
    cout<<"Description: "<<description<<endl;
}