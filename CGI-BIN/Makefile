
OBJS= main.o futils.o mutils.o mdialog.o httpcgi.o\
menucgi.o gamelogic01.o gamelogic02.o gamelogic03.o\
statedata.o statefile.o
CFLAGS=
CC= gcc
INCLUDES=
LIBS=

BMPSv0.81.cgi: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

main.o: main.c common.h gamelogic.h statedata.h
	${CC} ${CFLAGS} -c main.c

futils.o: futils.c common.h
	${CC} ${CFLAGS} -c futils.c

mutils.o: mutils.c common.h
	${CC} ${CFLAGS} -c mutils.c

mdialog.o: mdialog.c common.h
	${CC} ${CFLAGS} -c mdialog.c

httpcgi.o: httpcgi.c common.h
	${CC} ${CFLAGS} -c httpcgi.c

menucgi.o: menucgi.c common.h statedata.h
	${CC} ${CFLAGS} -c menucgi.c

gamelogic01.o: gamelogic01.c common.h gamelogic.h statedata.h
	${CC} ${CFLAGS} -c gamelogic01.c

gamelogic02.o: gamelogic02.c common.h gamelogic.h statedata.h
	${CC} ${CFLAGS} -c gamelogic02.c

gamelogic03.o: gamelogic03.c common.h gamelogic.h statedata.h
	${CC} ${CFLAGS} -c gamelogic03.c

statedata.o: statedata.c common.h gamelogic.h statedata.h
	${CC} ${CFLAGS} -c statedata.c

statefile.o: statefile.c common.h gamelogic.h statedata.h
	${CC} ${CFLAGS} -c statefile.c


