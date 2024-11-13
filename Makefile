a.out: main.o pagina.o dicpaginas.o tablahash.o arbol.o nodo.o
	g++ main.o pagina.o dicpaginas.o tablahash.o arbol.o nodo.o

pagina.o: pagina.cpp pagina.hpp
	g++ -c pagina.cpp

nodo.o: nodo.cpp nodo.hpp pagina.hpp
	g++ -c nodo.cpp

arbol.o: arbol.cpp arbol.hpp nodo.hpp pagina.hpp
	g++ -c arbol.cpp

tablahash.o: tablahash.cpp tablahash.hpp pagina.hpp
	g++ -c tablahash.cpp

dicpaginas.o: dicpaginas.cpp dicpaginas.hpp pagina.hpp tablahash.hpp
	g++ -c dicpaginas.cpp

main.o: main.cpp pagina.hpp tablahash.hpp dicpaginas.hpp
	g++ -c main.cpp

clean:
	rm a.out *.o