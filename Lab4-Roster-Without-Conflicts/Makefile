all: build

.SILENT:

build: rosterObject.cpp, roster.cpp
	g++ -std=c++11 -o rosterObject rosterObject.cpp
	g++ -std=c++11 -o roster roster.cpp

rosterObject:
	@./rosterObject $(filter-out $@, $(MAKECMDGOALS))

roster:
	@./roster $(filter-out $@, $(MAKECMDGOALS))

%:
	@true

clean:
	rm -f roster
	rm -f rosterObject