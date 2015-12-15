#ifndef __PERSONA_H__
#define __PERSONA_H__

#include <iostream>
#include <list>
using namespace std;
#include "prenotazione.h"

class Utente {
		string nome, cognome, luogoNascita, dataNascita, docIdentita;
		list <Prenotazione> lpreno;
		list <Presenza> lprese;

	public:
		Utente();
		Utente(string n, string c, string l, string d, string doc);
		void stampa() const;
		bool esistePrenotazione(Prenotazione& p);
		bool esistePresenza(Presenza& p);
		Prenotazione& trovaPrenotazione(Prenotazione& p);
		void prenota(Prenotazione& p);
		void addTipoStanzaAPrenotazione(Prenotazione& p, TipoStanza& _ts);
		void addStanzaAPresenza(Presenza& p, Stanza& _ts);
		void presenza(Presenza& p);
		bool operator==(Utente& u);
		friend int costiTotali(Utente& u);

};


#endif