#compiler 
CXX = g++

CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system 

# source files 
SRC = src/main.cpp src/FlatMath.cpp src/vec2.cpp src/FlatBody.cpp src/collisions.cpp  

TARGET =main

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)


run: $(TARGET)
	./$(TARGET)
