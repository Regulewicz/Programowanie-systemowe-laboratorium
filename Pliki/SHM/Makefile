Dir := build
TARGET := $(Dir)/SHM
SRC_Dir := SRC
CC := gcc

SRC := $(wildcard $(SRC_Dir)/*.c)
OBJ := $(patsubst $(SRC_Dir)/%.c, $(Dir)/%.o, $(SRC))

CFLAGS := -I$(SRC_Dir) -Wall
LDFLAGS := -lrt -pthread

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(Dir)/%.o: $(SRC_Dir)/%.c | $(Dir)
	$(CC) $(CFLAGS) -c $< -o $@

$(Dir):
	mkdir -p $@

clean:
	rm -rf $(Dir)
