
OBJS= main.o futils.o mutils.o mdialog.o menuraw.o\
httppost.o htmlskin.o gamelogic01.o gamelogic02.o\
gamelogic03.o statedata.o statefile.o
CFLAGS=
CC= gcc
INCLUDES=
LIBS=

BMPS: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

main.o: main.c common.h gamelogic.h statedata.h
	${CC} ${CFLAGS} -c main.c

futils.o: futils.c common.h
	${CC} ${CFLAGS} -c futils.c

mutils.o: mutils.c common.h
	${CC} ${CFLAGS} -c mutils.c

mdialog.o: mdialog.c common.h
	${CC} ${CFLAGS} -c mdialog.c

menuraw.o: menuraw.c common.h statedata.h
	${CC} ${CFLAGS} -c menuraw.c

httppost.o: httppost.c common.h
	${CC} ${CFLAGS} -c httppost.c

htmlskin.o: htmlskin.c common.h
	${CC} ${CFLAGS} -c htmlskin.c

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


