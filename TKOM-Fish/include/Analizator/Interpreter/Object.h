//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_OBJECT_H
#define FISH_OBJECT_H


#include <list>
#include <vector>
#include "ObjectType.h"
#include "Env.h"

class Object {
public:
    virtual ObjectType getObjectType() const = 0;
    virtual std::string getName() const;
    virtual Object &operator[](int i);
    virtual int getInt() const;
    virtual double getDouble() const;
    virtual std::string getString() const;
    virtual bool getBool() const;
    virtual Object &getObject();
    virtual void execute(Env &env);
};
using ObjectUP = std::unique_ptr<Object>;

#endif //FISH_OBJECT_H
