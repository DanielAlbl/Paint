SOURCE = event.cpp \
	     gui.cpp \
	     main.cpp \
	     output.cpp \
	     rectangleClass.cpp \
	     shapeClass.cpp \
	     utilities.cpp \
         lineClass.cpp \
         ellipseClass.cpp \
         currentSelectionClass.cpp 

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O3 -std=c++11 -I.
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lglut -lGLU -lGL -lm -lpthread

.PHONY: clean

# Targets include all, clean, debug, tar

all : paint

paint: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
		rm -rf *.o *.d paint core main driver performance

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: paint

tar: clean
	tar zcvf paint.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make main  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; /bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

