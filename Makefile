# Definindo variáveis de compilação
CXX = g++
CXXFLAGS = -std=c++14 -Wall -g

# Diretórios
SRC_DIR_UNIDADES = Unidades
SRC_DIR_EXERCITO = Exercito
SRC_DIR_CAMPANHA = Campanha
SRC_DIR_BATALHA = Batalha
OBJ_DIR = obj

# Arquivos de origem
SOURCES = main.cpp \
          $(SRC_DIR_UNIDADES)/Aeronave.cpp \
          $(SRC_DIR_UNIDADES)/Infantaria.cpp \
          $(SRC_DIR_UNIDADES)/Unidade.cpp \
          $(SRC_DIR_UNIDADES)/Veiculo.cpp \
          $(SRC_DIR_EXERCITO)/Exercito.cpp \
          $(SRC_DIR_CAMPANHA)/Campanha.cpp \
          $(SRC_DIR_BATALHA)/Date.cpp \
          $(SRC_DIR_BATALHA)/Batalha.cpp

# Arquivos de cabeçalho
HEADERS = $(SRC_DIR_UNIDADES)/Aeronave.h \
          $(SRC_DIR_UNIDADES)/Infantaria.h \
          $(SRC_DIR_UNIDADES)/Unidade.h \
          $(SRC_DIR_UNIDADES)/Veiculo.h \
          $(SRC_DIR_EXERCITO)/Exercito.h \
          $(SRC_DIR_CAMPANHA)/Campanha.h \
          $(SRC_DIR_BATALHA)/Date.h \
          $(SRC_DIR_BATALHA)/Batalha.h

# Arquivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Nome do executável
EXEC = main

# Regra para compilar o programa
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/Unidades $(OBJ_DIR)/Exercito $(OBJ_DIR)/Campanha $(OBJ_DIR)/Batalha
	$(CXX) $(CXXFLAGS) -c $< -o $(OBJ_DIR)/$(@D)/$(@F)

# Limpar arquivos objeto e o executável
clean:
	rm -rf $(OBJECTS) $(EXEC) $(OBJ_DIR)

# Rodar o programa
run: $(EXEC)
	./$(EXEC)




