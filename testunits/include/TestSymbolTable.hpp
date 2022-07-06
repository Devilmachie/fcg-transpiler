#include "catch.hpp"
#include "SymbolTable.hpp"

SCENARIO("Symbol Table Gestion", "symboltable"){

    GIVEN("An Empty Symbol Table"){
        SymbolTable st;
        REQUIRE(st.getSymbolList().empty());
        WHEN("An Symbol is added"){
            Symbol new_sym (LexicalUnit("example", Lexeme::VARNAME), 5, 8);
            Symbol new_sym_after (LexicalUnit("example", Lexeme::VARNAME), 6, 8);
            Symbol new_sym2 (LexicalUnit("example2", Lexeme::VARNAME), 6, 8);
            st.addSymbol(new_sym);
            THEN("Check if Symbol Table Contains New Symbol"){
                REQUIRE(st.contains(new_sym_after));
                REQUIRE(!st.contains(new_sym2));
            }

            WHEN("The same symbol is removed"){
                st.deleteSymbol(new_sym);

                THEN("Verify that the SymbolTable does not contains the symbol"){
                    REQUIRE(!st.exists(new_sym));
                }
            }
        }



    }
}