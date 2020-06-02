//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_OBJ_H
#define FISH_OBJ_H

#include "ObjectType.h"
#include "Env.h"
#include <list>

class Env;
using EnvUP = std::unique_ptr<Env>;

class Obj;
using ObjectRef = std::reference_wrapper<Obj>;
using ObjectList = std::list<ObjectRef>;

class Obj {
protected:
    ObjectList objectList;
public:
    virtual ObjectType getObjectType() const = 0;
    //virtual std::string getName() const;
    virtual int getInt() const;
    virtual double getDouble() const;
    virtual std::string getString() const;
    virtual bool getBool() const;
    virtual bool isFinal() const;
    virtual Obj &operator[](int i);
    Obj &evaluateObject();
    ObjectList &evaluateList();
    Obj &getObject();
};
using ObjectUP = std::unique_ptr<Obj>;

#endif //FISH_OBJ_H
