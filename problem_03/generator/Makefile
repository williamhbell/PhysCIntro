CC = gcc

TARGET=pptobbar

OBJECTS=main.o 
SUPPORT_DIR=../../support

LIBS=-L$(SUPPORT_DIR)/lib -lpythia -lhepevt -lgfortran -lm
INCFLAGS=-I$(SUPPORT_DIR)/include/pythia -I$(SUPPORT_DIR)/include/hepevt

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
	$(CC) -O -c $(INCFLAGS) $< 
