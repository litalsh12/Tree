#!make -f

demo: TreeDemo.o Tree.o
	g++ -std=c++1z $^ -o demo

test: TreeTest.o Tree.o
	g++ -std=c++1z $^ -o test

%.o: %.cpp
	g++ -std=c++1z -c $< -o $@

TreeTest.o: badkan.hpp Tree.hpp

TreeDemo.o: Tree.hpp

clean:
	rm -f *.o demo test
