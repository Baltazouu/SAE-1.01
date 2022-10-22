CC=gcc
CFLAGS=-Wall
LDFLAGS=
_EXEC=sae1-01

PBIN=../bin/
PSRC=../src/
PDATA=../data/
PROOT=../
PDOC=../doc/

EXEC= $(PBIN)$(_EXEC)
SRC= $(wildcard *.c)
_OBJ= $(SRC:.c=.o)
OBJ= $(patsubst %,$(PBIN)%,$(_OBJ))


all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $(PBIN)$@ $(PBIN)$^ $(LDFLAGS)

$(PBIN)%.o: %.c
	@$(CC) -o $(PBIN)$@ -c $< $(CFLAGS)


.PHONY: clall
clall: clbin cldata

.PHONY: clbin
clbin:
	@rm -rfv $(PBIN)*.o $(PBIN)$(EXEC) $(PROOT)$(EXEC)

.PHONY: cldata
cldata:
	@rm -rfv $(PDATA)*

.PHONY: doc
doc:
	@doxygen 
	@echo
	@echo "${PWD}/$(PDOC)html/index.html"
