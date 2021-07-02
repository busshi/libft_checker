#!/bin/bash


diff_tests()
{
dif=$( diff "$CUR_DIR/srcs/tests/$file/test.$testing" "$CUR_DIR/temp/$file/result.$testing" )
[ -n "$dif" ] && { printf "❌"; wrong=$(( $wrong + 1 )); } || printf "${green}√${white}"
}


print_grade()
{
grade=$( echo "$max - $wrong" | bc )
[ $grade -eq $max ] && { res_color="${green}"; txt="[ OK ]"; } || { res_color="${red}"; txt="[ KO ]"; fail=$(( $fail + 1 )); }
max=$( echo "$max" | rev | cut -c-2 | rev )
printf "${res_color}\033[85G${grade}\033[88G/ ${max}\033[100G${txt}${white}"
}


run_tests()
{
testing=1
while [ $testing -le $max ] ; do
	run=$( ./a.out "$testing" 1> "$CUR_DIR/temp/$file/result.$testing" 2> /dev/null )
	sig=$?
	if [ $sig -eq 0 ] ; then
		diff_tests
	elif [ $sig -eq 134 ] ; then
		printf "${red}A" && wrong=$(( $wrong + 1 ))
	elif [ $sig -eq 138 ] ; then
		printf "${red}B" && wrong=$(( $wrong + 1 ))
	elif [ $sig -eq 139 ] ; then
		printf "${red}S" && wrong=$(( $wrong + 1 ))
	elif [ $sig -eq 142 ] ; then
		printf "${red}T" wrong=$(( $wrong + 1 ))
	fi
	testing=$(( $testing + 1 ))
done
}


count_tests()
{
max=0
wrong=0
max=$( ls $CUR_DIR/srcs/tests/$file/test.* | wc -l )
[ $max -gt 0 ] && { run_tests; print_grade; }
}


tests()
{
cd "$CUR_DIR/temp/$file"
count_tests
}

