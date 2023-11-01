#include "helpers.h"

//purpose: displays menu of genres
//input: none
//output: a menu with 9 options
void displayMenuOne(){
    cout<<"1. SciFi"<<endl;
        cout<<"2. Fantasy"<<endl; 
        cout<<"3. Biography/Documentary"<<endl; 
        cout<<"4. Romance"<<endl; 
        cout<<"5. Comedy"<<endl; 
        cout<<"6. Horror"<<endl;  
        cout<<"7. Drama"<<endl; 
        cout<<"8. Family"<<endl;
        cout<<"9. EXIT"<<endl;        
        cout<<"=========================================================\n";
        cout<<"Which genre of movie would you like to view (enter 1 - 9)? ";
}


//purpose: displays menu with sorting options
//input: none
//output: a menu with 6 options
void displayMenuTwo(){
    cout<<"1. Alphabetically by title"<<endl;
            cout<<"2. Alphabetically by director last name"<<endl;
            cout<<"3. Numerically by year"<<endl;
            cout<<"4. Numerically by rating"<<endl;
            cout<<"5. Numerically by metascore"<<endl;
            cout<<"6. Exit"<<endl;
            cout<<"=========================================================\n";
}

//purpose: displays last menu containing films of the selected genre
//input: a Genre object
//output: a list of movies in the genre
void displayMenuThree(Genre g)
{
    for(int k=0; k < g.getNumMoviesInGenre(); k++){
        cout<<k+1<<". "<<g.getMoviesOfGenre()[k].getTitle()<<endl;                            
    }
    cout<<g.getNumMoviesInGenre()+1<<". Exit"<<endl;
    cout<<"======================================="<<endl;

    cout<<"Which movie would you like to view? ";
}

//purpose: prompts user for choice on viewing more movies
//input: none
//output: a char indicating yes (y) or no (n)
char getYesNo()
{
    char yesno='.';
    while(yesno!='y' && yesno!='n'){
        cout<<"Would you like to select another movie(y/n)? ";
        cin>>yesno;
    }
    return yesno;
}

//purpose: prompts user for choice on first menu displaying genres
//input: the number of total genres
//output: user's menu choice (int)
int getInputOne(int genreNum){
    int userChoice1=-1;
    cin>>userChoice1;
    if(userChoice1<1 || userChoice1>(genreNum+1)){
        cout<<"Invalid entry!\n";    
        //continue;
    }
    return userChoice1;
}

//purpose: prompts user for choice on second menu displaying sorting options
//input: user's first choice (int)
//output: user's second menu choice (int)
int getInputTwo(int userChoice1){
    int userChoice2=-1; 
    do{
        displayMenuTwo();
        cout<<"How would you like to view "<<setMenuGenre(userChoice1)<< " movies? ";
        cin>>userChoice2;
        if(userChoice2==6)
            return userChoice2;
    }while(checkInputB(userChoice2)!=1);
    
    return userChoice2;
}

//purpose: check's that user's second choice is in the right range
//input: user's second choice (int)
//output: int indicating validity of entered input
int checkInputB(int userInput){
    if(userInput < 1 || userInput > 6){
        cout<<"Invalid entry!\n";
        return -1;
    }
    return 1;
}

//purpose: reads CSV file
//input: Movie array, input file stream
//output: number of movies read from file
int readCSV(Movie* movieArray, ifstream& inputFile){
    
    string tempLine = "";

    //remove header
    getline(inputFile, tempLine);
    int mcount=0;

    for(; mcount<MAX_MOVIES; mcount++)
    {
        if(inputFile.eof())
            break;

        //read movies line by line
        //swallow rank
        string rank;
        getline(inputFile, rank, ',');
        
        //store title
        string title;
        getline(inputFile, title, ',');
        
        //swallow quotes
        string quotes1;
        getline(inputFile, quotes1, '\"');

        //store genre list
        string genreList;
        getline(inputFile, genreList, '\"');

        char separator1 = ',';
        string genres[MAX_GENRES];
        string temp1 = "";
        int k=0, l=0, genreCount=0;

        while(genreList[k] != '\0'){
            if(genreList[k] != separator1){
                temp1 += genreList[k];
            }
            else{
                genres[l] = temp1;
                genreCount++;
                temp1.clear();
                l++;
                if(genreList[k+1]==' '){
                    k++;
                }
            }
            k++;
        }
        genres[l] = temp1;
        genreCount++;
        
        //swallow space
        string space;
        getline(inputFile, space, ',');

        //store description
        string description;
        getline(inputFile, description, ',');

        //store director
        string director;
        getline(inputFile, director, ',');

        //swallow quotes
        string quotes2;
        getline(inputFile, quotes2, '\"');

        //store actors
        string actorsString;
        getline(inputFile, actorsString, '\"');

        char separator = ',';
        string actors[MAX_ACTORS];
        string temp = "";
        int j=0, i=0, actorCount=0;

        while(actorsString[i] != '\0'){
            if(actorsString[i] != separator){
                temp += actorsString[i];
            }
            else{
                actors[j] = temp;
                actorCount++;
                temp.clear();
                j++;
                if(actorsString[i+1]==' '){
                    i++;
                }
            }
            i++;
        }
        actors[j] = temp;
        actorCount++;

        //swallow comma 
        string comma;
        getline(inputFile, comma, ',');

        //store year
        string year;
        getline(inputFile, year, ',');
        int yearInt = stoi(year);

        //swallow runtime
        string runtime;
        getline(inputFile, runtime, ',');

        //store rating
        string rating;
        getline(inputFile, rating, ',');
        double ratingDouble = stof(rating);

        //swallow votes
        string votes;
        getline(inputFile, votes, ',');

        //swallow revenue
        string revenue;
        getline(inputFile, revenue, ',');

        //store metascore
        string metascore;
        getline(inputFile, metascore);
        int msInt = stoi(metascore);

        Movie newMovie(title, genres, actors, description, director, yearInt, ratingDouble, msInt, actorCount, genreCount);
        movieArray[mcount]=newMovie;
    }
    return mcount;
}

