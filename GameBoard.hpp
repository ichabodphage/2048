#include "textformat.hpp"
#include <vector>
#include <random>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

/* class that creates and runs a game board for a game of 2048
*/
class GameBoard{
public:
  long score = 0;
  std::vector<std::vector<int>> gameMap;
  GameBoard(int length,int width){
    gameMap.assign(length,std::vector<int>());
    for(int i = 0; i < length;i++){
      gameMap[i].assign(width,0);
    }
  }
  // inserts 2 new numbers into the 2048 board
  void insertNum(){
    int numCount = 0;
    std::mt19937_64 numCountGen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(1,2);
    numCount = distribution(numCountGen);
    for(int i = 0; i < numCount;i++){

      std::mt19937_64 generator(std::chrono::steady_clock::now().time_since_epoch().count());
      std::uniform_int_distribution<int> distributionLength(0,gameMap.size()-1);
      std::uniform_int_distribution<int> distributionwidth(0,gameMap[0].size()-1);
      int r = distributionLength(generator);
      int c = distributionwidth(generator);
      
      if (gameMap[r][c] > 0){
          i=0;
          continue;
      }else{ 
        gameMap[r][c] = 2;
      }
    }
  }
  // moves all numbers to the right
  void moveRight(){
    for(int row = 0; row < gameMap.size();row++){
      for(int  i = 0; i < gameMap[row].size();i++){
      for(int col = gameMap[row].size()-1; col >0;col--){
        //swap numbers if there is a non zero number and a zero number in the row
        if(gameMap[row][col] == 0 && gameMap[row][col-1] != 0){
          std::swap(gameMap[row][col-1],gameMap[row][col]);
        }
        //add 2 numbers if they are the same and touching eachother
        if(gameMap[row][col] == gameMap[row][col-1]){
          gameMap[row][col]+= gameMap[row][col-1];
          score += gameMap[row][col-1];
          gameMap[row][col-1] = 0;
        }
        
      }
      }
        system("clear");
        std::cout.flush();
        std::cout << this->to_string();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
  //moves all the numbers left
  void moveLeft(){
    for(int row = 0; row < gameMap.size();row++){
      for(int  i = 0; i < gameMap[row].size();i++){
      for(int col = 0; col <gameMap[row].size()-1;col++){
        //swap numbers if there is a non zero number and a zero number in the row
        if(gameMap[row][col] == 0 && gameMap[row][col+1] != 0){
          std::swap(gameMap[row][col+1],gameMap[row][col]);
        }
        //add 2 numbers if they are the same and touching eachother
        if(gameMap[row][col] == gameMap[row][col+1]){
          gameMap[row][col]+= gameMap[row][col+1];
          score += gameMap[row][col+1];
          gameMap[row][col+1] = 0;
        }
      }
      }
      system("clear");
      std::cout.flush();
      std::cout << this->to_string();
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
  //moves all the numbers up
  void moveUp(){
    for(int col = 0; col < gameMap[0].size(); col++){
      for(int i = 0; i < gameMap[0].size();i++){

      
      for(int row = 0; row <gameMap.size()-1;row++){
        //swap numbers if there is a non zero number and a zero number in the row
        if(gameMap[row][col] == 0 && gameMap[row+1][col] != 0){
          std::swap(gameMap[row+1][col],gameMap[row][col]);
        }
        //add 2 numbers if they are the same and touching eachother
        if(gameMap[row+1][col] == gameMap[row][col]){
          gameMap[row][col]+= gameMap[row+1][col];
          score += gameMap[row+1][col];
          gameMap[row+1][col] = 0;
        }
      }
      }
      system("clear");
      std::cout.flush();
      std::cout << this->to_string();
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
  //moves all the numbers down
  void moveDown(){
    for(int col = 0; col < gameMap[0].size(); col++){
      for(int i = 0; i < gameMap[0].size();i++){

      
      for(int row = gameMap.size()-1; row >0;row--){
        //swap numbers if there is a non zero number and a zero number in the row
        if(gameMap[row][col] == 0 && gameMap[row-1][col] != 0){
          std::swap(gameMap[row-1][col],gameMap[row][col]);
        }
        //add 2 numbers if they are the same and touching eachother
        if(gameMap[row-1][col] == gameMap[row][col]){
          gameMap[row][col]+= gameMap[row-1][col];
          score += gameMap[row-1][col];
          gameMap[row-1][col] = 0;
        }
      }
      }
      system("clear");
      std::cout.flush();
      std::cout << this->to_string();
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
  //returns the game board as a string
  std::string to_string(){
    std::string k = "";
    for(int i = 0; i < gameMap.size(); i++){
      k+= "|";
    for(int j = 0; j < gameMap[i].size(); j++){
      
      std::string out = std::to_string(gameMap[i][j]);
      std::string numColor = "";
      switch(gameMap[i][j]){
        case 0:
          numColor = tf::hide;
          break;
        case 2:
          numColor = tf::color(22);
          break;
        case 4:
          numColor = tf::color(34);
          break;
        case 8:
          numColor = tf::color(58);
          break;
        case 16:
          numColor = tf::color(94);
          break;
        case 32:
          numColor = tf::color(137);
          break;
        case 64:
          numColor = tf::color(139);
          break;
        case 128:
          numColor = tf::color(185);
          break;
        case 256:
          numColor = tf::color(184);
          break;
        case 512:
          numColor = tf::color(27);
          break;
        case 1024:
          numColor = tf::color(88);
          break;
        case 2048:
          numColor = tf::color(55);
          break;

      }
      switch(out.length()){
        case 1:
          out = numColor+"  " + out+" " + tf::hideEnd+tf::color(255);
          break;
        case 2:
          out = numColor+" "+ out+" " +tf::color(255);
          break;
        case 3:
          out = numColor+" "+ out +tf::color(255);
          break;
        case 4:
          out = numColor+ out +tf::color(255);
          break;
      }
      out += "|";
      k += out;
    }
  
    k+= "\n";
  }
  k += " __________________\n  score: " 
  + tf::bold + std::to_string(score)+ tf::boldEnd +"\n";
  return k;
  }
  //checks if 2048 is on the board as a win condition
  bool checkWin(){
    for(int row = 0; row < gameMap.size();row++){
      for(int col = 0;col < gameMap[row].size();col++){
        if(gameMap[row][col] >= 2048){
          return true;
        }
      }
    }
    return false;
  }
};