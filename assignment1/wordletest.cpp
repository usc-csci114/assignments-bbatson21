#include <sstream>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std; 
int main()
{
    vector<string> word_list; 
    ifstream ifile("wordlist.txt"); 
    string word;
    string guess;  
    srand(time(0)); 

    while(getline(ifile, word)){
        word_list.push_back(word);
    }
    ifile.close(); 
    int num_words = word_list.size(); 
    int word_ind = rand() % num_words; 
    
    cout << word_ind << endl; 
    word = word_list[word_ind]; 
    cout << word << endl; 

}