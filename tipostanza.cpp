#include <iostream>
using namespace std;

#include "tipostanza.h"

void TipoStanza::stampa() const {
	switch(tipo) {
		case SINGOLA: cout << "singola"; break;
		case DOPPIA: cout << "doppia"; break;
		case FAMILIARE: cout << "familiare"; break;
		case SUITE: cout << "suite"; break;
		default: cout << "Tipostanza non trovato.";
	}
	cout << " - " << posti << " posti - ";
	switch(esposizione) {
		case SE: cout << "sud-est"; break;
		case NE: cout << "nord-est"; break;
		case NO: cout << "nord-ovest"; break;
		case SO: cout << "sud-ovest"; break;
		default: cout << "Tipo esposizione non trovato.";
	}
}

TipoStanza::TipoStanza(dimStanza t, int p, esposizioneStanza e) {
	tipo = t;
	// in realtà lo fa già il compilatore questo lavoro facendo il confronto
	// con i valori nell'enum.
	// if (tipo != SINGOLA && tipo != DOPPIA && tipo != FAMILIARE &&
															// tipo != SUITE) {
			// cout << "Errore di inserimento. Stanza singola di default.";
			// tipo = SINGOLA;
	// }
	posti = p;
	esposizione = e;
	// if (esposizione != NE && esposizione != NO && esposizione != SE &&
														// esposizione != SO) {
			// cout << "Errore di inserimento. Orientamento Nord Est di default.";
			// esposizione = NE;
	// }
	cout << "creato oggetto tipoStanza con queste caratteristiche: ";
	this->stampa();
	cout << endl;
}


bool TipoStanza::operator==(TipoStanza& ts) {
	return tipo==ts.tipo and posti==ts.posti and esposizione==ts.esposizione;
}


Stanza::Stanza(dimStanza t, int p, esposizioneStanza e, int num, int pmin,
									int pmax, bool _lib):TipoStanza(t, p, e) {
	numero = num;
	libera = _lib;
	// un minimo di controllo sugli ingressi.
	if (pmin <= 0) { prezzoMin = 15; }
	if (pmax <= 0 or pmax < pmin) { prezzoMax = prezzoMin + 1; }
}


bool Stanza::isEmpty() { return libera; }