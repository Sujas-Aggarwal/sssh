#pragma once
#include <cstdlib>
#include <unistd.h>


bool isExecutable(const char* path) { // useful to check if executable or not
    return access(path, X_OK) == 0;
}

int execute(const char* command){
    int result = std::system(command);
    return result;
}