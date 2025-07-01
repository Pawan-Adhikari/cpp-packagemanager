#include "Package.h"
#include "Project.h"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void copy_pkg(string name, std::string this_p){
    cout << "Adding Package!";
    fs::path module_header_path = "/Users/pawanadhikari/Documents/Course_Stuff/Second_Sem/OOP_project/packages/"+name+".h";
    fs::copy(module_header_path, this_p + "/include");
    fs::path module_src_path = "/Users/pawanadhikari/Documents/Course_Stuff/Second_Sem/OOP_project/packages/"+name+".cpp";
    fs::copy(module_src_path, this_p + "/src");
}

void Package::installTo(const std::string path){
    if (fs::exists(path + "/include")){
        copy_pkg(module_name, path);
    }
    else{
        Project newProj(fs::current_path().string().c_str());
        newProj.initialize();
        copy_pkg(module_name, path);

    }
}

void Package::removeFrom(const std::string path){
    cout << "Removing Package!";
    fs::path rmtarget_header = path + "/include/" + module_name + ".h";
    fs::remove(rmtarget_header);
    fs::path rmtarget_src = path + "/src/" + module_name + ".cpp";
    fs::remove(rmtarget_src);
}
