//
// Created by Wojtek on 16/04/2020.
//

#include "Analizator/Parser/Parser.h"

using namespace std;


void Parser::parse(Token &token) {
    while (!symbol->checkToken(token)) {
        ++(*symbol);
    }
}

Parser::Parser() : symbol(make_unique<Symbol>(File)) {
    auto &rules = Symbol::getRules();
    rules[Bool] = R(Or, {
            Symbol("true"),
            Symbol("false")
    });
    rules[Type] = R(IDENTIFIER);
    rules[Library] = R(IDENTIFIER);
    rules[File] = R(Or, {
            R(Statement),
            R(FunctionDefinition),
            R(ClassDefinition)
    });
    rules[Statement] = R(Or, {
            R(CompoundStatement),
            R(SimpleStatement)
    });
    rules[SimpleStatement] = R(Or, {
            R(ExpressionStatement),
            R(DeleteStatement),
            R(ImportStatement),
            R(NewStatement),
            R(AssignStatement),
            R(ControlStatement)
    });
    rules[ExpressionStatement] = R(Expression);
    rules[DeleteStatement] = R({
                                       R("delete"),
                                       R(IDENTIFIER)
                               });
    rules[ImportStatement] = R({
                                       R("import"),
                                       R(Symbol(Library)),
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
                                          R(Or, {R(ArithmeticExpression), R(NewExpression)}),
                                          R(Repeat, {
                                                  R(','),
                                                  R(Or, {R(ArithmeticExpression),
                                                         R(NewExpression)}),
                                          })
                                  })
                          });
    rules[NewExpression] = R({
                                     R("new"),
                                     R(Optional, {R("mut")}),
                                     R(Optional, {R("static")}),
                                     R(Optional, {R(Type)}),
                                     R(Or, {R(IDENTIFIER), R(CONSTANT)}),
                                     R(Optional, {
                                             R('('),
                                             R(ArgumentList),
                                             R(')'),
                                     }),
                                     R(Optional, {
                                             R(AssignOperator),
                                             R(ConditionalExpression)
                                     })
                             });
    rules[AssignExpression] = R({
                                        R(IDENTIFIER),
                                        R(AssignOperator),
                                        R(Term)
                                });
    rules[ConditionalExpression] = R({
                                             R(AndExpression),
                                             R(Repeat, {
                                                     R("or"),
                                                     R(AndExpression)
                                             })
                                     });
    rules[AndExpression] = R({
                                     R(OrExpression),
                                     R(Repeat, {
                                             R("and"),
                                             R(OrExpression)
                                     })
                             });
    rules[OrExpression] = R({
                                    R(Optional, {R(UnaryNot)}),
                                    R(RelativeExpression),
                                    R(Repeat, {
                                            R(RelativeOperator),
                                            R(Optional, {R(UnaryNot)}),
                                            R(RelativeExpression)
                                    })
                            });
    rules[RelativeExpression] = R(Or, {
            R({
                      R('('),
                      R(ConditionalExpression),
                      R(')'),
              }),
            R(ArithmeticExpression)
    });
    rules[ArithmeticExpression] = R({
                                            R(AddExpression),
                                            R(Repeat, {
                                                    R(AddOperator),
                                                    R(AddExpression)
                                            })
                                    });
    rules[AddExpression] = R({
                                     R(MultiplyExpression),
                                     R(Repeat, {
                                             R(MultiplyOperator),
                                             R(MultiplyExpression)
                                     })
                             });
    rules[MultiplyExpression] = R({
                                          R(Optional, {R(UnarySign)}),
                                          R(Term)
                                  });

    rules[Term] = R(Or, {
            R(INT),
            R(DBL),
            R(STR),
            R(Bool),
            R({
                      R('('),
                      R(ArithmeticExpression),
                      R(')'),
              }),
            R({
                      R(Or, {
                              R(IDENTIFIER),
                              R(CONSTANT),
                              R(FunctionCall)
                      }),
                      R(Repeat, {R(ArraySubscript)}),
                      R(Repeat, {
                              R('.'),
                              R(Or, {
                                      R(IDENTIFIER),
                                      R(CONSTANT),
                                      R(FunctionCall)
                              }),
                              R(Repeat, {R(ArraySubscript)})
                      })
              })
    });
    rules[FunctionCall] = R({
                                    R(IDENTIFIER),
                                    R('('),
                                    R(ArgumentList),
                                    R(')')
                            });
    rules[ArgumentList] = R(Optional, {
            R(Argument),
            R(Repeat, {
                    R(','),
                    R(Argument)
            })
    });
    rules[Argument] = R(ConditionalExpression);
    rules[AssignOperator] = R(Or, {
            R('='),
            R("+="),
            R("-="),
            R("*="),
            R("/="),
            R("%="),
    });
    rules[RelativeOperator] = R(Or, {
            R("=="),
            R("!="),
            R('<'),
            R('>'),
            R("<="),
            R(">="),
    });
    rules[AddOperator] = R(Or, {
            R('+'),
            R('-')
    });
    rules[MultiplyOperator] = R(Or, {
            R('*'),
            R('/'),
            R('%')
    });
    rules[UnarySign] = R(Or, {
            R("not"),
            R('!')
    });
    rules[ArraySubscript] = R({
                                      R('['),
                                      R(Or, {
                                              R(UnsignedIntTerm),
                                              R({
                                                        R(Optional, {R(UnsignedIntTerm)}),
                                                        R(':'),
                                                        R(Optional, {R(UnsignedIntTerm)}),
                                                })
                                      }),
                                      R(']')
                              });
    rules[UnsignedIntTerm] = R(Term);
    rules[CompoundStatement] = R(Or, {
            R(IfStatement),
            R(WhileStatement),
            R(ForStatement),
            R(ForiStatement),
            R(ForeachStatement)
    });
    rules[BlockInstruction] = R(Or, {
            R(Statement),
            R({
                      R('{'),
                      R(Repeat, {R(Statement)}),
                      R('}')
              })
    });
    rules[IfStatement] = R({
                                   R("if"),
                                   R('('),
                                   R(ConditionalExpression),
                                   R(')'),
                                   R(BlockInstruction),
                                   R(Optional, {
                                           R("else"),
                                           R(BlockInstruction)
                                   })
                           });
    rules[WhileStatement] = R(Normal, {
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
                                          R(Optional, {R(Type)}),
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
    rules[ParameterList] = R(Optional, {
            R(Parameter),
            R(Repeat, {
                    R(','),
                    R(Parameter)
            })
    });
    rules[Parameter] = R({
                                 R(Optional, {R(Type)}),
                                 R(IDENTIFIER),
                                 R(Optional, {R({
                                                       R('='),
                                                       R(Default)
                                               })})
                         });
    rules[Default] = R(Term);
    rules[ListIdentifier] = R({
                                      R(IDENTIFIER),
                                      R(Optional, {R(ArraySubscript)})
                              });
    rules[ClassBody] = R(Repeat, {R(ClassBodyStatement)});
    rules[ClassBodyStatement] = R(Or, {
            R(MemberDefinition),
            R(FunctionDefinition)
    });
    rules[MemberDefinition] = R({
                                        R(Optional, {R(Or, {
                                                R("public"),
                                                R("private"),
                                                R("secret")
                                        })}),
                                        R(Optional, {R("mut")}),
                                        R(Optional, {R("static")}),
                                        R(Optional, {R(Type)}),
                                        R(IDENTIFIER),
                                        R(Optional, {
                                                R('('),
                                                R(ArgumentList),
                                                R(')')
                                        })
                                });
}


