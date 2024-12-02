#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
//#include <matplot/matplot.h>

//using namespace matplot; 

int main(){
    //bg site plot, bugs per row and standardized moon 
    //if bg, get total number of bugs and standardized moon 
    std::ifstream ifile("bug-attraction.csv");  

    std::string line; 
    std::getline(ifile, line); //get first line and throw away 

    std::map<int, std::set<double> > bg_data; //map to store total vs. moon phase 

    //moon is i=4, site is i=2, total is 31 
    for(int i=0; i < 192; i++){
        std::getline(ifile, line); 
        std::stringstream ss(line); 
        std::string sub;  
        std::string site;
        double moon; 
        int tot; 
        for(int j=0; j < 33; j++){
            std::getline(ss, sub, ',');
            if(j == 2){
                std::cout << "entered site if" << std::endl; 
                site = sub; 
            }
            else if(j == 4){
                std::cout << "entered i=4" << std::endl; 
                try{
                    moon = stod(sub);
                }
                catch(const std::exception&){
                    moon = 0.0; 
                }    
            }
            else if(j == 31){
                std::cout << "entered tot" << std::endl; 
                try{
                    tot = stoi(sub); 
                }
                catch(const std::exception&){
                    tot = 0; 
                } 
            }
    }
        std::cout << "after loop, site is" << site << std::endl; 
        if(site == "BG"){
            std::cout << "site is" << site << std::endl; 
            std::cout << "sub is: " << sub << std::endl; 
            std::cout << "tot is" << tot << std::endl; 
            std::cout << "moon is" << moon << std::endl; 
            std::cout << "inserting for tot: " << tot << " and for moon: " << moon << std::endl; 
            bg_data[tot].insert(moon); 
            std::cout << "inserted moon val " << moon << std::endl; 
        }
        
    }
    

 
    for(auto it = bg_data.begin(); it != bg_data.end(); ++it){
        std::cout << "total: " << it->first << " moon phases: "; 
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            std::cout << *it2 << " "; 
        }
        std::cout << std::endl; 
    }

    //convert data to vectors to plot it 

    //std::vector<int> totals; 
    //std::vector<std::vector<double>> phases; 
    //std::vector<double> one_phase; 

    //for(auto it3 = bg_data.begin(); it3 != bg_data.end(); ++it3){
      //  totals.push_back(it3->first); //put total into the vector 
      //  for(auto it4 = it3->second.begin(); it4 != it3->second.end(); ++it4){
      //      one_phase.push_back()
      //  }
    //}

    //plot(bg_data->first, bg_data->second, "-"); 
    //show(); 
    //save("bg.png");

    return 0; 
}