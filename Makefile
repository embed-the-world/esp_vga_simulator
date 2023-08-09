
.PHONY: all
all:
	cmake -S . -B build
	cmake --build ./build/

.PHONY: config
config:
	cmake -S . -B build/

.PHONY: clean
clean:
	rm -rf build/*

