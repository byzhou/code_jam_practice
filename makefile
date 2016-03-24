CC              := g++
CFLAGS          := -c -Wall
LDFLAGS         := 
SOURCES         := alien_number.cc main.cc
OBJECTS         := $(SOURCES:.cc=.o)
EXECUTABLE      := run_code

all:  $(EXECUTABLE)

%.o:%.cc
	$(CC) $(CFLAGS) $< 
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
