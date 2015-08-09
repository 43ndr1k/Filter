//Grauwert aus den R G B Wert berechnen mit Assembler code
int grauwertBerechnen(int r, int g, int b) {

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
				"fld %2\n" // Ersten Wert Laden (rot)
				"fld %3\n" // Zweiten Wert Laden (rotwert)
				"fmulp\n"  // multiplikation von x und f
				"fstp %0\n" //ergebnis holen in (fa) laden
				"fld %0\n"//Ergbnis laden
				"fld %1\n"// Summe laden
				"faddp\n"//Addieren
				"fstp %1\n"//Addition in sum speichern					
				:"=m"(zwischensumme), "=m" (sum) // schreiben  
				:"m"(rot), "m" (rotwert) //lesen

        );
        
                asm(	
				"fld %2\n" // Ersten Wert Laden 
				"fld %3\n" // Zweiten Wert Laden 
				"fmulp\n"  // multiplikation 
				"fstp %0\n" //ergebnis holen 
				"fld %0\n"
				"fld %1\n"
				"faddp;\n"
				"fstp %1\n"				
				:"=m"(zwischensumme), "=m" (sum) // schreiben  
				:"m"(gruen), "m" (gruenwert) //lesen

        );
        
        asm(	
				"fld %2;\n" // Ersten Wert Laden 
				"fld %3\n" // Zweiten Wert Laden 
				"fmulp\n"  // multiplikation 
				"fstp %0\n" //ergebnis holen 
				"fld %0\n" //Ergbnis laden
				"fld %1\n" // Summe laden
				"faddp\n" //Addieren
				"fstp %1\n" //Addition in sum speichern				
				:"=m"(zwischensumme), "=m" (sum) // schreiben  
				:"m"(blau), "m" (blauwert) //lesen

        );              
	ergebnis = (int) (sum);

return ergebnis;	
}


int asmfarbeinvertieren(int w, int h) {
	
	int wert, hell;
	wert = w;
	hell = h;
	
	  /* Hier beginnt der Inline-Assembler Abschnitt in AT&T-Syntax */
  asm (
	
		"sub %1, %0\n" //Subtraktion
		"movl %0,%1\n" //Register kopieren
	

      /* Definition der Nebenbedingungen:
       * Diese weisen den C-Variablen der Reihe nach aufzählend einen für den Inline-Assemblercode nutzbaren Operanden
       * zu und teilen dem Compiler mit, auf welche Weise (lesend und/oder schreibend) dieser im Inline-Assemblercode
       * verwendet werden kann und auf welche Register dieser beschränkt ist. Dadurch wird eine korrekte und effiziente
       * Übergabe der Variablenwerte in und aus dem Assemblercodeabschnitt gewährleistet. */
      : "+r" (hell) /* Gibt an, dass die Variable bar sowohl gelesen als auch beschrieben ('+') wird und deren Wert in
                    * ein allgemeines Register ('r') zu platzieren ist.
                    * Als erster Operand wird er im Assemblercodeabschnitt unter der Bezeichnung %0 genutzt. */
	  : "g" (wert)  /* Beschränkt die Verwendung der Variable foo nur zum Lesen. Sie kann auf beliebige Weise ('g', im
                    * Speicher, in einem Register oder als Direktwert) an den Assemblerteil übergeben werden.
                    * Als zweiter Operand wird er im Assemblercodeabschnitt unter der Bezeichnung %1 genutzt */
      : "cc"       /* Gibt an, dass die Statusanzeige (durch die Befehle add und inc) verändert wurde. */
  );
	
	//printf("Ergebnis: %i\n", wert);
	return wert;
	
}
