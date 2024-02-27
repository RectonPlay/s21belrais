OS = $(shell uname)
ifeq ($(OS), Linux)
	GCC = gcc -pedantic -std=c++17 -lstdc++ -Wall -Wextra -Werror
	CHECK_FLAGS = -lgtest -lcheck -pthread -lm
	MEM_CHECK = valgrind --tool=memcheck --trace-children=yes --track-origins=yes --leak-check=full -s
else
	GCC = gcc -pedantic -std=c++17 -lstdc++ -Wall -Wextra -Werror
	CHECK_FLAGS = -lgtest -pthread
	MEM_CHECK = leaks --atExit -- ./test
endif

all: test
	make clean
	make check_style

test: s21_matrix_oop.a
	$(GCC) matrix_oop_test.cc -o test $(CHECK_FLAGS) -lstdc++ -L. -ls21_matrix_oop
	./test

gcov_report:
	$(GCC) matrix_oop_test.cc s21*.cc $(CHECK_FLAGS) -lstdc++ --coverage -o ./gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

s21_matrix_oop.o:
	$(GCC) -c s21_*.cc

s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs libs21_matrix_oop.a *.o
	rm -rf *.o
	ranlib libs21_matrix_oop.a

check:
	make test
	CK_FORK=no $(MEM_CHECK) ./test

check_style:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.cc *.h

fix_style:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.cc *.h

clean:
	rm -rf report
	rm -f gcov*
	rm -f test*
	rm -f libs*
	rm -f a*
	rm -f report*
	rm -rf build
	rm -f s21_matrix_oop
	rm -f *.gcda
	rm -f *.gcno