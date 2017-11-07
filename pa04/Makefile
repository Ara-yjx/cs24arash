bin = polytest2 polytest2.o polyexam2 polyexam2.o poly2.o

all: polyexam2 polytest2

%.o: %.cxx
	g++ -c -g $<

poly2.o: poly2.cpp
	g++ poly2.cpp -c

#polyexam2.o: polyexam2.cxx
#	g++ -c -g $@ $<
	
polyexam2: polyexam2.o poly2.o	
	g++ -g polyexam2 -o polyexam2.o poly2.o 

#polytest2.o: polytest2.cxx
#	g++ -c polytest2.cxx

polytest2: polytest2.o poly2.o
	g++ -g polytest2 -o polytest2.o poly2.o

clean:
	rm -f $(bin)