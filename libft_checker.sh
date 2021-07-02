#!/bin/bash

clear


### COLORS

red="\e[1;31m"
green="\e[1;32m"
white="\e[0;m"
purple="\e[0;35m"
orange="\e[0;33m"
grey="\e[1;30m"



### FOLDER VARIABLES

DIR="../"

CUR_DIR=$PWD
error="$CUR_DIR/error.txt"


### SOURCES FILES

source "$CUR_DIR/srcs/cheat.sh"
source "$CUR_DIR/srcs/checks.sh"
source "$CUR_DIR/srcs/makefile.sh"
source "$CUR_DIR/srcs/tests_ft.sh"
source "$CUR_DIR/srcs/compil.sh"


### HEADER

printf "${orange}____________________________________________________________________________________________________________\n"
printf "________________________________________________ LIBFT CHECKER _____________________________________________\n"
printf "____________________________________________________________________________________________________________\n\n"



## FIRST STEPS : Folder libft, files name, header libft.h and Makefile

printf "${purple}FIRST STEPS :"
printf "${white}\n===> Libft folder :"
[ -d $DIR ] && printf "${green} √" || printf " ❌"

printf "$white\n===> Libft.h Header :"
[ -f "$DIR/libft.h" ] && printf "${green} √" || printf " ❌"

printf "${white}\n\n===> Files name :"
list=("memset" "bzero" "memcpy" "memccpy" "memmove" "memchr" "strlen" "isalpha" "isdigit" "isalnum" "isascii" "isprint" "toupper" "tolower" "strchr" "strrchr" "strncmp" "strlcpy" "strlcat" "strnstr" "atoi" "calloc" "strdup" "substr" "strjoin" "strtrim" "split" "itoa" "strmapi" "putchar_fd" "putstr_fd" "putendl_fd" "putnbr_fd")
file_error=0
for name in ${list[@]} ; do
	[ ! -f "$DIR/ft_${name}.c" ] && { printf "${red} ft_$name.c"; file_error=$(( $file_error + 1 )); }
done
[ $file_error -eq 0 ] && printf "${green} √"

printf "${white}\n\n===> Bonus files name:"
bonus=(lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap)
file_error=0
for name in ${bonus[@]} ; do
        [ ! -f "$DIR/ft_${name}.c" ] && { printf "${red} ft_$name.c"; file_error=$(( $file_error + 1 )); }
done
[ $file_error -eq 0 ] && printf "${green} √${white}"


### MAKEFILE CHECK

printf "${purple}\n\nMAKEFILE :"
printf "${white}\n===> File name :"


[ -f "$DIR/Makefile" ] && Makefile="Makefile"
[ -f "$DIR/makefile" ] && Makefile="makefile"
[ -n "$Makefile" ] && { printf "${green} √"; makefile; } || { printf " ❌\n"; exit 1; }



### LIBRARY COMPILATION

printf "${white}\n===> Library compilation :"
[ ! -f "../libft.a" ]  && { printf " ❌\n"; exit 1; } || printf "${green} √\n"
lib_cpy=$( cp "../libft.a" . 2>> $error && make fclean -C $DIR 2>> $error )


### PAUSE

#printf "${orange}\nHit <Enter> to continue..."
#read
#[ "$REPLY" != "" ] && exit 0



### TESTS START

printf "${orange}____________________________________________________________________________________________________________\n"
printf "FILE\033[30GCHEAT\033[45GCOMPILATION\033[60GTESTS\033[85GGRADE\033[100GRESULT\n\n"

fail=0
checks



### PRINT ERRORS
#cat "$CUR_DIR/error.txt"

#cd $CUR_DIR
check_error=$( cat $error )
if [ "$check_error" != "" ] ; then
	printf "${red}\n\n⚠️   Errors generated during tests:${white}\n\n"
	cat "$error"
#	printf "${orange}\nPrint generated errors during tests (y/n) ? ${white}"
#	read
#	[ "$REPLY" = "o" -o "$REPLY" = "y" ] && cat "$CUR_DIR/error.txt"
fi



### CLEANING TEMPORARY FILES
rm -f "${CUR_DIR}/libft.a" # && make fclean -C $DIR
[ $fail -eq 0 ] && { rm -rf ${error} "${CUR_DIR}/temp"; exit 0; } || exit 1 

#if [ $fail -gt 0 ] ; then
#	printf "${orange}\nKeep temporary files ? (y/n) ${white}"
#	read
#	[ ! "$REPLY" = "o" -a ! "$REPLY" = "y" ] && rm -rf temp error.txt
#else
#	rm -rf error.txt temp
#fi

#rm -rf libft.a


exit 0
