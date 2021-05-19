#!/bin/bash


### COMPILATION CHECK

check_compil()
{
cd "$CUR_DIR"
[ ! -d "$CUR_DIR/temp" ] && mkdir "$CUR_DIR/temp"
[ ! -d "$CUR_DIR/temp/$file" ] && mkdir "$CUR_DIR/temp/$file"
clang -Wall -Wextra -Werror "$DIR/ft_${file}.c" "$CUR_DIR/srcs/tests/$file/main.c" -L. -lft -o "$CUR_DIR/temp/$file/a.out" 2>> $error
[ -f "$CUR_DIR/temp/$file/a.out" ] && { printf "\033[45G${green}√\033[60G"; tests; } || { printf "\033[45G❌\033[100G${red}[ KO ]"; fail=$(( $fail + 1 )); }
}

