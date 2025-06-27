#include "Project.h"
#include <iostream>
#include <cstdlib>  // For system()
#include <string>

Project::Project(const char* projectName) {
    name = (projectName);
    std::cout << "Project '" << name << "' created." << std::endl;
}

void Project::initialize() {
    std::cout << "Initializing project: " << name << std::endl;
    
    // Create project directory structure using system calls
    std::string mkdirCmd = "mkdir -p " + name;
    std::system(mkdirCmd.c_str());
    
    std::string srcDir = "mkdir -p " + name + "/src";
    std::system(srcDir.c_str());
    
    std::string includeDir = "mkdir -p " + name + "/include";
    std::system(includeDir.c_str());
    
    std::string includepkg = "mkdir -p " + name + "/.cppkg";
    std::system(includepkg.c_str());


    std::cout << "Project structure created successfully!" << std::endl;
}
