nolib:
	gcc nolib.c -o nolib.o -lm -O3
	ls -lh nolib.o
	/usr/bin/time ./nolib.o
	rm nolib.o

clib:
	gcc -shared -o libclinalg.so clinalg.h -O3
	ls -lh libclinalg.so
	gcc clib.c -o clib.o -Llibclinalg -lm -O3
	ls -lh clib.o
	/usr/bin/time ./clib.o
	rm clib.o libclinalg.so

rustlib:
	rustc rustlinalg.rs --crate-type=cdylib -C opt-level=3 -C target-cpu=native
	ls -lh librustlinalg.so
	gcc rustlib.c -o rustlib.o -L. -lrustlinalg -O3
	ls -lh rustlib.o
	LD_LIBRARY_PATH=. /usr/bin/time ./rustlib.o
	rm rustlib.o librustlinalg.so
