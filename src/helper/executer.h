#pragma once
#include <cstdlib>
#include <unistd.h>
#include<string>
#include<filesystem>
#include<vector>
#include<iostream>
#include<sstream>

bool isExecutable(const char* path) { // useful to check if executable or not
    return access(path, X_OK) == 0;
}

int execute(const char* command){
    int result = std::system(command);
    return result;
}

namespace fs = std::filesystem;

bool findFile(std::string path,std::string file){
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            if (entry.path().filename()==file) return true;
        }
    }
    return false;
}

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

std::string executionPath(std::string path){
    if (path.substr(0,2)=="./" && isExecutable(path.c_str())){
        return path;
    }
    for (const std::string& dir:getPaths()){
        std::string fullPath = dir + "/" + path;
        try{
        if (findFile(dir,path) && isExecutable(fullPath.c_str())){
            return fullPath;
        }
        }
        catch (...){
        }
    }
    return "";
}