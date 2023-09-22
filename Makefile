override CFLAGS += -Wall -g 
# -O3 -mavx -march=native # gerar "warnings" detalhados e infos de depuração
LDLIBS = -lm
program = interpola
objs = interpola.o utils.o libNewton.o libLagrange.o

# Lista de arquivos para distribuição
DISTFILES = *.c *.h README* Makefile *.in *.sh
DISTDIR = `basename ${PWD}`

all: $(program)

interpola: $(objs)
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@

interpola.o: interpola.c libLagrange.h utils.h
libLagrange.o: libLagrange.c libLagrange.h utils.h
libNewton.o: libNewton.c libNewton.h utils.h
libUtils.o: utils.c utils.h

clean:
	-rm -f  $(objs) *~ $(program)

purge: clean

dist: purge
	@echo "Gerando arquivo de distribuição ($(DISTDIR).tar) ..."
	@ln -s . $(DISTDIR)
	@tar -cvf $(DISTDIR).tar $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)
