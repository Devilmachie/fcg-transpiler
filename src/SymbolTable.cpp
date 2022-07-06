#include "SymbolTable.hpp"


bool SymbolTable::contains(Symbol sym){
    std::string symname = sym.getLexicalUnit().getValue();
    for(std::vector<Symbol>::iterator it = std::begin(symtable); it != std::end(symtable); it++){
        if((*it).getLexicalUnit().getValue() == symname){
            return (*it).getLine() < sym.getLine();
        }
    }
    return false;
}

bool SymbolTable::exists(Symbol sym){
    std::string symname = sym.getLexicalUnit().getValue();
    for(std::vector<Symbol>::iterator it = std::begin(symtable); it != std::end(symtable); it++){
        if((*it).getLexicalUnit().getValue() == symname){
            return true;
        }
    }
    return false;
}

void SymbolTable::addSymbol(Symbol sym){
    this->symtable.push_back(sym);
}

void SymbolTable::deleteSymbol(Symbol sym){
    std::string symname = sym.getLexicalUnit().getValue();
    for(std::vector<Symbol>::iterator it = std::begin(symtable); it != std::end(symtable); it++){
        if((*it).getLexicalUnit().getValue() == symname){
            it = symtable.erase(it);
            return;
        }
    }
}

std::vector<Symbol> SymbolTable::getSymbolList(){
    return this->symtable;
}