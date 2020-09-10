P = mypcb
OBJECTS = Helper.o PCBData.o PCBFile.o
CFLAGS = -g -Wall -O3
LDLIBS =
CC = cc

$(P) : $(OBJECTS)
