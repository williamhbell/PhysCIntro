CC = gcc

TARGET=pptobbar

OBJECTS=main.o 

LIBS=-L$(CLAB_SUPPORT_DIR)/lib -lpythia -lhepevt -lg2c
INCFLAGS=-I$(CLAB_SUPPORT_DIR)/include/pythia -I$(CLAB_SUPPORT_DIR)/include/hepevt

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
