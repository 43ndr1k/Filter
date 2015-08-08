#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void speichernFarbe(void);
void speichernGrau(void);
void ausgabe(void);
void menu1(void);
void menu2(void);
void graufilter(void);
void farbeninverieren(void);

void leseDatei(void);
void matrixFuellen(void);
int **matrixspeicher(int **, int, int);
void speicherfreigabe(void);
char *leseZeichen(void);
char *eingabeDateiname(void);
void initialisiereMatrix(void);
char *temp(void);
void leseKommentar(void);

char * dateiname;
FILE* datei;

/*
 * Bildbezifische Daten
 */ 
	//Dateityp
	char dateityp[] = {".pnm"};
 	// Breite des Bildes
	char *m_Breite;
 
	// Hoehe des Bildes
	char *m_Hoehe;
 
	// maximale Helligkeit
	char *m_maxHelligkeit; 
	
	//typ der MagicNr der Datei
	char *typVonPpm;

    // Madrizen der Farben
	int **R,**G,**B, **Grau;

    //Hoehe des Grauwertes
    int newHoehe = -1;
    
    char *neuerDateiName;
    
int main(){

    dateiname = eingabeDateiname();



    do {
        datei = fopen(dateiname,"r");

        if(datei == NULL){
            menu1();
        }else {
            fclose(datei);
        }

    }while (datei == NULL);


    printf("Die folgende Datei wird eingelesen: %s\n", dateiname);
    leseDatei();

    do {
        menu2();

    } while (1);
    fclose(datei);

    return EXIT_SUCCESS;
}

