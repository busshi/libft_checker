#!/bin.bash

checks()
{
printf "${purple}LIBC FONCTIONS :\n"
part1=("memset" "bzero" "memcpy" "memccpy" "memmove" "memchr" "strlen" "isalpha" "isdigit" "isalnum" "isascii" "isprint" "toupper" "tolower" "strchr" "strrchr" "strncmp" "strlcpy" "strlcat" "strnstr" "atoi")
for file in ${part1[@]} ; do
	[ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "all"; check_compil; printf "\n${white}"; }
done

part1_bis=("calloc" "strdup")
for file in ${part1_bis[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "write" "printf" "free"; check_compil; printf "\n"; }
done


printf "${purple}\nSUPPLEMENTARY FONCTIONS :\n"
part2=("substr" "strjoin" "strtrim" "itoa" "strmapi")
for file in ${part2[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "write" "printf" "free"; check_compil; printf "\n"; }
done

part2_2=("split")
for file in ${part2_2[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "write" "printf"; check_compil; printf "\n"; }
done

part2_3=("putchar_fd" "putstr_fd" "putendl_fd" "putnbr_fd")
for file in ${part2_3[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "malloc" "printf" "free"; check_compil; printf "\n"; }
done


printf "${purple}\nBONUS FONCTIONS :\n"
check2=$( cd "$CUR_DIR/$DIR" && make bonus 2>> $error && cp "libft.a" "$CUR_DIR/libft.a" 2>> $error && make fclean 2>> $error )


bonus=("lstnew")
for file in ${bonus[@]} ; do
	[ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "write" "printf" "free"; check_compil; printf "\n"; }
done

bonus_2=("lstadd_front" "lstsize" "lstlast" "lstadd_back" "lstiter")
for file in ${bonus_2[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "all"; check_compil; printf "\n"; }
done

bonus_3=("lstdelone" "lstclear")
for file in ${bonus_3[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "write" "printf" "malloc"; check_compil; printf "\n"; }
done

bonus_4=("lstmap")
for file in ${bonus_4[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "write" "printf"; check_compil; printf "\n"; }
done



printf "${purple}\nEXTRA FONCTIONS :\n"
extras=("islower" "isspace" "isupper" "strcmp" "strcpy" "strncpy" "strcat" "strncat" "strstr")
for file in ${extras[@]} ; do
	[ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "all"; check_compil; printf "\n"; }
done
extras2=("putchar" "putstr" "putendl" "putnbr")
for file in ${extras2[@]} ; do
        [ -f "$CUR_DIR/$DIR/ft_${file}.c" ] && { check_cheat "malloc" "printf" "free"; check_compil; printf "\n"; }
done

}
