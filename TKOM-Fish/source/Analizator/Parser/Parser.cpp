//
// Created by Wojtek on 16/04/2020.
//

#include "Analizator/Parser/Parser.h"
#include <iostream>

using namespace std;


bool Parser::parse(Token &token_) {
    tokenList->push_back(token_);
    expandTreeUntilFoundToken();
    while (!tokenList->empty()) {
        parseToken();
    }
    // if symbol type is FileRepeat, then we can interprete some values.
    return symbol->getSymbolType() == FileRepeat;
}


void Parser::serveSuccess() {


    while (symbol->nextRuleAfterSuccess()) {
        goUp();
    }
}

bool Parser::serveFailure() {
    const bool CONTINUE_SERVING = true, FINISH_SERVING = false;
    auto childMode = symbol->getChildMode();
    if (childMode == Optional || childMode == Repeat) {
        cleanChild();
        if (!symbol->hasChildren()) {
            goUp();
            return CONTINUE_SERVING;
        }
        // if has children and was completed - optional value was last
        if (symbol->isCompleted()) {
            goUp();
            serveSuccess();
        }
        return FINISH_SERVING;
    }
    if (!symbol->hasChildren() && !symbol->isTerminal()) {
        goUp();
        return CONTINUE_SERVING;
    }
    if (*symbol == Normal || *symbol == Optional || *symbol == Repeat) {
        goUp();
        return CONTINUE_SERVING;
    }
    if (*symbol == Or) {
        cleanChild();
        if (!symbol->hasChildren()) {
            goUp();
            return CONTINUE_SERVING;
        }
        // if has children and was completed - optional value was last
        if (symbol->isCompleted()) {
            goUp();
            serveSuccess();
        }
        return FINISH_SERVING;
    }
    return FINISH_SERVING;
}

void Parser::expandTreeUntilFoundToken() {
    while (!symbol->isTerminal()) {
        symbol->buildChildren();
        if (!symbol->isTerminal()) {
            goDown();
        }
    }
}

void Parser::goDown() {
    if (symbol->hasChildren()) {
        auto child = move(symbol->getCurrentChild());
        child->setParent(move(symbol));
        symbol = move(child);
    }
}

void Parser::goUp() {
    auto child = move(symbol);
    symbol = move(child->getParent());
    if (symbol) {
        symbol->setCurrentChild(move(child));
    }
    if (!symbol) {
        throw tokenList->back();
    }
}

