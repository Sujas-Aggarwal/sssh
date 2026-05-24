#include <iostream>
#include <string>
#include<set>
#include <commands/echo.h>
#include <commands/type.h>
#include <commands/pwd.h>
#include <commands/cd.h>
#include <globals/variables.h>
#include <helper/executer.h>
#include <vector>
#include<sstream>


std::vector<std::string> getProcessedCommand(std::string com){
  // basically to get the main command like the start of the command
  std::vector<std::string> sol;
  std::stringstream ss(com);
  std::string temp;
  while (std::getline(ss,temp,' ')){
    sol.push_back(temp);
  }
  return sol;
}

void notFound(std::string command){
    std::cout<<command<<": command not found"<<std::endl;
}

void core(){
 // TODO: Uncomment the code below to pass the first stage
  std::cout << "$ ";

  // Taking User Input
  std::string command;
  std::getline(std::cin,command);

  std::vector<std::string> processedCommand = getProcessedCommand(command);
  std::string func = "";
  if (processedCommand.size()>0){
    func = processedCommand[0];
  }
  
  std::string args = "";
  if (processedCommand.size()>1){
    for (int i = 1; i < processedCommand.size() - 1; i++){
      args += processedCommand[i];
      args += ' ';
    }
    args += processedCommand[processedCommand.size()-1];
  }

  if (command=="exit"){
    LOOP = false;
    return;
  }

  std::string exec_path = executionPath(func);

  //Now we will analyse command here
  // Right now, lets just work on getting single commands get working
  if (func=="echo"){
    echo(args);
  }
  else if (func=="type"){
    type(args);
  }
  // else if (func=="pwd"){
  //   pwd();
  // }
  else if (func=="cd" && processedCommand.size()>1){
    cd(processedCommand[1]);
  }
  else if (exec_path!=""){ // executing external commands
    execute(command.c_str());
  }
  else if (command==""){
    return;
  }
  else{
    notFound(func);
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
