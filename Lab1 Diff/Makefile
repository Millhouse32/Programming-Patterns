all : diff.cpp
	clang++ -o diff diff.cpp


.SILENT:

run:
	@./diff $(filter-out $@, $(MAKECMDGOALS))

%:
	@true

clean :
	rm -f diff