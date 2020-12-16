####################################################################
# Makefile for building the skeleton of the ATM machines
#


#
# Definitions
#
CXX = g++ 
CXXFLAGS = -Wall -g -std=c++11
CLINK = $(CXX)
OBJS = skeleton.o simple.o
RM = rm -f
TARGET = ATM
#
# Target Section
#
$(TARGET): $(OBJS)
	$(CLINK) $(CXXFLAGS) -o $(TARGET) $(OBJS)
#
# File Section
#

skeleton.o: skeleton.cpp simple.h
simple.o: simple.cpp simple.h
#
# Cleaning
#
clean:
	$(RM) $(TARGET) *.o *.bak *~"#"* core
