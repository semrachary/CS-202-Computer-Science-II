jukebox: main.o song.o helpers.o playlist.o
	g++ -o jukebox main.o song.o helpers.o playlist.o -g

main.o: main.cpp song.h helpers.h
	g++ -c main.cpp 

playlist.o: playlist.cpp playlist.h song.h
	g++ -c playlist.cpp

song.o: song.cpp song.h 
	g++ -c song.cpp

helpers.o: helpers.cpp helpers.h
	g++ -c helpers.cpp

clean:
	rm *.o jukebox