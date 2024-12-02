//make a data table that shows which light type is most attractive for each species 

#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std; 

int main(){
    ifstream ifile("bug-attraction.csv"); 

    map<string, map<string, int> > Order; 
    Order["Diptera"]["A"] = 0; 
    Order["Diptera"]["B"] = 0;
    Order["Diptera"]["C"] = 0;
    Order["Diptera"]["LED"] = 0;
    Order["Diptera"]["CFL"] = 0;
    Order["Hymenoptera"]["A"] = 0; 
    Order["Hymenoptera"]["B"] = 0; 
    Order["Hymenoptera"]["C"] = 0; 
    Order["Hymenoptera"]["LED"] = 0; 
    Order["Hymenoptera"]["CFL"] = 0; 
    Order["Psocoptera"]["A"] = 0; 
    Order["Psocoptera"]["B"] = 0;
    Order["Psocoptera"]["C"] = 0;
    Order["Psocoptera"]["LED"] = 0;
    Order["Psocoptera"]["CFL"] = 0;
    Order["Coleoptera"]["A"] = 0;
    Order["Coleoptera"]["B"] = 0;
    Order["Coleoptera"]["C"] = 0;
    Order["Coleoptera"]["LED"] = 0;
    Order["Coleoptera"]["CFL"] = 0;
    Order["Collembola"]["A"] = 0; 
    Order["Collembola"]["B"] = 0; 
    Order["Collembola"]["C"] = 0; 
    Order["Collembola"]["LED"] = 0; 
    Order["Collembola"]["CFL"] = 0; 
    Order["Arachnid"]["A"] = 0;
    Order["Arachnid"]["B"] = 0;
    Order["Arachnid"]["C"] = 0;
    Order["Arachnid"]["LED"] = 0;
    Order["Arachnid"]["CFL"] = 0;   
    Order["Thysanura"]["A"] = 0; 
    Order["Thysanura"]["B"] = 0;
    Order["Thysanura"]["C"] = 0;
    Order["Thysanura"]["LED"] = 0;
    Order["Thysanura"]["CFL"] = 0;
    Order["Isoptera"]["A"] = 0;
    Order["Isoptera"]["B"] = 0;
    Order["Isoptera"]["C"] = 0;
    Order["Isoptera"]["LED"] = 0;
    Order["Isoptera"]["CFL"] = 0;
    Order["Lepidoptera"]["A"] = 0; 
    Order["Lepidoptera"]["B"] = 0;
    Order["Lepidoptera"]["C"] = 0;
    Order["Lepidoptera"]["LED"] = 0;
    Order["Lepidoptera"]["CFL"] = 0;
    Order["Neuroptera"]["A"] = 0; 
    Order["Neuroptera"]["B"] = 0;
    Order["Neuroptera"]["C"] = 0;
    Order["Neuroptera"]["LED"] = 0;
    Order["Neuroptera"]["CFL"] = 0;
    Order["Larave"]["A"] = 0; 
    Order["Larave"]["B"] = 0;
    Order["Larave"]["C"] = 0;
    Order["Larave"]["LED"] = 0;
    Order["Larave"]["CFL"] = 0;
    Order["Orthoptera"]["A"] = 0; 
    Order["Orthoptera"]["B"] = 0;
    Order["Orthoptera"]["C"] = 0;
    Order["Orthoptera"]["LED"] = 0;
    Order["Orthoptera"]["CFL"] = 0;
    Order["Unident"]["A"] = 0; 
    Order["Unident"]["B"] = 0;
    Order["Unident"]["C"] = 0;
    Order["Unident"]["LED"] = 0;
    Order["Unident"]["CFL"] = 0;

    //for vector, 0: A, 1: B, 2: C, 3: LED, 4: CFL 
    //for dataset: 17: Diptera, 18: Hymenoptera, 19: Hemiptera, 20: Psocoptera, 21: Coleoptera, 22: Collembola, 23: Arachnid, 24: Thysanura
    //25: Isoptera, 26: Lepidoptera, 27: Neuroptera, 28: Larave, 29: Orthoptera, 30: Unident
    string line; 
    getline(ifile, line); //get the first line, throw away 
    for(int i=0; i < 192; i++){
        getline(ifile, line); //get a whole line of data 
        stringstream ss(line); //put the data into a stringstream, there are 33 cols total 
        //account for not getting line of "No"
        string light_; 
        string sub;
        getline(ss, sub, ',');
        light_ = sub; //get light here, past first value in line string 
        if(light_ != "No"){ //condition to enter for loop 

            for(int j=1; j < 33; j++){
                string order_; //declare these here 
                getline(ss, sub, ','); //get indiv item separated by comma 
                if(j == 17){ 
                    order_ = "Diptera"; 
                    Order[order_][light_] += stoi(sub); //append value to this location 
                }
                else if(j == 18){
                    order_ = "Hymenoptera"; 
                    Order[order_][light_] += stoi(sub); 
                }
                else if(j == 19){
                    order_ = "Hemiptera"; 
                    Order[order_][light_] += stoi(sub); 
                }
                else if(j == 20){
                    order_ = "Psocoptera"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 21){
                    order_ = "Coleoptera"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 22){
                    order_ = "Collembola"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 23){
                    order_ = "Arachnid"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 24){
                    order_ = "Thysanura"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 25){
                    order_ = "Isoptera"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 26){
                    order_ = "Lepidoptera";
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 27){
                    order_ = "Neuroptera"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 28){
                    order_ = "Larave"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 29){
                    order_ = "Orthoptera"; 
                    Order[order_][light_] += stoi(sub);
                }
                else if(j == 30){
                    order_ = "Unident"; 
                    Order[order_][light_] += stoi(sub);
                }
            }
        }
    }
    //should have all info at this point 
    for(auto it = Order.begin(); it != Order.end(); ++it){
        cout << "Order is: " << it->first << endl; 
        int total = 0;  
        for(auto it1 = it->second.begin(); it1 != it->second.end(); ++it1){
            cout << it1->first << ":" << it1->second << endl; 
            total += it1->second; 
        }
        
    }

    for(auto it = Order.begin(); it != Order.end(); ++it){
        cout << it->first; 
        int max = 0; 
        string max_string; 
        for(auto it1 = it->second.begin(); it1 != it->second.end(); ++it1){
            //cout << it1->second << endl;
            if(it1->second > max){
                max_string = it1->first; 
                max = it1->second;
            }
        }
        cout << ": " << max_string << endl; 
    }
    
     //have a max value 

}