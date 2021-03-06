#ifndef while_hpp
#define while_hpp

#include "../node.hpp"

class whileLoop;
typedef const whileLoop* whileLoopPtr;

class whileLoop : public Node {
public:
    whileLoop(NodePtr cond, NodePtr block): condition(cond), loopBlock(block) { };
    void print(std::ostream& dst, pycon& con, int level) const {
        dst << std::endl;
        con.indent(dst);
        dst << "while (";
        con.subTab();
        condition->print(dst, con, level);
        con.addTab();
        dst<< "):";
        con.addTab();
        std::cout << std::endl;
        con.indent(dst);
        loopBlock->print(dst, con, level);
        dst << std::endl;
        con.indent(dst);
        dst << "pass" << std::endl;
        con.subTab();
    }
    void pythonGen(std::ostream& os) const { }
    void mipsGen(std::ostream& os, mipsCon& con, int dest=0) const {
    //don't know how to scope this properly
        con.enterScope();
        //std::cout << "entered scope" << std::endl;
        con.statement().offset=con.stack.back().spOffset;
        con.statement().continueFlag=con.makeALabel("continue");
        con.statement().breakFlag=con.makeALabel("break");
        os << con.statement().continueFlag << ": ";
        os << std::endl;
        condition->mipsGen(os, con, 2);
        os << "beq " << con.reg(2) << ", " << con.reg(0) << ", " << con.statement().breakFlag;
        os << std::endl;
        os << "nop";
        os << std::endl;
        con.conditional().conditionalPatty=true;
        loopBlock->mipsGen(os, con);
        os << "j " << con.statement().continueFlag;
        os << std::endl;
        os << "nop";
        os << std::endl;
        os << con.statement().breakFlag << ":";
        os << std::endl;
        con.exitScope(os);
    }

    void look(mipsCon& con) const {}

protected:
    NodePtr condition;
    NodePtr loopBlock;
};

#endif

