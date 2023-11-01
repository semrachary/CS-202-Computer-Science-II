//Author: Semra Ozdemir
//Purpose: Helper functions that manage the playlists - read data, create playlist, delete song, delete playlist, add to playlist -
//in addition to functions that display menus, prompt for user input, and check input.

#ifndef HELPERS_H
#define HELPERS_H

#include <fstream>
//#include "dirent.h"
#include "playlist.h"
#include <iostream>
using namespace std;

#define MAX_SONGS 200

//purpose: uses an input stream to iterate over the entire file, reading each line into a song object, and each song object into a playlist object (using addition operator overload).
//input: input file stream and playlist object
//output: none
void readData(ifstream&, Playlist&);
//purpose: displays all songs in database, and a menu with return to main, exit, or make a song selection.
//input: two playlist objects (first is database, second is empty - to be filled)
//output: bool - indicating menu to return to
bool createNewPlaylist(Playlist&, Playlist&);
//purpose: displays all songs in the playlist, and a menu with return to main or exit; prompts for song(s) to delete.
//input: a playlist object
//output: bool - indicating menu to return to
bool deleteSongFromPlaylist(Playlist&);
//purpose: displays all songs in the playlist, and a menu with return to main, exit, or select song to add; prompts for insertion index.
//input: a playlist object
//output: bool - indicating menu to return to
bool addSongToPlaylist(Playlist&, Playlist&);
//purpose: uses remove() to delete a playlist and displays menu with eturn to main or exit.
//input: a playlist object
//output: bool - indicating menu to return to
bool deletePlaylist(Playlist);


//purpose: loads .txt file of selected playlist
//input: integer indicating user choice and string containing file name
//output: pointer to playlist
Playlist* loadPlayList(int userChoiceThree, string&);
//purpose: checks if a string ends with .txt
//input: two strings passed by reference (a string to search and a suffix)
//output: a bool indicating whether the string contains the suffix
bool endsWith(string const &str, string const &suffix);
//purpose: displays main menu
//input: none
//output: none
void displayMenuOne();
//purpose: prompts for menu one choice
//input: none
//output: user's integer choice for menu one
int getInputOne();
//purpose: displays menu after user chooses to load a playlist, and prompts for input
//input: pointer to a playlist and integer passed by reference indicating menu to return to
//output: none
void loadExecute(Playlist*, int&);
//purpose: displays modify playlist menu and prompts for input
//input: playlist pointer
//output: integer indicating user choice 
int loadModifyPlaylistMenu(Playlist*);
//purpose: prompts user for new playlist name
//input: none
//output: string containing user-selected playlist name
string createPlayList_GetPlayListNameUser();
//purpose: checks whether a playlist name already exists
//input: string containing playlist name to be checked
//output: integer indicating whether playlist exists
int checkIfPlaylistExist(string);
//purpose: displays songs in database
//input: pointer to database playlist
//output: none
void displaySongsInDatabase(Playlist*);
//purpose: displays available playlists and prompts user to choose one to load
//input: integer indicating number of playlists
//output: integer indicating user choice
int getLoadMenuChoice(int&);
//purpose: creates a .txt file containing a playlist to be saved
//input: pointer to a playlist
//output: none
void savePlaylist(Playlist* newPlaylist);
//purpose: displays options for altering loaded playlist and prompts for choice
//input: pointer to a playlist
//output: integer containing user choice
int getSubChoiceLoadPlaylist(Playlist* loadedPlayList);
//purpose: displays available playlists by scanning for playlist files ending it ".txt" 
//input: none
//output: integer indicating number of available playlists
int showAvailablePlaylists();
//purpose: finds playlist name by checking index
//input: integer containg index to be checked
//output: string containing playlist name if it exists, or "none"
string getPlaylistFileName(int);
//purpose: removes <playlist.txt> file
//input: string containing name of playlist to be removed
//output: none
void removeFile(string);
//purpose: updates a playlist .txt file once it is altered 
//input: pointer to a playlist
//output: none
void updatePlaylist(Playlist* );

#endif 
