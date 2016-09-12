CFLAGS = -std=c++11

NitroTest: Main.o CommandLine.o FileLoader.o IntersectionsCalculator.o OutputGenerator.o Rectangle.o Utils.o
	g++ -o ./bin/NitroTest ./NitroTest/obj/Main.o ./NitroTest/obj/CommandLine.o ./NitroTest/obj/FileLoader.o ./NitroTest/obj/IntersectionsCalculator.o ./NitroTest/obj/OutputGenerator.o ./NitroTest/obj/Rectangle.o ./NitroTest/obj/Utils.o

Main.o: ./NitroTest/Src/Main.cpp
	g++ -I ./NitroTest/Inc $(CFLAGS) -c ./NitroTest/Src/Main.cpp -o ./NitroTest/obj/Main.o

CommandLine.o: ./NitroTest/Src/CommandLine.cpp
	g++ -I ./NitroTest/Inc $(CFLAGS) -c ./NitroTest/Src/CommandLine.cpp -o ./NitroTest/obj/CommandLine.o

FileLoader.o: ./NitroTest/Src/FileLoader.cpp
	g++ -I ./NitroTest/Inc $(CFLAGS) -c ./NitroTest/Src/FileLoader.cpp -o ./NitroTest/obj/FileLoader.o

IntersectionsCalculator.o: ./NitroTest/Src/IntersectionsCalculator.cpp
	g++ -I ./NitroTest/Inc $(CFLAGS) -c ./NitroTest/Src/IntersectionsCalculator.cpp -o ./NitroTest/obj/IntersectionsCalculator.o

OutputGenerator.o: ./NitroTest/Src/OutputGenerator.cpp
	g++ -I ./NitroTest/Inc $(CFLAGS) -c ./NitroTest/Src/OutputGenerator.cpp -o ./NitroTest/obj/OutputGenerator.o

Rectangle.o: ./NitroTest/Src/Rectangle.cpp
	g++ -I ./NitroTest/Inc $(CFLAGS) -c ./NitroTest/Src/Rectangle.cpp -o ./NitroTest/obj/Rectangle.o

Utils.o: ./NitroTest/Src/Utils.cpp
	g++ -I ./NitroTest/Inc $(CFLAGS) -c ./NitroTest/Src/Utils.cpp -o ./NitroTest/obj/Utils.o

clean:
	\rm ./NitroTest/obj/*.*
	\rm ./bin/*.*