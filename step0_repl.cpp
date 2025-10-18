#include <iostream>
#include <string>

std::string read() {
    std::string line;
    if (std::getline(std::cin, line)) return line;
    else return "(exit)";
}

std::string eval(std::string line) {
    return line;
}

std::string print(std::string line) {
    std::cout <<line <<std::endl;
    return line;
}

int rep() {
    std::string ret;
    ret = print(eval(read()));
    if (ret == "(exit)") return 0;
    return 1;
}

void repl() {
    std::cout <<"input> ";
    while (rep()) {
        std::cout <<"input> ";
    }
    std::cout <<"broke" <<std::endl;

}

int main() {
    repl();
}
