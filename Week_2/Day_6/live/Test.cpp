#include "../music/string/Veena.h"
#include "../music/wind/Saxophone.h"

using namespace music::string_instruments;
using namespace music::wind;

int main() {
    Veena veena;
    veena.play();

    Saxophone saxophone;
    saxophone.play();

    Playable* p;

    p = &veena;
    p->play();

    p = &saxophone;
    p->play();

    return 0;
}