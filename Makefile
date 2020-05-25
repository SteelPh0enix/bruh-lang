CXX = clang++
CXXFLAGS = -Wall -Wextra -Wpedantic -g
CXXSTANDARD = c++14
CXXOPTIMALIZATION = -O0

MAIN_CXX = interpreter.cpp
OUTPUT_EXEC = interpreter
SOURCE_DIR = src

INCLUDES = -I./$(SOURCE_DIR)/
LIBS =
LFLAGS =

SOURCES = $(filter-out $(MAIN_CXX),$(wildcard $(SOURCE_DIR)/*.cpp))
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: clean

all:	$(OUTPUT_EXEC)
			@echo File list: $(OBJECTS)
			@echo Compilation completed

$(OUTPUT_EXEC): $(OBJECTS)
			$(CXX) $(CXXFLAGS) -std=$(CXXSTANDARD) $(CXXOPTIMALIZATION) $(INCLUDES) $(LFLAGS) $(LIBS) $(MAIN_CXX) -o $(OUTPUT_EXEC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -std=$(CXXSTANDARD) $(CXXOPTIMALIZATION) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o $(SOURCE_DIR)/*.o *~ $(OUTPUT_EXEC)
