//Main
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream> // for file input and output ('saved game')
#include <cstdlib> // for srand(), rand()
#include <algorithm>
#include "run.h"
using namespace std;

int run_guessing_random_number_game(vector<int>& to_be_guessed, vector<char>& out_put) { // only run once
     //showing the pre-any in-put bingo board
      cout << "Your current status: (New Game Version) " << endl;
      for (int i = 0; i<9; i=i+3) {
        for (int a = 0; a<3; a++) {
          cout << out_put[i+a] << "   ";
        }
        cout << endl;
      }

      //how many nodes left?
      int number_of_node_available = 0;
      for (int i=0; i<9; i++) {
        if (out_put[i]>='A' && out_put[i]<='I') {
          number_of_node_available++;
        }
      }
      //main body
      while (number_of_node_available>0) {
        char node_input;
        cout << "Please input letters from A to I for the guessing. Do not pick either 'X' (wrong) or 'O' (correct), as those are your result. " << endl;
        cin >> node_input;
        int node_conversion = int(node_input) - int('A');
        if (run(to_be_guessed, node_conversion) == 1) {out_put[node_conversion] = 'O';}
        else {out_put[node_conversion] = 'X';}
        if (number_of_node_available==1) {
          cout << "Your Final Result: " << endl;
          for (int i = 0; i<9; i=i+3) {
            for (int a = 0; a<3; a++) {
              cout << out_put[i+a] << " ";
            }
            cout << endl;
          }
        }
        else {
          cout << "Your updated grid: " << endl;
          for (int i = 0; i<9; i=i+3) {
            for (int a = 0; a<3; a++) {
              cout << out_put[i+a] << " ";
            }
            cout << endl;
          }
        }
        number_of_node_available--;
      }

      //result checking
      int decide_factor = 1;
      if (out_put[0] == 'O' && out_put[3] == 'O' && out_put[6] == 'O' && decide_factor == 1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (out_put[1] == 'O' && out_put[4] == 'O' && out_put[7] == 'O' && decide_factor == 1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (out_put[2] == 'O' && out_put[5] == 'O' && out_put[8] == 'O' && decide_factor == 1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (out_put[0] == 'O' && out_put[1] == 'O' && out_put[2] == 'O' && decide_factor ==
       1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (out_put[3] == 'O' && out_put[4] == 'O' && out_put[5] == 'O' && decide_factor == 1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (out_put[6] == 'O' && out_put[7] == 'O' && out_put[8] == 'O' && decide_factor == 1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (out_put[0] == 'O' && out_put[4] == 'O' && out_put[8] == 'O' && decide_factor == 1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (out_put[2] == 'O' && out_put[4] == 'O' && out_put[7] == 'O' && decide_factor == 1) {
        cout << "Congrats u got one or more than one bingo" << endl;
        decide_factor = decide_factor-1;
      }
      else if (decide_factor == 1){
          cout << "Sorry you lose the game" << endl;
      }
      return 0;
      }


void save(vector<int>& to_be_guessed, vector<char>& out_put) {
  ofstream fout("Savefile.txt", ofstream::out | ofstream::trunc);
  fout << "to_be_guessed ";
  for (int x=0; x < to_be_guessed.size(); x++) {
		if (x < to_be_guessed.size() - 1) {
			fout << to_be_guessed[x] << " ";
		}
		if (x == to_be_guessed.size() - 1) {
			fout << to_be_guessed[x] << " " << 0 << endl;
		}
	}

  fout << "out_put ";
  for (int y=0; y < out_put.size(); y++) {
		if (y < out_put.size() - 1) {
			fout << out_put[y] << " ";
		}
		if (y == out_put.size() - 1) {
			fout << out_put[y] << " " << 0 << endl;
		}
	}

  fout << "#";
  fout.close();
  to_be_guessed.clear();
  out_put.clear();
}

void load(vector<int>& to_be_guessed, vector<char>& out_put) {
  ifstream fin("Savefile.txt");
	string vector_list_to_be_loaded;
	int item_to_be_loaded_into_the_list;
	fin >> vector_list_to_be_loaded;
  while (vector_list_to_be_loaded != "#") {
		if (vector_list_to_be_loaded == "to_be_guessed") {
			fin >> item_to_be_loaded_into_the_list;
			while (item_to_be_loaded_into_the_list != 0) {
				to_be_guessed.push_back(item_to_be_loaded_into_the_list);
				fin >> item_to_be_loaded_into_the_list;
			}
		}

		if (vector_list_to_be_loaded == "out_put") {
			fin >> item_to_be_loaded_into_the_list;
			while (item_to_be_loaded_into_the_list != 0) {
				out_put.push_back(item_to_be_loaded_into_the_list);
				fin >> item_to_be_loaded_into_the_list;
			}
		}

    fin >> vector_list_to_be_loaded;
  }
    fin.close();
}

int main() {
  cout << "Welcome to this game! \nTry your luck and see if you are lucky or not today! \n\n"; //Welcoming
    // instruction code
    char instruction_code;
    cout << "Enter 'L' to load the previous saved game" << endl << "Enter 'N' to start a new game" << endl;
    cout << "Enter 'Q' to quit the game" << endl;
    cin >> instruction_code;
    while (true) {
      if (instruction_code != 'L' && instruction_code != 'N' && instruction_code != 'Q') {
        cout << "Invalid input. Please enter only 'L', 'N' or 'Q' to continue. " << endl;
        cin >> instruction_code;
      }
      else if (instruction_code == 'N') {
        vector<int> to_be_guessed(9);
        vector<char> out_put(9);
      // start game
        cout << "Thank you for starting a new game! Here we go! " << endl;
      // initiate to_be_guessed
	srand(time(NULL));
  	for (int i=0; i<9; i++) {
    	int a = 1 + (rand()%9);
    	to_be_guessed[i] = a;
  }
      // initiate out_put
      out_put = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
      run_guessing_random_number_game(to_be_guessed, out_put);
      break;
    }

      else if (instruction_code == 'L') {
        vector<int> to_be_guessed(9);
        vector<char> out_put(9);
      // run load.cpp save at saved file
      // load cpp should be able to input saved data into the vector out_put
        load(to_be_guessed, out_put);
      // then start game
        cout << "Thank you for continuing the saved game. Here we go again. " << endl;
      // run new to_be_guessed anyway
        run_guessing_random_number_game(to_be_guessed, out_put);
        break;
    }


    else if (instruction_code == 'Q') {
      // Exit, then break while loop
      cout << "Bye Bye, see you next time!" << endl;
      exit(1);
      break;
    }
}

  return 0;
}
