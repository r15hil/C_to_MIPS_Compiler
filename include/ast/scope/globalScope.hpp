#ifndef globalScope_hpp
#define globalScope_hpp

class globalScope;
typedef const globalScope* globalScopePtr;

class globalScope: public Scope{
public:
    globalScope() { }

    globalScope(NodePtr inNode) {
        sequence.push_back(inNode);
    }

    globalScope(ListPtr inList) {
        sequence=inList->getlistOfExpressions();
    }

    void print(std::ostream& dst, pycon& con, int level) const {
        for(unsigned int i=0; i<sequence.size(); i++) {
            dst << std::endl;
            sequence[i]->print(dst, con, level);
            con.zeroTab();
            con.indent(dst);
        }
    }
    void genPython(std::ostream& os) const { }

    void mipsGen(std::ostream& os, mipsCon& con, int dest=0) const {
        con.stack.push_back({});
        for(unsigned int i=0; i<sequence.size(); i++) {
            sequence[i]->mipsGen(os, con, dest);
            con.exitScope(os);
        }
    }
    void look(mipsCon& con) const {}
};

#endif