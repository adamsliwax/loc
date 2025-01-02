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

char A[]= {'J','O','9','0','i','e'};

main()
{
    printf("Input QTH locator, only six chars, two big chars, two numbers and two small chars,\r\n");
    printf("example : JI90ie \r\n");
    gets(A);
/* ------ LONGITUDE -------------- */    
    step1=(A[0]-65) * 20;
    step2=(A[2]-48)*2;
    lon_g=step1+step2-180;
    step3=((A[4]-97) /12.0) +(1.0/24);
    lon_m=(A[4]-97)*5.0;  
    lon=step1+step2+step3-180.0;
/*  printf(">> LOCATOR: %s <<\r\n",A);
    printf("LONGITUDE-----------------------------------\r\n");
    printf("step1[%c]= %d \r\n",A[0],step1);
    printf("step2[%c]= %d \r\n",A[2],step2);
    printf("step3[%c]= %f \r\n",A[4],step3);
    printf("[%c] to %d x 5 = minutes: %2.3f \r\n",A[4],(A[4]-97),lon_m);
    printf("%f = %d + %d + %f - 180\r\n",lon,step1,step2,step3);
*/
/* -----  LATITUDE ---------------- */
    step1=(A[1]-65 )*10;
    step2=A[3]-48;
    lat_g=step1+step2-90;
    step3=((A[5]-97) /24.0) +(1.0/48);
    lat_m=(A[5]-97)*2.5;  
    lat=step1+step2+step3 -90;   
/*  printf("LATITUDE------------------------------------\r\n");
    printf("step1[%c]= %d \r\n",A[1],step1);
    printf("step2[%c]= %d \r\n",A[3],step2);
    printf("step3[%c]= %f \r\n",A[5],step3);
    printf("[%c] to %d x 2.5 = minutes: %2.3f \r\n",A[5],(A[5]-97),lat_m);
    printf("%f = %d + %d + %f - 90 \r\n",lat,step1,step2,step3);
*/
/* ------ EAST OR WEST ----------- */
    if (lon > 0) eow=EAST; else eow=WEST;
/* ------ NORT OR SOUTH ---------- */
    if (lat > 0) nos=NORTH; else nos=SOUTH;
/* ----- SHOW POSITION ----------- */    
    printf("============================================\r\n");
    printf("LON: %c%d%c%2.1f'\t| ",eow,lon_g,GR,lon_m);
    printf("LAT: %c%d%c%2.1f'\r\n",nos,lat_g,GR,lat_m);
    printf("LON: %c%3.3f%c \t| ",eow,lon,GR);
    printf("LAT: %c%3.3f%c \r\n",nos,lat,GR);
}


