
#/bin/bash

RM=/usr/bin/rm -f
PATH=${PWD}
ROOT=${PATH}/..
LDFLAGS=-L ${ROOT}/StaticJSON/sharedlib/ -lstaticjson
CPPFLAGS= -std=c++11
CXX = /usr/bin/g++
INC= -I ${ROOT}/StaticJSON/rapidjson/include/ -I ${ROOT}/StaticJSON/include/ -I ${ROOT}/inc/ -I ${ROOT}/inc_common 
TARGET=${ROOT}/bin/jsonparser

SRCS=jsonparser.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all:jsonparser

jsonparser: $(OBJS)
	$(CXX) $(LDFLAGS) ${CPPFLAGS} -o ${TARGET} $(OBJS)

jsonparser.o:
	$(CXX) $(CPPFLAGS) ${INC} -c jsonparser.cpp
depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) ${INC} -MM $^>>./.depend;

clean:
	$(RM) $(OBJS) ${TARGET} 

include .depend

