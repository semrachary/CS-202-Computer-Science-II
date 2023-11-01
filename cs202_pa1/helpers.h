//Author: Semra Ozdemir
//Purpose: Helper functions - check input, read csv, construct genre, bubble sort 

#ifndef HELPERS_H
#define HELPERS_H

#include<iostream>
using namespace std;


#include<fstream> 
#include "movie.h"
#include "genre.h"


//display menu one
void displayMenuOne();

//display menu two
void displayMenuTwo();

//check that user input is between 1 and 9
int checkInputA(int);
//check that user input is between 1 and 6
int checkInputB(int);

//read CSV file
int readCSV(Movie* movieArray, ifstream& inputFile);

//set genre name for menu
string setMenuGenre(int);

//set genre name by user choice
string setGenreToSort(int);

//construct Genre class
Genre constructGenre(Movie*, int, string);


void bubbleSortSelection(int, Genre& );

void displayMenuThree(Genre g);

char getYesNo();
int getInputOne(int);
int getInputTwo(int );

#endif