#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;

#define WALL 	'#'
#define VISITED '?'
#define PATH 	'.'
#define SPACE ' '

struct maze{
	int width;
	int height;
	int xs, ys;
	int xe, ye;
	char** tile;
};

struct step{
	step* prevStep;
	int col;
	int row;
};

void setStep (step* s, step* p, int row, int col){
	s->prevStep = p;
	s->row = row;
	s->col = col;
}

void loadMaze (maze& m){
	cin >> m.height >> m.width;
	cin >> m.ys >> m.xs >> m.ye >> m.xe;
	cin.get (); // '\n'
	m.tile = new char* [m.height];
	for (int row=0; row < m.height; ++row){
		m.tile[row] = new char [m.width];
		for (int col=0; col < m.width; ++col){
			m.tile[row][col] = cin.get();
		}cin.get (); // '\n'
	}
}

void tryStep (maze& m, list<step*>& steps, step* from, int row, int col){
	if (row >= 0 && row < m.height && col >= 0 && col < m.width){
		if (m.tile[row][col] != WALL && m.tile[row][col] != VISITED){
			step* next = new step;
			setStep (next, from, row, col);
			steps.push_back (next);
			m.tile[row][col] = VISITED;
		}
	}
}

void solveMaze (maze& m){
	step* start = new step;
	setStep (start, NULL, m.ys, m.xs);
	m.tile[m.ys][m.xs] = VISITED;
	list <step*> steps;
	steps.push_back (start);
	while (!steps.empty()){
		step* from = steps.front();
		tryStep (m, steps, from, from->row, from->col+1);
		tryStep (m, steps, from, from->row+1, from->col);
		tryStep (m, steps, from, from->row, from->col-1);
		tryStep (m, steps, from, from->row-1, from->col);
		if ( (from->row == m.ye) && (from->col == m.xe) ){
			step* path = steps.front();
			while (path != NULL){
				m.tile[path->row][path->col] = PATH;
				path = path->prevStep;
			}
			break;
		}
		else{
			steps.pop_front();
		}
	}
}

void printMaze (maze& m){
	for (int row=0; row < m.height; ++row){
		for (int col=0; col < m.width; ++col){
			cout << m.tile[row][col];
		}cout << endl;
	}
}

int main (){
	int N;
	cin >> N;
	for ( ;N; --N){
		maze m;
		loadMaze  (m);
		solveMaze (m);
		printMaze (m);
	}
	return 0;
}