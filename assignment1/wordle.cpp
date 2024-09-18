#include <sstream>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

bool find_word(std::string guess, std::vector<std::string> word_list);
int inplace_cnt(std::string guess, std::string word);
bool letter_inword(std::string guess, std::string word);
std::string get_word(std::vector<std::string> word_list); 

using namespace std; 
int main()
{
    vector<string> word_list; 
    ifstream ifile("wordlist.txt"); 
    string guess;  
    string word; 
    string green = "\033[92m";
	string yellow = "\033[93m";
	string coloroff = "\033[0m";
    srand(time(0)); 
    while(getline(ifile, word)){
        word_list.push_back(word);
    }
    ifile.close(); 

    vector<string> board(6, "*****"); 
    word = get_word(word_list);  
    int guess_cnt = 0; 
    
    cout << "Welcome to Wordle!" << endl; 
    for(int i=0; i < 6; i++){
        cout << board[i] << endl; 
    }
    bool quit = false; 
    while(quit == false){
        cout << "Enter your guess:" << endl; 
        cin >> guess; 
        bool in_list = find_word(guess, word_list); 
        int guess_size = guess.length(); 
        if(guess == "quit"){
            cout << "Quitting program" << endl; 
            quit = true; 
            break; 
        }
        else if(guess == "new"){
            guess_cnt = 0; 
            word = get_word(word_list); 
            cout << "Welcome to Wordle!" << endl; 
            for(int i=0; i < 6; i++){
                cout << board[i] << endl; 
            }
            cout << "Enter your guess:" << endl; 
        }
        else if(guess_size != 5){
            cout << "Unable to parse input, please try again." << endl; 
        }
        else if(!in_list){
            cout << "Invalid word, please try again." << endl;
        }
        else if(in_list){
            guess_cnt++;
            int match = inplace_cnt(guess, word); 
            //bool in_word = letter_inword(guess, word); 
            string updated_word = ""; //remember to add updated word to new vector
            for(int i=0; i < guess.length(); i++){
                if(word[i] == guess[i]){
                    updated_word += green + guess[i] + coloroff; 
                }
                else{
                    bool is_present = letter_inword(guess, word); //make this function check at a specific index?, then can just update without looping
                    for(int j=0; j < guess.length(); j++){
                        if(word[j] == guess[i] && guess[j] != word[j]){
                            updated_word += yellow + guess[i] + coloroff; 
                            is_present = true; 
                            break; 
                        }
                    }
                    if(is_present == false){
                        updated_word += coloroff + guess[i]; 
                    }
                }
                
            }
            board[guess_cnt - 1] = updated_word;
            for(int i = 0; i < 6; i++){
                cout << board[i] << endl; 
            }
            if(match == 5){
                cout << "Congratulations! Begin a new game or quit at the next prompt." << endl; 
            }
            else if(guess_cnt == 6){
                cout << "Sorry, the correct word was:" << word << endl; 
                cout << "Begin a new game or quit at the next prompt" << endl; 
            }
            
        }        
    }


    return 0; 
}

bool find_word(std::string guess, std::vector<std::string> word_list){
    bool word_exist = false; 
    for(int i = 0; i < word_list.size(); i++){
        if(guess == word_list[i]){
            word_exist = true; 
            break; 
        }
    }
    return word_exist; 
}

int inplace_cnt(std::string guess, std::string word){
    int cnt = 0; 
    for(int i = 0; i < guess.length(); i++){
        if(guess[i] == word[i]){
            cnt++; 
        }
    }
    return cnt; 
}
 

bool letter_inword(std::string guess, std::string word){
    bool inword = false; 
    for(int i=0; i < guess.length(); i++){
        for(int j=0; j < guess.length(); j++){
            if(word[i] == guess[j]){
                inword = true; 
                break; 
            }
        }
    }
    return inword; 
}

std::string get_word(std::vector<std::string> word_list){
    int num_words = word_list.size(); 
    int word_ind = rand() % num_words;
    string word = word_list[word_ind];
    return word; 
}


//make <vector> string board(6), then override 
//outerloop handles input, inner loop handles if it's a specific guess
//use string concatenation to change color, why better to use string than char array 
//bool function for if word matches space and then if letter is in word, make updated string 