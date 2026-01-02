#include "main.h"

Tokenizer read() {
    std::string line(" (lambda (x) (+ 2.0 x)) ; Comment til end of line");
    //if (std::getline(std::cin, junk)) {
    return Tokenizer(line);
}

Tokenizer eval(Tokenizer thing) {
    return thing;
}

std::string print(Tokenizer thing) {
    std::cout <<"'" <<thing.peek() <<"'"<<std::endl;
    while (!thing.eof()) {
        thing.next();
        std::cout <<"'" <<thing.peek() <<"'"<<std::endl;
    }

    return std::string("(exit)");
}

int rep() {
    std::string ret;
    ret = print(eval(read()));
    if (ret == "(exit)") return 0;
    return 1;
}

int repl() {
    std::cout <<"input> ";
    while (rep()) {
        std::cout <<"input> ";
    }
    std::cout <<"broke" <<std::endl;

    return 0;
}

int main() {
    return repl();
}
