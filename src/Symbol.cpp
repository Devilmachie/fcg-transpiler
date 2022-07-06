#include "Symbol.hpp"

Symbol::Symbol(LexicalUnit unit, int line, int col)
{
    this->type = unit;
    this->line = line;
    this->column = col;    
}

Symbol::Symbol(LexicalUnit unit, int line)
{
    this->type = unit;
    this->line = line;
    this->column = UNDEFINED_POSITION;
}


Symbol::Symbol(LexicalUnit unit)
{
    this->type = unit;
    this->line = UNDEFINED_POSITION;
    this->column = UNDEFINED_POSITION;
}

Symbol::Symbol()
{
    this->type = LexicalUnit("NULL", Lexeme::UNKNOWN);
    this->line = UNDEFINED_POSITION;
    this->column = UNDEFINED_POSITION;
}

bool Symbol::isTerminal()
{
    return this->type.getTokenType() != Lexeme::ROOT;
}

LexicalUnit Symbol::getLexicalUnit()
{
    return this->type;
}

int Symbol::getLine()
{
    return this->line;
}

int Symbol::getColumn()
{
    return this->column;
}

std::string Symbol::getSymbolDefinition()
{
    std::string retval;
    if(isTerminal()){
        std::string strline = (line < 0) ? "?" : std::to_string(line);
        std::string strcol = (column < 0) ? "?" : std::to_string(column); 
        retval = std::string("token: '") + type.getValue() + "', unit: " + 
            lex2String(type.getTokenType()) + " at line: " + strline + 
            ", col: " + strcol;
    }
    else{
        retval = "Non-terminal symbol";
    }
    return retval;
    
}