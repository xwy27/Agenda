CC := g++
CCFLAGS := -std=c++11 -w
INC_DIR := include
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INCLUDE := -I./$(INC_DIR)

$(BIN_DIR)/test: $(BUILD_DIR)/add.o $(BUILD_DIR)/sub.o $(BUILD_DIR)/test.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CCFLAGS) $(INCLUDE) $(BUILD_DIR)/add.o $(BUILD_DIR)/sub.o $(BUILD_DIR)/test.o -o $@

$(BUILD_DIR)/add.o: $(SRC_DIR)/functionAdd.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CCFLAGS) $(INCLUDE) -c -o $@ $(SRC_DIR)/functionAdd.cpp

$(BUILD_DIR)/sub.o: $(SRC_DIR)/functionSubtract.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CCFLAGS) $(INCLUDE) -c -o $@ $(SRC_DIR)/functionSubtract.cpp

$(BUILD_DIR)/test.o: $(SRC_DIR)/main.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CCFLAGS) $(INCLUDE) -c -o $@ $(SRC_DIR)/main.cpp

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)