#include <iostream>
#include "GameBoard.hpp"
int main() {
  char action = '-';
  std::cout << "welcome to 2048\n"<<
  "_____________\n"<< 
  "movement controls:\n"<< 
  "- w move up\n" <<
  "- a move left \n" <<
  "- d move right\n" << 
  "- s move down\n" <<
  "_____________\n"<< 
  "game controls:\n"<<
  "- j begin game\n" << 
  "- k quit game\n" <<
  "- p set grid size\n" <<
  "_____________\n"<<
  "input controlls with enter key\n"<<
  std::endl;
  std::cin >> action;
  int rows = 4;
  int columns = 4;
  std::cout << "\033[2J\033[1;1H";

  if(action == 'p'){
    std::cout << "how many rows (default is 4)"<< "\n";
    std::cin >> rows;
    std::cout << "how many columns (default is 4)"<< "\n";
    std::cin >> columns;
    std::cout << "\033[2J\033[1;1H";
  }
  GameBoard g(rows,columns);
  while(action != 'k'){
    g.insertNum();
    std::cout << g.to_string();
    if(g.checkWin()){
      std::cout << "congradulations, you have won!\n" << "press any movement key to continue,\nor press k to quit the game" << std::endl;
    }
    std::cin >> action;
    switch(action){
      case 'w':
        g.moveUp();
        break;
      case 'a':
        g.moveLeft();
        break;
      case 'd':
        g.moveRight();
        break;
      case 's':
        g.moveDown();
        break;
      case '4':
        g.insertNum();
        break;
      default:
        action = 'k';
    }
    std::cout << "\033[2J\033[1;1H";
  }
} 
