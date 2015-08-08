#include <stdio.h>

int grauwertBerechnen(int r, int g, int b) {

	//grauwert = (int) (0.299 * R[i][j] + 0.587 *G[i][j] + 0.114*B[i][j]); 299/1000  587/1000 57/500

	float rot = r;
	float rotwert = 0.299f;
	float gruen = g;
	float gruenwert = 0.587f;
	float blau = b;
	float blauwert = 0.114f;
	int ergebnis = 0;
	float sum = 0;
	float zwischensumme = 0;
        asm(	
				"fld %2;" // Ersten Wert Laden (x)
				"fld %3;" // Zweiten Wert Laden (f)
				"fmulp;"  // multiplikation von x und f
				"fstp %0;" //ergebnis holen in (fa) laden
				"fld %0;"
				"fld %1;"
				"faddp;"
				"fstp %1;"				
				:"=m"(zwischensumme), "=m" (sum) // schreiben  
				:"m"(rot), "m" (rotwert) //lesen

        );
        
                asm(	
				"fld %2;" // Ersten Wert Laden (x)
				"fld %3;" // Zweiten Wert Laden (f)
				"fmulp;"  // multiplikation von x und f
				"fstp %0;" //ergebnis holen in (fa) laden
				"fld %0;"
				"fld %1;"
				"faddp;"
				"fstp %1;"				
				:"=m"(zwischensumme), "=m" (sum) // schreiben  
				:"m"(gruen), "m" (gruenwert) //lesen

        );
        
        asm(	
				"fld %2;" // Ersten Wert Laden (x)
				"fld %3;" // Zweiten Wert Laden (f)
				"fmulp;"  // multiplikation von x und f
				"fstp %0;" //ergebnis holen in (fa) laden
				"fld %0;" //Ergbnis laden
				"fld %1;" // Summe laden
				"faddp;" //Addieren
				"fstp %1;" //Addition in sum speichern				
				:"=m"(zwischensumme), "=m" (sum) // schreiben  
				:"m"(blau), "m" (blauwert) //lesen

        );              
	ergebnis = (int) (sum);

return ergebnis;	
}

int main() {
	
int grau = grauwertBerechnen(2,2,2);
printf("Ergebnis: %d", grau);


    return 0 ;
}
