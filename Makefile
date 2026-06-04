CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.
TARGET = lab4

SOURCES = main.cpp \
	$(wildcard Clases/*.cpp) \
	$(wildcard Datatypes/*.cpp) \
	$(wildcard Interfaces/*.cpp) \
	$(wildcard ICollection/*.cpp) \
	$(wildcard ICollection/collections/*.cpp) \
	$(wildcard ICollection/interfaces/*.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
