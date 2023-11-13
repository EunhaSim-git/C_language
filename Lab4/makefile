CFLAGS = -g -ansi -pedantic -Wall

final: lab4

lab4: main.o tokenizeLine.o header.h createTemp.o createWindSpeedDir.o createWindGusts.o convertTimestamp.o printData.o
	gcc $(CFLAGS) -o lab4 main.o tokenizeLine.o createTemp.o createWindSpeedDir.o createWindGusts.o convertTimestamp.o printData.o
	@chmod +x lab4

main.o: main.c header.h
	gcc $(CFLAGS) -c main.c

tokenizeLine.o: tokenizeLine.c header.h
	gcc $(CFLAGS) -c tokenizeLine.c

createTemp.o: createTemp.c header.h
	gcc $(CFLAGS) -c createTemp.c

createWindSpeedDir.o: createWindSpeedDir.c header.h
	gcc $(CFLAGS) -c createWindSpeedDir.c

createWindGusts.o: createWindGusts.c header.h
	gcc $(CFLAGS) -c createWindGusts.c

convertTimestamp.o: convertTimestamp.c header.h
	gcc $(CFLAGS) -c convertTimestamp.c

printData.o: printData.c header.h
	gcc $(CFLAGS) -c printData.c

clean:
	rm *.o lab4