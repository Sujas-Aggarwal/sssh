#pragma once
#include <iostream>
#include <filesystem>
#include<string>

namespace fs = std::filesystem;
void pwd(){
    std::string path = fs::current_path();
    std::cout << path << std::endl;
}