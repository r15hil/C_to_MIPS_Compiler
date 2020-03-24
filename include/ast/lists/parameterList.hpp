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

  ~paramList() {
    for(int i=0; i<listOfExpressions.size(); i++) {
      delete listOfExpressions[i];
    }
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
    con.isParam = 1;
    con.firstTime = 1;
    con.extraCheck = 1;
    for(int i=0; i<listOfExpressions.size(); i++) {
      listOfExpressions[i]->mipsGen(os, con, dest);
      con.writeToStack(2, con.varBinding().at(con.dummyDec.id).offset, os); //THIS IS ADDED IN
      con.paramReg++;
      con.extraCheck = 0;
    }
     con.isParam = 0;
  }
};

#endif