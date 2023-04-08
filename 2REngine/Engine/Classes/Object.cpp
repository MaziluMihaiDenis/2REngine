#include "Object.h"
#include <typeindex>
#include <string>
extern "C"
{
#include <Basic/core.h>
}

void Object::Start() {}
void Object::Loop(float deltaTime) {}
void Object::Destroy(float time) 
{
    if (time == 0.f)
        delete this;
}