CC = g++ -std=c++11
DEBUG = -g
EXECUTABLE = snake
SOURCES = snake.cpp


all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(DEBUG) $< -o $@

clean:
	rm -f $(EXECUTABLE)
