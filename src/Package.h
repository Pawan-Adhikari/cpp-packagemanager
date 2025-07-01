#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <iostream>

class Package{
    private:
        std::string module_name;
        std::string src_path;

    public:
        Package(const std::string& pac){
            module_name = pac;
        }
        void installTo(const std::string path = ".");
        void removeFrom(const std::string path = ".");
};


#endif