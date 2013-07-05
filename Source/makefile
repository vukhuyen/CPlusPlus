#Developed after reading GNU make tutorial. Use only with gmake.

# Compiler name given to a variable (called macro) in Makefile
CC=g++

# Parameters given to the compiler
#CFLAGS= -g -Wall
#(maximum warning)

CFLAGS = -s
#(reduces warning and file size)

# Output executables
OUT= ex1.exe ex2.exe ex3.exe ex4.exe ex5.exe ex6.exe ex7.exe ex8.exe \
ex9.exe ex10.exe ex11.exe

#Source
SRC= $(OUT:.exe=.cpp)

#Tell the rule for compilation
#%.o: %.cpp
#	$(CC) $(CFLAGS) -c $*.cpp 				#(notice the tab used)
#The above rule says compile .cpp to .o according to the command specified. $* is a special
#macro which replaces one dependency file from the specified list at a time, without the extension
#name. Some other important macros are $^, $@ and $<.
#We will specify the dependencies later. The command is specified on the next line. One command
#on one line, beginning with a tab. $ substitutes the actual value of the macro.

%.exe: %.cpp
	$(CC) $(CFLAGS) -c $*.cpp
	$(CC) $(CFLAGS) -o $*.exe $*.o

# Now we specify the actual targets
all: $(OUT)
# This says make a target all from the list of files specified by macro OUT. Each specified
#file (.exe) is checked if it is older than its dependencies. We could have specified separate
#dependencies and rules for each file but they are the same in this case. So according to the
#default rule .exe.cpp, timestamp of .o file is checked for which according to rule .o.cpp timestamp
#of .cpp files is checked. The files are compiled and linked as needed.

#suppose a specific file, say  ex5.exe depends on ex5.h also, then specify
#ex5.exe: ex5.cpp ex5.h

RM = rm -rvf
.PHONY: clean
clean: $(OUT)
	-$(RM) $<
#a rule to delete all object files
#type make clean to execute it.


