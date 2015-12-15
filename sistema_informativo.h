#ifndef __SISTEMA_INFORMATIVO_H__
#define __SISTEMA_INFORMATIVO_H__

#include <iostream>
#include <list>
using namespace std;
#include "utente.h"


class SistemaInformativo {
		list <Utente> lutenti;
		list <Prenotazione> lprenotazioni;
		list <Presenza> lpresenze;
		list <TipoStanza> ltstanze;
		list <Stanza> lstanze;

	public:
		void addStanzaAlSistema(Stanza s);
		bool checkDisponibilitaStanza(TipoStanza& ts);
		void addUtente(Utente u);
		// prima controllo se esiste l'utente, e con trovaUtente lo recupero.
		bool checkUtente(Utente& u);
		Utente& trovaUtente(Utente& u);
		void addPrenotazione(Utente& u, Prenotazione& p);
		void addTipoStanzaAPrenotazione(Utente& u, Prenotazione& p, TipoStanza& ts);
		void addPresenza(Utente& u, Presenza& p);
		void randomInitStanze();
		void randomInitUtentiPrenotazioniPresenze();
		// friend list<Utente> PersonePresenti(SistemaInformativo& s);
		Utente* getRandomUser();
};

int casuale(int min, int max);

#endif