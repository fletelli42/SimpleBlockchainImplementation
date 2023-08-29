# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Include directories
INCLUDES = -Isrc/ -I/opt/homebrew/Cellar/openssl@1.1/1.1.1u/include/

# Libraries
LIBS = -L/opt/homebrew/Cellar/openssl@3/3.1.2/lib/ -lssl -lcrypto

# Source Files
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Object Files
OBJ_DIR = obj
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Executable
EXEC = blockchain_app

# Targets
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Create the obj directory if it doesn't exist
$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean
