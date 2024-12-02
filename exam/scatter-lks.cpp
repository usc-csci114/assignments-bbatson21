#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <matplot/matplot.h>

using namespace matplot; 

int main(){
    std::ifstream ifile("bug-attraction.csv");  

    std::string line; 
    std::getline(ifile, line); //get first line and throw away 

    std::vector<int> totals; //vector of totals
    std::vector<double> moon_phases;  

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
                if(site == "LK" || site == "Stunt"){
                    //std::cout << "adding phases, site is: " << site << std::endl; 
                    moon_phases.push_back(moon); 
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
                if(site == "LK" || site == "Stunt"){
                    //std::cout << "adding total, site is " << site << std::endl; 
                    totals.push_back(tot); 
                }
            }
    }
        //if(site == "BG"){
        //    std:: cout << "tot size" << totals.size() << std::endl; 
        //    std:: cout << "moon size" << moon_phases.size() << std::endl; 
       // }
        
        
    }
    
    std:: cout << "total size" << totals.size() << std::endl; 
    std:: cout << "moon size" << moon_phases.size() << std::endl; 


 
    //conduct linear regression 
    double tot_sum = 0; 
    double moon_sum = 0; 

    for(int i=0; i < totals.size(); i++){
        tot_sum += totals[i]; 
        moon_sum += moon_phases[i]; 
    }

    double tot_mean = tot_sum / totals.size(); 
    double moon_mean = moon_sum / moon_phases.size(); 

    double num = 0; 
    double denom = 0; 
    double beta; 

    for(int i=0; i < totals.size(); i++){
        double num_i, denom_i; 
        num_i = (totals[i] - tot_mean) * (moon_phases[i] - moon_mean); 
        denom_i = (totals[i] - tot_mean) * (totals[i] - tot_mean); 

        num += num_i; 
        denom += denom_i; 
    }

    beta = num / denom; 
    double alpha = moon_mean - (beta * tot_mean); 

    int size = totals.size(); 
    std::vector<double> f_vals(size); 
    double ss_res = 0;
    double ss_tot = 0; 

    for(int i=0; i < size; i++){
        double f = alpha + (beta * moon_phases[i]); 
        f_vals[i] = f; 
        std::cout << "f is " << f << std::endl; 

        double sr, st; 
        sr = (moon_phases[i] - f) * (moon_phases[i] - f); 
        ss_res += sr; 
        st = (moon_phases[i] - moon_mean) * (moon_phases[i] - moon_mean); 
        ss_tot += st;
    }

    double r_sq = 1 - (ss_res / ss_tot);

    std::cout << "Line equation is: Moon phase = " << alpha << " + " << beta << "*" << "Total" << std::endl; 
    std::cout << "R^2 value: " << r_sq << std::endl; 


    plot(totals, moon_phases, "rx"); 
    hold(on); 
    plot(totals, f_vals, "b-"); 
    xlabel("Total Bugs at site (LKS and Stunt)"); 
    ylabel("Moon phase"); 
    show(); 
    save("lk-stunt.png"); 

    return 0; 
}