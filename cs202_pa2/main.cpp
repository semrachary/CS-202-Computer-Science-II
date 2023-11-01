//Author: Semra Ozdemir
//Date Completed: 10/29/23
//Purpose: PA2 - Playlist Manager 
//Description: This program allows the user to manage (i.e. load, create, delete, add to or remove from) playlists which consist of songs the user has selected from a central database.

#include "helpers.h"

int main(){
    Playlist* database=new Playlist;    //load database
    database->setPlaylistName("dbLarge");
    ifstream fin;
    fin.open("dbLarge.txt");
    readData(fin, *database);
    fin.close();

    int userChoiceOne = 0;
    do{
        userChoiceOne = 0;
        userChoiceOne = getInputOne();

        int exitProgram=0;
        if(userChoiceOne == 1){                                 //Load existing playlist
            loadExecute(database, exitProgram);
            if(exitProgram==1){                                 //exit the program
                return 0;
            }      
        }
        else if(userChoiceOne == 2){                             //Create new playlist
            string newUserPlaylist=createPlayList_GetPlayListNameUser();
            displaySongsInDatabase(database);
            Playlist* newPlaylist=new Playlist;
            newPlaylist->setPlaylistName(newUserPlaylist);

            bool exitProgram=createNewPlaylist(*database, *newPlaylist);  
            if(exitProgram==true){                                 //exit the program
                return 0;
            }      
        }
    }while(userChoiceOne!=3); 
    
    return 0;
}