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
OBJ_FILES := $(shell ls obj/)
OBJ_FILES_EXPECTED := Apple.obj \
                      Cow.obj \
                      Dragon.obj \
                      Koenigsegg.obj \
                      Lion.obj \
                      PrettyCube.obj \
                      Teapot.obj \
                      Teddy.obj \
                      bugatti.obj \
                      cube.obj \
                      skull.obj

all: clean install

install: clean
	mkdir build
	cd build && cmake ../CMakeLists.txt && make
ifeq ($(OS),Darwin)
	mv ./build/3DViewer.app "$(INSTALL_DIR)"
else
	mv ./build/3DViewer "$(INSTALL_DIR)"
endif

uninstall:
ifeq ($(OS),Darwin)
	rm -rf build/ $(INSTALL_DIR)/3DViewer.app
else
	rm -rf build/ $(INSTALL_DIR)/3DViewer
endif

clean:
	@rm -rf report buildmake
	@rm -rf *.gcda *.gcno *.info *.gch *.dSYM .DS_Store
	@rm -rf ../*.idea ../.run ../*.dSYM
	@rm -rf *.a *.o
	@rm -rf build/
	@rm -rf *.user ./--main main.tar.gz 3DViewer.tar.gz

dvi:
ifeq ($(OS),Darwin)
	open ./dvi.html
else
	xdg-open ./dvi.html
endif

dist:
	rm -rf 3DViewer/
	mkdir 3DViewer/
	mkdir 3DViewer/src
	cp -r controller \
			model \
			 helpers \
			 resources \
			 tests \
			 view \
			 .clang-format \
			 Makefile \
			 CMakeLists.txt \
			 main.cc dvi.html \
			 viewer.icns \
			 resource.qrc \
			 3DViewer/src
	tar -cvzf 3DViewer.tar.gz 3DViewer
	rm -rf 3DViewer

tests: clean download test.o
	./test.o

test.o:
ifeq ($(OS),Darwin)
	$(CC) $(CPPFLAGS) $(TESTS) -o test.o $(TEST_FLAGS);
else
	$(CC) $(TESTS) $(CPPFLAGS) $(TEST_FLAGS) -o test.o $(LINUX_FLAGS);
endif

gcov_report: tests
	lcov -t "test"  -o s21_test.info -c -d ./ --no-external --exclude '$(CURRENT_DIR)/resources/*' --ignore-errors mismatch --ignore-errors unused
	genhtml ./s21_test.info --output-directory ./report/
ifeq ($(OS),Darwin)
	open ./report/index.html
else
	xdg-open ./report/index.html
endif

check:
	find . -type f \( -name "*.cc" -o -name "*.h" \) -exec clang-format -n --style="Google" {} \;
	rm -f .clang-format

lint:
	find . -type f \( -name "*.cc" -o -name "*.h" \) -exec clang-format -i --style="Google" {} \;
	rm -f .clang-format

leaks: download test.o
ifeq ($(OS),Darwin)
	leaks --atExit -- ./test.o
else
	$(VG_FLAGS) --log-file=RESULT_VALGRIND.txt ./test.o
endif

open:
ifeq ($(OS),Darwin)
	open $(INSTALL_DIR)/3DViewer.app
else
	xdg-open $(INSTALL_DIR)/3DViewer
endif

download:
ifneq ($(OBJ_FILES),$(OBJ_FILES_EXPECTED))
#	rm -rf obj
	@echo "Downloading resources..."
	@curl -O -L https://github.com/tamelabe/-/archive/refs/heads/main.tar.gz
	@tar -xzf main.tar.gz
	cd ./--main && unzip -q  obj.zip && mv ./obj ../ && cd ../
	rm -rf ./main.tar.gz ./--main
endif