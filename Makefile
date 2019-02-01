survival: BioLab.o ColChamber.o ComRoom.o Daniels.o Enemy.o Game.o Item.o LoadBay.o main.o MedBay.o NavRoom.o Room.o Xenomorph.o inputVal.o menu.o Medkit.o XenDet.o MineTool.o
	g++ -std=c++0x -g BioLab.o ColChamber.o ComRoom.o Daniels.o Enemy.o Game.o Item.o LoadBay.o main.o MedBay.o NavRoom.o Room.o Xenomorph.o inputVal.o menu.o Medkit.o XenDet.o MineTool.o -o final

BioLab.o: BioLab.cpp
	g++ -std=c++0x -c BioLab.cpp

ColChamber.o: ColChamber.cpp
	g++ -std=c++0x -c ColChamber.cpp

ComRoom.o: ComRoom.cpp
	g++ -std=c++0x -c ComRoom.cpp

Daniels.o: Daniels.cpp
	g++ -std=c++0x -c Daniels.cpp

Enemy.o: Enemy.cpp
	g++ -std=c++0x -c Enemy.cpp

Game.o: Game.cpp
	g++ -std=c++0x -c Game.cpp

Item.o: Item.cpp
	g++ -std=c++0x -c Item.cpp

LoadBay.o: LoadBay.cpp
	g++ -std=c++0x -c LoadBay.cpp

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

MedBay.o: MedBay.cpp
	g++ -std=c++0x -c MedBay.cpp

NavRoom.o: NavRoom.cpp
	g++ -std=c++0x -c NavRoom.cpp

Room.o: Room.cpp
	g++ -std=c++0x -c Room.cpp

Xenomorph.o: Xenomorph.cpp
	g++ -std=c++0x -c Xenomorph.cpp

inputVal.o: inputVal.cpp
	g++ -std=c++0x -c inputVal.cpp

menu.o: menu.cpp
	g++ -std=c++0x -c menu.cpp

Medkit.o: Medkit.cpp
	g++ -std=c++0x -c Medkit.cpp

XenDet.o: XenDet.cpp
	g++ -std=c++0x -c XenDet.cpp

MineTool.o: MineTool.cpp
	g++ -std=c++0x -c MineTool.cpp


clean:
	rm *.o final 

 
	 
