#makefile

EXECUTAVEL=app
CFLAGS=-c -std=c++11

all: ${EXECUTAVEL}

${EXECUTAVEL}: app.o contato.o agenda.o conta.o
	@g++ app.o contato.o agenda.o conta.o -o ${EXECUTAVEL}

app.o: ../app.cpp ../include/Conta.hpp
	@g++ ${CFLAGS} ../app.cpp

contato.o: ../include/Contato.hpp
	@g++ ${CFLAGS} ../include/Contato.cpp

agenda.o: ../include/Agenda.hpp ../include/Contato.hpp
	@g++ ${CFLAGS} ../include/Agenda.cpp

conta.o: ../include/Conta.hpp ../include/Agenda.hpp ../include/Contato.hpp
	@g++ ${CFLAGS} ../include/Conta.cpp

run: ${EXECUTAVEL}
	@./${EXECUTAVEL}

clean:
	@rm -f app.o contato.o agenda.o conta.o ${EXECUTAVEL}