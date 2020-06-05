//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/ConditionalExpression.h>

using namespace std;

ConditionalExpression::ConditionalExpression(std::list<AndExpressionUP> &&andExpressionList)
    : andExpressionList(move(andExpressionList)){

}
