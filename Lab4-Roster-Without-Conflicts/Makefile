all: build

.SILENT:

build: roster.cpp
	g++ -std=c++11 -o roster roster.cpp

run:
	@./roster $(filter-out $@, $(MAKECMDGOALS))

%:
	@true

clean:
	rm -f roster