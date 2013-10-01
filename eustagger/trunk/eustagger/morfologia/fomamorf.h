#include <stdio.h>
#include <vector>
#include <string>
#include <stdbool.h> // fomalib.h-k behar du
#include <map>
#include "fomalib.h"


// Berria, Itziar
#define MAX_LEXIK 7
//#define MAX_LEXIK 5

#define ESTANDARRA 1
#define ALDAERAK 2
#define LEX_GABE 3     /* BI HAUEK LEXIKORIK GABE EGITEKO */
#define ALD_STD  4
#define ALD_BANA 5
#define ALD_BANA_ANA 6
#define OROK 4         /* 1 ?? LORTZEKO ETA 2. LEMA LORTZEKO */
#define SORKUNTZA 5
#define SORKUNTZA_KAT 6

#define LUZMAXAN 1000

typedef std::multimap<std::string, std::string> sStrStrMap;
typedef std::pair<std::string, std::string> sStrStrPair;

extern std::string getEnvVar(std::string const& key);

class fomaMorf {
  struct fsm *lexikoiak[MAX_LEXIK];
  struct apply_handle *lexHandle[MAX_LEXIK];
//  std::map<std::string,std::string> lexGabe;
  sStrStrMap lexGabe;

 public:
  fomaMorf();
  int hasieratu_transd(const std::string fitx_iz, int n_lex);
  int amaitu_transd(int);
  int amaitu_transd_guztiak();
  int analizatu_hitza(int zein, char *hitza,char anal[][LUZMAXAN]);
  int sortu(int n_lex, std::string hitza, std::vector<std::string> &emaitza);
  int sortu_dena(int n_lex, std::string hitza,  std::vector<std::string> &emaitza);
  int ireki_erab_lex (const std::string izena, int sortu, int info_morfo);
  sStrStrMap::iterator bilatu_erab_guztiak (char *sar);
  sStrStrMap::iterator azkena ();
  ~fomaMorf();
 private:
  int analizatu(int n_lex, std::string hitza, std::vector<std::string> &emaitza);
};
