CC			:= gcc
COPTIONS 	:= -Wall -Wextra -Iinclude -g
DEPFLAGS 	:= -MMD -MP
OBJ_DIR  	:= obj
LIBS 		:= -lncurses

SRCS	 	:=  src/game.c \
				src/gameloop.c \
				src/map.c \
				src/cursor.c \
				src/util.c \
				src/alert.c

OBJS     	:= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)
DEPS     	:= $(OBJS:.o=.d)
BUILD_DIR	:= build

all: $(BUILD_DIR)/game

$(BUILD_DIR)/game: $(OBJS) | $(BUILD_DIR)
	$(CC) $(COPTIONS) $(OBJS) -o $@ $(LIBS)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(COPTIONS) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

-include $(DEPS)

.PHONY: all clean