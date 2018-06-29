LIBFLAGS =
CXX = g++

SRC_DIR = ./src/
OBJETOS_DIR = ./objetos/
BUILD_DIR = ./build/

SRCS = main.cpp \
heap.cpp

BIN_NOME = heap

OBJS = $(SRCS:.cpp=.o)

OBJS_FINAL = $(OBJS:%.o=$(OBJETOS_DIR)%.o)

BIN = $(BUILD_DIR)$(BIN_NOME)

all : limparObjetos $(BIN)

$(BIN) : $(OBJS_FINAL)
	$(CXX) $(OBJS_FINAL) -o $(BIN)

$(OBJS_FINAL) : $(OBJETOS_DIR)%.o : $(SRC_DIR)%.cpp
	$(CXX) -c $< -o $@

clean :
	rm $(BIN) $(OBJS_FINAL)

limparObjetos :
	rm $(OBJS_FINAL)
