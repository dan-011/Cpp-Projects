//
//  ECTextDocument.cpp
//  

#include "ECTextDocument.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

// **********************************************************
// Commands

ECInsertCommand::ECInsertCommand(ECTextDocument &docIn): textDoc(docIn){}
ECInsertCommand::~ECInsertCommand(){}
void ECInsertCommand::AddIndivCommand(int index, char c){
  indivCommands.push_back(pair<int, char>(index, c));
}
void ECInsertCommand::Execute(){
  for(auto command : indivCommands){
    int index = command.first;
    int character = command.second;
    textDoc.InsertCharAt(index, character);
  }
}
void ECInsertCommand::UnExecute(){
  for(auto command : indivCommands){
    int index = command.first;
    textDoc.RemoveCharAt(index);
  }
}
ECRemoveCommand::ECRemoveCommand(ECTextDocument &docIn): textDoc(docIn){}
ECRemoveCommand::~ECRemoveCommand(){}
void ECRemoveCommand::AddIndivCommand(int index, char c){
  indivCommands.push_back(index);
  removedCharacters.push_back(c);
}
void ECRemoveCommand::Execute(){
  for(int pos : indivCommands){
    textDoc.RemoveCharAt(pos);
  }
}
void ECRemoveCommand::UnExecute(){
  assert(indivCommands.size() == removedCharacters.size());
  for(int i = (int)indivCommands.size() - 1; i >= 0; i--){
    textDoc.InsertCharAt(indivCommands[i], removedCharacters[i]);
  }
}
ECCapCommand::ECCapCommand(ECTextDocument &docIn): textDoc(docIn){}
ECCapCommand::~ECCapCommand(){}
void ECCapCommand::AddIndivCommand(int index, bool wasCapitalized){
  indivCommands.push_back(pair<int, double>(index, wasCapitalized));
}
void ECCapCommand::Execute(){
  for(auto command : indivCommands){
    int pos = command.first;
    bool needsChange = command.second;
    if(needsChange){
      textDoc.CapCharAt(pos);
    }
  }
}
void ECCapCommand::UnExecute(){
  for(auto command : indivCommands){
    int pos = command.first;
    bool needsChange = command.second;
    if(needsChange){
      textDoc.LowerCharAt(pos);
    }
  }
}

ECLowerCommand::ECLowerCommand(ECTextDocument &docIn): textDoc(docIn){}
ECLowerCommand::~ECLowerCommand(){}
void ECLowerCommand::AddIndivCommand(int index, bool wasLowered){
  indivCommands.push_back(pair<int, bool>(index, wasLowered));
}
void ECLowerCommand::Execute(){
  for(auto command : indivCommands){
    int pos = command.first;
    bool needsChange = command.second;
    if(needsChange){
      textDoc.LowerCharAt(pos);
    }
  }
}
void ECLowerCommand::UnExecute(){
  for(auto command : indivCommands){
    int pos = command.first;
    bool needsChange = command.second;
    if(needsChange){
      textDoc.CapCharAt(pos);
    }
  }
}



// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn): textDoc(docIn)
{
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  ECInsertCommand* insertCommand = new ECInsertCommand(textDoc);
  for(auto k = listCharsToIns.rbegin(); k != listCharsToIns.rend(); k++){
    insertCommand->AddIndivCommand(pos, *k);
  }
  history.ExecuteCmd(insertCommand);
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  ECRemoveCommand* remCommand = new ECRemoveCommand(textDoc);
  int count = 0;
  for(int i = pos; i < textDoc.GetDocLen() && count < lenToRemove; i++){
  //for(int i = 0; i < lenToRemove; i++){
    if(pos >= textDoc.GetDocLen()) break;
    remCommand->AddIndivCommand(pos, textDoc.GetCharAt(i));
    count++;
  }
  history.ExecuteCmd(remCommand);
}

void ECTextDocumentCtrl :: CapTextAt(int pos, int lenToCap)
{
  ECCapCommand* capCommand = new ECCapCommand(textDoc);
  int count = 0;
  for(int i = pos; i < textDoc.GetDocLen() && count < lenToCap; i++){
    bool needsChange = islower(textDoc.GetCharAt(i));
    capCommand->AddIndivCommand(i, needsChange);
    count++;
  }
  history.ExecuteCmd(capCommand);
}

void ECTextDocumentCtrl :: LowerTextAt(int pos, int lenToLower)
{
  ECLowerCommand* lowerCommand = new ECLowerCommand(textDoc);
  int count = 0;
  for(int i = pos; i < textDoc.GetDocLen() && count < lenToLower; i++){
    bool needsChange = isupper(textDoc.GetCharAt(i));
    lowerCommand->AddIndivCommand(i, needsChange);
    count++;
  }
  history.ExecuteCmd(lowerCommand);
}

bool ECTextDocumentCtrl :: Undo()
{
  return history.Undo();
}

bool ECTextDocumentCtrl :: Redo()
{
  return history.Redo();
}

// **********************************************************
// Document for text document


ECTextDocument :: ECTextDocument(): docCtrl(*this)
{
}

ECTextDocument :: ~ECTextDocument()
{
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
    return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
  if(GetDocLen() == pos){
    listChars.push_back(ch);
    return;
  }
  if(pos > GetDocLen()){
    string str("Cannot insert item at position {");
    str += to_string(pos);
    str += string("} with size {");
    str += to_string(GetDocLen());
    str += string("}");
    throw str;
  }
  listChars.insert(listChars.begin() + pos, ch);
}

void ECTextDocument :: RemoveCharAt(int pos)
{
  if(pos >= GetDocLen()){
    string str("Cannot remove item at position {");
    str += to_string(pos);
    str += string("} with size {");
    str += to_string(GetDocLen());
    str += string("}");
    throw str;
  }
  listChars.erase(listChars.begin() + pos);
}

void ECTextDocument :: CapCharAt(int pos)
{
  if(pos >= GetDocLen()){
    string str("Cannot capitalize item at position {");
    str += to_string(pos);
    str += string("} with size {");
    str += to_string(GetDocLen());
    str += string("}");
    throw str;
  }
  listChars[pos] = toupper(listChars[pos]);
}

void ECTextDocument :: LowerCharAt(int pos)
{
  listChars[pos] = tolower(listChars[pos]);
}

