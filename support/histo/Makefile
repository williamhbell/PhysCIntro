# W. H. Bell
#
# A make file to build a static library

CC = gcc

BASE_DIR = .
INCFLAGS = -I../include/histo

TARGET=../lib/libhisto.a
OBJECTS = gnuplot.o histogram.o

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
	$(CC) -O -c $(INCFLAGS) $<
