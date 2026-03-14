#ifndef __JAMAL_TYPES_H
#define __JAMAL_TYPES_H

#include <string>
#include <vector>
#include <iostream>

enum TokenTypes { NA, WHITESPACE, OPEN_PAREN, CLOSE_PAREN,
                  COMMENT, QUOTE, BOOLEAN, IDENTIFIER, NUMBER, JUNK};

class JamalType {
    public:
        JamalType() { }
        JamalType(TokenTypes token, std::string str) :
            m_token(token),
            m_string(str)
           { }
        virtual ~JamalType() { }

	void print() { this->print_indent(0); }
	virtual void print_indent(int ind) { std::cout <<m_string <<' ';}

        std::string get_string() { return m_string; }
    protected:
        TokenTypes m_token;
        std::string m_string;
};

class JamalList : public JamalType {
    public:
        JamalList(TokenTypes token, std::string str, std::string end, std::vector<JamalType*> *ast) :
        m_end(end), m_value(ast)
        { m_token=token; m_string=str; }

        ~JamalList() { for (auto i : *m_value) delete i; delete m_value; }

	void print_indent(int ind) { //std::cout <<std::endl;
		                     for (auto i=0; i<ind; i++) std::cout <<' ';
                                     std::cout <<m_string;
		                     for (auto i : *m_value) i->print_indent(ind+4);
                                     std::cout <<m_end <<std::endl;
		                     for (auto i=0; i<(ind - 4) ; i++) std::cout <<' ';
}
 
    private:
        std::vector<JamalType*> *m_value;
        std::string m_end;
};

class JamalAtom : public JamalType {
    public:
        JamalAtom() { }
        JamalAtom(TokenTypes token, std::string str) { m_value = new JamalType(token, str); }
        ~JamalAtom() { delete m_value; }

	void print_indent(int ind) { m_value->print_indent(ind); }
    public:
        JamalType *m_value;
};

#endif
