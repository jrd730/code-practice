#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

#define REFLECT_UP '^'
#define REFLECT_RIGHT '>'
#define REFLECT_LEFT '<'
#define REFLECT_DOWN 'V'
#define ORIGIN '@'
#define SPACE '-'

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  char** cells;
} MatrixC;

int rows, cols;

int fire_laser (MatrixC *mc)
{
  // find the origin
  Point beam;
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < cols; ++j){
      if (mc->cells[i][j] == ORIGIN){
        beam.y = i;
        beam.x = j;
        printf ("%d %d\n", i, j);
        goto foundOrigin;
      }
    }
  }

  foundOrigin: ;
  int direction = RIGHT;
  int steps = 0;
  
  // keeps track of cells containing prisms that have been visited
  set <int> visited;

  // continue tracing the path of the beam until it goes off the grid or 
  // returns to a prism that it has been to before indicating an infinite loop
  while (beam.x >= 0 && beam.x < cols && beam.y >= 0 && beam.y < rows){

    if (visited.find (beam.y*cols + beam.x) != visited.end()){
      // found an infinite loop, discontinue search
      return -1;
    }

    // Check the current cell to see if a prism will redirect the beam.
    // If the current cell is a prism store that cell's unique id.
    switch (mc->cells[beam.y][beam.x]){
      case (REFLECT_UP):
        direction = UP;
        visited.insert(beam.y*cols + beam.x);
        break;
      case (REFLECT_DOWN):
        direction = DOWN;
        visited.insert(beam.y*cols + beam.x);
        break;
      case (REFLECT_LEFT):
        direction = LEFT;
        visited.insert(beam.y*cols + beam.x);
        break;
      case (REFLECT_RIGHT):
        direction = RIGHT;
        visited.insert(beam.y*cols + beam.x);
        break;
    }

    // increment the beam in its current direction by 1 unit
    switch (direction){
      case (UP):    beam.y--; break;
      case (DOWN):  beam.y++; break;
      case (LEFT):  beam.x--; break;
      case (RIGHT): beam.x++; break;
    }
    printf ("%d %d\n", beam.y, beam.x);
    steps++;
  }
  return steps;
}

int main()
{
  cin >> rows >> cols;
  MatrixC mc;
  mc.cells = new char* [rows];
  for (int i = 0; i < rows; ++i){
    mc.cells[i] = new char [cols];
    for (int j = 0; j < cols; ++j){
      cin >> mc.cells[i][j];
    }cin.get ();
  }

  int num_steps = fire_laser (&mc);
  if (num_steps >= 0) {
    cout << "The laser beam traveled " << num_steps << " units before hitting a wall.\n";
  }
  else {
    cout << "The laser beam is stuck in an infinite loop.\n";
  }

  return 0;
}