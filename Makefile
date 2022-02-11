TESTS=tests/
TMP=tmp/tests/
ESSENTIALS=tmp/essentials/
EXECUTABLES=bin/

generate_executables: generate_object_files
	@for f in $(shell ls -1 ${TMP}/*.o | xargs -n 1 basename | sed 's/\.[a-z]*//g'); do gcc ${ESSENTIALS}/queue.o ${ESSENTIALS}/tree.o ${ESSENTIALS}/dictionary.o ${TMP}/$${f}.o -o ${EXECUTABLES}/$${f} ; done

generate_object_files: tests/*.c dictionary_module
	@for f in $(shell ls -1 ${TESTS}/*.c | xargs -n 1 basename | sed 's/\.[a-z]*//g'); do gcc -c ${TESTS}/$${f}.c -o ${TMP}/$${f}.o ; done

dictionary_module: tree_module dictionary/*
	gcc -c dictionary/dictionary.c -o tmp/essentials/dictionary.o

tree_module: tree/*
	gcc -c tree/queue.c -o tmp/essentials/queue.o & gcc -c tree/tree.c -o tmp/essentials/tree.o
