/**
 * @file SymbolTable.hpp
 * @author Devilmachie (https://github.com/Devilmachie)
 * @brief Symbol table will encapsulate all the information
 *        of variables encountered during the parsing of 
 *        the FCG-EASY language.
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <vector>
#include <string>
#include <algorithm>
#include "Symbol.hpp"

class SymbolTable{
    private:
        std::vector<Symbol> symtable;
    public:

        /**
         * @brief Check if a symbol is in the SymTable and if it was on a 
         *        previous line than the one of the symbol given in arg;
         * 
         * @param sym Symbol which will be verify if is in SymTable
         * @return true if is contained in SymTable and on a previous line
         * @return false otherwise
         */
        bool contains(Symbol sym);

        /**
         * @brief Check if a symbol is in the SymTable even if it was encountered
         *        on the same line.
         * 
         * @param sym Symbol which will be verify if exists in SymTable
         * @return true if exists in SymbolTable
         * @return false otherwise
         */
        bool exists(Symbol sym);

        /**
         * @brief add a new Symbol to the table
         * 
         * @param sym symbol to be added
         */
        void addSymbol(Symbol sym);

        /**
         * @brief delete a symbol from the symbol table
         * 
         * @param sym symbol to be deleted
         */
        void deleteSymbol(Symbol sym);

        /**
         * @brief Get the Symbol List object
         * 
         * @return std::vector<Symbol> 
         */
        std::vector<Symbol> getSymbolList();
};

#endif // __SYMBOLTABLE_H__