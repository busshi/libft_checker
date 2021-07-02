#!/bin/bash


makefile()
{

### FLAGS CHECK

printf "${white}\n===> Flags :"
flags=("Wall" "Wextra" "Werror")
for flag in ${flags[@]} ; do
	flg=$( cat "$DIR/$Makefile" | grep "\-$flag" | wc -l )
	[ $flg -eq 1 ] && printf "${green} -$flag" || printf "${red} -$flag"
done



### RULES CHECK

printf "${white}\n===> Existing rules :"
rules=("all:" "clean:" "fclean:" "re:" "bonus:")
for rule in ${rules[@]} ; do
        rl=$( cat "$DIR/$Makefile" | grep -w "$rule" | wc -l )
        [ $rl -eq 1 ] && printf "${green} $rule" || printf "${red} $rule"
done

printf "${white}\n===> Rules checking :"



### Make

make_libft=$( make -C $DIR 2> $error )
pb=0
for objet in ${liste[@]} ; do
	[ ! -f "$DIR/ft_${objet}.o" ] && pb=$(( $pb + 1 ))
done
[ ! -f "$DIR/libft.a" ] && pb=$(( $pb + 1 ))
[ $pb -eq 0 ] && printf "${green} make" || printf "${red} make"



### Make clean

clean=$( make clean -C $DIR 2>> $error )
pb=0
for objet in ${liste[@]} ; do
        [ -f "$DIR/ft_${objet}.o" ] && pb=$(( $pb + 1 ))
done
[ ! -f "$DIR/libft.a" ] && pb=$(( $pb + 1 ))
[ $pb -eq 0 ] && printf "${green} clean" || printf "${red} clean"



### Make bonus

make_bonus=$( make bonus -C $DIR 2>> $error )
pb=0
for objet in ${bonus[@]} ; do
        [ ! -f "$DIR/ft_${objet}.o" ] && pb=$(( $pb + 1 ))
done
[ ! -f "$DIR/libft.a" ] && pb=$(( $pb + 1 ))
[ $pb -eq 0 ] && printf "${green} bonus" || printf "${red} bonus"



### Make fclean

cleanf=$( make -C $DIR fclean 2>> $error )
pb=0
for objet in ${liste[@]} ; do
        [ -f "$DIR/ft_${objet}.o" ] && pb=$(( $pb + 1 ))
done
[ -f "$DIR/libft.a" ] && pb=$(( $pb + 1 ))
[ $pb -eq 0 ] && printf "${green} fclean" || printf "${red} fclean"



### Relink

printf "${white}\n===> Relink :"
link=$( make re -C $DIR 2>> $error )
relink=$( make -C $DIR 2>> $error )
if [ "$relink" = "make: « libft.a » est à jour." -o "$relink" = "make: rien à faire pour « all »." -o "$relink" = "make: « libft.a » is up-to-date." -o "$relink" = "make: nothing to be done for « all »." -o "$relink" = "make: Nothing to be done for \`all'." -o "$relink" = "make: \`libft.a' is up to date." -o "$relink" = "make[1]: Nothing to be done for \`all'." ] ; then
	printf "${green} No relink"
else
	printf "${red} $relink"
fi
}

