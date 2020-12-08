N = uls

SRC_1 = src

OBJ_1 = obj

INC_1 = inc

FLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
		@make -C ./libmx
		@clang $(FLAG) -I $(INC_1) $(SRC_1)/*.c -L ./libmx -lmx -o $(N)

uninstall: clean
		@rm -rf $(N)
		@rm -rf libmx.a
		@make uninstall -C ./libmx

clean:
		@rm -rf $(OBJ_1)

reinstall: all