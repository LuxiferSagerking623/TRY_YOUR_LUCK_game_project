//run.cpp
//bingo board: only 3x3 bingo board
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstdlib> // for srand(), rand()
#include <algorithm>
#include "run.h"
using namespace std;

int run(vector<int>& to_be_guessed, int node_conversion) { // return true if guessed successfully, false if not guessed successfully
  int correct_ans = to_be_guessed[node_conversion];
  srand(time(NULL));
  int i = 2 + (rand()%5);
  cout << "You have only " << i << " chances to ant interger between 1-9. Good Luck." << endl;
  while (i>0) {
    int user_input_for_node;
    cin >> user_input_for_node;
    if(user_input_for_node == correct_ans) {
      cout << "Congratulations! You have guessed the right letter within the given chances!" << endl;
      return 1;
      break;
    }
    else if (user_input_for_node != correct_ans && i > 1) {
      cout << "Please retry guessing." << endl;
    }
    i--;
  }

  if (i==0) {
  cout << "I am sorry that your chances are used up. You still haven't guessed the right letter. " << endl;
  return 0; }
}
