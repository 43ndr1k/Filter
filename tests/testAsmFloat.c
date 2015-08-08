#include <stdio.h>
// In GCC AT&T syntax, this compiles successfully
int main(int argc, char *argv[])
{
        float x=2.2f;
        float f=3;
        float fa=0.2f;

        asm(	
				"fld %1;" // Ersten Wert Laden (x)
				"fld %2;" // Zweiten Wert Laden (f)
				"fmulp;"  // multiplikation von x und f
				"fstp %0;" //ergebnis holen in (fa) laden
				:"=m"(fa) // schreiben  
				:"m"(x), "m" (f) //lesen

        );
        printf("x : %f\n",x);
        printf("f : %f\n",f);
        printf("fa : %f\n",fa);
        return 0;
}
