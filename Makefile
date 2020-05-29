PROJECT=small-game
SOURCES=$(wildcard sources/*.c) $(wildcard sources/*/*.c)
OBJECTS=$(SOURCES:.c=.o)

CC = gcc
LDFLAGS = -lraylib -lm
CFLAGS = -g \
		 -MD \
		 -Isources \
		 -Wall \
		 -Wextra  \
		 -Wc++-compat \
		 -Werror \
		 -fsanitize=address \
		 -fsanitize=undefined

$(PROJECT).out: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean test

all: $(PROJECT).out

clean:
	rm -f $(OBJECTS) $(SOURCES:.c=.d) $(PROJECT).out

test: $(PROJECT).out
	./$(PROJECT).out

-include $(SOURCES:.c=.d)