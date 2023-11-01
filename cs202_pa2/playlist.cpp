#include "playlist.h"
#include <string>
#include <iostream> 
#include <fstream>
using namespace std;
        
Playlist::Playlist(){ 
    numSong=0;
    playlistName = "NONE";
    firstSong = nullptr;
    lastSong = nullptr;
} 

Playlist::Playlist(string p, Song* ptr1, Song* ptr2){ 
    playlistName = p;
    if(ptr1 == nullptr){
        firstSong = lastSong = nullptr;
        return;
    }
    Song* temp = ptr1;
    firstSong = lastSong = new Song;
    firstSong->setArtist(temp->getArtist());
    firstSong->setTitle(temp->getTitle());
    temp = temp->getNextSong();
    while(temp!=nullptr){
        lastSong->setNextSong(new Song);
        lastSong = lastSong->getNextSong();
        lastSong->setArtist(temp->getArtist());
        lastSong->setTitle(temp->getTitle());
        lastSong->setNextSong(nullptr);
        temp = temp->getNextSong();
    }
}

Playlist::Playlist(const Playlist& rhs){
    numSong = rhs.numSong;
    playlistName = rhs.playlistName;
    if(rhs.firstSong == nullptr){
        firstSong = lastSong = nullptr;
        return;
    }
    Song* temp = rhs.firstSong;
    firstSong = lastSong = new Song;
    firstSong->setArtist(temp->getArtist());
    firstSong->setTitle(temp->getTitle());

    temp = temp->getNextSong();
    
    while(temp!=nullptr){
        lastSong->setNextSong(new Song);
        lastSong = lastSong->getNextSong(); 
        lastSong->setArtist(temp->getArtist());
        lastSong->setTitle(temp->getTitle());
        lastSong->setNextSong(nullptr);
        temp = temp->getNextSong();
    }
}

Playlist& Playlist::operator=(const Playlist& rhs){
    numSong = rhs.numSong;
    playlistName = rhs.playlistName;
    if(rhs.firstSong == nullptr){
        firstSong = lastSong = nullptr;
    }
    Song* temp = rhs.firstSong;
    firstSong = lastSong = new Song;
    firstSong->setArtist(temp->getArtist());
    firstSong->setTitle(temp->getTitle());
    temp = temp->getNextSong();
    while(temp!=nullptr){
        lastSong->setNextSong(new Song);
        lastSong = lastSong->getNextSong(); 
        lastSong->setArtist(temp->getArtist());
        lastSong->setTitle(temp->getTitle());
        lastSong->setNextSong(nullptr);
        temp = temp->getNextSong();
    }
    return *this;
}

Playlist::~Playlist(){
    this->deletePlayListObject();
}

int Playlist::getNumSong(){
    return numSong;
}

Song* Playlist::getFirstSong(){
    return firstSong;
}

Song* Playlist::getLastSong(){
    return lastSong;
}

string Playlist::getPlaylistName(){
    return playlistName;
}

void Playlist::setPlaylistName(string n){
    playlistName = n;
}

void Playlist::setFirstSong(Song* f){
    firstSong = f;
}
void Playlist::setLastSong(Song* l){
    lastSong = l;
}

//private addNewSong, used to add to end of playlist
void Playlist::addNewSong(const Song s){
    Song* newSong = new Song;
    if(checkIfSongExists(s, firstSong)==false)
    {
        newSong->setTitle(s.getTitle());
        newSong->setArtist(s.getArtist());
        newSong->setNextSong(nullptr);

        if(firstSong==nullptr){
            firstSong = lastSong = newSong;
        }
        else{
            lastSong->setNextSong(newSong);
        }
        lastSong = newSong;
        numSong++;
    }
}

//public addNewSong, used to insert before a user-selected index
void Playlist::addNewSong(const Song s, int index){

    if(checkIfSongExists(s, firstSong)==true)
        return;
    
    Song* newSong=new Song;
    newSong->setTitle(s.getTitle());
    newSong->setArtist(s.getArtist());

    if(index==1){
        newSong->setNextSong(firstSong);
        firstSong=newSong;
        numSong++;
        return ;
    }

    Song* tmp=firstSong;
    Song* tmpPrevious=nullptr;
    int count=1;
    while (count < index)
    {
        tmpPrevious=tmp;
        tmp = tmp->getNextSong();
        count++;
    }
    newSong->setNextSong(tmp);
    tmpPrevious->setNextSong(newSong);
    numSong++;    
}

bool Playlist::checkIfSongExists(Song s, Song* f){
    Song* tempFirst = f;
    
    while(tempFirst!= nullptr){
        if(tempFirst->getArtist() == s.getArtist() && tempFirst->getTitle() == s.getTitle()){
            return true;
        }
        tempFirst = tempFirst->getNextSong();
    }
    return false;
}

//use it whenever you want to add to end of playlist, this looks like somePlaylist + someSong;
void Playlist::operator+(Song newSong){
    addNewSong(newSong);
}

//private deleteSong, no parameters
void Playlist::deleteSong(){
    if(firstSong == lastSong){
        Song* tmp=firstSong;
        firstSong = lastSong = nullptr;
        numSong--;
        delete tmp;
    }
    else{
        Song* temp=firstSong;
        firstSong = firstSong->getNextSong();
        
        //temp->setNextSong(nullptr);
        delete temp;
        numSong--;
    }

}

//private deleteSong, one int parameter
void Playlist::deleteSong(int index){

    if(index==1){ //first song
        deleteSong();
    }
    else{
        Song* tmp = firstSong;
        Song* tmpPrevious=nullptr;
        int count = 1;
        while (count < index)
        {
            tmpPrevious=tmp;
            tmp = tmp->getNextSong();
            count++;
        }
        tmpPrevious->setNextSong(tmp->getNextSong());
        numSong--;
    }
    if(numSong==0){
        Song* tmp=firstSong;
        firstSong = lastSong = nullptr;
        delete tmp;
    }
}

//use to remove song at a specific index; this would look like somePlaylist - userSelectedIndex
void Playlist::operator-(int i){
    deleteSong(i);
}

Song* Playlist::getSongAtIndex(int index){
    Song* current = firstSong;
    int count = 0;
    while(current != nullptr){
        count++;
        if(count == index){
            return current;
        }
        current = current->getNextSong();
    }
    return nullptr;
}

void Playlist::deletePlayListObject(){
    while(this->getNumSong()!=0){
        this->deleteSong();
    }
}
