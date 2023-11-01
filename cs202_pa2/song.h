//Author: Semra Ozdemir
//Purpose: Creating a "Song" class that stores Song objects
//Description: "title" refers to the song title; "artist" indicates the singer; and "nextSong" is a pointer that points to the next song.

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream> 
using namespace std;

class Song{
    private:
        string title;
        string artist;
        Song* nextSong;
    public:
        Song(); //should set next song pointer to null 
        Song(string, string);
        Song(const Song&);

        string getTitle() const;
        string getArtist() const;
        Song* getNextSong() const;

        void setTitle(string);
        void setArtist(string);
        void setNextSong(Song*);

        Song& operator=(const Song&);
        //insertion operator overload
        friend ostream& operator<< (ostream&, const Song&);
        
        ~Song();
};

#endif
