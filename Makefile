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
TARGET = renard.exe
LIBDIR = lib

# List all cpp files
SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
# List corresponding obj files to be created.
# 	patsubst  pattern,substitution,text
OBJ_FILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC_FILES))

# INCLPATH specifies the additional include paths
INCLPATH =  -I$(HEADDIR) \
			-I$(LIBDIR)/SDL2-2.0.8/include/SDL2 \
			-I$(LIBDIR)/SDL2_image-2.0.3/include/SDL2 \
			-I$(LIBDIR)/SDL2_ttf-2.0.14/include/SDL2 \
			-I$(LIBDIR)/SDL2_mixer-2.0.2/include/SDL2

# LIBPATH specifies the additional library paths
LIBPATH = 	-L$(LIBDIR)/SDL2-2.0.8/lib \
			-L$(LIBDIR)/SDL2_image-2.0.3/lib \
			-L$(LIBDIR)/SDL2_ttf-2.0.14/lib \
			-L$(LIBDIR)/SDL2_mixer-2.0.2/lib

LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

### Quick help
###		$@	Target
###		$<	First prerequisite
###		$^	All prerequisites

# main exe from .o files
$(TARGET) : $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^ $(LIBPATH) $(LIBS)

# .o files from .cpp files
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLPATH)
## -c : compile/assemble but do not link.

