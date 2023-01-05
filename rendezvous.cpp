#include "rendezvous.h"

RendezVous::RendezVous(int nb)
{
    this->N = nb;
    this->count = 0;
    this->varProtect = new CSemaphore(1);
    this->attente = new CSemaphore(0);
}

bool RendezVous::arriver() {
    this->varProtect->wait();
    this->count++;

    if (this->count >= N) {
        std::cout << "Je libère la file d'attente ..." << std::endl;
        for (int i = 1; i < N; i++) {
            this->attente->notify();
        }
        this->count = this->count - this->N;
        this->varProtect->notify();
    } else {
        std::cout << "Je rentre dans la file d'attente ... ( n : " << this->count << " )" << std::endl;
        this->varProtect->notify();
        this->attente->wait();
    }
    return true;
}

RendezVous::~RendezVous()
{
    delete this->varProtect;
    delete this->attente;
}