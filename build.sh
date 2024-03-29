mkdir build

g++ -c Main.cpp -g -O0 -o ./build/Main.o

g++ -c Node.cpp -g -O0 -o ./build/Node.o
g++ -c Edge.cpp -g -O0 -o ./build/Edge.o

g++ -c MySTL.cpp -g -O0 -o ./build/MySTL.o
g++ -c Graph.cpp -g -O0 -o ./build/Graph.o
cd ./build

g++ -g -O0 -o test Main.o Edge.o Node.o MySTL.o Graph.o 

cd ..