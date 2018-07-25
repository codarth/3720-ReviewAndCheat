CXX=g++
CXXFLAGS= -std=c++0x -g -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest -lpthread
SRC_DIR = src
SRCS = ./src/Game.cpp ./src/Player.cpp ./src/Deck.cpp ./src/Card.cpp ./src/Viewer.cpp ./src/Builder.cpp
TEST_DIR = test
GMOCK = /usr/src/gmock/gmock-all.cc
SRC_INCLUDE = include
TEST_INCLUDE = test
INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}
GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage
MEMCHECK_RESULTS = ValgrindOut.xml
STATIC_RESULTS = CppCheckResults.xml
PROGRAM = cardGame
PROGRAM_TEST = testGame
.PHONY: all
all: $(PROGRAM) $(PROGRAM_TEST) memcheck-test coverage docs static
# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o *.gcov *.gcda *.gcno $(COVERAGE_RESULTS) $(PROGRAM) $(PROGRAM_TEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR) $(STATIC_RESULTS)
.PHONY: clean-all
clean-all: clean
	rm -rf $(PROGRAM) $(PROGRAM_TEST)
$(PROGRAM):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRC_DIR)/*.cpp $(LINKFLAGS)
$(PROGRAM_TEST):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) $(TEST_DIR)/*.cpp $(SRCS) $(GMOCK) $(LINKFLAGS) 
	$(PROGRAM_TEST)
memcheck-game: $(PROGRAM)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_RESULTS) $(PROGRAM)
memcheck-test: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_RESULTS) $(PROGRAM_TEST)
coverage: $(PROGRAM_TEST)
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	# Only show code coverage for the source code files (not library files)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/asn1/src/*" -o $(COVERAGE_RESULTS)
	#Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	#Remove all of the generated files from gcov
	rm -f *.gc*
static: ${SRC_DIR}
	cppcheck --verbose --enable=all --xml ${SRC_DIR} ${TEST_DIR} ${INCLUDE} --suppress=missingInclude &> $(STATIC_RESULTS)
docs: ${SRC_INCLUDE}
	doxygen
