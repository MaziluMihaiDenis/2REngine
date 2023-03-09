#include "Object.h"
#include <typeindex>

ClassName Object::GetClassName()
{
    return typeid(this).name();
}
