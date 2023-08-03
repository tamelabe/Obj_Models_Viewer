.PHONY : install uninstall clean dvi dist tests gcov_report check leaks open download

CC = g++
CPPFLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra
TEST_FLAGS = -lgtest --coverage
LINUX_FLAGS = -lrt -lpthread -lm -lsubunit
VG_FLAGS = CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose
TESTS = ./tests/model_test.cc ./model/model.cc ./model/opening/parser.cc ./model/opening/normalizer.cc ./model/processing/base_movement.cc ./model/processing/transformer.h
CURRENT_DIR := $(abspath $(CURDIR))
INSTALL_DIR ?= $(HOME)/Desktop

OS := $(shell uname -s)

all: clean install

install: clean
	mkdir build
	cd build && cmake ../CMakeLists.txt
ifeq ($(OS),Darwin)
	mv ./build/3DViewer.app "$(INSTALL_DIR)"
else
	mv ./build/3DViewer "$(INSTALL_DIR)"
endif

uninstall:
ifeq ($(OS),Darwin)
	rm -rf $(INSTALL_DIR)/3DViewer.app
else
	rm -rf $(INSTALL_DIR)/3DViewer
endif

clean:
	@rm -rf report build
	@rm -rf *.gcda *.gcno *.info *.gch *.dSYM .DS_Store
	@rm -rf ../*.idea ../.run ../*.dSYM
	@rm -rf *.a *.o
	@rm -rf build/*
	@rm -rf *.user

dvi:
ifeq ($(OS),Darwin)
	open ./dvi.html
else
	xdg-open ./dvi.html
endif

dist: clean
	mkdir 3DViewer/
	mkdir 3DViewer/src
	cp -r controller model helpers tests view Makefile CMakeLists.txt main.cc dvi.html 3DViewer/src
	tar -cvzf 3DViewer.tar.gz 3DViewer
	rm -rf 3DViewer

tests:
ifeq ($(OS),Darwin)
	$(CC) $(CPPFLAGS) $(TESTS) -o test.o $(TEST_FLAGS);
else
	$(CC) $(TESTS) $(CPPFLAGS) $(TEST_FLAGS) -o test.o $(LINUX_FLAGS);
endif
	./test.o

gcov_report:
	lcov -t "test"  -o s21_test.info -c -d ./ --no-external --exclude '$(CURRENT_DIR)/resources/*'
	genhtml ./s21_test.info --output-directory ./report/
ifeq ($(OS),Darwin)
	open ./report/index.html
else
	xdg-open ./report/index.html
endif

check:
	cp ../materials/linters/.clang-format .
	find . -type f \( -name "*.cc" -o -name "*.h" \) -exec clang-format -i --style="Google" {} \;
	rm -f .clang-format

leaks:
ifeq ($(OS),Darwin)
	leaks --atExit -- ./test.o
else
	$(VG_FLAGS) --log-file=RESULT_VALGRIND.txt ./test.o
endif

open:
ifeq ($(OS),Darwin)
	open $(INSTALL_DIR)/TameCalc.app
else
	xdg-open $(INSTALL_DIR)/TameCalc
endif

download:
	@echo "Downloading resources..."
	@curl -O -L https://github.com/tamelabe/-/archive/refs/heads/main.tar.gz
	@tar -xzf main.tar.gz
	cd ./--main && unzip -q  obj.zip && mv ./obj ../ && cd ../
	rm -rf ./main.tar.gz ./--main