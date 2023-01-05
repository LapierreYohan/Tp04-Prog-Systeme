#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sys/wait.h>
#include <thread>
#include <cstring>

#include "rendezvous.h"

using namespace std;

bool doSomething(int id, RendezVous* rdv);

int main(int argc, char const *argv[])
{
    int cpt = 1;
    srand(time(NULL));
    int random;
    thread t;
    RendezVous rdv(5);
    while (true) {
        random = rand()%10;
        if (random < 4) {
            t = thread(doSomething, cpt, &rdv);
            t.detach();
            cpt++;
        }
        sleep(1);
    }

    return EXIT_SUCCESS;
}

bool doSomething(int id, RendezVous* rdv) {
    cout << "Thread n " << id << " : Je fais quelque chose wallah" << endl;
    sleep(5);
    rdv->arriver();
    cout << "Thread n " << id << " : J'ai finit ma tache..." << endl;
    return true;
}
