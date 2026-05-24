#include <iostream>
#include <string>

bool LOOP = true;

void echo(std::string arg){
  std::cout<<arg<<std::endl;
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
  else{
    std::cout<<command<<": command not found"<<std::endl;
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
