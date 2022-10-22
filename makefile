EXEC=sae1-01
PBIN=./bin/
PSRC=./src/
PDATA=./data/
PROOT=./
PDOC=./doc/

all:
	+$(MAKE) -C src
ifeq (,$(wildcard $(PROOT)$(EXEC)))
	ln -s $(PBIN)$(EXEC) .
endif


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
