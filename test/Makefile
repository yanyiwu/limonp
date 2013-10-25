CC = g++
CCOPT = -Wall -O3
LINK = g++
LINKOPT =
PACKA = ar
PARCAOPT = rc
DOLINK = $(LINK) $(LINKOPT) -o $@ $^
SOURCES := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SOURCES))
UTS := $(patsubst %.cpp,%.ut,$(SOURCES))

<<<<<<< HEAD
LIBDIR = 
LIBDB =  
LIBDBOPT = 
CMDIR = ../cppcommon
CMLIB = $(CMDIR)/libcm.a

LINK_LIB := -lmysqlclient
=======
INCS := -I../limonp

LIMON_DIR = ../limonp
>>>>>>> dev

# remove the objs after compilation
.INTERMEDIATE: 
.PHONY: clean 

# This is a suffix rule 
#.c.o: 
%.o: %.cpp
	$(CC) $(CCOPT) -c -o $@ $<
%.ut: %.cpp 
	$(CC) $(CCOPT) -o $@ $< $(INCS) 

<<<<<<< HEAD
all: main

main: main.o $(CMLIB)
	$(CC) $(CCOPT) -o $@ $^ $(LINK_LIB)

$(CMLIB):
	cd $(CMDIR) && $(MAKE)
=======
all: $(UTS)
>>>>>>> dev

clean:
	rm -f main *.o *.d *.d.* *.ut

sinclude $(SOURCES:.cpp=.d)
%.d:%.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $< > $@.$$$$; \
	sed 's,\($*\).o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
