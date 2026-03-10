#include "main.h"

JamalType* read() {
    // Stand-in for "cin"
    std::string line(" (lambda (x) (+ 2.0 x)) ; Comment til end of line");
    std::cout <<std::endl <<line <<std::endl <<std::endl;

    
    std::cout <<"calling read_form()" <<std::endl;
    Tokenizer tok(line);
    std::cout <<"Peek at tok: " <<tok.peek() <<std::endl;
    JamalType *jal = read_form(tok);
    return jal;
}

JamalType* eval(JamalType* jal) {
    return jal;
}

void print(JamalType *jal) {
    std::cout <<"Done with jal" <<std::endl;
    delete jal;
}

int rep() {
    std::string ret;
    print(eval(read()));
    return 1;
}

int repl() {
    std::cout <<"input> ";
rep();
//    while (rep()) {
//        std::cout <<"input> ";
//    }

    return 0;
}

int main() {
    return repl();
}
