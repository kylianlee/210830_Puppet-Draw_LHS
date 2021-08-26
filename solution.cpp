//
// Created by Kylian Lee on 2021/08/26.
//

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int size = board.size();
  vector<stack<int>> board_stack(size);
  for(int i = size - 1; i >= 0; i--){
    for(int j = 0; j < size; j++){
      if(board[i][j] != 0){
        //        cout << i << ", " << j << ", " << board[i][j] << endl;
        board_stack[j].push(board[i][j]);
        //        cout << board_stack[j].top() << endl;
      }
    }
  }
  int answer = 0;
  int number_of_attempts = moves.size();
  stack<int> basket;
  for(int i = 0; i < number_of_attempts; i++){
    int idx = moves[i] - 1;
    if(!board_stack[idx].empty()){
      if(!basket.empty() && basket.top() == board_stack[idx].top()){
        basket.pop();
        answer += 2;
      }
      else
        basket.push(board_stack[idx].top());
      board_stack[idx].pop();
    }
  }
  return answer;
}

int main(){
  vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
  vector<int> moves = {1,5,3,5,1,2,1,4};
  cout << solution(board, moves) << endl;

  return 0;
}