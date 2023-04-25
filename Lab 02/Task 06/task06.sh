a=0
b=1
t=0
echo "$a"
echo "$b"
temp=$1
for i in $(seq $(($1-2)));
do 
	t=$(($a + $b))
	a=$b
	b=$t
	echo "$t"
done
