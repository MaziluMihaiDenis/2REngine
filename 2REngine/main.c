#include <stdio.h>
#include "DataTypes/dstring.h"
#include "DataTypes/dvector2D.h"
#include "Logging/logging.h"

int main()
{
    int a;
    DVector2D v = { 3.14, 2.71};
    DEBUG_LOG(v);
    return 0;
}