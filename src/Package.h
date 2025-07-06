#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <iostream>

class Package{
    private:
        std::string module_name;
        std::string src_path;

    public:
        Package(){}
        Package(const std::string& pac){
            module_name = pac;
        }
        void installTo(const std::string path = ".");
        void removeFrom(const std::string path = ".");
};

class Remote_Package:public Package{
    private:
        std::string URL;
    public:
        Remote_Package(const std::string& shorthand){
            URL = "https://github.com/" + shorthand + ".git";
        }
        void Clone();
        void Copy_headers();
        void Copy_src();
        void remove_temp();
};
#endif