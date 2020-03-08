#ifndef functionDec_hpp
#define functionDec_hpp

class functionDec: public Expression{
public:

      functionDec(NodePtr n1): single(1) {
        branches.push_back(n1);

     }
     functionDec(NodePtr n1, ListPtr n2) : single(0) {
        branches.push_back(n1);
        branches.push_back(n2);
     }

      void print(std::ostream& dst, pycon& con, int level) const{
         //con.indent(dst);
         branches[0]->print(dst, con, level);
         dst << "(";
         if(!single){
         branches[1]->print(dst, con, level);
         }
         dst << ")";
    }
      void pythonGen(std::ostream& os) const { }
protected:
     DeclarationPtr deckedBoi;
     int argNum;
     bool single;
};

#endif