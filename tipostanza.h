#ifndef __TIPOSTANZA_H__
#define __TIPOSTANZA_H__

#include <iostream>
using namespace std;
// #include "utente.h"

enum dimStanza {SINGOLA, DOPPIA, FAMILIARE, SUITE};
enum esposizioneStanza {SE, NE, NO, SO};


class TipoStanza {
		dimStanza tipo;
		int posti;
		esposizioneStanza esposizione;

	public:
		TipoStanza(dimStanza t, int p, esposizioneStanza e);
		void stampa() const;
		bool operator==(TipoStanza& ts);
};


class Stanza:public TipoStanza {
		bool libera;
		int numero;
		int prezzoMin, prezzoMax;
	public:
		Stanza(dimStanza t, int p, esposizioneStanza e, int num, int pmin,
												int pmax, bool _lib=true);
		bool isEmpty();
};


#endif