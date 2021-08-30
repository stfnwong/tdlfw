# Template Deep Learning 
#

# OUTPUT DIRS
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
TEST_DIR=test
PROGRAM_DIR=programs
TEST_BIN_DIR=$(BIN_DIR)/test
TOOL_DIR=tools

# Tool options
CXX=g++
OPT=-O0
CXXFLAGS=-Wall -g2 -std=c++17 $(OPT)
TESTFLAGS=
LDFLAGS=
LIBS= 
TEST_LIBS= 

# Object targets
INCS=-I$(SRC_DIR)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Unit tests 
TEST_SOURCES  = $(wildcard $(TEST_DIR)/*.cpp)
# Tools (program entry points)
TOOL_SOURCES = $(wildcard $(TOOL_DIR)/*.cpp)

.PHONY: clean

# ======== REGULAR OBJECTS ======= #
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ======== UNIT TESTS ======= #
TEST_OBJECTS  := $(TEST_SOURCES:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(TEST_OBJECTS): $(OBJ_DIR)/%.o : $(TEST_DIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@ 


# ==== TEST TARGETS ==== #
TESTS=

$(TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(OBJ_DIR)/$@.o\
		-o $(TEST_BIN_DIR)/$@ $(LIBS) $(TEST_LIBS)


# ==== STANDALONE PROGRAMS ==== #
PROGRAMS=c1_template 

PROGRAM_SOURCES  = $(wildcard $(PROGRAM_DIR)/*.cpp)
PROGRAM_OBJECTS  := $(PROGRAM_SOURCES:$(PROGRAM_DIR)/%.cpp=$(OBJ_DIR)/%.o)
$(PROGRAM_OBJECTS): $(OBJ_DIR)/%.o : $(PROGRAM_DIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@ 


$(PROGRAMS): $(PROGRAM_OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJ_DIR)/$@.o -o $(BIN_DIR)/$@ $(LIBS)


# ======== MAIN TARGETS ======== #
all : test programs

test : $(TESTS)

programs: $(PROGRAMS)

clean:
	rm -rfv *.o $(OBJ_DIR)/*.o 
	rm -rfv bin/test/test_*

print-%:
	@echo $* = $($*)
