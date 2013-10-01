/*azterzen.c*/
/*deklinatuta dauden digituzko zenbakiak "hamasei", "hamahiru", "hamalau",
"hamaika" eta "bost" zenbakietan bihurtzen ditu automata baten bidez zenbakia 
zer motatakoa den aztertu ondoren*/
/*** NEREA : 95/11/16 zenbakiak bi, hiru, lau eta bostengatik aldatu beharrean,
hamasei, hamahiru, hamalau eta hamabostengatik ordezkatuko dira.
Aldaketa honen arrazoia zera da, bi eta lauk arazoak ematen zituztela, bira
aditzaren analisiak ematen ditu eta lau adjektibo eta aditza delako. Beste
biak, hiru eta bost alegia, homogeneotasun kontuengatik aldatuak.
****************************************************** NEREA . 95/11/16 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filtro.h"
/*#include "taipak.h" */ /*** externs.h fitxategian */
#include "tamaino.h"
#include "hizkia.h"
/*#include  "klaseak.h" */ /*** NEREA : 94/6/9 ez da behar */
#include "externs.h"

char *eman_azken_zifra(char zenb[])
/*char zenb[]; */
{
 int l=strlen(zenb)-1;

/*  tmp=zenb; */
 
 while (strchr(ZIFRA,zenb[l]) == NULL) /*** NEREA : 97/10/23 %90 eta antzekoetarako */
   {
    l--;
    /*   l2++;*/
   }
 while ((l>=0) && (strchr(ZIFRA,zenb[l]) != NULL))
   {
/*     l2+=l; */
/*     tmp+=l; */
/*     l=strspn(tmp,ZIFRA); */
/*     l++; */
/*     if (l>=strlen(tmp)) break; */
     l--;
   }
 return(&zenb[l+1]);

}

void aztertu_zenbakia( char *filtratua, char *hitza)
/*char hitza[];
char filtratua[];
*/

{ 
  char bitar[2];
  int y,z,k,estadua,kont,zenb,p;
#ifndef __EXEKU__
  extern  automata_lag autofil2;
#else
  extern  automata autofil2;
#endif /*__EXEKU__*/

  char atzizkia[KMAXHITZ];
  char tmp2[KMAXHITZ_FIL_GABE];
       /*** NEREA : 95/5/25 zenbakietan marratxoa dagoenerako */
  int zenbaki[10];
  int l;

   atzizkia[0]='\0';
   zenbaki[0]='\0';
   kont = 0;
   zenb = 0;
   z = 0;
   k = 0;
   bitar[1] = '\0';

/*** NEREA : 95/5/25 zenbakietan bereizgarriak daudenerako */
  strcpy(tmp2,eman_azken_zifra(filtratua));
/*******************************************************/

   l = strlen (tmp2); /*** NEREA : 94/3/23 */

 while ((strchr(ZIFRA,tmp2[kont]) != NULL) && (kont < l))
     {
      bitar[0] = tmp2[kont];
      zenbaki[k] = atoi(bitar);
      k++;
      kont++;
     }   
   zenbaki[k] ='\0';
   zenb = kont-1;
   if (tmp2[kont] == '.') 
     {
      strcpy(atzizkia,"garren");
      z = 6;
      kont++;
     }

   while (kont != l) 
     {
       if (!filtratu(tmp2[kont])) {   /*** NEREA : 99/8/3 zuriguneak eta bereizgarriak ez sartzeko*/
	 atzizkia[z] = tmp2[kont];
	 z++;
       }
      kont++;
     }
   atzizkia[z] = '\0';
   estadua = 1;
   p = estadua-1;

   if /* ((k==1) && */ /*** NEREA : 94/6/27 */
	  (zenbaki[k-1] == 3)
	  /* ) */ /*** NEREA : 94/6/27 */
     strcpy(hitza,"hamahiru");
   else
     if /* ((k==1) && */ /*** NEREA : 94/6/27 */
		(zenbaki[k-1] ==4)
		/* ) */ /*** NEREA : 94/6/27 */
       strcpy(hitza,"hamalau");
     else     
       if ( (k==1) && (zenbaki[k-1] == 1) )
	 strcpy(hitza,"bat");
       else {
	 while ((autofil2.final[p] == 0) && (estadua != 0))
	   {
	     if (zenb < 0)
	       y = 10;
	     /*  if (strchr(ZIFRA,tmp2[zenb]) == NULL)
		 y = 10; */ /*** NEREA : 94/6/9 */
	     else y =zenbaki[zenb];
	     estadua = autofil2.estaduak[p][y];
	     p = estadua-1;
	     zenb--;
	   }     
	 
	 if (autofil2.final[p] == 1)
	   {
	     if (estadua == 4)
	       strcpy(hitza,"hamazazpi");
	     if (estadua == 6) {
	       if ((atzizkia[0] == 'g') || (atzizkia[0] == 'G')) 
		 strcpy(hitza,"hamabos"); 
	       else {
		 strcpy(hitza,"hamabost");
		 if (strchr(BOKALE,atzizkia[0]) == NULL) {
		   strcat(hitza,"e");
		 }
	       }
	     }
	     if (estadua == 7) 
	       if (atzizkia[0] == 'e' || atzizkia[0] == 'E' || atzizkia[0] == 'a' || atzizkia[0] == 'A')
		 strcpy(hitza,"hamaik");
	       else
		 strcpy(hitza, "hamaika");
	   }
       }

   strcat(hitza,atzizkia);
 
 
}
 
 

