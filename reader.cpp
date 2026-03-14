#include "reader.h"


Tokenizer::Tokenizer(std::string &str)
{
    token_string = "";
    token_type   = NA;
    input_string = str;
    cur_pos = input_string.begin();
    end_pos = input_string.end();

    next();
}


bool Tokenizer::eof() const { return (cur_pos == end_pos); }


bool Tokenizer::match_next() {
    // Checking for EOF
    if (eof()) {
        token_type = NA;
        return false;
    }

    // Iterate through list of token regexs
    for (auto i : regs) {
        auto flags = std::regex_constants::match_continuous;
        std::smatch match;
        std::regex_search(cur_pos, end_pos, match, i.reg, flags);

        // We found a match? Do stuff and return true.
        if (match.length(0) != 0) {
            token_string = match[0];
            token_type   = i.typ;
            cur_pos +=   match.length(0);

#ifdef DEBUG_TOKEN_OUT
            std::cout <<"{" << i.typ <<"  " <<match.length(0);
            std::cout <<" ," <<token_string <<"}  " ; //<<std::endl;
#endif

            return true;
        }
    }

    // No match found
    token_type = NA;
    cur_pos++;
    return false;
}

std::string Tokenizer::next() {
    if (eof()) {
        return "end";
    }
    std::string ret_string = token_string;
    match_next();
    return ret_string;
}

std::string Tokenizer::peek() {
    return token_string;
}

TokenTypes Tokenizer::peek_tok() {
    return token_type;
}

JamalType *read_list(Tokenizer &token, const std::string &beg, const std::string &end) {
    std::vector<JamalType*> *ast = new std::vector<JamalType*>;
    TokenTypes cur_tok=token.peek_tok();
    
#ifdef DEBUG_OUT
    std::cout <<"read_list() " <<beg <<std::endl;
#endif

    while (token.peek() !=  end) {
        // TODO David: The reference code checks for EOF
        // at this point. I should do the same.
        JamalType *jal = read_form(token);
        ast->push_back(jal);
    }
    token.next();

    return new JamalList(cur_tok, beg, end, ast);
}

JamalType *read_atom(Tokenizer &token) {
#ifdef DEBUG_OUT
    std::cout <<"read_atom() " <<token.peek() <<std::endl;
#endif
    JamalAtom *ast = new JamalAtom(token.peek_tok(), token.peek());
    token.next();

    return ast;
}

JamalType* read_form(Tokenizer &token) {
    while (token.peek_tok() == WHITESPACE) token.next();
    if (token.peek() == "(") {
        token.next();
        return read_list(token, "(", ")");
    }
    if (token.peek() == "{") {
        token.next();
        return read_list(token, "{", "}");
    }
    return read_atom(token);
}
