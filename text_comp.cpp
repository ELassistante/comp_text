#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std ;

const string message("Line ") ;

int main () {

    string file_name_1 ;
    string file_name_2 ;
    string ref ;
    string comp ;
    size_t cnt(0) ;

    cout << "Name of the reference file (include extention) :" << endl ;
    cin >> file_name_1 ;
    cout << "Name of the file to compare (include extention) :" << endl ;
    cin >> file_name_2 ; 

    ifstream text_ref ;
    ifstream text_comp ;
    ofstream diff ;

    text_ref.open(file_name_1) ;
    text_comp.open(file_name_2) ;
    diff.open("differences.txt") ;
 
    while(getline(text_ref >> ws, ref)) {
        if(getline(text_comp >> ws, comp)) {
            cnt++ ;
            if (ref != comp) diff << message << cnt <<  endl ;
        } else return 0 ;
    }

    return 0 ;
}
}
