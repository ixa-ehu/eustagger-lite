//////////////////////////////////////////////////////////////////
//
//  EUSTAGGER LITE
//
//  Copyright (C) 1996-2013  IXA Taldea
//                           EHU-UPV
//
//  This file is part of EUSTAGGER LITE.
//
//  EUSTAGGER LITE is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  EUSTAGGER LITE is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with EUSTAGGER LITE.  If not, see <http://www.gnu.org/licenses/>.
//
//  Contact: Ixa Taldea (ixa@ehu.es)
//           649 Posta kutxa
//           20080 Donostia (Basque Country)
//
//////////////////////////////////////////////////////////////////


#ifndef EUPAROLE_H_
#define EUPAROLE_H_
#include <string>
#include <map>

class euParole {
  std::map<std::string,char> euPar[8];
  int level;
  int maxColumns[4]; 
  bool loaded;
  std::string toParole(const std::string analysis);
  void loadMap();
public:
  euParole();
  euParole(int tagLevel);
  // set multitag system level
  void setLevel(int level);
  // extract lemma and tag from analysis according to level
  void getLemmaTag(const std::string analysis,std::wstring &lemma,std::wstring &tag);
};

#endif //EUPAROLE_H_
