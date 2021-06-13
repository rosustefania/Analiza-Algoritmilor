CC = g++
CFLAGS = -Wall -Wextra -O2

run_Floyd:
	./test_Floyd in/test0.in > out/out_Floyd/test0.out
	./test_Floyd in/test1.in > out/out_Floyd/test1.out
	./test_Floyd in/test2.in > out/out_Floyd/test2.out
	./test_Floyd in/test3.in > out/out_Floyd/test3.out
	./test_Floyd in/test4.in > out/out_Floyd/test4.out
	./test_Floyd in/test5.in > out/out_Floyd/test5.out
	./test_Floyd in/test6.in > out/out_Floyd/test6.out
	./test_Floyd in/test7.in > out/out_Floyd/test7.out
	./test_Floyd in/test8.in > out/out_Floyd/test8.out
	./test_Floyd in/test9.in > out/out_Floyd/test9.out
	
run_Dijkstra:
	./test_Dijkstra in/test0.in > out/out_Dijkstra/test0.out
	./test_Dijkstra in/test1.in > out/out_Dijkstra/test1.out
	./test_Dijkstra in/test2.in > out/out_Dijkstra/test2.out
	./test_Dijkstra in/test3.in > out/out_Dijkstra/test3.out
	./test_Dijkstra in/test4.in > out/out_Dijkstra/test4.out
	./test_Dijkstra in/test5.in > out/out_Dijkstra/test5.out
	./test_Dijkstra in/test6.in > out/out_Dijkstra/test6.out
	./test_Dijkstra in/test7.in > out/out_Dijkstra/test7.out
	./test_Dijkstra in/test8.in > out/out_Dijkstra/test8.out
	./test_Dijkstra in/test9.in > out/out_Dijkstra/test9.out

run_Johnson:
	./test_Johnson in/test0.in > out/out_Johnson/test0.out
	./test_Johnson in/test1.in > out/out_Johnson/test1.out
	./test_Johnson in/test2.in > out/out_Johnson/test2.out
	./test_Johnson in/test3.in > out/out_Johnson/test3.out
	./test_Johnson in/test4.in > out/out_Johnson/test4.out
	./test_Johnson in/test5.in > out/out_Johnson/test5.out
	./test_Johnson in/test6.in > out/out_Johnson/test6.out
	./test_Johnson in/test7.in > out/out_Johnson/test7.out
	./test_Johnson in/test8.in > out/out_Johnson/test8.out
	./test_Johnson in/test9.in > out/out_Johnson/test9.out

build_Floyd: algo_Floyd.o algo_Floyd_test.cpp  
	mkdir out/out_Floyd	
	$(CC) $(CFLAGS) algo_Floyd_test.cpp algo_Floyd.o -o test_Floyd -g	

build_Dijkstra: algo_Dijkstra.o algo_Dijkstra_test.cpp
	mkdir out/out_Dijkstra
	$(CC) $(CFLAGS) algo_Dijkstra_test.cpp algo_Dijkstra.o -o test_Dijkstra -g
	
build_Johnson: algo_Johnson.o algo_Johnson_test.cpp
	mkdir out/out_Johnson
	$(CC) $(CFLAGS) algo_Johnson_test.cpp algo_Johnson.o -o test_Johnson -g
	
algo_Floyd.o: algo_Floyd.cpp algo_Floyd.h
	$(CC) -c algo_Floyd.cpp -g
	
algo_Dijkstra.o: algo_Dijkstra.cpp algo_Dijkstra.h
	$(CC) -c algo_Dijkstra.cpp -g
	
algo_Johnson.o: algo_Johnson.cpp algo_Johnson.h
	$(CC) -c algo_Johnson.cpp -g	
	

.PHONY: clean
clean_Floyd:
	rm -rf out/out_Floyd 
	rm -rf *.o test_Floyd 
	
clean_Dijkstra:
	rm -rf out/out_Dijkstra 
	rm -rf *.o test_Dijkstra 
	
clean_Johnson:
	rm -rf out/out_Johnson
	rm -rf *.o test_Johnson
	

