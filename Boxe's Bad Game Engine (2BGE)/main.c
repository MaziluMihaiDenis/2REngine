#include <stdio.h>
#include "DataTypes/dstring.h"

int main()
{
    DString str, *str1;
    str = float_to_string(3.141592653589793);
    printf("%s", str.text);

    return 0;
}