#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <sstream>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    int counter = 0;
    std::string DateInfo, ArrDate[365];
    double EastSt, WestSt, EastEl, WestEl, ArrWestEl[365];

    while(fin >> DateInfo >> EastSt >> EastEl >> WestSt >>WestEl){
        fin.ignore(INT_MAX, '\n');
        if(DateInfo >= date1 && DateInfo <= date2){ 
            counter++;
            ArrDate[counter] = DateInfo; 
            ArrWestEl[counter] = WestEl;
        }
    }

    for(int i=counter; i>0; i--){
        std::cout << ArrDate[i] << " " << ArrWestEl[i] << " ft" << std::endl; 

    }

    fin.close();
}
