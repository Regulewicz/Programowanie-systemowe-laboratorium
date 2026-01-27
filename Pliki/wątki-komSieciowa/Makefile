Dir := build
TARGET := $(Dir)/watki_komunikacja_sieciowa

SRC_Dir := SRC
CC := gcc

CLIENT_SRC := $(SRC_Dir)/client.py
CLIENT_DEST := $(Dir)/client.py

SRC := $(wildcard $(SRC_Dir)/*.c)
OBJ := $(patsubst $(SRC_Dir)/%.c, $(Dir)/%.o, $(SRC))

CFLAGS := -I$(SRC_Dir) -Wall
LDFLAGS := -lrt -pthread

all: $(TARGET) $(CLIENT_DEST)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(Dir)/%.o: $(SRC_Dir)/%.c | $(Dir)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_DEST): $(CLIENT_SRC) | $(Dir)
	cp $< $@
	chmod +x $@

$(Dir):
	mkdir -p $@

clean:
	rm -rf $(Dir)