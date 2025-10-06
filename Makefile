CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS = 
BUILD_DIR = bin
SRC_DIR = src
LAB_DIR = lab

PROGRAMS = $(BUILD_DIR)/labfile1 $(BUILD_DIR)/labfile2 $(BUILD_DIR)/labfile3

all: $(PROGRAMS)

$(BUILD_DIR)/labfile1: $(LAB_DIR)/labfile1.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/labfile2: $(LAB_DIR)/labfile2.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/labfile3: $(LAB_DIR)/labfile3.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

labfile1: $(BUILD_DIR)/labfile1
labfile2: $(BUILD_DIR)/labfile2
labfile3: $(BUILD_DIR)/labfile3

run-labfile1: labfile1
	./$(BUILD_DIR)/labfile1

run-labfile2: labfile2
	./$(BUILD_DIR)/labfile2

run-labfile3: labfile3
	./$(BUILD_DIR)/labfile3

clean:
	rm -rf $(BUILD_DIR)/*.o $(PROGRAMS)
