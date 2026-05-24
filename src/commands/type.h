#pragma once
#include <string>
#include <iostream>
#include <globals/constants.h>
#include <helper/executer.h>



void type(std::string arg){
  if (INBUILD_COMMANDS.find(arg)!=INBUILD_COMMANDS.end()){
    std::cout << arg << " is a shell builtin"<<std::endl;
    return;
  }
  std::string fullPath = executionPath(arg);
  if (fullPath!=""){
    std::cout << arg << " is " << fullPath <<std::endl;
    return;
  }
  // check if any executable is present external
    std::cout<<arg<<": not found"<<std::endl;
}