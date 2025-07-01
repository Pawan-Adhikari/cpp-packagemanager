#include "Project.h"
#include <iostream>
#include <cstdlib>  
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

Project::Project(const char* projectName) {
    name = (projectName);
    std::cout << "Project '" << name << "' created." << std::endl;
}

void Project::initialize() {
    std::cout << "Initializing project: " << name << std::endl;
    
    std::string mkdirCmd = "mkdir -p " + name;
    std::system(mkdirCmd.c_str());
    
    std::string srcDir = mkdirCmd + "/src";
    std::system(srcDir.c_str());
    
    std::string includeDir = mkdirCmd + "/include";
    std::system(includeDir.c_str());
    
    std::string includepkg = mkdirCmd + "/.cppkg";
    std::system(includepkg.c_str());

    std::string copy_main = "cp ../template/main_to_copy.cpp " + name + "/src/main.cpp";
    std::system(copy_main.c_str());

    std::string copy_makefile = "cp ../template/CMakeLists.txt " + name;
    std::system(copy_makefile.c_str());

    std::string copy_packagestxt = "cp ../template/packages.txt " + name + "/.cppkg/";
    std::system(copy_packagestxt.c_str());

    std::cout << "Project structure created successfully!" << std::endl;
}

void Project::list_modules(){
    fs::path folder = "./include/";  
    std::vector<std::string> file_names;
    for (const auto& entry : fs::directory_iterator(folder)) {
        if (entry.is_regular_file()) {
            file_names.push_back(entry.path().filename().string());
        }
    }
    if (file_names.size() == 0){
        std::cout << "No Packages found in this directory." <<std::endl;
    }
    else{
        std::cout << "Installed Packages: " <<std::endl;
        for (const auto& name : file_names) {
                std::cout << "-" << name << std::endl;
        }
    }
}
