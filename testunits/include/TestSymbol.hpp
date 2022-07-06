#include "catch.hpp"
#include "Symbol.hpp"

SCENARIO("Symbol Creation", "symbol"){

    GIVEN("A Terminal Symbol (a GRAMNAME token) with line and col"){
        Symbol gramname (LexicalUnit("test-grammar", Lexeme::GRAMNAME), 1, 8);
        REQUIRE(gramname.getColumn() == 8);
        REQUIRE(gramname.getLine() == 1);
        REQUIRE(gramname.isTerminal() == true);
        REQUIRE(gramname.getSymbolDefinition() == "token: 'test-grammar', unit: GRAMNAME at line: 1, col: 8");

    }

    GIVEN("A non-Terminal Symbol (a GRAMNAME token) with line and col"){
        Symbol gramname (LexicalUnit("ROOT", Lexeme::ROOT), 2, 9);
        REQUIRE(gramname.getColumn() == 9);
        REQUIRE(gramname.getLine() == 2);
        REQUIRE(gramname.isTerminal() == false);
        REQUIRE(gramname.getSymbolDefinition() == "Non-terminal symbol");
    }

    GIVEN("A Terminal Symbol (a GRAMNAME token) with no line and no col"){
        Symbol gramname (LexicalUnit("test-grammar", Lexeme::GRAMNAME));
        REQUIRE(gramname.getColumn() == UNDEFINED_POSITION);
        REQUIRE(gramname.getLine() == UNDEFINED_POSITION);
        REQUIRE(gramname.isTerminal() == true);
        REQUIRE(gramname.getSymbolDefinition() == "token: 'test-grammar', unit: GRAMNAME at line: ?, col: ?");

    }

    
}