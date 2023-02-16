#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date){

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()){
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dateInfo;
    double EastSt;

    while(fin >> dateInfo >> EastSt){     
        fin.ignore(INT_MAX, '\n'); 
        if(dateInfo == date){
            return EastSt;
        }
    }

    fin.close();
    return 0;
}



double get_min_east(){

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()){
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dataInfo;
    double EastSt;
    double min = INT_MAX;

    while(fin >> dataInfo >> EastSt){
        fin.ignore(INT_MAX, '\n');
        if(min > EastSt){
            min = EastSt;
        }
    }

    fin.close();
    return min;
}



double get_max_east(){

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()){
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dataInfo;
    double EastSt;
    double max = INT_MIN;

    while(fin >> dataInfo >> EastSt){
        fin.ignore(INT_MAX, '\n');
        if(max < EastSt) {
            max = EastSt;
        }
    }
    
    fin.close();
    return max;
}



std::string compare_basins(std::string date){

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dateInfo;
    double EastSt;
    double WestSt;
    double EastEl;

    while(fin >> dateInfo >> EastSt >> EastEl >> WestSt ){
        fin.ignore(INT_MAX, '\n');
        if(dateInfo == date) {
            if(EastSt > WestSt){
                return "East";
            } else if(WestSt > EastSt){
                return "West";
            } else{
                return "Equal";
            }
        }
    }

    fin.close();
    return "";
}