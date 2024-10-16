#include <iostream>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath> 
#include <iomanip>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct Element {
	Element() :
	symbol(),name(),number(0),atomic_mass(0.0),type() {};
	
	string symbol; //e.g "H", "He"
	string name; //e.g "Hydrogen", "Helium"
	int number; //e.g 1, 2
	double atomic_mass; //e.g. 1.008, 4.0026
	string phase; //phase at room temp e.g gas, liquid, solid
	string type; //e.g. "metalliod, "transitional metals"
};

struct compclass {
  bool operator() ( pair<string, int> a, pair<string, int> b) { return (a.first < b.first);}
} comp;

//prototype
size_t index_find(vector< pair<string, int> > index, string key);
bool is_num(string input); 
void print_element(Element elements); 


int main(int argc, char* argv[])
{
	ifstream ifile("elements.csv");
	vector<Element> Elements(119);
	vector< pair<string, int> > name_index(118);
	vector< pair<string, int> > symbol_index(118);
	cout << Elements.size() << endl; 
	string text_line; 
	getline(ifile, text_line); //get past first line 
	for(int i=0; i < 119; i++){
		Element temp; 
		pair<string, int> p_n; 
		pair<string, int> p_s; 
		int at_num;
		string at_name; 
		string at_sym; 
		double at_mass; 
		string at_phase; 
		string at_type; 
		if(i == 0){
			temp.number = 0; 
			temp.name = ""; 
			temp.symbol = ""; 
			temp.atomic_mass = 0; 
			temp.phase = ""; 
			temp.type = ""; 
			Elements[0] = temp;  
		}
		getline(ifile, text_line); 
		replace(text_line.begin(), text_line.end(), ',', ' '); //pick up here 
		stringstream ss(text_line); 
		ss >> at_num >> at_name >> at_sym >> at_mass >> at_phase >> at_type; 

		p_n.first = at_name; 
		p_n.second = at_num; 
		p_s.first = at_sym; 
		p_s.second = at_num; 
		name_index[at_num - 1] = p_n;
		symbol_index[at_num - 1] = p_s; 
		temp.number = at_num; 
		temp.name = at_name; 
		temp.symbol = at_sym; 
		temp.atomic_mass = at_mass; 
		temp.phase = at_phase; 
		temp.type = at_type; 
		Elements[at_num] = temp; 

	}

	//sort vector of pairs 
	std::sort(symbol_index.begin(), symbol_index.end(), comp);
	std::sort(name_index.begin(), name_index.end(), comp);


	string input;
	size_t index;  

	while(true){
		cout << "Enter an element name, symbol, or atomic number to learn more details about this element." << endl; 
		cin >> input; 
		//cout << "Input received" << endl; 
		//cout << input << endl; 
		//int ind; 
		if(input == "quit"){
			cout << "Quitting program." << endl; 
			break;
		}
		else if(is_num(input) == true){ //check if it's a number 
			//cout << "entered if" << endl; 
			index = stoi(input);  
		}
		else{
			if(input.size() <= 2){
				//cout << "entered if" << endl; 
				index = index_find(symbol_index, input);  
				//cout << "found index" << endl; 
			}
			else{
				index = index_find(name_index, input); 
			}
		//cout << "Index is " << index << endl; 
		}
		//cout << "Check run" << endl; 
		if(index >= 1 && index <= 118){
			print_element(Elements[index]);
		}
		else{
			cout << "Element not found. Please try again or quit." << endl; 
		}
	}
	return 0; 
}

size_t index_find(vector< pair<string, int> > index, string key){
	//perform binary search 
	//index is atomic number, must find this, looking for .second val 
	size_t return_ind; 
	size_t start = 0; 
	size_t end = index.size() - 1; //start and end indexes to start 
	while(start <= end){
		size_t mid = start + (end - start) / 2; 
		if(index[mid].first == key){
			return_ind = index[mid].second; 
			return return_ind; 
		}
		else if(index[mid].first < key){ //if midpoint is less than key
			start = mid + 1; 
		}
		else if(index[mid].first > key){
			end = mid - 1; 
		}  
	}
	return 200;  
} //need to check if returns good value 

bool is_num(string input){ //says whether input is a number 
	bool num = false;
	if(isdigit(input[0])){
		num = true; 
	}
	return num; 
}

void print_element(Element element){
	cout << "Atomic number: " << element.number << endl; 
	cout << "Symbol: " << element.symbol << endl;
	cout << "Name: " << element.name << endl; 
	cout << "Atomic mass: " << element.atomic_mass << endl; 
	cout << "Phase: " << element.phase << endl; 
	cout << "Type: " << element.type << endl; 
}


