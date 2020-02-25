#include "ast.hpp"

int main()
{
    const Node *ast=parseAST();
    std::cout << "parsed AST" << std::endl;
    ast->pythonGen(std::cout);
    std::cout<<std::endl;

    return 0;
}
