CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

APP_SRCS = main.cpp Restaurant.cpp Order.cpp MenuItem.cpp Employee.cpp Expense.cpp DateTimeFormatter.cpp
APP_OBJS = $(APP_SRCS:.cpp=.o)

all: restaurant_app

restaurant_app: $(APP_SRCS)
	$(CXX) $(CXXFLAGS) $(APP_SRCS) -o restaurant_app

# Tests (Catch2)

# GoogleTest configuration (override with env vars if needed)
GTEST_INCLUDE ?= /usr/local/include
GTEST_LIB ?= /usr/local/lib
TEST_SRCS = tests/test_datetime.cpp DateTimeFormatter.cpp Order.cpp MenuItem.cpp Employee.cpp Expense.cpp Restaurant.cpp

test: $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_INCLUDE) $(TEST_SRCS) -L$(GTEST_LIB) -lgtest -lgtest_main -pthread -o run_tests
	./run_tests

clean:
	rm -f restaurant_app run_tests *.o
