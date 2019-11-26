GCC=g++

Checkpoint4: TestCheckpoint4.o GameCommand.o Model.o Pokemon.o PokemonGym.o PokemonCenter.o Building.o GameObject.o Point2D.o Vector2D.o

Checkpoint3: TestCheckpoint3.o Pokemon.o PokemonGym.o PokemonCenter.o Building.o GameObject.o Point2D.o Vector2D.o
	$(GCC) TestCheckpoint3.o Pokemon.o PokemonGym.o PokemonCenter.o Building.o GameObject.o Point2D.o Vector2D.o -o Checkpoint3

Checkpoint2: TestCheckpoint2.o PokemonGym.o PokemonCenter.o Building.o GameObject.o Point2D.o Vector2D.o
	$(GCC) TestCheckpoint2.o PokemonGym.o PokemonCenter.o Building.o GameObject.o Point2D.o Vector2D.o -o Checkpoint2

Checkpoint1: TestCheckpoint1.o Vector2D.o Point2D.o
	$(GCC) TestCheckpoint1.o Vector2D.o Point2D.o -o Checkpoint1

TestCheckpoint4.o: TestCheckpoint4.cpp
	$(GCC) -c TestCheckpoint4.cpp

TestCheckpoint3.o: TestCheckpoint3.cpp
	$(GCC) -c TestCheckpoint3.cpp

TestCheckpoint2.o: TestCheckpoint2.cpp
	$(GCC) -c TestCheckpoint2.cpp

TestCheckpoint1.o: TestCheckpoint1.cpp
	$(GCC) -c TestCheckpoint1.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

Pokemon.o: Pokemon.cpp
	$(GCC) -c Pokemon.cpp

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
	rm Pokemon.o PokemonGym.o PokemonCenter.o Building.o GameObject.o Point2D.o Vector2D.o TestCheckpoint1.o TestCheckpoint2.o TestCheckpoint3.o Checkpoint1 Checkpoint2 Checkpoint3
