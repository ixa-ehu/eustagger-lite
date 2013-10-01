#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "aurreproz_raw.h"
#include "taipak.h"
#include "dat_orok.h"
#include "formatua.h"

#include "analizatzailea.h"


extern int XEROX;
extern int xeroxerako;
extern int edbl_bertsioa;
analizatzailea anali;
automata_lag autofil2;
aurreprozRaw proz;

extern int irakur_automata(char *fp,automata_lag *aut,int erre,int zut);


std::string getEnvVar(std::string const& key);


void segHasieraketak(int sar_lem, int lex_uzei, int bigarren, int ez_est, int erab_lex, string &lexiko_izena, int parentizatua, int deslokala) {
    anali.hasieraketak(sar_lem, lex_uzei, bigarren, ez_est, erab_lex, lexiko_izena, parentizatua, deslokala);
}

void segAmaierakoak() {
 anali.amaierakoak();
}

void segmentazioaSortuRaw(string &fitxategiIzena, string &segIrteera) {
  vector<string>::iterator hasi,amai,non;
  string lerro,segFitx;
  vector<string> emaitza;
  string amaraunIzena;

  irakur_automata("autofiltro2.dat",&autofil2,ESTADU2_MAX,MULTZO2_MAX);


  if (fitxategiIzena.length() == 0) 
    proz.init(AURREAN_LEX,"stdin");
  else {
    char *sarfitx = strdup(fitxategiIzena.c_str());
    proz.init(AURREAN_LEX,sarfitx);
    free(sarfitx);
  }
  proz.aurreprozesua(ANALIRA,&emaitza);
  emaitza = anali.analizatu(TAULAN,&emaitza);


  stringstream segString;
  
  hasi = emaitza.begin();
  amai = emaitza.end();
  
  for (non=hasi;non!=amai;++non) {
    segString << *non;
  }
  segIrteera = segString.str();
}

