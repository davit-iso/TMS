TARGET = MyProject

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	g++ $(OBJ) -o $(TARGET)

%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -f $(TARGET) *.o
