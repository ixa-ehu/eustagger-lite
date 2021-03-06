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


#ifndef TOKENIZATZAILE_H
#define TOKENIZATZAILE_H

#include "token_raw.h"
using namespace std;

class tokenizatzaile
{

public:

 tokenizatzaile() {}; // hasieraketa funtzioa

 virtual void back() {};
 virtual void back_token(long offsetaa) {};// tokenaren barruko aurreneko tokenera itzuli

 virtual int next_token() { return -1;}; // hurrengo tokena lortzen duena

 virtual tokenRaw e_azkena() { tokenRaw tmp; return(tmp); };    // azken tokena ematen duena

//       ~tokenizatzaile();     // suntsitzailea

};

#endif // TOKENIZATZAILE_H

