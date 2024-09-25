CC=g++ -g -Wall
CCFLAGS = -I./include -lm
#DEPS = 
ODIR = ./obj
TARGET = matrix
OBJS = main.o guassianElimination.o MatrixClass.o \
	   lowerUpperDecomposition.o guassJacobi.o \
	   guassSeidel.o choleskiFactorization.o \
	   inverseGuassJordan.o

OBJ = $(patsubst %,$(ODIR)/%,$(OBJS));

$(ODIR)/%.o : %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

#$(OBJ) ensures that the *.o files are found in (or picked up from) the obj folder	
$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)
	
.PHONY:clean

clean:
	rm -f $(ODIR)/*.o $(TARGET)