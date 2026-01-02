#include "reader.h"


Tokenizer::Tokenizer(std::string &str)
    //input_string(str), cur_pos(str.begin()), end_pos(str.end())
{
    token_string = "";
    token_type   = NA;
    input_string = str;
    cur_pos = input_string.begin();
    end_pos = input_string.end();
}



bool Tokenizer::match_next() {
    if (cur_pos == end_pos) {
        token_type = NA;
        return false;
    }

    // Iterate through list of token regexs
    for (auto i : regs) {
        auto flags = std::regex_constants::match_continuous;
        std::smatch match;
        std::regex_search(cur_pos, end_pos, match, i.reg, flags);
        if (match.length(0) != 0) {
            token_string = match[0];
            token_type   = i.typ;
            cur_pos +=   match.length(0);

            std::cout <<"{" << i.typ <<"  " <<match.length(0);
            std::cout <<" ," <<token_string <<"}  " ; //<<std::endl;

            return true;
        }
    }
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
