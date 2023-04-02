#include "Object.h"
#include <typeindex>
#include <string>

void Object::Start() {}
void Object::Loop(float deltaTime) {}
void Object::Destroy(float time) 
{
    if (time == 0.f)
        free(this);
}