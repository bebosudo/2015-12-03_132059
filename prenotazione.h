#ifndef __PRENOTAZIONE_H__
#define __PRENOTAZIONE_H__

#include <iostream>
#include <list>
using namespace std;
#include "tipostanza.h"

enum strumPagamento {BANCOMAT, CONTANTI, CARTADICREDITO, PREPAGATO};

class Booking {
	protected:
		string giornoarrivo, giornopartenza;
	public:
		Booking(string garr, string gpar);
		bool operator==(Booking& b);
		void stampa() const;
};


class Prenotazione:public Booking {
		list <TipoStanza> lts;
	public:
		// Prenotazione(string garr, string gpar, TipoStanza& _ts);
		Prenotazione(string garr, string gpar);
		bool operator==(Prenotazione& p);
		void addTipoStanza(TipoStanza& _ts);
		// bool esisteBooking(Prenotazione& p);
		// Prenotazione& trovaBooking(Prenotazione& p);
};


class Presenza:public Booking {
		int prezzo;
		list <Stanza*> lps;
		strumPagamento pagamento;
	public:
		Presenza(string garr, string gpar, int pr, strumPagamento pagam);
		bool operator==(Presenza& p);
		void addStanza(Stanza* ps);
		void stampa() const;
		int getPrezzo() const;
};


#endif