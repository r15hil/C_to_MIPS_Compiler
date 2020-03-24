#ifndef andOp_hpp
#define andOp_hpp

class andOp;
typedef const andOp* andOpPtr;

class andOp: public Expression{
public:
    andOp(NodePtr left, NodePtr right) { branches.push_back(left); branches.push_back(right); }
    void print(std::ostream& dst, pycon& con, int level) const { }
    void pythonGen(std::ostream& os) const { }


    void mipsGen(std::ostream& os, mipsCon& con, int dest=0) const { 
        
        int addrDest1 = con.registerSet.freeRegister();
        int addrDest2 = con.registerSet.freeRegister();

        con.flushReg({addrDest1, addrDest2}, os);

        branches[0]->mipsGen(os, con, addrDest1);
        branches[1]->mipsGen(os, con, addrDest2);

        os << std::endl;
        os << "and " << con.reg(dest) << ", " << con.reg(addrDest1) << ", " << con.reg(addrDest2);
        os << std::endl;

        con.recoverReg({addrDest2, addrDest1}, os);
    }
protected:
};

#endif