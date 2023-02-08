for i in {1..5}; do 
	mkdir test0$i
	cd "test0$i"
	mkdir "01"
	cd "01"
	touch test.txt
	date > test.txt
	cd ..
	mkdir "02"
	cd "02"
	touch test.txt
	date > test.txt
	cd ..
	cd ..
done
