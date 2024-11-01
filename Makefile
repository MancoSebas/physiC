#compiler 
CXX = g++

CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system 
#
# source files 
SRC = src/main.cpp

TARGET = main

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)


run: $(TARGET)
	./$(TARGET)
