#ifndef parameter_lists_hpp
#define parameter_lists_hpp

#include <vector>


class paramList;
typedef paramList* paramListPtr;

class paramList : public List {
public:
  paramList() {}
  paramList(NodePtr b) {
    listOfExpressions.push_back(b);
  }
  
  paramList(const ListPtr& lol) {
    listOfExpressions = lol->getlistOfExpressions(); 
  }

  void print(std::ostream& dst, pycon& con, int level) const {
     for(int i=0; i<listOfExpressions.size(); i++){
      
      listOfExpressions[i]->print(dst, con, level);
      if(i!=listOfExpressions.size()-1) {
        dst << ", ";
      }
     }
  }

  void mipsGen(std::ostream& os, mipsCon& con, int dest=0) const {
    con.paramReg = 4;
    if(!con.inCall){
    con.isParam = 1;
    con.firstTime = 1;
    con.extraCheck = 1;
    for(unsigned int i=0; i<listOfExpressions.size(); i++) {
      listOfExpressions[i]->mipsGen(os, con, dest);
      con.writeToStack(2, con.varBinding().at(con.dummyDec.id).offset, os); //THIS IS ADDED IN
      con.paramReg++;
      con.extraCheck = 0;
    }
     con.isParam = 0;
    }else if(con.inCall){
        int counter = 0;
         for(unsigned int i=0; i<listOfExpressions.size(); i++) {

            con.isParam = 1;
            con.isIdentifierCall = 0;
            con.isConstantCall = 0;   //these all get activated if they are it


            listOfExpressions[i]->mipsGen(os, con, con.paramReg);
            //the following 4 lines broke recursion lmaooooo but fixed external func calls
            int offsetter = (con.paramReg - 4)*4;
            os << "addi " << con.reg(29) << ", " << con.reg(29) << ", -4" << std::endl; 
            con.stackSize += 4;
            os << "sw " << con.reg(con.paramReg) << ", 0(" << con.reg(29) << ")" << std::endl;

            con.paramReg++;   
            counter++;
         }
         con.isParam = 0;
   }
            con.isIdentifierCall = 0;
            con.isConstantCall = 0;
            con.isParam = 0;
  }
  void look(mipsCon& con) const {}

};

#endif
