CC=g++ -g -Wall
CCFLAGS = -I./include -lm
#DEPS = 
ODIR = ./obj
TARGET = root
OBJS = main.o bisection.o fixedPoint.o \
	   newtonRaphson.o
	   
OBJ = $(patsubst %,$(ODIR)/%,$(OBJS));

$(ODIR)/%.o : %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

#$(OBJ) ensures that the *.o files are found in (or picked up from) the obj folder	
$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)
	
.PHONY:clean

clean:
	rm -f $(ODIR)/*.o $(TARGET)