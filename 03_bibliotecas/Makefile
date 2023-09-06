all: run output

run: 
	gcc *.c -o prog -lm

output: 
	mkdir outprog
	./prog  >outprog/test_1.txt 
	./prog  >outprog/test_2.txt 

script:
	bash ./corresao.sh

clean:
	rm -rf *.o prog outprog/*

