#include <iostream>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath> 
#include <iomanip>

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

//prototype
//size_t index_find(vector< pair<string, int> > index, string key);


int main(int argc, char* argv[])
{
	ifstream ifile("elements.csv");
	vector<Element> Elements;
	string text_line; 
	getline(ifile, text_line); //get past first line 
	for(int i=0; i < 118; i++){
		Element temp; 
		int at_num;
		string name; 
		string symbol; 
		double at_mass; 
		string phase; 
		string type; 
		getline(ifile, text_line); 
		stringstream ss(text_line); 
		string temp_line; 
		for(int j=0; j < 6; j++){
			if(j == 0){
				getline(ss, temp_line, ','); 
				stringstream ss1(temp_line); 
				ss1 >> at_num; 
			}
			else if(j == 1){
				getline(ss, temp_line, ','); 
				stringstream ss1(temp_line); 
				ss1 >> name; 
			}
			else if(j == 2){
				getline(ss, temp_line, ','); 
				stringstream ss1(temp_line); 
				ss1 >> symbol; 
			}
			else if(j == 3){
				getline(ss, temp_line, ','); 
				stringstream ss1(temp_line); 
				ss1 >> at_mass; 
			}
			else if(j == 4){
				getline(ss, temp_line, ','); 
				stringstream ss1(temp_line); 
				ss1 >> phase; 
			}
			else if(j == 5){
				getline(ss, temp_line, ','); 
				stringstream ss1(temp_line); 
				ss1 >> type; 
			}
		}
		temp.number = at_num; 
		temp.name = name; 
		temp.symbol = symbol; 
		temp.atomic_mass = at_mass; 
		temp.phase = phase; 
		temp.type = type; 
		if(Elements.size() == 0){
			Elements.push_back(temp); 
		}
		else{
			for(int k=0; k < Elements.size(); k++){
				if(Elements[k].number < temp.number){
					Elements.insert(Elements.begin() + k + 1, temp); 
				}
			}
		}
	}
	//cout << Elements.size() << endl; 
	for(int i=0; i < Elements.size(); i++){
		cout << Elements[i].number << endl; 
	}
	cout << "End of program" << endl; 

	
}

