# Please run 'make new' at first to avoid errors.

# Compiler and options
CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra
# -g : enable debugging
# -std=c++17 : C++17 support
# -Wall : a lot of warnings flags.
# -Wextra : more warning flags.
# -Wl,-subsystem : no console window.

# Project Directories
SRCDIR = src
BINDIR = bin
OBJDIR = bin/obj
HEADDIR = headers

SDL2DIR = C:/mingw_dev_lib

# List all cpp files
SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
# List corresponding obj files to be created.
# 	patsubst  pattern,substitution,text
OBJ_FILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC_FILES))

#INCLPATH specifies the additional include paths
INCLPATH =  -I$(HEADDIR) \
			-I$(SDL2DIR)/include/SDL2

#LIBPATH specifies the additional library paths
LIBPATH = -L$(SDL2DIR)/lib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image


### Quick help
###		$@	Target
###		$<	First prerequisite
###		$^	All prerequisites

#main exe from .o files
renard.exe : $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^ $(LIBPATH) $(LIBS)

#.o files from .cpp files
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLPATH)
## -c : compile/assemble but do not link.

.PHONY: new
.PHONY: clean

# create directories
new:
	mkdir -p $(BINDIR) $(OBJDIR)

# remove object files
clean :
	rm -f $(OBJDIR)/*.o