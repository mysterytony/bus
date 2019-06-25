CXX = g++-8					# compiler
CXXFLAGS = -std=c++14 -g -Wall -Wextra -MMD
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:.cc=.o)

CPP_CLIENT = cpp_client
CPP_CLIENT_OBJECTS = client.o request.o

DAEMON = daemon
DAEMON_OBJECTS = busd.o daemon.o

DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"

EXECS = ${DAEMON} ${CPP_CLIENT}

#############################################################

.PHONY : all clean

all : ${EXECS}					# build all executables

${CPP_CLIENT} : ${CPP_CLIENT_OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

${DAEMON} : ${DAEMON_OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

#############################################################

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f *.d *.o ${EXECS}

