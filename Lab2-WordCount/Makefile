all: WordListDriver

.SILENT:

WordListDriver: WordListDriver.cpp
	clang++ -o WordCount WordListDriver.cpp

run:
	@./WordCount $(filter-out $@, $(MAKECMDGOALS))
%:
	@true

clean:
	rm -f WordCount