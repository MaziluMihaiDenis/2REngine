#include <stdio.h>
#include "Core/DataTypes/dstring.h"
#include "Core/DataTypes/dvector2D.h"
#include "Core/Logging/logging.h"

#define MKSTR(x) #x

int main()
{
    printf("%s", MKSTR(3.14));
    return 0;
}