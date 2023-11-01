//Author: Semra Ozdemir
//Purpose: Creating a "Playlist" class that stores dynamic linked lists of Songs
//Description: "numSong" contains the number of songs in the playlist; "playlistName" refers to the user-provided name for the playlist; 
//"firstSong" is a pointer to the first song in the playlist; and "lastSong" is a pointer to the last song in the playlist

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream> 
using namespace std;
#include "song.h"


class Playlist{
    private:
        int numSong;
        string playlistName;
        Song *firstSong, *lastSong;

        //purpose: private function that checks if song was already added to playlist and adds new song accordingly 
        //input: constant song object
        //output: none
        void addNewSong (const Song); 
        //purpose: private function that removes song from the end of the playlist
        //input: none
        //output: none
        void deleteSong();
        //purpose: private function that removes song at a certain index
        //input: integer containing index
        //output: none
        void deleteSong(int);

    public:
        Playlist(); //should set both pointers to null
        Playlist(string, Song*, Song*);
        Playlist(const Playlist&);
        Playlist& operator=(const Playlist&);
        ~Playlist();

        string getPlaylistName();
        Song* getFirstSong();
        Song* getLastSong();
        int getNumSong();
        void setPlaylistName(string);
        void setFirstSong(Song*);
        void setLastSong(Song*);

        //purpose: inserts a song before a user-selected index
        //input: const song object, integer indicating index
        //output: none
        void addNewSong(const Song, int); //public version
        //purpose: checks if a song already exists in a given playlist by iterating from the beginning to the end
        //input: song object, pointer to a song
        //output: bool indicating whether the song exists
        bool checkIfSongExists(Song s, Song* f);

        friend ostream& operator<<(ostream&, const Playlist&);
        void operator+(Song); 
        void operator-(int);

        //purpose: grabs the song at a user-selected index
        //input: integer containing index
        //output: pointer to a song object at the selected index, nullptr if there is no song at that index
        Song* getSongAtIndex(int);


        //purpose: deletes all the songs in a playlist 
        //input: none
        //output: none
        void deletePlayListObject(); 
};

#endif