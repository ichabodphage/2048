#include <iostream>
#include "GameBoard.hpp"

int main() {
  char action = '-';
  std::cout << "welcome to "<< tf::bold <<

  tf::color(129) <<"2048\n"<< tf::boldEnd<<
  tf::color(255)<< 
  tf::color(34)<<"_____________\n"<<
  tf::color(255)<<

  "movement controls:\n"<< 
  "-"<< tf::color(48)<<" w "<< tf::color(255)
  <<"move up\n" <<

  "-"<< tf::color(38)<<" a "<< tf::color(255)<<"move left \n" <<

  "-" << tf::color(198)<<" s "<< tf::color(255) 
  <<"move down\n" <<

  "-" << tf::color(98)<<" d "<< tf::color(255)
  << "move right\n" <<

  tf::color(34)<<"_____________\n"<<
  tf::color(255)<<
  "game controls:\n"<<

  "-"<< tf::color(46)<<" j "<< tf::color(255)
  <<"begin game\n" <<
  
  "-"<< tf::color(88)<<" k "<< tf::color(255)
  <<"quit game\n" <<

  "-"<< tf::color(109)<<" p "<< tf::color(255)
  <<"resize game board\n (bigger game board's may flicker)\n" <<

  tf::color(34)<<"_____________\n"<<
  tf::color(255)<<
  "input controlls with enter key\n";
  std::cin >> action;
  
  int rows = 4;
  int col = 4;
  std::cout << "\033[2J\033[1;1H";

  if(action == 'p'){
    std::cout << "how many rows (default is 4)"<< "\n";
    std::cin >> rows;
    std::cout << "how many columns (default is 4)"<< "\n";
    std::cin >> col;
    std::cout << "\033[2J\033[1;1H";
  }
  GameBoard g(rows,col);
  std::cout << g.to_string();
  while(action != 'k'){
    g.insertNum();
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
  }
  std::cout << "\033[2J\033[1;1H";
} 
