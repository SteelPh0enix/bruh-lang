CXX = clang++
CXXFLAGS = -Wall -Wextra -Wpedantic -g
CXXSTANDARD = c++14
CXXOPTIMALIZATION = -O0

MAIN_CXX = interpreter.cpp
OUTPUT_EXEC = interpreter
SOURCE_DIR = src
UTILS_DIR = utils

INCLUDES = -I./$(SOURCE_DIR)/ -I./$(UTILS_DIR)/
LIBS =
LFLAGS =

SOURCE_FILES_CPP = $(wildcard $(SOURCE_DIR)/*.cpp)
UTILS_FILES_CPP = $(wildcard $(UTILS_DIR)/*.cpp)

SOURCES = $(UTILS_FILES_CPP) $(SOURCE_FILES_CPP) $(MAIN_CXX)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: clean

all:	$(OUTPUT_EXEC)
			@echo Compilation completed

$(OUTPUT_EXEC): $(OBJECTS)
			$(CXX) $(CXXFLAGS) -std=$(CXXSTANDARD) $(CXXOPTIMALIZATION) $(INCLUDES) $(LFLAGS) $(LIBS) $(OBJECTS) -o $(OUTPUT_EXEC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -std=$(CXXSTANDARD) $(CXXOPTIMALIZATION) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o $(SOURCE_DIR)/*.o $(UTILS_DIR)/*.o *~ $(OUTPUT_EXEC)
