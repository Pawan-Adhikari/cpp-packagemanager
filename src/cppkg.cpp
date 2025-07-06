
#include <iostream>
#include "Project.h"
#include "Package.h"
#include <string>
#include <regex>

using namespace std;

int main(int argc, char* argv[]){      
    if (argc==3){
        if (!(strcmp(argv[1],"init"))){
            Project myProject(argv[2]);
            myProject.initialize();
        }
        else if (!(strcmp(argv[1],"add"))){
            std::regex pattern(R"(^[a-zA-Z0-9_.-]+/[a-zA-Z0-9_.-]+$)");
            if (std::regex_match(argv[2], pattern)) {
                Remote_Package rem_pac_to_add(argv[2]);
                cout << "Matched a URL."<<endl;
                rem_pac_to_add.Clone(); 
                rem_pac_to_add.Copy_headers();
                rem_pac_to_add.Copy_src();    
                rem_pac_to_add.remove_temp(); 
            }
            else{
                cout << "Matched a File locally."<<endl;
                std::string mod_name = argv[2];
                Package pac_to_add(mod_name);
                pac_to_add.installTo();
            }
            cout << "Added the package sucessfully!";

        }
        else if(!(strcmp(argv[1],"remove"))){
            std::string mod_name = argv[2];
            Package pac_to_rm(mod_name);
            pac_to_rm.removeFrom();
            cout << "Removed the package sucessfully!";
        }
        else{
            cout << "Invalid Usage" <<endl;
            cout << "Do cppkg <command> <options>"<<endl;
        }
    }
    else if (argc == 2){
        if (!(strcmp(argv[1],"list"))){
            Project::list_modules();
        }
        else {
        cout << "Invalid usage" << endl;
        cout << "Do cppkg <command> <options>"<<endl;
    } 
    }
    else {
        cout << "Invalid usage" << endl;
        cout << "Do cppkg <command> <options>"<<endl;
    } 

    return 0;
}