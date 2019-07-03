INC = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
DOC = ./doc
DATOS = ./datos
CXX = g++
CPPFLAGS = -Wall -g -c

# ************ Compilación de módulos ************

all: diccionario cantidad_letras letras

diccionario: $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o -I$(INC)

cantidad_letras: $(OBJ)/cantidad_letras.o $(OBJ)/conjunto_letras.o $(OBJ)/diccionario.o $(OBJ)/letra.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/conjunto_letras.o $(OBJ)/cantidad_letras.o $(OBJ)/diccionario.o $(OBJ)/letra.o -I$(INC)

letras: $(OBJ)/letras.o $(OBJ)/bolsa_letras.o $(OBJ)/conjunto_letras.o $(OBJ)/letra.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/bolsa_letras.o $(OBJ)/conjunto_letras.o $(OBJ)/letra.o $(OBJ)/diccionario.o -I$(INC)

$(OBJ)/letras.o: $(SRC)/letras.cpp $(SRC)/bolsa_letras.cpp $(SRC)/conjunto_letras.cpp  $(SRC)/diccionario.cpp $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letras.o $(SRC)/letras.cpp -I$(INC)

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I$(INC)

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp -I$(INC)

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp $(SRC)/conjunto_letras.cpp $(SRC)/diccionario.cpp $(OBJ)/letra.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp $(OBJ)/letra.o -I$(INC)

$(OBJ)/bolsa_letras.o: $(SRC)/bolsa_letras.cpp $(SRC)/letra.cpp $(SRC)/conjunto_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/bolsa_letras.o $(SRC)/bolsa_letras.cpp -I$(INC)

$(OBJ)/conjunto_letras.o: $(SRC)/conjunto_letras.cpp $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/conjunto_letras.o $(SRC)/conjunto_letras.cpp -I$(INC)

$(OBJ)/letra.o: $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letra.o $(SRC)/letra.cpp -I$(INC)

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*
	rm -f $(BIN)/*

mrproper : clean
	rm -r $(DOC)/html $(DOC)/latex
	rm $(DATOS)/salida.txt

# ************ Documentación ***********
doxy :
	doxygen $(DOC)/letras.doxy
