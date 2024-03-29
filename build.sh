mkdir build

g++ -c Main.cpp -o ./build/Main.o

g++ -c Node.cpp -o ./build/Node.o
g++ -c Edge.cpp -o ./build/Edge.o

g++ -c MySTL.cpp -o ./build/MySTL.o
g++ -c Graph.cpp -o ./build/Graph.o
cd ./build

g++ -o test Main.o Edge.o Node.o MySTL.o Graph.o 

cd ..