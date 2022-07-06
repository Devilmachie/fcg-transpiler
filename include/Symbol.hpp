#ifndef __SYMBOL_H__
#define __SYMBOL_H__

/**
 * @file Symbol.hpp
 * @author Devilmachie (https://github.com/Devilmachie)
 * @brief  Symbol Class will be used as the Class encapsulating information about a token of the FCG-EASY grammar
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "LexicalUnit.hpp"
#include <string>
#define UNDEFINED_POSITION -1

class Symbol{
    private:
        LexicalUnit type;
        int line, column;

    public:
        /**
         * @brief Construct a new Symbol object with line and columns position
         * 
         * @param unit 
         * @param line 
         * @param col 
         */
        Symbol(LexicalUnit unit, int line, int col);
        
        /**
         * @brief Construct a new Symbol object with undefined column position
         * 
         * @param unit 
         * @param line 
         */
        Symbol(LexicalUnit unit, int line);

        /**
         * @brief Construct a new Symbol object undefined line and column position
         * 
         * @param unit 
         */
        Symbol(LexicalUnit unit);
        
        /**
         * @brief Construct a new Symbol object, However, no useful would be retrievable from such symbol.
         * 
         */
        Symbol();

        /**
         * @brief Check if a symbol is terminal or not.
         * 
         * @return true if is terminal
         * @return false if not terminal
         */
        bool isTerminal();
        
        /**
         * @brief Get the Lexical Unit object
         * 
         * @return LexicalUnit 
         */
        LexicalUnit getLexicalUnit();
        
        /**
         * @brief Get the Line object
         * 
         * @return int 
         */
        int getLine();
       
        /**
         * @brief Get the Column object
         * 
         * @return int 
         */
        int getColumn();
       
        /**
         * @brief Get the string representation of objects
         * 
         * @return std::string 
         */
        std::string getSymbolDefinition();

        

};
#endif // __SYMBOL_H__