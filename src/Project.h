#ifndef PROJECT_H
#define PROJECT_H

#include <string>

class Project {
private:
    std::string name;
    
public:
    Project(const char* projectName);
    void initialize();
};

#endif
