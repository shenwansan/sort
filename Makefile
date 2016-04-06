CC:= gcc
SOURCE:=sort.c
OBJS:= $(patsubst %.c,%.o,$(SOURCE))
TARGET:=main
LINKS:=/use/include
LIBS:=/use/libs
FLAGS:=-I$(LINKS) -L$(LIBS) -lpthread -g
CFLAGS:= $(FLAGS)

all:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
.PHONE:clean
xlesn:
	rm -rf *.o
	
