# W. H. Bell
#
# A make file to build a static library

CC = gcc
F77 = gfortran

BASE_DIR = .
INCFLAGS = 

TARGET=../lib/libpythia.a
OBJECTS = pythia-6.4.28.o
PYTHIA_FILE = pythia-6.4.28.f

$(TARGET): $(PYTHIA_FILE) $(OBJECTS) ../lib
	@echo "**"
	@echo "** Creating library"
	@echo "**" 
	ar -cr $(TARGET) $(OBJECTS)

../lib:
	mkdir -p ../lib

clean:
	@rm -f *.o *~
	@rm -f $(PYTHIA_FILE)

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

pythia-6.4.28.f:
	@echo "**"
	@echo "** Getting PYTHIA version 6.4.28 from web"
	@echo "**"
	wget http://www.hepforge.org/archive/pythia6/pythia-6.4.28.f.gz
	gunzip pythia-6.4.28.f.gz

