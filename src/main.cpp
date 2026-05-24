#include <iostream>
#include <string>
#include<set>

bool LOOP = true;

const std::set<std::string> INBUILD_COMMANDS = {"echo","type","exit"};

void echo(std::string arg){
  std::cout<<arg<<std::endl;
}

void notFound(std::string command){
    std::cout<<command<<": command not found"<<std::endl;
}

void type(std::string arg){
  if (INBUILD_COMMANDS.find(arg)!=INBUILD_COMMANDS.end()){
    std::cout << arg << " is a shell builtin"<<std::endl;
  }
  else{
    notFound(arg);
  }
}

void core(){
 // TODO: Uncomment the code below to pass the first stage
  std::cout << "$ ";

  // Taking User Input
  std::string command;
  std::getline(std::cin,command);

  if (command=="exit"){
    LOOP = false;
    return;
  }
  
  //Now we will analyse command here
  // Right now, lets just work on getting single commands get working
  if (command.substr(0,5)=="echo "){
    echo(command.substr(5,-1));
  }
  else if (command.substr(0,5)=="type "){
    type(command.substr(5,-1));
  }
  else{
    notFound(command);
  }
}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (LOOP){
    core();
  }
  return 0;
}
