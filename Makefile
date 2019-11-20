GCC=g++

Checkpoint2:TestCheckpoint2.o PokemonGym.o PokemonCenter.o Building.o GameObject.o Point2D.o Vector2D.o
	$(GCC) PokemonGym.o PokemonCenter.o Building.o TestCheckpoint2.o GameObject.o Point2D.o Vector2D.o -o Checkpoint2

TestCheckpoint2.o: TestCheckpoint2.cpp
	$(GCC) -c TestCheckpoint2.cpp

PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp

PokemonCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp

Building.o: Building.cpp
	$(GCC) -c Building.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp

clean:
	rm PokemonGym.o PokemonCenter.o Building.o TestCheckpoint2.o GameObject.o Point2D.o Vector2D.o Checkpoint1
