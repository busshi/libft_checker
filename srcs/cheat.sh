#!/bin/bash

### FORBIDDEN FONCTIONS
check_cheat()
{
printf "${white}ft_${file}"
[ "$1" = "all" ] && forbidden_ft=("write" "malloc" "printf" "free") || forbidden_ft=("$@")

cheat_nb=0
cheat_str=""
for cheat in ${forbidden_ft[@]} ; do
	check_nb=$( cat "$CUR_DIR/$DIR/ft_${file}.c" | grep "$cheat" | wc -l )
	[ $check_nb -ne 0 ] && cheat_str+="$cheat "
done
[ ! "$cheat_str" = "" ] && { printf "\033[30G${red}${cheat_str}"; fail=$(( $fail + 1 )); } || printf "\033[30G${green}√"
}


