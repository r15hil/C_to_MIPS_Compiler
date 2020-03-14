#ifndef subOp_hpp
#define subOp_hpp

class subOp;
typedef const subOp* subOpPtr;

class subOp: public Expression {
public:
    subOp(NodePtr left, NodePtr right) { branches.push_back(left); branches.push_back(right); }
    void print(std::ostream& dst, pycon& con, int level) const {
        branches[0]->print(dst, con, level);
        dst << " - ";
        branches[1]->print(dst, con, level);
    }
    void pythonGen(std::ostream& os) const { }
    void mipsGen(std::ostream& os, mipsCon& con) const {
        std::string tempName;
        if(con.newIsInt){
            con.newIsInt = 0;
            tempName = con.justForInt;
        }else tempName = con.storeTo;

        branches[0]->mipsGen(os, con);
        branches[1]->mipsGen(os, con);
        os << std::endl;
        os << "nop";
        os << std::endl;
        os << "sub $2, $2, $3";
        os << std::endl;
        int offset = con.findOffset(tempName);
        os << "sw $2, " << offset << "($fp)";
        con.untickReg(2);
        con.untickReg(3);
    }
protected:
};

#endif