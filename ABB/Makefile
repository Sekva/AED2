CFLAGS = -std=c++11

ARVORE_SRC = src/arvore.cpp
NO_SRC = src/no.cpp
MAIN_SRC = src/main.cpp

NO_OBJ = objetos/no.o
ARVORE_OBJ = objetos/arvore.o
MAIN_OBJ = objetos/main.o

NOME_BIN = build/teste
OBJETOS = objetos/main.o ./objetos/no.o objetos/arvore.o

all : bin

bin : $(OBJETOS)
	$(CXX) $(CFLAGS) $(OBJETOS) -o $(NOME_BIN)

objetos/no.o : $(NO_SRC)
	$(CXX) $(CFLAGS) -c $(NO_SRC) -o $(NO_OBJ)

objetos/arvore.o : $(ARVORE_SRC)
	$(CXX) $(CFLAGS) -c $(ARVORE_SRC) -o $(ARVORE_OBJ)

objetos/main.o : $(MAIN_SRC)
	$(CXX) $(CFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)