Parser::Parser() : symbol(make_unique<Symbol>(File)), tokenList(make_unique<list<Token>>()) {
    auto &rules = Symbol::getRules();
    rules[Bool] = R(Or, {
            Symbol("true"),
            Symbol("false")
    });
    rules[Type] = R(IDENTIFIER);
    rules[Library] = R(IDENTIFIER);
    rules[File] = R(FileRepeat);
    rules[FileRepeat] = R(Repeat, {R(FilePart)});
    rules[FilePart] = R({
                                R(Or, {
                                        R(Statement),
                                        R(FunctionDefinition),
                                        R(ClassDefinition)
                                }),
                                R(Optional, {R(SEMICOLON)})
                        });
    rules[Statement] = R(Or, {
            R(CompoundStatement),
            R(SimpleStatement)
    });
    rules[SimpleStatement] = R(Or, {
            R(DeleteStatement),
            R(ImportStatement),
            R(NewStatement),
            R(AssignStatement),
            R(ControlStatement),
            R(ExpressionStatement)
    });
    rules[ExpressionStatement] = R(Expression);
    rules[DeleteStatement] = R({
                                       R("delete"),
                                       R(IDENTIFIER)
                               });
    rules[ImportStatement] = R({
                                       R("import"),
                                       R(Library),
                                       R(Optional, {
                                               R("as"),
                                               R(Library)
                                       })
                               });
    rules[NewStatement] = R(NewExpression);
    rules[AssignStatement] = R(AssignExpression);
    rules[ControlStatement] = R(Or, {
            R("break"),
            R("continue")
    });
    rules[AliasStatement] = R({
                                      R("alias"),
                                      R(Type),
                                      R(Type),
                              });
    rules[Expression] = R({
                                  R(Optional, {
                                          R(Or, {
                                                  R(AssignExpression),
                                                  R(ArithmeticExpression),
                                                  R(NewExpression)
                                          })
                                  })});
    rules[NewExpression] = R({
                                     R("new"),
                                     R(Optional, {R("mut")}),
                                     R(Optional, {R("static")}),
                                     R(Optional, {R(Type)}),
                                     R(Or,
                                       {
                                               R(IDENTIFIER), R(CONSTANT)
                                       }),
                                     R(Optional,
                                       {
                                               R({
                                                         R('('),
                                                         R(ArgumentList),
                                                         R(')'),
                                                 })}),
                                     R(Optional,
                                       {
                                               R({
                                                         R(AssignOperator),
                                                         R(ConditionalExpression)
                                                 })})
                             });
    rules[AssignExpression] = R({
                                        R(IDENTIFIER),
                                        R(AssignOperator),
                                        R(Term)
                                });
    rules[ConditionalExpression] = R({
                                             R(AndExpression),
                                             R(Repeat, {R(ConditionalExpressionRepeat)})
                                     });
    rules[ConditionalExpressionRepeat] = R({
                                                   R("or"),
                                                   R(AndExpression)
                                           });
    rules[AndExpression] = R({
                                     R(OrExpression),
                                     R(Repeat, {R(AndExpressionRepeat)})});
    rules[AndExpressionRepeat] = R({
                                           R("and"),
                                           R(OrExpression)
                                   });
    rules[OrExpression] = R({
                                    R(Optional,
                                      {
                                              R(UnaryNot)
                                      }),
                                    R(RelativeExpression),
                                    R(Repeat, {R(OrExpressionRepeat)})
                            });
    rules[OrExpressionRepeat] = R({
                                          R(RelativeOperator),
                                          R(Optional, {R(UnaryNot)}),
                                          R(RelativeExpression)
                                  });
    rules[RelativeExpression] =
            R(Or,
              {
                      R({
                                R('('),
                                R(ConditionalExpression),
                                R(')'),
                        }),
                      R(ArithmeticExpression)
              });
    rules[ArithmeticExpression] = R({
                                            R(AddExpression),
                                            R(Repeat, {R(ArithmeticExpressionRepeat)})
                                    });
    rules[ArithmeticExpressionRepeat] = R({
                                                  R(AddOperator),
                                                  R(AddExpression)
                                          });
    rules[AddExpression] = R({
                                     R(MultiplyExpression),
                                     R(Repeat, {R(AddExpressionRepeat)})
                             });
    rules[AddExpressionRepeat] = R({
                                           R(MultiplyOperator),
                                           R(MultiplyExpression)
                                   });
    rules[MultiplyExpression] = R({
                                          R(Optional,
                                            {
                                                    R(UnarySign)
                                            }),
                                          R(Term)
                                  });

    rules[Term] =
            R(Or,
              {
                      R(INT),
                      R(DBL),
                      R(STR),
                      R(Bool),
                      R({
                                R('('),
                                R(ArithmeticExpression),
                                R(')'),
                        }),
                      R(TermAddition)
              });
    rules[TermAddition] = R({
                                    R(Or, {
                                            R(FunctionCall),
                                            R(IDENTIFIER),
                                            R(CONSTANT)
                                    }),
                                    R(Repeat, {R(ArraySubscript)}),
                                    R(Repeat, {R(TermRepeat)})
                            });
    rules[TermRepeat] = R({
                                  R('.'),
                                  R(Or, {
                                          R(FunctionCall),
                                          R(IDENTIFIER),
                                          R(CONSTANT)
                                  }),
                                  R(Repeat, {R(ArraySubscript)})
                          });
    rules[FunctionCall] = R({
                                    R(IDENTIFIER),
                                    R('('),
                                    R(ArgumentList),
                                    R(')')
                            });
    rules[ArgumentList] =
            R(Optional,
              {
                      R({
                                R(Argument),
                                R(Repeat, {R(ArgumentListRepeat)})
                        })});
    rules[ArgumentListRepeat] = R({
                                          R(','),
                                          R(Argument)
                                  });
    rules[Argument] =
            R(ConditionalExpression);
    rules[AssignOperator] =
            R(Or,
              {
                      R('='),
                      R("+="),
                      R("-="),
                      R("*="),
                      R("/="),
                      R("%="),
              });
    rules[RelativeOperator] =
            R(Or,
              {
                      R("=="),
                      R("!="),
                      R('<'),
                      R('>'),
                      R("<="),
                      R(">="),
              });
    rules[AddOperator] =
            R(Or,
              {
                      R('+'),
                      R('-')
              });
    rules[MultiplyOperator] =
            R(Or,
              {
                      R('*'),
                      R('/'),
                      R('%')
              });
    rules[UnarySign] =
            R(Or,
              {
                      R('+'),
                      R('-')
              });
    rules[UnaryNot] =
            R(Or,
              {
                      R("not"),
                      R('!')
              });
    rules[ArraySubscript] = R({
                                      R('['),
                                      R(Or,
                                        {
                                                R(UnsignedIntTerm),
                                                R({
                                                          R(Optional, {R(UnsignedIntTerm)}),
                                                          R(':'),
                                                          R(Optional, {R(UnsignedIntTerm)}),
                                                  })
                                        }),
                                      R(']')
                              });
    rules[UnsignedIntTerm] =
            R(Term);
    rules[CompoundStatement] =
            R(Or,
              {
                      R(IfStatement),
                      R(WhileStatement),
                      R(ForStatement),
                      R(ForiStatement),
                      R(ForeachStatement)
              });
    rules[BlockInstruction] =
            R(Or, {
                    R({
                              R('{'),
                              R(Repeat, {R(Statement)}),
                              R('}')
                      }),
                    R(Statement)
            });
    rules[IfStatement] = R({
                                   R("if"),
                                   R('('),
                                   R(ConditionalExpression),
                                   R(')'),
                                   R(BlockInstruction),
                                   R(Optional, {R({
                                                          R("else"),
                                                          R(BlockInstruction)
                                                  })})
                           });
    rules[WhileStatement] =
            R(Normal,
              {
                      R("while"),
                      R('('),
                      R(ConditionalExpression),
                      R(')'),
                      R(BlockInstruction)
              });
    rules[ForStatement] = R({
                                    R("for"),
                                    R('('),
                                    R(Expression),
                                    R(';'),
                                    R(ConditionalExpression),
                                    R(';'),
                                    R(Expression),
                                    R(')'),
                                    R(BlockInstruction)
                            });
    rules[ForiStatement] = R({
                                     R("fori"),
                                     R('('),
                                     R(UnsignedIntTerm),
                                     R(')'),
                                     R(BlockInstruction)
                             });
    rules[ForeachStatement] = R({
                                        R("foreach"),
                                        R('('),
                                        R(IDENTIFIER),
                                        R("in"),
                                        R(ListIdentifier),
                                        R(')'),
                                        R(BlockInstruction)
                                });
    rules[FunctionDefinition] = R({
                                          R("def"),
                                          R(Optional,
                                            {
                                                    R(Type)
                                            }),
                                          R(IDENTIFIER),
                                          R('('),
                                          R(ParameterList),
                                          R(')'),
                                          R(BlockInstruction)
                                  });
    rules[ClassDefinition] = R({
                                       R("class"),
                                       R(Type),
                                       R('{'),
                                       R(ClassBody),
                                       R('}')
                               });
    rules[ParameterList] =
            R(Optional,
              {
                      R({
                                R(Parameter),
                                R(Repeat, {R(ParameterListRepeat)})
                        })});
    rules[ParameterListRepeat] = R({
                                           R(','),
                                           R(Parameter)
                                   });
    rules[Parameter] = R({
                                 R(Optional,
                                   {
                                           R(Type)
                                   }),
                                 R(IDENTIFIER),
                                 R(Optional, {R({
                                                        R('='),
                                                        R(Default)
                                                })})
                         });
    rules[Default] =
            R(Term);
    rules[ListIdentifier] = R({
                                      R(IDENTIFIER),
                                      R(Optional, {R(ArraySubscript)})
                              });
    rules[ClassBody] =
            R(Repeat, {R(ClassBodyStatement)});
    rules[ClassBodyStatement] =
            R(Or,
              {
                      R(MemberDefinition),
                      R(FunctionDefinition)
              });
    rules[MemberDefinition] = R({
                                        R(Optional,
                                          {
                                                  R(Or,
                                                    {
                                                            R("public"),
                                                            R("private"),
                                                            R("secret")
                                                    })}),
                                        R(Optional,
                                          {
                                                  R("mut")}),
                                        R(Optional,
                                          {
                                                  R("static")}),
                                        R(Optional,
                                          {
                                                  R(Type)
                                          }),
                                        R(IDENTIFIER),
                                        R(Optional, {R({
                                                               R('('),
                                                               R(ArgumentList),
                                                               R(')')
                                                       })})
                                });
}

void Parser::parseToken() {

    while (!symbol->parseToken(tokenList->front())) {
        while (serveFailure());
        expandTreeUntilFoundToken();
    }
    serveSuccess();
    tokenList->pop_front();
}

void Parser::cleanChild() {
    auto b = symbol->cleanChild();
    tokenList->insert(tokenList->begin(), b->begin(), b->end());
}

void Parser::cleanTree() {
    if (symbol->getSymbolType() != FileRepeat) {
        throw runtime_error("Cleaning non file repeat");
    }
    goUp();
    symbol->previousChild();
    for (auto &child: symbol->getChildren()) {
        child->cleanSymbol();
    }
}

Symbol &Parser::getTree() {
    return *symbol;
}

