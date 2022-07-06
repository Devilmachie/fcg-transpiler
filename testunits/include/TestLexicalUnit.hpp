#include "catch.hpp"
#include "LexicalUnit.hpp"

SCENARIO("Test LexicalUnit", "[lex]"){
    GIVEN("A LexicalUnit With Some Value Analyzed by the Lexical Analyze"){
        LexicalUnit unit ("doors", Lexeme::VARNAME);

        REQUIRE(unit.getTokenType() == Lexeme::VARNAME);
        REQUIRE(unit.getValue() == "doors");
    }
}