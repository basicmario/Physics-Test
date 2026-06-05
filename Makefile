
main : main.c
	gcc main.c -o main -IC:\raylib\include -LC:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -Wall 

run: main.c
	./main