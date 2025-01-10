program: files.a
	gcc main.c -L./lib -lqueue -lstack -o bin/main
files.a: files.o
	ar -rc ./lib/libqueue.a ./bin/queue.o
	ar -rc ./lib/libstack.a ./bin/stack.o
	ranlib ./lib/libqueue.a
	ranlib ./lib/libstack.a
files.o: bin lib ./src/queue.c ./src/stack.c
	gcc -c ./src/queue.c -o bin/queue.o
	gcc -c ./src/stack.c -o bin/stack.o
bin: 
	mkdir bin
lib: 
	mkdir lib 
run:
	./bin/main
clean: 
	@rm -r **/*.o
	@rm -r **/*.a
	@echo "Dependências removidas"
