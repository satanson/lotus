
SUBDIRS=slaver master gen-cpp consistent

.PHONY: subdir ${SUBDIRS}

subdir: ${SUBDIRS}

${SUBDIRS}:
	make -C $@

slaver: gen-cpp
master: gen-cpp

clean::
	@for subdir in $(SUBDIRS); \
	do \
		echo "making $@ in $$subdir"; \
		make -C $$subdir $@ ; \
	done
