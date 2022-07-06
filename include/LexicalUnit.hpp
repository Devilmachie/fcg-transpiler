#ifndef __LEXICALUNIT_H__
#define __LEXICALUNIT_H__

/**
 * @file LexicalUnit.hpp
 * @author Devilmachie (https://github.com/Devilmachie)
 * @brief This class is an enumeration of the the different type of possible lexical type
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>

/**
 * @brief This enum class is used to define every token that can exists Within The FCG-EASY language
 * 
 */
enum class Lexeme {
    BEGINGRAM,
    GRAMNAME,
    PARAMETERS,
    WORDS,
    SLASH,
    LPAREN,
    RPAREN,
    VARNAME,
    NUMBER,
    MAPPING,
    DOUBLEP,
    ENDGRAMMAR,
    ROOT,
    EOS,
    UNKNOWN
};

/**
 * @brief convert a lexeme to its string value
 * 
 * @param lex 
 * @return std::string written value of the lex
 */
std::string lex2String(Lexeme lex);

/**
 * @brief This is the class encapsulating the data of the tokens of the FCG-EASY language. 
 */
class LexicalUnit
{
private:
    std::string value;
    Lexeme tokenType;

public:
    /**
     * @brief Construct a new Lexical Unit object
     * 
     */
    LexicalUnit();

    /**
     * @brief Construct a new Lexical Unit object
     * 
     * @param value contains the plain value of the token 
     * @param tokenType contains the type of lexeme of the token
     */
    LexicalUnit(std::string value, Lexeme tokenType);
    
    /**
     * @brief Get the Token Type object
     * 
     * @return Lexeme 
     */
    Lexeme getTokenType();
    
    /**
     * @brief Get the Value object
     * 
     * @return std::string 
     */
    std::string getValue();
    
};

#endif // __LEXICALUNIT_H__