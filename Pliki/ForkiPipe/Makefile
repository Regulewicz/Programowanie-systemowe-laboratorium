Dir := build
TARGET := $(Dir)/fork
SRC_Dir := SRC
CC := gcc

SRC := $(wildcard $(SRC_Dir)/*.c)
OBJ := $(patsubst $(SRC_Dir)/%.c, $(Dir)/%.o, $(SRC))

all: $(Dir) $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(Dir)/%.o: $(SRC_Dir)/%.c | $(Dir)
	$(CC) -c $< -o $@

$(Dir):
	mkdir -p $(Dir)

clean:
	rm -rf $(Dir)
