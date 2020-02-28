#ifndef declaration_hpp
#define declaration_hpp

#include "expression.hpp"

class Declaration;

class Declaration : public Expression {
public:
    ~Declaration(){}
    Declaration(Node* type){
      branches.push_back(type);
      branches.push_back(0);
    }
    Declaration(NodePtr type, NodePtr name){
      branches.push_back(type);
      branches.push_back(name);
    }
    virtual void print(std::ostream &dst) const{
      branches[0]->print(dst);
      branches[1]->print(dst);
    }
    virtual void pythonGen(std::ostream& os) const { }
private:

};



#endif