char *eingabeDateiname(){

    char *input = (char *) malloc(30 * sizeof(char));
    neuerDateiName = (char *) malloc(30 * sizeof(char));
    printf("Bitte geben Sie den Dateinamen des Bildes an : ");
    fgets(input,30,stdin);

    if(input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';
	
	strcpy(neuerDateiName, input);
	neuerDateiName[strlen(neuerDateiName)-4] = '\0';
		
    return input;
}

void menu1(void)
{

    printf("\nEs ist bei dem Öffnen der Datei ein Fehler aufgetreten! Bitte wählen Sie!\n");
    char wahl;
    do
    {

        printf("1 : Dateiname ändern\n");
        printf("2 : Programm beenden\n");

        printf("Ihre Wahl: ");
        scanf("%c", &wahl);
        while(getchar() != '\n');

        wahl = toupper(wahl);
    } while(!(wahl =='1' || wahl=='2'));

    switch(wahl)
    {
        case '1':
            printf("\nAktueller Dateiname lautet: %s\n", dateiname);
            dateiname = eingabeDateiname();
            leseDatei();
            break;
        case '2':
            exit(0);
            break;
        default:
            printf("\nFalsche Eingabe!\n");
            break;
    }

}

void menu2(void)
{

    printf("\nWas wollen Sie tun?!\n");
    char wahl;
    do
    {
		//printf("0 : Dateiname ändern\n");
        printf("1 : Graufilter\n");
        printf("2 : Farben invertieren\n");
        printf("3 : Bild Speichern\n");
        printf("4 : Programm beenden\n");		
        printf("Ihre Wahl: ");
        scanf("%c", &wahl);
        while(getchar() != '\n');

        wahl = toupper(wahl);
    } while(!( wahl =='1' || wahl=='2' || wahl=='3' || wahl=='4'));

    switch(wahl)
    {
		case '0':
			speicherfreigabe();
            printf("\nAktueller Dateiname lautet: %s\n", dateiname);
            dateiname = eingabeDateiname();  
            leseDatei();             
            break;
        case '1':			
            printf("Graufilter wird auf Datei Datei: %s angewendet\n", dateiname);
            if(strcmp(typVonPpm,"P2") == 0) {
				printf("Bild ist bereits ein Graubild\n");
			} else {
	            graufilter();
                
			}
            break;
        case '2':
            printf("Farben werden invertiert, auf die Datei Datei: %s angewendet\n", dateiname);
            farbeninverieren();          
            break;
        case '3': 
			printf("Bild wird gespeichert");
			
			if(strcmp(typVonPpm,"P3") == 0) {
			speichernFarbe();
			}
			else {
			speichernGrau();
			}
            break;
        case '4':
            exit(0);
            break;
        default:
            printf("Falsche Eingabe!\n");
            break;
    }

}

char *temp() {
    char* temp = leseZeichen();
    if(temp != NULL) {
        return temp;
    }
    else {
        printf("Umgültige Werte in der Datei %s!\n", dateiname);
        menu1();
    }
	return NULL;
}

void leseDatei(){

    // Datei aus der die Daten gelesen werden sollen
    datei = fopen(dateiname,"r");

    if(NULL == datei){
        printf("Kann %s nicht öffnen!",dateiname);

    }
    
    // Ein Zähler, der die Anzahl der
	// Leerräume im Header der Anymap mitzählt.
	int count = 0;

	// Der Header besteht aus vier Werten 
	// mit drei Leerräumen
	// Typ LR Breite LR Höhe LR maxBr LR [Bildwerte]
	
	// Lesen von Zeichen für Zeichen
	
	while (!(count > 3)){

			// Die gelesenen Werte sollen gleich
			// umgewandelt werden.

            char* temp = leseZeichen();
            if(temp != NULL) {

                switch(count) {
                case 0:
                      typVonPpm = temp;

                    break;
                case 1:

                    m_Breite = temp;
                    break;
                case 2:
                    m_Hoehe = temp;
                    break;
                case 3:
                    m_maxHelligkeit = temp;
                    break;
                }
                count++;

            }else {
                printf("Umgültige Werte in der Datei %s!\n", dateiname);
                menu1();
            }
		
	}

    initialisiereMatrix();
    matrixFuellen();

    fclose(datei);
}


//Lese Zeichen bis zum Leerzeichen
char *leseZeichen() {

    // Temporärer String, der den eingelesenen
    // String speichert und später an die richtige
    // Variable kopiert.
    char puffer[] = "";
    char *str = malloc(strlen(puffer) + 1);
    size_t len = 0;

    //Werte auf 0 setzten
    memset(str, 0, (sizeof(str)));

    int gueltig = 0;
    

    
    // Lesen von Zeichen für Zeichen
    while (!feof(datei)) {
        fread(puffer, sizeof(char), 1, datei);

        if (puffer[0] == ' ' || puffer[0] == '\n' || puffer[0] == '\r' || puffer[0] == '\t') {
            if (gueltig == 1) {
                len = strlen(str);
                str[len] = '\0';
                return str;
            }
        }
        else {
            gueltig = 1;
            strncat(str, puffer,sizeof(char));
            str = realloc(str,strlen(puffer)+len+1);
        }

    }
    if (gueltig == 1) {
        len = strlen(str);
        str[len] = '\0';
        return str;
    }else {

    }
    return NULL;
}

void initialisiereMatrix() {
    //variablen für die Höhe, Breite und Helligkeit der Matrix
    int b,h;
        //Umwandlung der char Werte in int Werte
        b = atoi(m_Breite);
        h = atoi(m_Hoehe);
        
    //Prüft ob das richtige Dateiformat vorliegt.
    if(strcmp(typVonPpm, "P2") == 0){

        Grau = matrixspeicher(Grau,h,b);
	
   } else if (strcmp(typVonPpm, "P3") == 0) {
			 //Speicheranfordern für die Matrizen
			 
			R = matrixspeicher(R,h,b);
			G = matrixspeicher(G,h,b);
			B = matrixspeicher(B,h,b);
			Grau = matrixspeicher(Grau,h,b);
		}

    else {
        printf("Das Dateiformat der Datei %s ist nicht korrekt!",dateiname);
        menu1();
    }

}

//Anfordern von Speicher mit malloc für die Matrix
int **matrixspeicher(int **matrix, int zeile, int spalte){
	
	//Zähler
	int i;
	
	/* Speicher reservieren für die int-Zeiger (=zeile) */
   matrix = malloc(zeile * sizeof(int *));
   if(NULL == matrix) {
      printf("Kein virtueller RAM mehr vorhanden ... !");
     
   }
   /* Speicher reservieren für die einzelnen Spalten
    * der i-ten Zeile */
   for(i = 0; i < zeile; i++) {
      matrix[i] = malloc(spalte * sizeof(int));
         if(NULL == matrix[i]) {
            printf("Kein Speicher mehr fuer Zeile %d\n",i);
            
         }
   }
	return matrix;
	
}

void matrixFuellen() {

    int i, j, spalte, zeile;
    spalte = atoi(m_Breite);
    zeile = atoi(m_Hoehe);

    for (i = 0; i < zeile; i++) {
        for (j = 0; j < spalte; j++) {
			if(strcmp(typVonPpm,"P3") == 0) {
				R[i][j] = atoi(temp());
				G[i][j] = atoi(temp());
				B[i][j] = atoi(temp());
			} else {
					Grau[i][j] = atoi(temp());
				}
        }
    }
}

void graufilter(){
	
	
		int i, j, spalte, zeile;
		spalte = atoi(m_Breite);
		zeile = atoi(m_Hoehe);
		printf("Umwandeln der Matrix in Grauwerte\n");
		for (i = 0; i < zeile; i++) {
			for (j = 0; j < spalte; j++) {
				int grauwert = 0;
					grauwert = (int) (0.299 * R[i][j] + 0.587 *G[i][j] + 0.114*B[i][j]);
			
				if(newHoehe < grauwert) {
					newHoehe = grauwert;
				}
				Grau[i][j] = grauwert;

			}
		}
		free(typVonPpm);
		typVonPpm = malloc(2*sizeof(char));
		strncat(typVonPpm, "P2",sizeof(char));

}

void farbeninverieren(){
	
	
        int i, j, spalte, zeile, hell;
        spalte = atoi(m_Breite);
        zeile = atoi(m_Hoehe);
        hell = atoi(m_maxHelligkeit);

        for (i = 0; i < zeile; i++) {
            for (j = 0; j < spalte; j++) {
				if(strcmp(typVonPpm,"P3") == 0) {
					int blau, rot, gruen;
					rot = R[i][j]; 
					gruen = G[i][j];
					blau = B[i][j];
					
					R[i][j] = hell - rot;
					G[i][j] = hell - gruen;
					B[i][j] = hell - blau;

			} 
			else {					
					int g = Grau[i][j];
					Grau[i][j] =  hell - g;					
				}
				
            }
           
        }
}

//Eine Ausgabe um die Matrix zu sehen (für Test zwäcke)
void ausgabe(){

  printf("typ: %s\n", typVonPpm);
  printf("breite: %s\n", m_Breite);
  printf("hoehe: %s\n", m_Hoehe);
  printf("helligkeit: %s\n", m_maxHelligkeit);

    /* Inhalt der Matrix entsprechend ausgeben */
    int i, j, spalte, zeile;
    spalte = atoi(m_Breite);
    zeile = atoi(m_Hoehe);
    printf("Matrix\n");
    for (i = 0; i < zeile; i++) {
        for (j = 0; j < spalte; j++) {
            printf("%d %d %d ", R[i][j], G[i][j], B[i][j]);
        }
        printf("\n");
    }
}


void speichernFarbe(){

    FILE *fp;


    char name2[100] = {"Farbe.pnm"};
	char name[100];
	strcpy(name, neuerDateiName);
	strcat(name, name2);
	
    fp = fopen(name, "w");
    if(fp == NULL) {
        printf("Datei konnte nicht geoeffnet werden.\n");
    }else {

        int i, j, spalte, zeile;
        spalte = atoi(m_Breite);
        zeile = atoi(m_Hoehe);
        
        printf("Matrix Speichern\n");
       
		fprintf(fp, "P3");
        fprintf(fp, "\n");
        fprintf(fp,"%s", m_Breite);
        fprintf(fp," ");
        fprintf(fp,"%s", m_Hoehe);
        fprintf(fp,"\n");
        fprintf(fp,"%s", m_maxHelligkeit);
        fprintf(fp,"\n");

        for (i = 0; i < zeile; i++) {
            for (j = 0; j < spalte; j++) {
				fprintf(fp,"%4i %4i %4i ", R[i][j], G[i][j],B[i][j]);
            }
            fprintf(fp,"\n");
        }
        fclose(fp);
    }

}

void speichernGrau() {

    FILE *fp;
    
	char name2[100] = {"GrauBild.pnm"};
	char name[100];
	strcpy(name, neuerDateiName);
	strcat(name, name2);
    fp = fopen(name, "w");

    if(fp == NULL) {
        printf("Datei konnte nicht geoeffnet werden.\n");
    }else {

        int i, j, spalte, zeile;
        spalte = atoi(m_Breite);
        zeile = atoi(m_Hoehe);
        printf("Matrix Speichern\n");


        fprintf(fp, "P2");
        fprintf(fp, "\n");
        fprintf(fp,"%s", m_Breite);
        fprintf(fp," ");
        fprintf(fp,"%s", m_Hoehe);
        fprintf(fp,"\n");
        fprintf(fp,"%i", newHoehe);
        fprintf(fp,"\n");

        for (i = 0; i < zeile; i++) {
            for (j = 0; j < spalte; j++) {
                fprintf(fp,"%i", Grau[i][j]);
                fprintf(fp," ");
            }
            fprintf(fp,"\n");
        }
        fflush(fp);
        fclose(fp);
    }


}
void speicherfreigabe(){
	

	//Zähler
	int i,j , zeile, spalte;
	/* Speicherplatz wieder freigeben.
    * Wichtig! In umgekehrter Reihenfolge. */
    
	zeile = atoi(m_Hoehe);
	spalte = atoi(m_Breite);
	
   /* Spalten der i-ten Zeile freigeben */
   for(i = 0; i < zeile; i++) {

			free(R[i]);
		   free(G[i]);
		   free(B[i]);
		   free(Grau[i]);
   }
   /* Jetzt können die leeren Zeilen freigegeben werden. */
   free(R);
   free(G);
   free(B);
      
   	free(typVonPpm);
	free(m_Breite);
	free(m_Hoehe);
	free(m_maxHelligkeit);
	
}


