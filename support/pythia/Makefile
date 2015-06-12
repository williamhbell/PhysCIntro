# W. H. Bell
#
# A make file to build a static library

CC = gcc
F77 = g77

BASE_DIR = .
INCFLAGS = -I$(BASE_DIR)/include

TARGET=../lib/libpythia.a
OBJECTS = pythia6405.o

$(TARGET): $(OBJECTS)
	@echo "**"
	@echo "** Creating library"
	@echo "**" 
	ar -cr $(TARGET) $(OBJECTS)

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET)

%.o: %.c
	@echo "**"
	@echo "** Compiling C Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $<

%.o: %.f
	@echo "**"
	@echo "** Compiling Fortran Source"
	@echo "**"
	$(F77) -O -c $(INCFLAGS) $<
