#include "helpers.h"
#include "song.h"
#include "playlist.h"
#include<iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "dirent.h"


ostream& operator<< (ostream& out, const Song& song){
    out << song.title << "-" << song.artist << endl;
    return out;
}

ostream& operator<<(ostream& out, const Playlist& playlist){ 
    int i = 1;
    Song* temp = playlist.firstSong;
    while(temp!=nullptr){
        out << i << ". " << *temp;
        temp = temp->getNextSong();
        i++;
    }
    return out;
}

void readData(ifstream& fin, Playlist& playlist){
    
    while(fin.good()){
        
        string title, artist;
        getline(fin, title, '-');
        getline(fin, artist);
        Song newSong(title, artist);
        playlist + newSong;
    }
}

Playlist* loadPlayList(int userChoice, string& loadedFilename){
    loadedFilename=getPlaylistFileName(userChoice);

    Playlist* loadedPlayList=new Playlist;
    ifstream fin;
    fin.open(loadedFilename);
    readData(fin ,*loadedPlayList);
    fin.close();
        
    string plname=loadedFilename.substr(0, loadedFilename.find(".txt"));
    loadedPlayList->setPlaylistName(plname);

    return loadedPlayList;
}

bool endsWith(string const &str, string const &suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.rfind(suffix) == str.size() - suffix.size();
}

bool createNewPlaylist(Playlist& db, Playlist& npl)
{
    //string newUserPlaylist=createPlayList_GetPlayListNameUser();
    //displaySongsInDatabase(database);
    //Playlist* newPlaylist=new Playlist;
    //newPlaylist->setPlaylistName(newUserPlaylist);
    Playlist* database=&db;
    Playlist* newPlaylist=&npl;

    int userChoice=0;
    while(userChoice!=database->getNumSong()+1 && userChoice!=database->getNumSong()+2)
    {
        cout<<"Make a selection: ";
        cin>>userChoice;

        if(userChoice < 1 || userChoice > database->getNumSong()+2){
            cout<<"Enter correct index"<<endl;
            continue;
        }

        if(userChoice==database->getNumSong()+2) //user choses to exit the program
        {
            if(newPlaylist->getNumSong()==0){                    
                //exitProgram=1;
                return true; 
            }

            cout<<"Would you like to save (y/n): ";
            string saveornot;
            cin>>saveornot;
            if(saveornot=="y")
                savePlaylist(newPlaylist);
            
            //exitProgram=1;
            return true; 
        } 
        else if(userChoice==database->getNumSong()+1) //user choses to finalize playlist
        {
            if(newPlaylist->getNumSong()!=0)
                savePlaylist(newPlaylist);
            //exitProgram=1;
            return true; 
        }
        else{                                           //adding songs
            Song* temp=database->getSongAtIndex(userChoice);
            Song newSong=Song(*temp);
            
            *newPlaylist + newSong;
        }    
    }
    return false;
}

bool deleteSongFromPlaylist(Playlist& input)
{
    int nsong=input.getNumSong();
    int removeModify=0;
    while(input.getNumSong()>0)
    {
        nsong=input.getNumSong();
        cout<<"========"<<input.getPlaylistName()<<"========"<<endl;
        cout<<input<<endl<<endl;

        cout<<nsong+1<<". "<<"Return to Playlist Options Menu."<<endl;
        cout<<nsong+2<<". "<<"Exit Program."<<endl;
    
        cout<<"Select a song: ";
        cin>>removeModify;

        if(removeModify==nsong+1){ //Return to Playlist Options Menu
            return false;
        }
        else if(removeModify==nsong+2){ //Exit Program.
            return true;
        }
        else if(removeModify>0 && removeModify<=input.getNumSong()){
            input - removeModify;
        }

        nsong=input.getNumSong();
    }

    return input.getNumSong()==0;
}

bool addSongToPlaylist(Playlist& db, Playlist& lPLaylist)
{
    Playlist* database=&db;
    Playlist* loadedPlayList=&lPLaylist;

    cout<<*database<<endl;

    int nsong=database->getNumSong();
    cout<<nsong+1<<". "<<"Return to Playlist Options Menu."<<endl;
    cout<<nsong+2<<". "<<"Exit Program."<<endl;

    int addModify=0;
    while(addModify!=nsong+1 && addModify!=nsong+2)
    {
        cout<<"Select a song to add: ";
        cin>>addModify;


        if(addModify<1 || addModify>nsong+2)
            continue;
        
        if(addModify==nsong+1){
            return false;
        }
        else if(addModify==nsong+2){
            return true;
        }
        else{ //add the song
            Song *addedSong=database->getSongAtIndex(addModify);
            string toend;
            cout<<"Add song to end of playlist(y/n)? ";
            cin>>toend;
            if(toend=="y"){
                *loadedPlayList + (*addedSong);
            }
            else{
                cout<<"========"<<loadedPlayList->getPlaylistName()<<"========"<<endl;
                cout<<*loadedPlayList<<endl<<endl;
            
                int indexBefore=0;
                while(indexBefore<1 || indexBefore>loadedPlayList->getNumSong()){
                    cout<<"Which song would you like to insert before? ";
                    cin>>indexBefore;
                }
                loadedPlayList->addNewSong(*addedSong, indexBefore);
            }
        }
    }
    return false;
}

