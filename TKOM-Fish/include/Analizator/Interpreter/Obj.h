//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_OBJ_H
#define FISH_OBJ_H

#include "ObjectType.h"
#include "Env.h"

class Env;
using EnvUP = std::unique_ptr<Env>;

class Obj {
public:
    virtual ObjectType getObjectType() const = 0;
    virtual std::string getName() const;
    virtual Obj &operator[](int i);
    virtual int getInt() const;
    virtual double getDouble() const;
    virtual std::string getString() const;
    virtual bool getBool() const;
    virtual Obj &getObject();
    virtual void execute(Env &env);
};
using ObjectUP = std::unique_ptr<Obj>;

#endif //FISH_OBJ_H
