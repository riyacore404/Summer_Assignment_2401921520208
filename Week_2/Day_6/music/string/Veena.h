#ifndef VEENA_H
#define VEENA_H

#include "../Playable.h"
#include <iostream>

namespace music {
    namespace string_instruments {

        class Veena : public Playable {
        public:
            void play() override {
                std::cout << "Playing Veena" << std::endl;
            }
        };

    }
}

#endif