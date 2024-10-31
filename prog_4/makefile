all: generate mysort

generate:
	c++ generate.cpp -o generate

mysort:
	c++ --std=c++17 mysort.cpp -o mysort -pthread

clean:
	rm -f *.out generate mysort numbers.dat sortrace.log
