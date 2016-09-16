#/bin/bash
BINFOLDER=./bin/
OBJFOLDER=./NitroTest/obj/

if [ ! -d $BINFOLDER ]
then
   mkdir $BINFOLDER 
fi

if [ ! -d $OBJFOLDER ]
then
	mkdir $OBJFOLDER
fi

make clean

make
