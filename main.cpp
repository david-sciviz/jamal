#include "main.h"

JamalType* read() {
    std::string line(readline("jamal> "));
    std::cout <<"=Read=" <<std::endl;
    
    std::cout <<"calling read_form()" <<std::endl;
    Tokenizer tok(line);
    JamalType *jal = read_form(tok);
    return jal;
}

JamalType* read(std::string line) {
    std::cout <<"=Read (w/line)=" <<std::endl;
    
    std::cout <<"calling read_form()" <<std::endl;
    Tokenizer tok(line);
    JamalType *jal = read_form(tok);
    return jal;
}

JamalType* eval(JamalType* jal) {
    std::cout <<"=Eval=" <<std::endl;
    return jal;
}

JamalType* print(JamalType *jal) {
    std::cout <<"=Print=" <<std::endl;
    print_string(jal);
    return jal;
}

int rep() {
    JamalType* jal;
    jal = print(eval(read()));
    std::cout <<std::endl <<"=Done=" <<std::endl;
    delete jal;

    return 1;
}


int rep(std::string line) {
    JamalType* jal;
    jal = print(eval(read(line)));
    std::cout <<std::endl <<"=Done=" <<std::endl;
    delete jal;

    return 1;
}

int repl() {
    int i=0;
    std::string line(" {(lambda (x) (+ 2.0 x)) 10} ; Comment til the end of line");
    std::cout <<std::endl <<line <<std::endl <<std::endl;

    rep(line);

    while (i == 0) {
        i = rep();
    }

    return 0;
}

int main() {
    return repl();
}
