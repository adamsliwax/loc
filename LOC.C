#include <stdio.h>

#define BIGCHAR 65
#define SMALLCHAR 97
#define NUMBER 48

#define GR     248

#define NORTH   'N'
#define SOUTH   'S'
#define EAST    'E'
#define WEST    'W'

typedef int dlugos;
typedef int szerok;

int step1, step2, lat_g, lon_g;
float  step3;
float lat,lon;
float lat_m,lon_m;
char nos, eow;

unsigned correct;
unsigned len;

char A[]= {'\0','\0','\0','\0','\0','\0','\0'};


main()
{
    correct=1;
    printf("Input QTH locator, only six characters,\r\n");
    printf("\t2 big leter, 2 didgits and 2 small leters.\r\n");
    printf("\tExample: JM91ie .\r\n");
    while(correct) {
        correct=0;
        for (len=0;len<8;len++) A[len]='\0';
        printf("Write characters end press ENTER:");    
        gets(A);
        len=strlen(A);
        if (len > 6) { correct=1; printf("Too long!\r\n"); }
        if (len < 6) { correct=1; printf("More chars!\r\n"); }
        if ( !(isdigit(A[2]) && isdigit(A[3]))) {
           correct=1; 
           printf("Characters [%c] or/and [%c] arn't digits!\r\n",A[2],A[3]);
        }
        if ( !(isupper(A[0]) && isupper(A[1]))) {
           correct=1; 
           printf("Characters [%c] or/and [%c] arn't big leters!\r\n",A[0],A[1]);
        }
        if ( !(islower(A[4]) && islower(A[5]))) {
           correct=1; 
           printf("Characters [%c] or/and [%c] arn't small leters!\r\n",A[4],A[5]);
        } 
    }
/* ------ LONGITUDE -------------- */    
    step1=(A[0]-65) * 20;
    step2=(A[2]-48)*2;
    lon_g=step1+step2-180;
    step3=((A[4]-97) /12.0) +(1.0/24);
    lon_m=(A[4]-97)*5.0;  
    lon=step1+step2+step3-180.0;
/* -----  LATITUDE ---------------- */
    step1=(A[1]-65 )*10;
    step2=A[3]-48;
    lat_g=step1+step2-90;
    step3=((A[5]-97) /24.0) +(1.0/48);
    lat_m=(A[5]-97)*2.5;  
    lat=step1+step2+step3 -90;   
/* ------ EAST OR WEST ----------- */
    if (lon > 0) eow=EAST; else eow=WEST;
/* ------ NORT OR SOUTH ---------- */
    if (lat > 0) nos=NORTH; else nos=SOUTH;
/* ----- SHOW POSITION ----------- */    
    printf("\n\r\t>> LOCATOR: %s <<\r\n",A);
    printf("============================================\r\n");
    printf("LON: %c%d%c%2.1f'\t| ",eow,lon_g,GR,lon_m);
    printf("LAT: %c%d%c%2.1f'\r\n",nos,lat_g,GR,lat_m);
    printf("LON: %c%3.3f%c \t| ",eow,lon,GR);
    printf("LAT: %c%3.3f%c \r\n",nos,lat,GR);
}
