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

INCS := -I../cppcommon

LIBDIR = 
LIBDB =  
LIBDBOPT = 
CMDIR = ../cppcommon
CMLIB = cm

# remove the objs after compilation
.INTERMEDIATE: 
.PHONY: clean $(CMLIB)

# This is a suffix rule 
#.c.o: 
%.o: %.cpp
	$(CC) $(CCOPT) -c -o $@ $<
%.ut: %.cpp 
	$(CC) $(CCOPT) -o $@ $< $(INCS) -L$(CMDIR) -l$(CMLIB)

all: $(CMLIB) $(UTS)

$(CMLIB):
	cd $(CMDIR) && $(MAKE)

clean:
	rm -f main *.o *.d *.d.* *.ut
	cd $(CMDIR) && make clean

sinclude $(SOURCES:.cpp=.d)
%.d:%.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $< > $@.$$$$; \
	sed 's,\($*\).o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
