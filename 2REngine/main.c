#include <stdio.h>
#include "Core/DataTypes/dstring.h"
#include "Core/DataTypes/dvector2D.h"
#include "Core/Logging/logging.h"

int main()
{
    int a;
    DVector2D v = { 3.14, 2.71};
    DEBUG_LOG(v);
    return 0;
}