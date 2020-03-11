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
    void mipsGen(std::ostream& os) const { }
protected:
};

#endif