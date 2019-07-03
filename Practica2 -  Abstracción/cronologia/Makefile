INC = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g -c


all: $(BIN)/prueba


# ************ Compilación de módulos ************

$(BIN)/prueba : $(OBJ)/pruebacronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o
	$(CXX) -o $(BIN)/prueba $(OBJ)/pruebacronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o

$(OBJ)/pruebacronologia.o : $(INC)/Cronologia.h $(INC)/Fecha_Historica.h $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(OBJ)/Cronologia.o : $(INC)/Cronologia.h $(INC)/Fecha_Historica.h $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp

$(OBJ)/Fecha_Historica.o : $(INC)/Fecha_Historica.h $(SRC)/Fecha_Historica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Fecha_Historica.o $(SRC)/Fecha_Historica.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*
	rm -f $(BIN)/* 

mrproper : clean
	rm -r $(DOC)/html $(DOC)/latex

# ************ Documentación ***********
doxy:
	doxygen doc/cronologia.doxy
