all: clean dijkstra dial radixheap

dijkstra:
	g++ -O3 -Wall -Wextra -std=c++17 -pedantic ./app/dijkstra.cpp ./src/*.cpp -I./lib -I./inc -o dijkstra
	
dial:
	g++ -O3 -Wall -Wextra -std=c++17 -pedantic ./app/dial.cpp ./src/*.cpp -I./lib -I./inc -o dial
	
radixheap:
	g++ -O3 -Wall -Wextra -std=c++17 -pedantic ./app/radixheap.cpp ./src/*.cpp -I./lib -I./inc -o radixheap

clean:
	rm -f dijkstra dial radixheap test

test:
	g++ -O3 -Wall -Wextra -std=c++17 -pedantic ./app/test.cpp ./src/*.cpp -I./lib -I./inc -o test
	./test