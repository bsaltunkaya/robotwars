#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Robot.h"

const int GRID_SIZE = 10;
const int INIT_COUNT = 5;

void placeRobots(std::vector<std::vector<Robot*>>& grid, std::vector<Robot*>& robots) {
  srand(time(nullptr)); // seed rand

  // create and place each type of robot
  for (int i = 0; i < INIT_COUNT; ++i) {
    robots.push_back(new optimusprime());
    robots.push_back(new robocop());
    robots.push_back(new roomba());
    robots.push_back(new bulldozer());
    robots.push_back(new kamikaze());
  }

  // randomly place robots on the grid
  for (auto& robot : robots) {
    int x, y;
    do {
      x = rand() % GRID_SIZE;
      y = rand() % GRID_SIZE;
    } while (grid[x][y] != nullptr); // make sure the cell is empty

    grid[x][y] = robot;
    std::cout << "Placing " << robot->getName() << " at (" << x << ", " << y << ").\n";
  }
}

void simulate(std::vector<std::vector<Robot*>>& grid) {
  bool oneLeft = false;
  while (!oneLeft) {
    // reset movement flags for all robots
    for (int i = 0; i < GRID_SIZE; ++i) {
      for (int j = 0; j < GRID_SIZE; ++j) {
        if (grid[i][j])
          grid[i][j]->resetMoved();
      }
    }

    // process each cell in the grid
    for (int i = 0; i < GRID_SIZE; ++i) {
      for (int j = 0; j < GRID_SIZE; ++j) {
        Robot* robot = grid[i][j];
        if (robot && !robot->hasMoved()) {
          robot->setMoved(true);
          int direction = rand() % 4;  // 0: up, 1: down, 2: left, 3: right
          int new_x = i, new_y = j;

          while (true) {
            if (direction == 0 && new_x > 0) new_x--;
            else if (direction == 1 && new_x < GRID_SIZE - 1) new_x++;
            else if (direction == 2 && new_y > 0) new_y--;
            else if (direction == 3 && new_y < GRID_SIZE - 1) new_y++;
            else {
              break; // stop if movement is not possible
            }

            if (grid[new_x][new_y] == nullptr) {
              grid[new_x][new_y] = robot;
              grid[i][j] = nullptr;
              i = new_x;
              j = new_y;
            } else {
              // fight if another robot is encountered
             
              std::cout << "The new hitpoints of " << grid[new_x][new_y]->getName() << " is " << grid[new_x][new_y]->getHitPoints() << "\n";

              if (robot->fight(*grid[new_x][new_y])) {
                std::cout << grid[new_x][new_y]->getName() << " is destroyed by " << robot->getName() << "!\n";
                delete grid[new_x][new_y];
                grid[new_x][new_y] = robot;
                grid[i][j] = nullptr;
              } else {
                std::cout << robot->getName() << " is destroyed by " << grid[new_x][new_y]->getName() << "!\n";
                delete robot;
                grid[i][j] = nullptr;
              }
              break; // end movement after a fight
            }
          }
        }
      }
    }

    // check if only one robot left
    int count = 0;
    Robot* lastRobot = nullptr;
    for (int i = 0; i < GRID_SIZE; ++i) {
      for (int j = 0; j < GRID_SIZE; ++j) {
        if (grid[i][j]) {
          count++;
          lastRobot = grid[i][j];
        }
      }
    }
    oneLeft = (count == 1);
    if (oneLeft) {
      std::cout << lastRobot->getName() << " is the last robot standing!\n";
    }
  }
}

int main() {
  std::vector<std::vector<Robot*>> grid(GRID_SIZE, std::vector<Robot*>(GRID_SIZE, nullptr));
  std::vector<Robot*> robots;
  placeRobots(grid, robots);
  simulate(grid);

  // cleanup
  for (auto& row : grid) {
    for (auto& cell : row) {
      if (cell) {
        delete cell;
      }
    }
  }
  return 0;
}
