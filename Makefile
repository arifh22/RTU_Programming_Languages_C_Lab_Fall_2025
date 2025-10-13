CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS = 
BUILD_DIR = bin
SRC_DIR = src
LAB_DIR = lab

PROGRAMS = $(BUILD_DIR)/week5_task1_file_io $(BUILD_DIR)/week5_task2_struct_save_load $(BUILD_DIR)/week5_task3_student_management_system

all: $(PROGRAMS)

$(BUILD_DIR)/week5_task1_file_io: $(LAB_DIR)/week5_task1_file_io.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/week5_task2_struct_save_load: $(LAB_DIR)/week5_task2_struct_save_load.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/week5_task3_student_management_system: $(LAB_DIR)/week5_task3_student_management_system.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

week5_task1_file_io: $(BUILD_DIR)/week5_task1_file_io
week5_task2_struct_save_load: $(BUILD_DIR)/week5_task2_struct_save_load
week5_task3_student_management_system: $(BUILD_DIR)/week5_task3_student_management_system

run-week5_task1_file_io: week5_task1_file_io
	./$(BUILD_DIR)/week5_task1_file_io

run-week5_task2_struct_save_load: week5_task2_struct_save_load
	./$(BUILD_DIR)/week5_task2_struct_save_load

run-week5_task3_student_management_system: week5_task3_student_management_system
	./$(BUILD_DIR)/week5_task3_student_management_system

clean:
	rm -rf $(BUILD_DIR)/*.o $(PROGRAMS)
