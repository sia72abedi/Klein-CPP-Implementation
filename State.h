//
// Created by siavash on ۲۰۲۱/۸/۲۵.
//

#ifndef CPPKLEIN_STATE_H
#define CPPKLEIN_STATE_H


#include "Data.h"
#include "RoundKey.h"

class State: public Data {
public:
    State addRoundKey(RoundKey k);
    State subNibbles();
    State rotateNibbles();
    State mixNibble();
    State(int size);

    State(const std::vector<uint8_t> &data);
    const State &operator=(const std::vector<uint8_t> &that);
};


#endif //CPPKLEIN_STATE_H
