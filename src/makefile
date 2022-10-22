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

$(PBIN)%.o: %.c $(PBIN)
	@$(CC) -o $(PBIN)$@ -c $< $(CFLAGS)

$(PBIN):
	mkdir $(PBIN)

.PHONY: clall
clall: clbin cldata cldoc

.PHONY: clbin
clbin:
	@rm -rfv $(PBIN) $(PROOT)$(EXEC)

.PHONY: cldata
cldata:
	@rm -riv $(PDATA)*

.PHONY: cldoc
cldoc:
	@rm -rfv $(PDOC)


.PHONY: doc
doc:
ifeq (,$(wildcard $(PDOC)))
	mkdir $(PDOC)
endif
	@doxygen 
	@echo
	@echo "${PWD}/$(PDOC)html/index.html"
