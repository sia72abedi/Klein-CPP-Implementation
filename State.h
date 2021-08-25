//
// Created by siavash on ۲۰۲۱/۸/۲۵.
//

#ifndef CPPKLEIN_STATE_H
#define CPPKLEIN_STATE_H


#include "Data.h"
#include "Key.h"

class State: public Data {
private:
    const uint8_t sbox[16]={0x7,0x4,0xA,0x9,0x1,0xF,0xB,0x0,0xC,0x3,0x2,0x6,0x8,0xE,0xD,0x5};
public:
    State addRoundKey(Key k);
    State subNibbles(State s);
    State rotateNibbles();
    State mixColumn();
    State(int size);
};


#endif //CPPKLEIN_STATE_H
