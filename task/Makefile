all: task.run

# Which compiler
CC = gcc
CXX = g++

# wthat is the objects
OBJ = main.o task1.o task2.o task3.o

# The source file
# ROBOT_SRC = robot.cpp ecrt.h
# DRIVES_SRC = drives2.c ecrt.h
# Where to install
#INSTDIR = /usr/sbin

# Where are include files kept
INCLUDE = /usr/xenomai/include

# Options for C development
CFLAGS = -g -Wall

# Options for C++ development
CXXFLAGS = -g -Wall -std=c++11

# Where to link liberary
ECAT_LIBPATH =/opt/etherlab/lib 
XENO_LIBPATH =/usr/xenomai/lib

# Which to link
ECAT_LIBVAR = -lethercat_rtdm 
XENO_LIBVAR = -lnative -lrtdm -lxenomai
# Options for release
# CFLAGS = -O -Wall -ansi

task.run: $(OBJ)
	$(CC) -o $@ $(OBJ) -L$(XENO_LIBPATH) $(XENO_LIBVAR)

main.o: main.c task1.h task2.h task3.h
	$(CC) -I$(INCLUDE) $(CCFLAGS) -c $<

task1.o: task1.c task1.h
	$(CC) -I$(INCLUDE) $(CCFLAGS) -c $<

task2.o: task2.c task2.h
	$(CC) -I$(INCLUDE) $(CCFLAGS) -c $<
task3.o: task3.c task3.h
	$(CC) -I$(INCLUDE) $(CCFLAGS) -c $<

#ecat_dc.o: ecat_dc.c ecat_dc.h ecrt.h
#	$(CC) -I$(INCLUDE) $(CFLAGS) -c $<
#2.o: 2.c a.h b.h
#	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.c
#3.o: 3.c b.h c.h
#	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.c

.PHONY:clean
clean:
	-rm -f *.o
	-rm -f *.run

#install: myapp
#	@if [ -d $(INSTDIR) ]; \
		then \
		cp myapp $(INSTDIR);\
		chmod a+x $(INSTDIR)/myapp;\
		chmod og-w $(INSTDIR)/myapp;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi