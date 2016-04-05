# This is the makefile for testing Institute Security Management
# Course Project CS223 - Software Engineering

# Authors 
# Anmol

# Below is the output of tree command on root project
#
# # .
# ├── googletest
# │   ├── CMakeLists.txt
# │   ├── googlemock
# │   └── googletest
# ├── ism
#     ├── ism.cpp
#     ├── ism.o
#     ├── Makefile
#     ├── output.txt
#     ├── README.md
#     ├── sample1_unittest
#     ├── srs3.docx
#     ├── test_ism


# The main googletest and google mock directories.
GTEST_DIR = /home/anmol/git/googletest/googletest
GMOCK_DIR = /home/anmol/git/googletest/googlemock

# The user code directory.
USER_DIR = .

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = sample1_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h                

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

# Builds gtest.a and gtest_main.a.
# Don't tweak these, these are system generated library files.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

# sample1.o : $(USER_DIR)/ism.cpp $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/ism.cpp

sample1_unittest.o : $(USER_DIR)/test_ism.cc $(USER_DIR)/ism.cpp \
                     $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS)  $(CXXFLAGS) -c $(USER_DIR)/test_ism.cc

sample1_unittest : test_ism.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
