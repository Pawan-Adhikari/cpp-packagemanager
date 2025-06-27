
#include <iostream>
using namespace std;
#include "Project.h"
#include <string>

int main(int argc, char* argv[]){
    if (argc < 3){
        cout << "Invalid usage" << endl;
        cout << "Do cppkg <command> <options>"<<endl;
    }
    if (argc==3){
        if (strcmp(argv[2],"init")){
            Project myProject(argv[2]);
            myProject.initialize();
        }
        else{
            cout << "Invalid Usage" <<endl;
            cout << "Do cppkg <command> <options>"<<endl;
        }
    }
    return 0;
}