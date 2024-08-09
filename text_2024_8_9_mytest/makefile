static-lib = libmymath.a
dy-lib = libmymethod.so

.PHONY:all
all: $(static-lib) $(dy-lib)

$(static-lib):mymath.o
	ar -rc $@ $^
mymath.o:mymath.c
	gcc -c $^

$(dy-lib):myprintf.o mylog.o
	gcc -shared -o $@ $^ 
myprintf.o:myprintf.c
	gcc -fPIC -c $^
mylog.o:mylog.c
	gcc -fPIC -c $^

.PHONY:clean
clean:
	rm -rf *.o *.a mylib

.PHONY:output
output:
	mkdir -p mylib/include
	mkdir -p mylib/lib
	cp *.h mylib/include
	cp *.a mylib/lib
	cp *.so mylib/lib
