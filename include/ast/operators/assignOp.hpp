#ifndef assignOp_hpp
#define assignOp_hpp

class assignOp;
typedef const assignOp* assignOpPtr;

class assignOp: public Expression {
public:
    assignOp(NodePtr left, NodePtr right) { branches.push_back(left); branches.push_back(right); }
    void print(std::ostream& dst, pycon& con, int level) const {
        branches[0]->print(dst, con, level);
        dst << " = ";
        branches[1]->print(dst, con, level);
    }
    void pythonGen(std::ostream& os) const { }
    void mipsGen(std::ostream& os, mipsCon& con) const {
        std::cout << "STARTING THE 0TH BRANCH" << std::endl;
        branches[0]->mipsGen(os, con);
        os << std::endl;
        std::cout << "FINISHED THE 0TH BRANCH" << std::endl;
        branches[1]->mipsGen(os, con);
        std::cout << "FINISHED THE 1ST BRANCH" << std::endl;
    }

protected:
};

#endif