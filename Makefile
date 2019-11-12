GCC=g++

Checkpoint1:TestCheckpoint1.o GameObject.o Point2D.o Vector2D.o
	$(GCC) TestCheckpoint1.o GameObject.o Point2D.o Vector2D.o -o Checkpoint1

TestCheckpoint1.o: TestCheckpoint1.cpp
	$(GCC) -c TestCheckpoint1.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp

Building.o: Building.cpp
	$(GCC) -c Building.cpp

clean:
	rm TestCheckpoint1.o Building.o GameObject.o Point2D.o Vector2D.o Checkpoint1
