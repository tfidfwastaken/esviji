a.out: test.o esviji.o
	gcc test.o esviji.o	
esviji.o: esviji.c esviji.h
	gcc -c esviji.c
test.o: test.c esviji.h 
	gcc -c test.c