void displayMenuOne(){
    cout << "Welcome to SongStoreSupreme!" << endl;
    cout << "1. Load an existing playlist."<< endl;
    cout << "2. Create a new playlist." << endl;
    cout << "3. EXIT SongStoreSupreme" << endl;
    cout << "Make your selection: ";
}


int getInputOne(){

    int choiceOne = 0;
    while(choiceOne < 1 || choiceOne > 3){ //check user input
        displayMenuOne();
        cin >> choiceOne;
        if(choiceOne < 1 || choiceOne > 3)
            cout<<"Invalid entry!"<<endl;
    }
    return choiceOne;
}

int showAvailablePlaylists(){

    cout<<"The following playlists are currently available:"<<endl;
    
    DIR *directoryPtr = opendir(".");
    struct dirent *directoryEntry;
    
    int numPlaylists = 0;
    if (directoryPtr) 
    {
        while ((directoryEntry = readdir(directoryPtr)) != NULL) {
            string filename = directoryEntry->d_name;
            if(endsWith(filename, ".txt") && filename!="dbSmall.txt" && filename!="dbLarge.txt"){
                numPlaylists++;
                string playlistname=filename.substr(0, filename.find(".txt")); 

                cout<<numPlaylists<<". "<<playlistname<<endl;
            }
        }
        closedir(directoryPtr); //close all directory
    }
    cout<<numPlaylists+1<<". Return to Main Menu."<<endl;
    cout<<numPlaylists+2<<". Exit Program."<<endl;

    return numPlaylists;
}

int getLoadMenuChoice(int& numPlaylist)
{
    int userChoice=0;
    while(userChoice < 1 || userChoice > numPlaylist+2){
        numPlaylist=showAvailablePlaylists();
        cout<<endl<<"Which playlist would you like to load? ";
        cin>>userChoice;
    }
    return userChoice;
}

string getPlaylistFileName(int index){

    DIR *directoryPtr = opendir(".");
    struct dirent *directoryEntry;
    int numPlaylists = 0;
    
    if (directoryPtr) 
    {
        while ((directoryEntry = readdir(directoryPtr)) != NULL) {
            string filename = directoryEntry->d_name;
            if(endsWith(filename, ".txt") && filename!="dbSmall.txt" && filename!="dbLarge.txt"){
                numPlaylists++;
                if(numPlaylists==index)
                    return filename;
            }
        }
        closedir(directoryPtr); //close all directory
    }
    return "none";  
}

int getSubChoiceLoadPlaylist(Playlist* loadedPlayList){

    int subchoice=0;
    while(subchoice<1 || subchoice>4){
        cout<<"========"<<loadedPlayList->getPlaylistName()<<"========"<<endl;
        cout<<*loadedPlayList<<endl<<endl;

        cout<<"1. Modify Playlist."<<endl;
        cout<<"2. Delete Playlist."<<endl;
        cout<<"3. Return to Main Menu."<<endl;
        cout<<"4. Exit Program."<<endl;
        cout<<"What would you like to do with "<<loadedPlayList->getPlaylistName()<<"? ";
        
        cin>>subchoice;
    }
    return subchoice;
}


void removeFile(string filename){
    remove(filename.c_str()); // delete file
}

bool deletePlayList(Playlist loadedPlayList){
    
    string plnamedelete=loadedPlayList.getPlaylistName();
    string loadedFilename=plnamedelete+".txt";
    removeFile(loadedFilename);                 //deletes file
    cout<<plnamedelete<<" deleted!"<<endl;
    cout<<"1. Return to Main Menu."<<endl;
    cout<<"2. Exit Program."<<endl;
    cout<<"What would you like to do? ";

    int deleteinput=0;
    cin>>deleteinput;

    return deleteinput==2;
}

