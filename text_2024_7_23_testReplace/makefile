.PHONY:all
all:mycommand otherExe
mycommand:mycommand.c
	gcc -o $@ $^  
otherExe:otherExe.cpp
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f mycommand otherExe
