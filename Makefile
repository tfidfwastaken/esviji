a.out: rectangletest.o esviji.o
	gcc rectangletest.o esviji.o	
esviji.o: esviji.c esviji.h
	gcc -c esviji.c
rectangletest.o: rectangletest.c esviji.h 
	gcc -c rectangletest.c