int loadModifyPlaylistMenu(Playlist* loadedPlayList){
    
    int modifyinput=0;

    while(modifyinput<1 || modifyinput>4){
        cout<<"========"<<loadedPlayList->getPlaylistName()<<"========"<<endl;
        cout<<*loadedPlayList<<endl<<endl;

        cout<<"1. Remove Song(s)."<<endl;
        cout<<"2. Add Song(s)."<<endl;
        cout<<"3. Return to Playlist Options Menu."<<endl; 
        cout<<"4. Exit."<<endl;
        cout<<"What would you like to do? ";
        cin>>modifyinput;
    }
    return modifyinput;
}

void loadExecute(Playlist* database, int& exitProgram){
    int numPlaylist=0;
    int userChoice=getLoadMenuChoice(numPlaylist); 
    if(userChoice==numPlaylist+1 || userChoice==numPlaylist+2){      //exit program or return main menu         
        if(userChoice==numPlaylist+2)
            exitProgram=1;
        return;
    }             
    else {                                                          //load
        string loadedFilename;
        Playlist* loadedPlayList=loadPlayList(userChoice, loadedFilename);    

        int returnPlayListOptionMenu=2;
        while(returnPlayListOptionMenu==2){
            returnPlayListOptionMenu=1;
            int subchoiceLoad=getSubChoiceLoadPlaylist(loadedPlayList);

            if(subchoiceLoad==1){           //modify playlist 
                int modifyinput=loadModifyPlaylistMenu(loadedPlayList);
                if(modifyinput==1){      //remove song
                    bool ret=deleteSongFromPlaylist(*loadedPlayList);
                    if(loadedPlayList->getNumSong()>0 && ret==true ){
                        updatePlaylist(loadedPlayList);                        
                        exitProgram=1;
                        return;
                    }
                    if(ret==true){ //all songs deleted
                        removeFile(loadedFilename);
                        cout<<"All songs deleted. Removing playlist."<<endl<<"Exit program (y/n)?"<<endl;
                        string exitmodifyremove;
                        cin>>exitmodifyremove;
                        if(exitmodifyremove=="y")   //exit program
                            exitProgram=1;
                        return;
                    }
                    else
                        returnPlayListOptionMenu=2;
                }
                else if(modifyinput==2){             //add song
                    bool ret=addSongToPlaylist(*database, *loadedPlayList);
                    if(ret==true){
                        exitProgram=1;
                        return;
                    }
                    else
                        returnPlayListOptionMenu=2;
                }
                else if(modifyinput==3)
                    returnPlayListOptionMenu=2;
                else if(modifyinput==4){
                    updatePlaylist(loadedPlayList);
                    exitProgram=1;
                    return;
                }
            }                
            else if(subchoiceLoad==2){                       //delete playlist               
                bool deleteinput=deletePlayList(*loadedPlayList); //delete file and object
                loadedPlayList->deletePlayListObject();
                if(deleteinput==true)
                    exitProgram=1;
                return;                 
            }
            else if(subchoiceLoad==3 || subchoiceLoad==4){   //exit program or return main menu   
                if(subchoiceLoad==4)          
                    exitProgram=1;
                return;
            }
            updatePlaylist(loadedPlayList); 
        }
    }
}


void updatePlaylist(Playlist* loadedPlayList){

    string path=loadedPlayList->getPlaylistName()+".txt";
    remove(path.c_str());
    savePlaylist(loadedPlayList);
}

int checkIfPlaylistExist(string newP){ 
    string path=newP+".txt";
    ifstream f(path.c_str());
    return  f.good();
}

string createPlayList_GetPlayListNameUser(){
    string newUserPlaylist;
    cin.ignore();

    while(1)
    {
        cout << "Playlist name: ";
        //cin.ignore();
        cin.clear();
        cin.sync();
        
        getline(cin, newUserPlaylist);
        //cout<<newUserPlaylist<<endl;
        
        if(checkIfPlaylistExist(newUserPlaylist)==1)    //if exist
            cout<<"Playlist already exist, please enter new playlist name"<<endl;
        else                                            //if playlist does not exist
            break;
    }
    return newUserPlaylist;
}

void displaySongsInDatabase(Playlist* database){

    cout<<"Displaying Available Songs:"<<endl;
    cout<<*database;

    cout<<database->getNumSong()+1<<". Finalize List."<<endl;
    cout<<database->getNumSong()+2<<". Exit Program."<<endl;
}

void savePlaylist(Playlist* newPlaylist){

    string path=newPlaylist->getPlaylistName() + ".txt";
    ofstream myfile;
    myfile.open (path);
    
    Song* tmp=newPlaylist->getFirstSong();
    while(tmp!=nullptr){
        string line=tmp->getTitle()+"-"+tmp->getArtist();
        myfile <<line;
        if(tmp->getNextSong()!=nullptr)
            myfile <<"\n";
        tmp=tmp->getNextSong();
    }
    myfile.close();
}
