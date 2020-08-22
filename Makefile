# Makefile based off lazy foo SDL tutorial Makefile
# http://lazyfoo.net/
OBJS = main.c

CC = gcc

COMPILER_FLAGS = -w 

LINKER_FLAGS = -lSDL2

OBJ_NAME = run.out
# change flags to suit your system
ifneq (,$(findstring MINGW,$(uname_S)))
	INCLUDE_PATHS = -IC:\SDL2\sdl_64\include

	LIBRARY_PATHS = -LC:\SDL2\sdl_64\lib
	COMPILER_FLAGS 	+= -Wl
	COMPILER_FLAGS 	+= -subsystem,windows

	LINKER_FLAGS 	+= -lmingw32
	LINKER_FLAGS	+= -lSDL2main

	OBJ_NAME = run.exe
endif




all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
