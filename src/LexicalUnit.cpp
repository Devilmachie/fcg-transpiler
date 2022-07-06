#include "LexicalUnit.hpp"

std::string lex2String(Lexeme lex){
    std::string retval;
    switch (lex)
    {
        case Lexeme::BEGINGRAM:
            retval = "BEGINGRAM";
            break;
        
        case Lexeme::GRAMNAME:
            retval = "GRAMNAME";
            break;
        
        case Lexeme::PARAMETERS:
            retval = "PARAMETERS";
            break;
        
        case Lexeme::WORDS:
            retval = "WORDS";
            break;
        
        case Lexeme::SLASH:
            retval = "/";
            break;
        
        case Lexeme::LPAREN:
            retval = "(";
            break;

        case Lexeme::RPAREN:
            retval = ")";
            break;
        
        case Lexeme::VARNAME:
            retval = "VARNAME";
            break;
        
        case Lexeme::NUMBER:
            retval = "NUMBER";
            break;

        case Lexeme::MAPPING:
            retval = "->";
            break;
        
        case Lexeme::DOUBLEP:
            retval = ":";
            break;
        
        case Lexeme::ENDGRAMMAR:
            retval = "ENDGRAMMAR";
            break;

        case Lexeme::ROOT:
            retval = "ROOT";
            break;
        
        case Lexeme::EOS:
            retval = "EOS";
            break;
        
        case Lexeme::UNKNOWN:
            retval = "UNKNOWN";
            break;

        default:
            retval = "NULL";
            break;
    }
    return retval;
}

LexicalUnit::LexicalUnit(){
    this->tokenType = Lexeme::UNKNOWN;
    this->value = "NULL";
}

LexicalUnit::LexicalUnit(std::string value, Lexeme tokenType){
    this->tokenType = tokenType;
    this->value = value;
}

Lexeme LexicalUnit::getTokenType(){
    return this->tokenType;
}

std::string LexicalUnit::getValue(){
    return this->value;
}