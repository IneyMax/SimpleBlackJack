#include  "io.h"

int main()
{
    double a = getValue();
    char sm = getOperator();
    double b = getValue();
 
    printResult(a, sm, b);
 
    return 0;
}