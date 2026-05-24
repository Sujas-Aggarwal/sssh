#include <iostream>
#include <string>

void core(){
 // TODO: Uncomment the code below to pass the first stage
  std::cout << "$ ";

  // Taking User Input
  std::string command;
  std::getline(std::cin,command);

  std::cout<<command<<": command not found"<<std::endl;
}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true){
    core();
  }
  return 0;
}
