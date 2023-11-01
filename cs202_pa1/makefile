genres: main.o helpers.o movie.o genre.o
	g++ -o genres main.o helpers.o movie.o genre.o

main.o: main.cpp 
	g++ -c main.cpp 

helpers.o: helpers.cpp helpers.h
	g++ -c helpers.cpp 

genre.o: genre.cpp genre.h
	g++ -c genre.cpp

movie.o: movie.cpp movie.h
	g++ -c movie.cpp

clean:
	rm *.o genres