CC = g++

.SUFFIXES: .c .o
.c.o:
	$(CC) -fopenmp -c -o $@ $<

default: all test
all: serial threaded

report:
	pdflatex report.tex

serial: main.o serial.o timer.o
	$(CC) -o $@ $^ -lm

threaded: main.o threaded.o timer.o
	$(CC) -fopenmp -o $@ $^ -lm

test:
	#./serial > serial.txt
	./threaded > threaded.txt
	#diff serial.txt threaded.txt

clean:
	/bin/rm -f *.o serial threaded
	/bin/rm -f serial.txt threaded.txt
	/bin/rm -f *.log *.aux *.synctex.gz report.pdf
