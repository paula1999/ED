INC = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g -c

all: $(BIN)/pila_max

# ************ Compilación de módulos ************

$(BIN)/pila_max : $(OBJ)/Pila_max.o $(OBJ)/Pila_max_VD.o
	$(CXX) -o $(BIN)/pila_max $(OBJ)/Pila_max.o $(OBJ)/Pila_max_VD.o -I$(INC)

$(OBJ)/Pila_max_VD.o : $(SRC)/Pila_max_VD.cpp $(INC)/VDG.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Pila_max_VD.o $(SRC)/Pila_max_VD.cpp -I$(INC)

$(OBJ)/Pila_max.o : $(SRC)/Pila_max.cpp $(OBJ)/Pila_max_VD.o
		$(CXX) $(CPPFLAGS) -o $(OBJ)/Pila_max.o $(OBJ)/Pila_max_VD.o $(SRC)/Pila_max.cpp -I$(INC)

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*
	rm -f $(BIN)/*

mrproper : clean
	rm -r $(DOC)/html $(DOC)/latex

# ************ Documentación ***********
doxy :
	doxygen $(DOC)/pila_max.doxy
