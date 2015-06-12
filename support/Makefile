
base_dir=${PWD}
dirs = hepevt histo pythia


all:
	@echo "**"
	@echo "** Building all libraries"
	@echo "**" 
	for dir in ${dirs}; do \
	  cd ${base_dir}/$$dir && $(MAKE); \
	done

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
