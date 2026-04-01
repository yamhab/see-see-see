SRC_DIR := src
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
BINS := $(OBJS:.o=)

CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2

all: $(BINS) $(OBJS)

$(BUILD_DIR)/%: $(BUILD_DIR)/%.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

.SECONDEXPANSION:
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $$(@D)/
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/%/:
	mkdir -p $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
