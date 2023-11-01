#include "song.h"

Song::Song(){
    title = "NONE";
    artist = "NONE";
    nextSong = nullptr;
};

Song::Song(string t, string a){
    title = t;
    artist = a;
    nextSong = nullptr;
}

Song::Song(const Song& org){
    title = org.title;
    artist = org.artist;
    nextSong = nullptr;
}

string Song::getTitle() const{
    return title;
}
string Song::getArtist() const{
    return artist;
}
Song* Song::getNextSong()const{
    return nextSong;
}

void Song::setTitle(string t){
    title = t;
}
void Song::setArtist(string a){
    artist = a;
}
void Song::setNextSong(Song* nxt){
    nextSong = nxt;
}

Song& Song::operator=(const Song& rhs){
    title = rhs.title;
    artist = rhs.artist;
    nextSong = rhs.nextSong;
    return *this;
}

ostream& operator<< (ostream& out, Song& song){
    out << song.getTitle() << "-" << song.getArtist() << endl;
    return out;
}
Song::~Song(){}

