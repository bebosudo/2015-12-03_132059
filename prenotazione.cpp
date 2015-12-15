using namespace std;

#include "prenotazione.h"

// ############   booking	 ####################
Booking::Booking(string garr, string gpar) {
	giornoarrivo = garr; giornopartenza = gpar;
}


void Booking::stampa() const {
	cout << giornoarrivo << "-" << giornopartenza;
}


bool Booking::operator==(Booking& p) {
	return giornoarrivo == p.giornoarrivo and
		   giornopartenza == p.giornopartenza;
}


// ############ prenotazione ####################

Prenotazione::Prenotazione(string garr, string gpar):Booking(garr, gpar) {}

bool Prenotazione::operator==(Prenotazione& p) {
	return this->Booking::operator==(p);
}


void Prenotazione::addTipoStanza(TipoStanza& _ts) {
	lts.push_back(_ts);
}


// ############   presenza   ####################

Presenza::Presenza(string garr, string gpar, int pr, strumPagamento pagam):Booking(garr, gpar) {
	prezzo = pr;
	pagamento = pagam;
}


void Presenza::addStanza(Stanza* ps) {
	lps.push_back(ps);
}


void Presenza::stampa() const {
	Booking::stampa();
	cout << ", " << prezzo << "€, ";
	switch(pagamento) {
		case BANCOMAT: cout << "Bancomat"; break;
		case CARTADICREDITO: cout << "Carta di Credito"; break;
		case CONTANTI: cout << "Contanti"; break;
		case PREPAGATO: cout << "Prepagato"; break;
		default: cout << "metodo di pagamento non trovato";
	}
}


bool Presenza::operator==(Presenza& p) {
	return this->Booking::operator==(p);
}

int Presenza::getPrezzo() const {
	return prezzo;
}