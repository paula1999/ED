INC = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g -c

# ************ Compilación de módulos ************

usodiccionario: $(OBJ)/usodiccionario.o
	$(CXX) -o $(BIN)/usodiccionario $(OBJ)/usodiccionario.o -I$(INC)

usoguia: $(OBJ)/usoguia.o $(OBJ)/guiatlf.o
	$(CXX) -o $(BIN)/usoguia $(OBJ)/usoguia.o $(OBJ)/guiatlf.o -I$(INC)


$(OBJ)/usodiccionario.o: $(INC)/diccionario.cpp $(SRC)/usodiccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usodiccionario.o $(SRC)/usodiccionario.cpp -I$(INC)

$(OBJ)/usoguia.o: $(SRC)/usoguia.cpp $(SRC)/guiatlf.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usoguia.o $(SRC)/usoguia.cpp -I$(INC)

$(OBJ)/guiatlf.o: $(SRC)/guiatlf.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/guiatlf.o $(SRC)/guiatlf.cpp -I$(INC)

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*
	rm -f $(BIN)/*

mrproper : clean
	rm -r $(DOC)/html $(DOC)/latex

# ************ Documentación ***********
doxy :
	doxygen $(DOC)/dic-tel.doxy
