# W. H. Bell
#
# A make file to build a static library

CC = gcc

BASE_DIR = .
INCFLAGS = -I../include/hepevt

TARGET=../lib/libhepevt.a
OBJECTS = hepevt_io.o

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
