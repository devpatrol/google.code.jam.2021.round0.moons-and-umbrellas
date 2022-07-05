all: App
	./App

App: run
	rm -rf *.o
	clear

run: ./solution-teamCPP/main.cpp
	g++ ./solution-teamCPP/main.cpp -o App