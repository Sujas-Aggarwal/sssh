#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include<vector>
#include<sstream>
#include <globals/constants.h>
#include <unistd.h>
#include <filesystem>

namespace fs = std::filesystem;

bool isExecutable(const char* path) { // useful to check if executable or not
    return access(path, X_OK) == 0;
}

bool findFile(std::string path,std::string file){
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            if (entry.path().filename()==file) return true;
        }
    }
    return false;
}


// TODO: We need to add functionality in such a way that we can - 
//1. get all the dir in PATH
//2. look for executable
//3. return nothign if nothign found

std::vector<std::string> getPaths(){
    const std::string path= std::getenv("PATH");
    std::stringstream pathSS(path);
    std::vector<std::string> dirs;
    char seperator = ':';
    #ifdef _WIN32
        seperator = ';';
    #endif
    std::string dir;
    while (std::getline(pathSS,dir,seperator)){
        dirs.push_back(dir);
    }
    return dirs;
}

void type(std::string arg){
  if (INBUILD_COMMANDS.find(arg)!=INBUILD_COMMANDS.end()){
    std::cout << arg << " is a shell builtin"<<std::endl;
    return;
  }
  for (const std::string& dir:getPaths()){
    std::string fullPath = dir + "/" + arg;
    try{
    if (findFile(dir,arg) && isExecutable(fullPath.c_str())){
        std::cout << arg << " is " << fullPath <<std::endl;
        return;
    }
    }
    catch (...){
    }
  }
    std::cout<<arg<<": not found"<<std::endl;
}