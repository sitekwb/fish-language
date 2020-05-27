//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_RELATIVEEXPRESSION_H
#define FISH_RELATIVEEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class RelativeExpression : public Symbol{
        using RelativeExpressionUP = std::unique_ptr<RelativeExpression>;
        protected:

        public:
        void execute() override;
};


#endif //FISH_RELATIVEEXPRESSION_H
