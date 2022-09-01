all : diff.cpp
	clang++ -o diff diff.cpp


run:
	./diff $(filter-out $@, $(MAKECMDGOALS))

%:
	@true

clean :
	rm -f diff