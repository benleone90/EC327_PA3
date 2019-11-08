Checkpoint1:TestCheckpoint1.o Point2D.o Vector2D.o
    g++ TestCheckpoint1.o Point2D.o Vector2D.o

TestCheckpoint1.o: TestCheckpoint1.cpp
    g++ -c TestCheckpoint1.cpp

Point2D.o: Point2D.cpp
    g++ -c Point2D.cpp

Vector2D.o: Vector2D.cpp
    g++ -c Point2D.cpp

clean:
    rm TestCheckpoint1.o Point2D.o Vector2D.o Checkpoint1