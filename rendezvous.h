#include "sema.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sys/wait.h>
#include <thread>
#include <cstring>

class RendezVous
{
private:
    int N;
    int count;
    CSemaphore* varProtect;
    CSemaphore* attente;
public:
    RendezVous(int nb);
    bool arriver ();
    ~RendezVous();
};