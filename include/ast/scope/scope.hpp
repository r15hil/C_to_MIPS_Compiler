#ifndef scope_hpp
#define scope_hpp

class Scope;
typedef const Scope* ScopePtr;

class Scope: public Node {
public:
    ~Scope() {
        for(int i=0; i<sequence.size(); i++) {
            delete sequence[i];
        }
    }
    Scope() { std::cout << "Scope made!" << std::endl; }
    Scope(NodePtr inNode) {
        sequence.push_back(inNode);
    }
    Scope(ListPtr inList) {
        sequence=inList->getlistOfExpressions();
    }
    std::vector<NodePtr> getSequence() {
        return sequence;
    }
    virtual void print(std::ostream& dst) const=0;
    virtual void pythonGen(std::ostream& os) const { } 

protected:
    std::vector<NodePtr> sequence;
};

#endif