//
//  ECTextDocument.h
//

#ifndef ECTextDocument_h
#define ECTextDocument_h

#include "ECCommand.h"
#include <vector>
#include <utility>

using namespace std;

class ECTextDocument;

// **********************************************************
// Implements Commands for editing 


class ECInsertCommand: public ECCommand{
public:
    ECInsertCommand(ECTextDocument &docIn);
    ~ECInsertCommand();
    void AddIndivCommand(int index, char c);
    virtual void Execute();
    virtual void UnExecute();
private:
    ECTextDocument &textDoc;
    vector<pair<int, char>> indivCommands;
};

class ECRemoveCommand: public ECCommand{
public:
    ECRemoveCommand(ECTextDocument &docIn);
    ~ECRemoveCommand();
    void AddIndivCommand(int index, char c);
    virtual void Execute();
    virtual void UnExecute();
private:
    ECTextDocument &textDoc;
    vector<int> indivCommands;
    vector<char> removedCharacters;
};

class ECCapCommand: public ECCommand{
public:
    ECCapCommand(ECTextDocument &docIn);
    ~ECCapCommand();
    void AddIndivCommand(int index, bool wasCapitalized);
    virtual void Execute();
    virtual void UnExecute();
private:
    ECTextDocument &textDoc;
    vector<pair<int, bool>> indivCommands;
};

class ECLowerCommand: public ECCommand{
public:
    ECLowerCommand(ECTextDocument &docIn);
    ~ECLowerCommand();
    void AddIndivCommand(int index, bool wasLowered);
    virtual void Execute();
    virtual void UnExecute();
private:
    ECTextDocument &textDoc;
    vector<pair<int, bool>> indivCommands;
};

// **********************************************************
// Controller for text document

class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn);          // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertTextAt(int pos, const std::vector<char> &listCharsToIns);    // insert a list of characters starting at position
    void RemoveTextAt(int pos, int lenToRemove);                            // remove a segment of characters  of lenToRemove starting from pos
    void CapTextAt(int pos, int lenToCap);                                  // Capitalize the text of lenToCap long starting from pos
    void LowerTextAt(int pos, int lenToLower);                              // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                                            // undo any change you did to the text
    bool Redo();                                                            // redo the change to the text
    
private:
    ECTextDocument& textDoc;
    ECCommandHistory history;
};

// **********************************************************
// Document for text document

class ECTextDocument
{
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl &GetCtrl();          // return document controller
    int GetDocLen() const { return listChars.size(); }
    char GetCharAt(int pos) const;          // get char at current position
    void InsertCharAt(int pos, char ch);    // insert a single char at position
    void RemoveCharAt(int pos);             // erase a single char at position
    void CapCharAt(int pos);                // capitalize the char at position
    void LowerCharAt(int pos);              // lowercase the char at position
    vector<char> GetChars(){return listChars;}

private:
    vector<char> listChars;
    ECTextDocumentCtrl docCtrl;
};


#endif /* ECTextDocument_h */
