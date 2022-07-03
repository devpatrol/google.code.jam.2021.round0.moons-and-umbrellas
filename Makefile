all: App
	./App

App: run
	rm -rf *.o

run: main.cpp
	g++ main.cpp -o App