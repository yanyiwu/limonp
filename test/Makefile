CC = g++
CCOPT = -Wall -O3 -std=c++0x
LINK = g++
LINKOPT =
PACKA = ar
PARCAOPT = rc
DOLINK = $(LINK) $(LINKOPT) -o $@ $^
SOURCES := ArgvContext.cpp io_functs.cpp  main.cpp str_functs.cpp Config.cpp  file_functs.cpp  logger.cpp     MysqlClient.cpp
OBJS := $(patsubst %.cpp,%.o,$(SOURCES))
UTS := $(patsubst %.cpp,%.ut,$(SOURCES))

LINK_LIB := -lmysqlclient
INCS := -I../limonp -I/usr/include/mysql
LIMON_DIR = ../limonp

.INTERMEDIATE: 
.PHONY: clean 

%.o: %.cpp
	$(CC) $(CCOPT) -c -o $@ $<
%.ut: %.cpp 
	$(CC) $(CCOPT) -o $@ $< $(INCS) $(LINK_LIB)

all: $(UTS)

clean:
	rm -f main *.o *.d *.d.* *.ut

sinclude $(SOURCES:.cpp=.d)
%.d:%.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $< > $@.$$$$; \
	sed 's,\($*\).o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
