#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <iostream>
#include <algorithm>
#include <matplot/matplot.h>

using namespace matplot; 

struct Bug_tot{
    std::string bug_; 
    int tot; 
}; 


int main(){

    Bug_tot Dip = {"Diptera", 0}; //i = 17
    Bug_tot Hym = {"Hymenoptera", 0}; //i = 18
    Bug_tot Hem = {"Hemiptera", 0}; //i = 19
    Bug_tot Pso = {"Psocoptera", 0}; //i = 20
    Bug_tot Col = {"Coleoptera", 0}; //i = 21
    Bug_tot Coll = {"Collembola", 0}; //i = 22
    Bug_tot Ara = {"Arachnid", 0}; //i = 23
    Bug_tot Thy = {"Thysanura", 0}; //i = 24
    Bug_tot Iso = {"Isoptera", 0}; //i = 25
    Bug_tot Lep = {"Lepidoptera", 0}; //i = 26
    Bug_tot Neu = {"Neuroptera", 0}; //i = 27
    Bug_tot Lar = {"Larave", 0}; //i = 28
    Bug_tot Ort = {"Orthoptera", 0}; //i = 29
    Bug_tot Uni = {"Unident", 0}; //i = 30 

    std::vector<Bug_tot> Bug_total = { {"Diptera", 0}, {"Hymenoptera", 0}, {"Hemiptera", 0}, {"Psocoptera", 0},
    {"Coleoptera", 0}, {"Collembola", 0}, {"Arachnid", 0}, {"Thysanura", 0},
    {"Isoptera", 0}, {"Lepidoptera", 0}, {"Neuroptera", 0}, {"Larave", 0},
    {"Orthoptera", 0}, {"Unident", 0} };

    std::ifstream ifile("bug-attraction.csv");  

    std::string line; 
    std::getline(ifile, line); //get first line and throw away 
 

    for(int i=0; i < 192; i++){
        std::getline(ifile, line); 
        std::stringstream ss(line); 
        std::string sub; //will be type  total  
        for(int j=0; j < 33; j++){
            std::getline(ss, sub, ',');
            if(j == 17){
                Bug_total[0].tot += stoi(sub); 
            }
            else if(j == 18){
                Bug_total[1].tot += stoi(sub); 
            }
            else if(j == 19){
                Bug_total[2].tot += stoi(sub); 
            }
            else if(j == 20){
                Bug_total[3].tot += stoi(sub); 
            }
            else if(j == 21){
                Bug_total[4].tot += stoi(sub); 
            }
            else if(j == 22){
                Bug_total[5].tot += stoi(sub);
            }
            else if(j == 23){
                Bug_total[6].tot += stoi(sub);
            }
            else if(j == 24){
                Bug_total[7].tot += stoi(sub);
            }
            else if(j == 25){
                Bug_total[8].tot += stoi(sub);
            }
            else if(j == 26){
                Bug_total[9].tot += stoi(sub);
            }
            else if(j == 27){
                Bug_total[10].tot += stoi(sub);
            }
            else if(j == 28){
                Bug_total[11].tot += stoi(sub);
            }
            else if(j == 29){
                Bug_total[12].tot += stoi(sub);
            }
            else if(j == 30){
                Bug_total[13].tot += stoi(sub);
            }
    }
        
        
    }

    for(int i=0; i < Bug_total.size(); i++){
        std::cout << Bug_total[i].bug_ << ": " << Bug_total[i].tot << std::endl; 
    }

    for(int i=0; i < Bug_total.size() - 1; i++){ 
        for(int j= i + 1; j < Bug_total.size(); j++){
            if(Bug_total[i].tot < Bug_total[j].tot){
                Bug_tot temp = Bug_total[i]; 
                Bug_total[i] = Bug_total[j]; 
                Bug_total[j] = temp; 
            }
        }
    }

    //for(int i = 0; i < Bug_total.size(); i++){
       // std::cout << Bug_total[i].bug_ << ": " << Bug_total[i].tot << std::endl; 
    //}

    std::string type1, type2, type3, type4; 

    //top 4 types 
    type1 = Bug_total[0].bug_;
    type2 = Bug_total[1].bug_;
    type3 = Bug_total[2].bug_;
    type4 = Bug_total[3].bug_;

    //std::cout << type1 << " " << type2 << " " << type3 << " " << type4 << std::endl; 

    //create 24 vectors of each light type, containing bug type totals based on index 

    std::vector<std::vector<int>> All_tots; 

    std::vector<int> T1 = {0, 0, 0, 0, 0, 0}; 
    std::vector<int> T2 = {0, 0, 0, 0, 0, 0}; 
    std::vector<int> T3 = {0, 0, 0, 0, 0, 0};
    std::vector<int> T4 = {0, 0, 0, 0, 0, 0};   

    //A- i=0; B- i= 1; C- i=2; LED- i=3; CFL- i=4; No- i=5

    std::ifstream ifile2("bug-attraction.csv");  

    std::string line2; 
    std::getline(ifile2, line2); //get first line
    std::stringstream ss2(line2); 

    int t1_i, t2_i, t3_i, t4_i; 
    std::string sub2; 
    for(int i=0; i < 33; i++){
        std::getline(ss2, sub2, ','); 
        if(sub2 == type1){
            t1_i = i; 
        }
        else if(sub2 == type2){
            t2_i = i; 
        }
        else if(sub2 == type3){
            t3_i = i; 
        }
        else if(sub2 == type4){
            t4_i = i; 
        }
    }

    //std:: cout << t1_i << " " << t2_i << " " << t3_i << " " << t4_i << std::endl; 
 
    //Diptera: 17, Lepidoptera: 26, Collembola: 22, Hymenoptera: 18



    for(int i=0; i < 192; i++){
        std::getline(ifile2, line2); 
        std::stringstream ss2(line2); 
        std::string sub2; //will be type  total 
        std::string light_;  
        std::getline(ss2, sub2, ',');
        light_ = sub2; 
        for(int j=1; j < 33; j++){
            std::getline(ss2, sub2, ',');
            if(j == t1_i && light_ == "A"){
                //std::cout << "Adding to Dip for light a, type is: " << type1 << "light is: " << light_ << "total is" << sub2 << std::endl; 
                T1[0] += stoi(sub2); 
            }
            else if(j == t1_i && light_ == "B"){
                T1[1] += stoi(sub2); 
            }
            else if(j == t1_i && light_ == "C"){
                T1[2] += stoi(sub2); 
            }
            else if(j == t1_i && light_ == "LED"){
                T1[3] += stoi(sub2); 
            }
            else if(j == t1_i && light_ == "CFL"){
                T1[4] += stoi(sub2); 
            }
            else if(j == t1_i && light_ == "No"){
                T1[5] += stoi(sub2); 
            }

            else if(j == t2_i && light_ == "A"){
                T2[0] += stoi(sub2); 
            }
            else if(j == t2_i && light_ == "B"){
                T2[1] += stoi(sub2); 
            }
            else if(j == t2_i && light_ == "C"){
                T2[2] += stoi(sub2); 
            }
            else if(j == t2_i && light_ == "LED"){
                T2[3] += stoi(sub2); 
            }
            else if(j == t2_i && light_ == "CFL"){
                T2[4] += stoi(sub2); 
            }
            else if(j == t2_i && light_ == "No"){
                T2[5] += stoi(sub2); 
            }

            else if(j == t3_i && light_ == "A"){
                T3[0] += stoi(sub2); 
            }
            else if(j == t3_i && light_ == "B"){
                T3[1] += stoi(sub2); 
            }
            else if(j == t3_i && light_ == "C"){
                T3[2] += stoi(sub2); 
            }
            else if(j == t3_i && light_ == "LED"){
                T3[3] += stoi(sub2); 
            }
            else if(j == t3_i && light_ == "CFL"){
                T3[4] += stoi(sub2); 
            }
            else if(j == t3_i && light_ == "No"){
                T3[5] += stoi(sub2); 
            }

            else if(j == t4_i && light_ == "A"){
                T4[0] += stoi(sub2); 
            }
            else if(j == t4_i && light_ == "B"){
                T4[1] += stoi(sub2);
            }
            else if(j == t4_i && light_ == "C"){
                T4[2] += stoi(sub2);
            }
            else if(j == t4_i && light_ == "LED"){
                T4[3] += stoi(sub2);
            }
            else if(j == t4_i && light_ == "CFL"){
                T4[4] += stoi(sub2);
            }
            else if(j == t4_i && light_ == "No"){
                T4[5] += stoi(sub2);
            } 
        }
    }

    All_tots.push_back(T1); 
    All_tots.push_back(T2); 
    All_tots.push_back(T3); 
    All_tots.push_back(T4); 

    //for(int i=0; i < All_tots.size(); i++){
      //  for(int j=0; j < T1.size(); j++){
       //     std::cout << All_tots[i][j] << " "; 
       // }
      //  std::cout << std::endl; 
    //}

    std::vector<std::string> Lights = {"A", "B", "C", "LED", "CFL", "No"}; 
    //std::cout << "Type1: " << type1 << "Type2: " << type2 << "Type3: " << type3 << std::endl; 

    bar(All_tots); 
    //legend({type1, type2, type3, type4}); 
    gca()->x_axis().ticklabels({"A", "B", "C", "LED", "CFL", "No"});
    show(); 
    save("Hist.png");
    return 0; 
}