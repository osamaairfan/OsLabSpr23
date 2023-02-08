for i in {1..5}; do 
	cd "test0$i"
	cd "01"
	rm test.txt
	cd ..
	cd "02"
	rm test.txt
	cd ..
	cd ..
done
