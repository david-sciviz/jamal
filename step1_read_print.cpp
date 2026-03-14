#include "main.h"

/*
 ((lambda
      (x)
      (+ 2.0 x)
   ) x
 )

  ((lambda
    (x)
    (+
       (* 2 3)
       3)
*/
JamalType* read() {
    // Stand-in for "cin"
    std::string line(" {(lambda (x) (+ 2.0 x)) 10} ; Comment til the end of line");
    std::cout <<std::endl <<line <<std::endl <<std::endl;

    
    std::cout <<"calling read_form()" <<std::endl;
    Tokenizer tok(line);
    std::cout <<"Peek at tok: " <<tok.peek() <<std::endl;
    JamalType *jal = read_form(tok);
    return jal;
}

JamalType* eval(JamalType* jal) {
    std::cout <<"Eval" <<std::endl;
    return jal;
}

JamalType* print(JamalType *jal) {
    std::cout <<"Printing: " <<std::endl;
    print_string(jal);
    return jal;
}

int rep() {
    JamalType* jal;
    jal = print(eval(read()));
    std::cout <<std::endl <<"Done with Jal" <<std::endl;
    delete jal;

    return 1;
}

int repl() {
//    std::cout <<"input> ";
    rep();
//    while (rep()) {
//        std::cout <<"input> ";
//    }

    return 0;
}

int main() {
    return repl();
}
