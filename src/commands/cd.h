#pragma once
#include<filesystem>
#include<string>
#include <cstdlib>
#include<iostream>

namespace fs = std::filesystem;

void cd(std::string path){
    // we need to check for absolute and relative paths
    try{
            if (path.substr(0,1)=="~"){
        fs::current_path(std::getenv("HOME"));
    }
    else{
        fs::current_path(path);
    }
    }
    catch(...){
        std::cout << "cd: "<<path<<": No such file or directory"<<std::endl;
    }

}