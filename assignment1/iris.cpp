#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

double get_mean(std::vector<double> vals);
double get_max(std::vector<double> vals);
double get_min(std::vector<double> vals);
double get_stdv(std::vector<double> vals); 
void print_segment(std::vector<double> vals); 

using namespace std; 
int main(){
    
    ifstream ifile("iris.txt"); 
    string text_line; 
    vector<double> set_sep_l; 
    vector<double> set_sep_w; 
    vector<double> set_pet_l; 
    vector<double> set_pet_w; 
    vector<double> ver_sep_l; 
    vector<double> ver_sep_w; 
    vector<double> ver_pet_l; 
    vector<double> ver_pet_w; 
    vector<double> vir_sep_l; 
    vector<double> vir_sep_w; 
    vector<double> vir_pet_l; 
    vector<double> vir_pet_w; 

    for(int i = 0; i < 150; i++){
        string temp_line; 
        getline(ifile, text_line); 
        stringstream ss(text_line); 
        double temp_sep_l; //0
        double temp_sep_w; //1
        double temp_pet_l; //2
        double temp_pet_w; //3
        string temp_name; 
        for(int j=0; j < 5; j++){
            //call getline with ss, and separator as comma
            //use a vector 
            //use getline to get the name, then can go back and add values to vector
            if(j == 0){
                getline(ss, temp_line, ','); //get line, put into temp line, sep by comma
                stringstream ss1(temp_line); //put into stringstream so can convert 
                ss1 >> temp_sep_l; //put first val into sepal length for this line 
            }
            if(j == 1){
                getline(ss, temp_line, ','); 
                stringstream ss1(temp_line); 
                ss1 >> temp_sep_w; 
            }
            if(j == 2){
                getline(ss, temp_line, ','); 
                stringstream ss1(temp_line); 
                ss1 >> temp_pet_l; 
            }
            if(j == 3){
                getline(ss, temp_line, ','); 
                stringstream ss1(temp_line); 
                ss1 >> temp_pet_w; 
            }
            if(j == 4){ //if getting name of iris
                getline(ss, temp_line, ','); //at end of line so get whole line 
                stringstream ss1(temp_line); //make a stringstream 
                ss1 >> temp_name; 
            }
        }
        //out of nested loop 
        if(temp_name == "Iris-setosa"){
            //add to these vectors 
            set_sep_l.push_back(temp_sep_l); 
            set_sep_w.push_back(temp_sep_w); 
            set_pet_l.push_back(temp_pet_l); 
            set_pet_w.push_back(temp_pet_w); 
        }
        else if(temp_name == "Iris-versicolor"){
            //add to these vectors 
            ver_sep_l.push_back(temp_sep_l); 
            ver_sep_w.push_back(temp_sep_w); 
            ver_pet_l.push_back(temp_pet_l); 
            ver_pet_w.push_back(temp_pet_w); 
        }
        else if(temp_name == "Iris-virginica"){
            //add to these vectors 
            vir_sep_l.push_back(temp_sep_l); 
            vir_sep_w.push_back(temp_sep_w); 
            vir_pet_l.push_back(temp_pet_l); 
            vir_pet_w.push_back(temp_pet_w); 
        }

    }

    int width = 101; 
    string title = "Iris Data"; 
    int edge1 = (width - title.length()) / 2; 
    int edge2 = width - edge1; 

    for(int i=0; i < 10; i++){
        if(i == 0){
            cout << setw(edge1) << "" << title << setw(edge2) << "" << endl; 
        }
        else if(i % 2 != 0){
            for(int i = 0; i < 101; i++){
                cout << "-"; 
            }
            cout << endl; 
        }
        else if(i == 2){  
            cout << "|            | sepal length       | sepal width        | petal length        | petal width          |" << endl; 
        }
        else if(i == 4){
            cout << "| setosa |";
            print_segment(set_sep_l);
            print_segment(set_sep_w);
            print_segment(set_pet_l);
            print_segment(set_pet_w);
            cout << endl;
        }
        else if(i == 6){
            cout << "| versicolor |";
            print_segment(ver_sep_l);
            print_segment(ver_sep_w);
            print_segment(ver_pet_l);
            print_segment(ver_pet_w);
            cout << endl; 
        }
        else if(i == 8){
            cout << "| virginica |";
            print_segment(vir_sep_l);
            print_segment(vir_sep_w);
            print_segment(vir_pet_l);
            print_segment(vir_pet_w);
            cout << endl; 
        }
    }

    

}

double get_mean(std::vector<double> vals){
    double sum = vals[0]; 
    int tot = vals.size(); 
    for(int i = 1; i < tot; i++){
        sum = sum + vals[i]; 
    }
    double mean = sum / tot; 
    return mean; 
}

double get_max(std::vector<double> vals){
    double curr_max = vals[0]; 
    for(int i = 0; i < vals.size(); i++){
        if(vals[i] > curr_max){
          curr_max = vals[i]; 
       } 
    }
    return curr_max;
} 

double get_min(std::vector<double> vals){
    double curr_min = vals[0]; 
    for(int i = 0; i < vals.size(); i++){
        if(vals[i] < curr_min){
            curr_min = vals[i]; 
        }
   }
   return curr_min; 
}

double get_stdv(std::vector<double> vals){
    double mean = get_mean(vals); 
    int n = vals.size(); 
    double num = 0; 
    for(int i=0; i < vals.size(); i++){
        double curr = vals[i] - mean; 
        double curr_sq = pow(curr, 2); 
        num = num + curr_sq; 
    }
    double var = num / (n - 1); 
    double stdv = sqrt(var); 
    return stdv; 
}

void print_segment(std::vector<double> vals){
    double min = get_min(vals);  
    double max = get_max(vals); 
    double mean = get_mean(vals); 
    double stdv = get_stdv(vals); 
    std::cout << " " << std::fixed << std::setprecision(1) << min << ", " << std::fixed << std::setprecision(1) << max << ", " << std::fixed << std::setprecision(1) << mean << ", " << std::fixed << std::setprecision(1) << stdv << " |"; 
}


