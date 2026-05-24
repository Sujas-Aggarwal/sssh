#include <iostream>
#include <string>

bool LOOP = true;

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

  std::cout<<command<<": command not found"<<std::endl;
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
