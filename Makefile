# Makefile based off lazy foo SDL tutorial Makefile
# http://lazyfoo.net/
OBJS = test.c

CC = gcc

# change flags to suit your system

INCLUDE_PATHS = -IC:\SDL2\sdl_64\include

LIBRARY_PATHS = -LC:\SDL2\sdl_64\lib


COMPILER_FLAGS = -w -Wl,-subsystem,windows

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

OBJ_NAME = run.exe

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
