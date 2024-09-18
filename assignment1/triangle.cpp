#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std; 
int main(){
    string points;  
    double x1, y1, x2, y2, x3, y3; 

    cout << "Enter 3 points of the triangle, separated by spaces, or 'quit' to quit the program:" << endl; 
    while(getline(cin, points)){
        if(points == "quit"){
            cout << "Quitting program" << endl; 
            return 0; 
        }
        stringstream ss(points); 
        if(ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
            break; 
        }
        else{
            cout << "Invalid value entered. Try again." << endl; 
        }
    }
    
    
    
    double side1, side2, side3; 
    side1 = (x1*(y2 - y3)); 
    side2 = x2*(y3 - y1); 
    side3 = x3*(y1 - y2); 
    double area = (0.5) * abs(side1 + side2 + side3); 
    
    cout << "Triangle area: " << area << endl; 

   return 0; 
}






