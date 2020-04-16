//
// Created by Wojtek on 14/04/2020.
//

#include "../../../include/Analizator/Lexer/Lexer.h"
#include "Analizator/Lexer/TerminalToken.h"
#include "../../../include/Exceptions/LengthException.h"
#include "../../../include/Analizator/Lexer/NonTerminalTokens/Str.h"
#include "../../../include/Exceptions/SecondPointException.h"
#include "../../../include/Exceptions/UnknownSignException.h"
#include "../../../include/Analizator/Lexer/NonTerminalTokens/Int.h"
#include "../../../include/Analizator/Lexer/NonTerminalTokens/Dbl.h"
#include "../../../include/Analizator/Lexer/NonTerminalTokens/LowerVar.h"
#include "../../../include/Analizator/Lexer/NonTerminalTokens/Type.h"
#include "../../../include/Analizator/Lexer/NonTerminalTokens/Constant.h"


Lexer::Lexer(Context &context_): state(S_STOP), context(context_){

}
TokenT Lexer::getNextToken(std::istream &is) {
    std::string buf;
    auto eat = [&is]() -> char {
        return is.get();
    };
    auto add = [&](char c) {
        buf += c;
        if (buf.length() > maxLength.at(state)) {
            throw LengthException(state);
        }
    };
    auto finish = [](char c) -> bool {
        if(TerminalToken::tokenSet.count(c) || isspace(c)) {
            return true;
        }
        throw UnknownSignException(c);
    };


    for (char c = is.peek(); state != S_EOF; c = is.peek()) {
        switch (state) {
            case S_STOP:
            case S_EOF:
                switch (c) {
                    case EQUAL:
                    case NEWLINE:
                    case SEMICOLON:
                    case PLUS:
                    case MINUS:
                    case MULTIPLY:
                    case DIVIDE:
                    case PERCENT:
                    case POINT:
                    case COMMA:
                    case BRACKET_SQUARE_CLOSE:
                    case BRACKET_SQUARE_OPEN:
                    case BRACKET_CIRCLE_CLOSE:
                    case BRACKET_CIRCLE_OPEN:
                    case BLOCK_CLOSE:
                    case BLOCK_OPEN:
                    case LESS:
                    case MORE:
                    case DOLLAR:
                        setState(S_STOP);
                        eat();
                        return TokenT(new TerminalToken(TerminalEnum(c)));
                    case END:
                        setState(S_EOF);
                        eat();
                        break;
                    case '0':
                        setState(S_ZERO);
                        add(c);
                        break;
                    case '"':
                        setState(S_STR_DBL_QUOTE);
                        break;
                    case '\'':
                        setState(S_STR_SGL_QUOTE);
                        break;
                    case '_':
                        setState(S_CONSTANT);
                        add(c);
                    default:
                        if (isspace(c)) {
                            break;
                        } else if (isdigit(c)) {
                            setState(S_INT);
                        } else if (isupper(c)) {
                            setState(S_TYPE);
                        } else if (islower(c)) {
                            setState(S_LOWER_VAR);
                        } else {
                            throw UnknownSignException(c);
                        }
                        add(c);
                }
                eat();
                break;
            case S_STR_DBL_QUOTE:
                switch (c) {
                    case '"':
                        eat();
                        setState(S_STOP);
                        return TokenT(new Str(buf));
                    case '\\':
                        eat();
                        c = eat();
                        add(c);
                        break;
                    default:
                        eat();
                        add(c);
                }
                break;
            case S_STR_SGL_QUOTE:
                if (c == '\'') {
                    eat();
                    setState(S_STOP);
                    return TokenT(new Str(buf));
                } else {
                    eat();
                    add(c);
                }
                break;
            case S_INT:
                if (isdigit(c)) {
                    add(c);
                    eat();
                } else if (c == '.') {
                    setState(S_DBL);
                    add(c);
                    eat();
                } else if (finish(c)) {
                    setState(S_STOP);
                    return TokenT(new Int(buf));
                }
                break;
            case S_DBL:
                if (isdigit(c)) {
                    add(c);
                    eat();
                }
                else if (c == '.') {
                    throw SecondPointException();
                }
                else if (finish(c)) {
                    setState(S_STOP);
                    return TokenT(new Dbl(buf));
                }
                break;
            case S_LOWER_VAR:
                if (islower(c)) {
                    add(c);
                    eat();
                }
                else if(isupper(c)) {
                    setState(S_VARIABLE);
                    add(c);
                    eat();
                }
                else if (finish(c)) {
                    setState(S_STOP);
                    return TokenT(new LowerVar(buf));
                }
                break;
            case S_VARIABLE:
                if (isalpha(c)) {
                    add(c);
                    eat();
                }
                else if (finish(c)) {
                    setState(S_STOP);
                    return TokenT(new Variable(buf));
                }
                break;
            case S_TYPE:
                if (isalpha(c)) {
                    add(c);
                    eat();
                }
                else if (finish(c)) {
                    setState(S_STOP);
                    return TokenT(new Type(buf));
                }
                break;
            case S_CONSTANT:
                if (isupper(c)) {
                    add(c);
                    eat();
                }
                else if (finish(c)) {
                    setState(S_STOP);
                    return TokenT(new Constant(buf));
                }
                break;
            case S_ZERO:
                if(c == '.') {
                    setState(S_DBL);
                    add(c);
                    eat();
                }
                else if(finish(c)) {
                    setState(S_STOP);
                    return TokenT(new Int(buf));
                }
                break;
        }
    }
    return TokenT(new TerminalToken(END));
}


void Lexer::setState(LexerState state) {
    this->state = state;
}

