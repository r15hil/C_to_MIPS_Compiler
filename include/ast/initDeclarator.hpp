#ifndef init_declarator_hpp
#define init_declarator_hpp

#include "expression.hpp"

class initDeclarator;

class initDeclarator : public Expression {
public:
    ~initDeclarator(){}
    
    initDeclarator(Node* type): isAssign(0){
      branches.push_back(type);
      branches.push_back(0);
    }

    initDeclarator(NodePtr type, NodePtr name): isAssign(1){
      branches.push_back(type);
      branches.push_back(name);
    }

    void print(std::ostream& dst, pycon& con, int level) const{
      branches[0]->print(dst, con, level);
      dst << " = ";
      if(isAssign){
        con.setAssign();
        branches[1]->print(dst, con, level);
      }
      else{
        dst << "0";
      }
      con.clearAssign();
      dst << std::endl;
    }

    void pythonGen(std::ostream& os) const { }


    void mipsGen(std::ostream& os, mipsCon& con) const { 
      branches[0]->mipsGen(os, con);
      os << " = ";
      if(isAssign){
        con.setAssign();
        branches[1]->mipsGen(os, con);
      }
      else{
        os << "0";
      }
      con.clearAssign();
      os << std::endl;
    }

private:
 bool isAssign;
};



#endif
