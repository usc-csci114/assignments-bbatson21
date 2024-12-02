#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <matplot/matplot.h>

using namespace matplot; 

int main(){
    //bg site plot, bugs per row and standardized moon 
    //if bg, get total number of bugs and standardized moon 
    std::ifstream ifile("bug-attraction.csv");  

    std::string line; 
    std::getline(ifile, line); //get first line and throw away 

    std::vector<int> totals; 
    std::vector<std::vector<double> > moon_ph; 
    std::vector<double> moon1;  

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
                if(site == "BG"){
                    moon1.push_back(moon); 
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
                if(site == "BG"){
                    totals.push_back(tot); 
                }
            }
    }
        std::cout << "after loop, site is" << site << std::endl; 
        if(site == "BG"){
            moon_ph.push_back(moon1); 
            std::cout << "added moon phase" << std::endl; 
        }
        
    }

    //for(int i=0; i < totals.size(); i++){
    //    std::cout << totals[i] << std::endl; 
    //}
    
    //for(int i=0; i < moon_ph.size(); i++){
     //   for(int j=0; j < moon1.size(); j++){
     //       std::cout << moon1[j]; 
      //  }
      //  std::cout << std::endl; 
    //}
 
   
 

   

    plot(totals, moon_ph[0], "-"); 
    show(); 
    save("bg.png");

    return 0; 
}