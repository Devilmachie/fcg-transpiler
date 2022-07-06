#ifndef __LEXICALANALYZER_H__
#define __LEXICALANALYZER_H__

/**
 * @file LexicalAnalyzer.hpp
 * @author Devilmachie (https://github.com/Devilmachie)
 * @brief LexicalAnalyzer Class is responsible for transforming source code into a series of tokens
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
//https://www.programmingnotes.org/4699/cpp-simple-lexer-using-a-finite-state-machine/

enum class States{
    INITIAL,
    SPACE,
    REJECT,
};

https://www.gnu.org/software/bison/manual/html_node/Calc_002b_002b-Scanner.html

static const std::string keywords[] = {"BEGINGRAM"};
class LexicalAnalyzer{
    public:
        bool isKeyWord();
    private:
        int line=0, col=0;
        bool atNewLine = true;
        States current = States::INITIAL;
        std::ifstream input;

};
#endif // __LEXICALANALYZER_H__