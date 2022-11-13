//
//  ECCommand.cpp
//  

#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory(): pos(-1)
{
  // your code goes here
}

ECCommandHistory :: ~ECCommandHistory()
{
  for(ECCommand* command : history){
    delete command;
  }
}

bool ECCommandHistory::Undo(){
  if(history.size() == 0) return false;
  if(pos < 0){
    pos = history.size() - 1;
  }
  history[pos]->UnExecute();
  pos--;
  return true;
}
bool ECCommandHistory::Redo(){
  if(history.size() == 0 || pos == (int)history.size()) return false;
  pos++;
  history[pos]->Execute();
  return true;
}
void ECCommandHistory::ExecuteCmd( ECCommand *pCmd ){
  history.push_back(pCmd);
  pCmd->Execute();
  pos++;
}
