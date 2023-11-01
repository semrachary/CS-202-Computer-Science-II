//Author: Semra Ozdemir
//Date Completed: 09/22/23
//Purpose: PA1 - Movie Filter
//Description: This program displays movies that belong to a genre of the user's choosing and sorts them based on the user's preference
#include "helpers.h"
#include "genre.h"
#include "movie.h"

int main(int argc, char* argv[]){
    int userChoice1=-1, userChoice2=-1, userChoice3=-1;
    string genreName;
    Movie movieArray[MAX_MOVIES];

    ifstream inputFile;
    inputFile.open(argv[1]);
    int count=readCSV(movieArray, inputFile);
    int genreNum=8;

    do{ 
        displayMenuOne();
        userChoice1=getInputOne(genreNum);
        if(userChoice1 == (genreNum+1) || userChoice1==-1)
            continue;
        
        string genreToStort = setGenreToSort(userChoice1);              //assign genre string to menu number
        Genre g = constructGenre(movieArray, count, genreToStort);

        userChoice2 = getInputTwo(userChoice1);
        if(userChoice2==6)
            return 0;

        bubbleSortSelection(userChoice2, g); //bubble sort
        
        int userChoice3=-1;
        while(userChoice3<1 || userChoice3>(g.getNumMoviesInGenre()+1)){      
            displayMenuThree(g);

            cin>>userChoice3;
            if(userChoice3==(g.getNumMoviesInGenre()+1)) //==k+1
                return 0;
            if(userChoice3 >= 1 && userChoice3 <=g.getNumMoviesInGenre()+1 )
                g.getMoviesOfGenre()[userChoice3-1].displayMovieData();
        }
        char yesno=getYesNo();
        if (yesno=='n')
            return 0;
    }while (userChoice1 != (genreNum+1));
    inputFile.close();
    return 0;
}