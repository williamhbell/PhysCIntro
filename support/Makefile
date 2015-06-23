
base_dir=${PWD}
dirs = hepevt histo pythia


all:	lib
	@echo "**"
	@echo "** Building all libraries"
	@echo "**" 
	for dir in ${dirs}; do \
	  cd ${base_dir}/$$dir && $(MAKE); \
	done

lib:
	mkdir -p lib

clean: 
	@echo "**"
	@echo "** Cleaning all libraries"
	@echo "**"
	for dir in ${dirs}; do \
	  cd ${base_dir}/$$dir && $(MAKE) clean; \
	done

veryclean:
	@echo "**"
	@echo "** Removing all libraries"
	@echo "**"
	for dir in ${dirs}; do \
	  cd ${base_dir}/$$dir && $(MAKE) veryclean; \
	done
