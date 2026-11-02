CC = gcc
CFLAGS = -Wall -fexec-charset=GBK

compile_main.c: main.c 
	$(CC) $(CFLAGS) main.c -o main.exe

compile_disease.c: disease.c
	$(CC) $(CFLAGS) disease.c -o disease.exe

compile_pesticide.c: pesticide.c
	$(CC) $(CFLAGS) pesticide.c -o pesticide.exe
clean:
	del *.o main.exe disease.exe pesticide.exe