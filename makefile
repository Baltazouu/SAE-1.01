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
