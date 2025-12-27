#include <iostream>
#include <regex>
#include <string>

enum TokenTypes { NA, WHITESPACE, OPEN_PAREN, CLOSE_PAREN,
                  COMMENT, QUOTE, BOOLEAN, IDENTIFIER};
struct TokenRegex {
    TokenTypes typ;
    std::regex reg;
};

static const TokenRegex regs[] = {
            { TokenTypes::WHITESPACE,      std::regex("[\\s]+")},
            { TokenTypes::OPEN_PAREN,      std::regex("\\(")    },
            { TokenTypes::CLOSE_PAREN,     std::regex("\\)")    },
            { TokenTypes::COMMENT,         std::regex(";.*")    },
            { TokenTypes::QUOTE,           std::regex("\'")     },
            { TokenTypes::BOOLEAN,         std::regex("true")   },
            { TokenTypes::BOOLEAN,         std::regex("false")  },
            { TokenTypes::IDENTIFIER,      std::regex("[+-=/*]")  },
            { TokenTypes::IDENTIFIER,      std::regex("[_a-zA-Z][_\\w]*")  }
};


class Tokenizer {
    public:
        Tokenizer(std::string &str);
        
        ~Tokenizer() {
        }

        bool eof() const {
            return cur_pos == end_pos;
        }

        bool match_next();
    private:
        std::string token_string;
        TokenTypes  token_type;
        std::string::const_iterator cur_pos;
        std::string::const_iterator end_pos;


};

Tokenizer::Tokenizer(std::string &str):
    cur_pos(str.begin()), end_pos(str.end())
{
    token_type = NA;
}


bool Tokenizer::match_next() {
    if (cur_pos == end_pos) {
        token_type = NA;
        return false;
    }

    for (auto i : regs) {
        auto flags = std::regex_constants::match_continuous;
        std::smatch match;
        std::regex_search(cur_pos, end_pos, match, i.reg, flags);
        if (match.length(0) != 0) {
            token_string = match[0];
            token_type   = i.typ;
            cur_pos +=   match.length(0);

            std::cout <<"{" << i.typ <<"  " <<match.length(0);
            std::cout <<" ," <<token_string <<"}" <<std::endl;
            //std::string s(cur_pos, end_pos);
            //std::cout <<"{" <<s <<"}" << std::endl;

            return true;
        }
    }
    token_type = NA;
    cur_pos++;
    return false;
}


/*int main() {
    std::string inpt="   (lambda (x) (+ 2 x)) ; I'm done";
    Tokenizer t(inpt);
    std::cout <<inpt <<std::endl;
    std::cout <<"a" <<std::endl;
    while (t.match_next()) { }
    std::cout <<"b" <<std::endl;

    return 0;
}*/


