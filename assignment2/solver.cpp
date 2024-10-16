#include <iostream>
#include <vector>
#include "system.h"
#include <string>
#include <sstream>


using namespace std;

int main(int argc, char* argv[])
{
    int m, n; 
    cout << "How many equations are in the system?" << endl;
    cin >> n; 
    cout << "How many unknowns are in the equations?" << endl; 
    cin >> m; 
    int col = m + 1; 
    vector< vector<double> > eqs(n, vector<double>(col)); 

    //take in coefficients for each equation and what it equals
    for(int i=0; i < n; i++){
        cout << "Enter the coefficients and the sum of equation " << i + 1 << ": " << endl; 
        bool size = false; 
        while(size == false){
            string input;
            cin >> ws; 
            getline(cin, input); 
            cout << "Got input" << endl; 
            cout << input << endl; 
            stringstream ss(input); 
            double x; 
            int cnt = 0; 
            for(int j=0; j < col; j++){
                ss >> x; 
                if(ss.fail()){
                    break; 
                }
                eqs[i][j] = x; 
                cnt ++; 
            }
            if(cnt != col || ss >> x){
                cout << "Invalid input. Try again." << endl; 
            }
            else{
                size = true; 
            }
        }
    }

    for(int i=0; i < n; i++){
        for(int j=0; j < col; j++){
            cout << eqs[i][j]; 
        }
        cout << endl; 
    }

    System system1(n, m, eqs); 
    system1.solve(); 

    int num_sol = system1.getNumSolutions(); 
    if(num_sol < 2){
        cout << "There are " << num_sol << " solutions to this system." << endl;
    }
    else if(num_sol == 2){
        cout << "There are infinite solutions to this system." << endl; 
    }
     
    if(num_sol != 0){
        vector<double> sols = system1.getSolution(); 
        cout << "The solutions to this system are: "; 
        for(int i=0; i < sols.size(); i++){
            cout << sols[i] << " "; 
        }
        cout << endl; 
    }

    
    

}
