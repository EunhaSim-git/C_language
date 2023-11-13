CFLAGS = -g -ansi -pedantic -Wall

final: assign1

assign1: main.o validateStudentId.o validateCourseId.o registerStudents.o displayRegis.o dropCourse.o
	gcc $(CFLAGS) main.o registerStudents.o validateStudentId.o validateCourseId.o displayRegis.o dropCourse.o -o assign1
	@chmod +x assign1

main.o: main.c header.h
	gcc $(CFLAGS) -c main.c

registerStudents.o : registerStudents.c header.h
	gcc $(CFLAGS) -c registerStudents.c

validateStudentId.o : validateStudentId.c header.h
	gcc $(CFLAGS) -c validateStudentId.c

validateCourseId.o : validateCourseId.c header.h
	gcc $(CFLAGS) -c validateCourseId.c

displayRegis.o: displayRegis.c header.h
	gcc $(CFLAGS) -c displayRegis.c

dropCourse.o: dropCourse.c header.h
	gcc $(CFLAGS) -c dropCourse.c
clean: 
	rm *.o assign1