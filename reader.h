#ifndef __JAMAL_READER_H
#define __JAMAL_READER_H

#include <iostream>
#include <regex>
#include <string>

#include "types.h"

struct TokenStruct {
    TokenTypes typ;
    std::regex reg;
};

static const TokenStruct regs[] = {
            { TokenTypes::WHITESPACE,      std::regex("[\\s]+") },
            { TokenTypes::OPEN_PAREN,      std::regex("\\(")    },
            { TokenTypes::CLOSE_PAREN,     std::regex("\\)")    },
            { TokenTypes::COMMENT,         std::regex(";.*")    },
            { TokenTypes::QUOTE,           std::regex("\'")     },
            { TokenTypes::BOOLEAN,         std::regex("true")   },
            { TokenTypes::BOOLEAN,         std::regex("false")  },
            { TokenTypes::NUMBER,          std::regex("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)") },
            { TokenTypes::IDENTIFIER,      std::regex("[+-=/*]")  },
            { TokenTypes::IDENTIFIER,      std::regex("[_a-zA-Z][_\\w]*")  }
};


class Tokenizer {
    public:
        Tokenizer(std::string &str);
        
        ~Tokenizer() {
        }

        bool eof() const;

        // TODO (David) : Returning strings below, but
        // should I be returning token types as well?
        std::string next();  // Return current token str and increment
        std::string peek();  // Return current token str
        TokenTypes  peek_tok();
    private:
        // Store of current token
        std::string token_string;
        TokenTypes  token_type;

        // Keeping track of input and positions
        std::string::const_iterator cur_pos;
        std::string::const_iterator end_pos;
        std::string input_string;

        bool match_next();
};

JamalType* read_list(Tokenizer &token, const std::string &beg, const std::string &end);
JamalType* read_atom(Tokenizer &token);
JamalType* read_form(Tokenizer &token);

#endif
