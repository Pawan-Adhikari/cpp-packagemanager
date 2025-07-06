#include "Package.h"
#include "Project.h"
#include <iostream>
#include <filesystem>
#include <cstdlib>  //for using system commands.

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

void Remote_Package::Clone(){
    string command_to_clone = "git clone " + URL + " .cppkg/tmp_package";
    system(command_to_clone.c_str());
    cout << "cloned repo" <<endl;
}

void Remote_Package::Copy_headers(){
    for (const auto& entry : std::filesystem::recursive_directory_iterator(".cppkg/tmp_package")) {
        if (entry.path().extension()==".hpp" || entry.path().extension()==".h"){
                fs::copy(entry.path(),"./include");
                cout << "copied headers" <<endl;
        }
    }

}

void Remote_Package::Copy_src(){
    for (const auto& entry : std::filesystem::recursive_directory_iterator(".cppkg/tmp_package")) {
        if (entry.path().extension()==".cpp" || entry.path().extension()==".c"){
                fs::copy(entry.path(),"./src");
        }
    }
    cout << "copied src" <<endl;

}

void Remote_Package::remove_temp(){
    fs::remove_all(".cppkg/tmp_package");
    cout << "removed repo locally." <<endl;

}

