#ifndef SAXOPHONE_H
#define SAXOPHONE_H

#include "../Playable.h"
#include <iostream>

namespace music {
    namespace wind {

        class Saxophone : public Playable {
        public:
            void play() override {
                std::cout << "Playing Saxophone" << std::endl;
            }
        };

    }
}

#endif