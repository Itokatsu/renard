#Compiler and options
CC = g++
CFLAGS = -w -Wl,-subsystem,windows

#Project Directories
SRCDIR = src
BINDIR = bin
OBJDIR = bin/obj

SDL2DIR = C:/mingw_dev_lib

#List all cpp files
SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
#List corresponding obj files to be created.
# patsubst  pattern,substitution,text
OBJ_FILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC_FILES))

#INCLPATH specifies the additional include paths we'll need
INCLPATH = -I$(SDL2DIR)/include/SDL2

#LIBPATH specifies the additional library paths we'll need
LIBPATH = -L$(SDL2DIR)\lib
LIBS = -lmingw32 -lSDL2main -lSDL2

### Quick help
###		$@	Target
###		$<	First prerequisite
###		$^	All prerequisites

#main exe from .o files
renard.exe : $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^ $(LIBPATH) $(LIBS)

#.o files from .cpp files
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLPATH)