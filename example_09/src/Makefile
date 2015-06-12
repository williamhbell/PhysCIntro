# W. H. Bell
# A Makefile to build gen_data.exe

CC=gcc
TARGET=gen_data
OBJECTS=main.o file_io.o gen_data.o plot_data.o gnuplot.o
LIBS=-lm

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) $(LIBS) -o $(TARGET).exe

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET).exe

%.o: %.c
	@echo "**"
	@echo "** Compiling C Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 
