#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_expression.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_functions.hpp"
#include "ast/identifier.hpp"
#include "ast/lists/list.hpp"
#include "ast/type/type.hpp"
#include "ast/type/PrimitiveType.hpp"


extern const Node *parseAST();

#endif
