#include "maze.h"

void Maze(){
	maze m;
	MazeInit(&m);
	Stack path;
	StackInit(&path);
	MazePrint(&m);
	GetPath(&m, m.entry, &path);
	MazePrint(&m);
}

int main(){
	Maze();
	system("pause");
	return 0;
}