//purpose: sets the name of the genre to appear in question asking how user would like to see X movies
//input: user choice one
//output: name of the genre (string)
string setMenuGenre(int uChoice1){
    string genreName;
    switch(uChoice1){
            case 1: 
                genreName = "Sci-Fi";
                break;
            case 2: 
                genreName = "Fantasy";
                break;
            case 3: 
                genreName = "Biography/Documentary";
                break;
            case 4: 
                genreName = "Romance";
                break;
            case 5: 
                genreName = "Comedy";
                break;
            case 6: 
                genreName = "Horror"; 
                break;
            case 7: 
                genreName = "Drama";
                break;
            case 8: 
                genreName = "Family"; 
                break;
        }
    return genreName;
}

//purpose: sets the name of the genre to appear in search for genre in genres array
//input: user choice one (int)
//output: name of the genre (string)
string setGenreToSort(int uChoice){
    string genreN;
    switch(uChoice){
    case 1: 
        genreN = "Sci-Fi";
        break;
    case 2: 
        genreN = "Fantasy";
        break;
    case 3: 
        genreN = "Biography";
        break;
    case 4: 
        genreN = "Romance";
        break;
    case 5: 
        genreN = "Comedy";
        break;
    case 6: 
        genreN = "Horror"; 
        break;
    case 7: 
        genreN = "Drama";
        break;
    case 8: 
        genreN = "Family"; 
        break;
    }
    return genreN;
}

//purpose: constructs genre object
//input: Movie array, number of movies (int), genre selected (string)
//output: Genre object
Genre constructGenre(Movie* movieArray, int numMovies, string genre){ 
    Genre newObj;
    newObj.setGenreOfObject(genre);

    for(int i = 0; i < numMovies; i++){
        int genreC = movieArray[i].getGenreCount();
        for(int j = 0; j < genreC; j++){
            if(movieArray[i].getGenres()[j] == genre){
                    newObj.addMoviesToGenre(movieArray[i]);
            }
        }
    }
    return newObj;
}

//purpose: sorts movie array based on user choice
//input: user choice (int), Genre array
//output: none
void bubbleSortSelection(int userChoice, Genre& genre)
{
    int countMov=genre.getNumMoviesInGenre();
    if(countMov<2)
        return;

    bool sorted=false;
    int last=countMov-1;

    for(int i=0; (i<last) && !sorted; i++)
    {
        sorted=true;
        for(int j=last; j>i; j--)
        {
            if(userChoice==1)
            {
                if(genre.getMoviesOfGenre()[j-1].getTitle() > genre.getMoviesOfGenre()[j].getTitle()){
                    genre.swap(j, j-1);
                    sorted=false;
                }
            }
            else if(userChoice==2)
            {
                string dir1=genre.getMoviesOfGenre()[j-1].getDirector();
                string dir2=genre.getMoviesOfGenre()[j].getDirector();
                string dir1Lastname=dir1.substr(dir1.find_last_of(" ")+1);
                string dir2Lastname=dir2.substr(dir2.find_last_of(" ")+1);
                               
                if(dir1Lastname > dir2Lastname){
                    genre.swap(j, j-1);
                    sorted=false;
                }
            } 
            else if(userChoice==3)
            {
                if(genre.getMoviesOfGenre()[j-1].getYear() > genre.getMoviesOfGenre()[j].getYear()){
                    genre.swap(j, j-1);
                    sorted=false;
                }
                else if(genre.getMoviesOfGenre()[j-1].getYear() == genre.getMoviesOfGenre()[j].getYear()){
                    if(genre.getMoviesOfGenre()[j-1].getTitle() > genre.getMoviesOfGenre()[j].getTitle()){
                        genre.swap(j, j-1);
                        sorted=false;
                    }
                }
            }
            else if(userChoice==4)
            {
                if(genre.getMoviesOfGenre()[j-1].getRating() < genre.getMoviesOfGenre()[j].getRating()){
                    genre.swap(j, j-1);
                    sorted=false;
                }
                else if(genre.getMoviesOfGenre()[j-1].getRating() == genre.getMoviesOfGenre()[j].getRating()){
                    if(genre.getMoviesOfGenre()[j-1].getTitle() > genre.getMoviesOfGenre()[j].getTitle()){
                        genre.swap(j, j-1);
                        sorted=false;
                    }
                }
            }
            else if(userChoice==5)
            {
                if(genre.getMoviesOfGenre()[j-1].getMetascore() < genre.getMoviesOfGenre()[j].getMetascore()){
                    genre.swap(j, j-1);
                    sorted=false;
                }
                else if(genre.getMoviesOfGenre()[j-1].getMetascore() == genre.getMoviesOfGenre()[j].getMetascore()){
                    if(genre.getMoviesOfGenre()[j-1].getTitle() > genre.getMoviesOfGenre()[j].getTitle()){
                        genre.swap(j, j-1);
                        sorted=false;
                    }
                }
            }
            else if (userChoice==6){
                return;
            }
        }
    }
}