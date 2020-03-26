#ifndef ast_hpp
#define ast_hpp

#include "ast/pYtHoNcOnTeXt.hpp"
#include "ast/registers.hpp"
#include "ast/mipsCon.hpp"
#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/expression.hpp"
#include "ast/lists/list.hpp"
#include "ast/lists/declaratorList.hpp"
#include "ast/lists/parameterList.hpp"
#include "ast/type/PrimitiveType.hpp"
#include "ast/declaration.hpp"
#include "ast/arrayDeclarator.hpp"
#include "ast/arrayIndex.hpp"
#include "ast/constant.hpp"
#include "ast/initDeclarator.hpp"
#include "ast/scope/scope.hpp"
#include "ast/scope/globalScope.hpp"
#include "ast/scope/localScope.hpp"
#include "ast/conditionals/ifStatement.hpp"
#include "ast/conditionals/ifElseStatement.hpp"
#include "ast/functions/functionDef.hpp"
#include "ast/functions/functionDec.hpp"
#include "ast/functions/functionCall.hpp"
#include "ast/operators/addOp.hpp"
#include "ast/operators/subOp.hpp"
#include "ast/operators/mulOp.hpp"
#include "ast/operators/divOp.hpp"
#include "ast/operators/modOp.hpp"
#include "ast/operators/rightShiftOp.hpp"
#include "ast/operators/leftShiftOp.hpp"
#include "ast/operators/logAndOp.hpp"
#include "ast/operators/logOrOp.hpp"
#include "ast/operators/orOp.hpp"
#include "ast/operators/incdinc.hpp"
#include "ast/operators/xorOp.hpp"
#include "ast/operators/lessThan.hpp"
#include "ast/operators/greaterThan.hpp"
#include "ast/operators/lessThanEqual.hpp"
#include "ast/operators/greaterThanEqual.hpp"
#include "ast/operators/equalTo.hpp"
#include "ast/operators/notEqualTo.hpp"
#include "ast/operators/assignOp.hpp"
#include "ast/operators/andOp.hpp"
#include "ast/loop/while.hpp"
#include "ast/loop/forLoop.hpp"
#include "ast/return.hpp"

extern const Node *parseAST();

#endif
