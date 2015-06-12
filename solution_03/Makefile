CC = gcc

TARGET=bmesons

OBJECTS=main.o tools.o kinematics.o

LIBS=-L$(CLAB_SUPPORT_DIR)/lib -lhisto -lhepevt -lm
INCFLAGS=-I$(CLAB_SUPPORT_DIR)/include/hepevt -I$(CLAB_SUPPORT_DIR)/include/histo


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
