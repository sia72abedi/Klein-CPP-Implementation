//
// Created by siavash on ۲۰۲۱/۸/۲۵.
//

#ifndef CPPKLEIN_ROUNDKEY_H
#define CPPKLEIN_ROUNDKEY_H


#include "Data.h"

class RoundKey: public Data {
private:
    uint8_t round;
public:
    RoundKey(const std::vector<uint8_t> &data);

    RoundKey(int size);
    RoundKey keySchedule();
};

void shiftRightVector(std::vector<uint8_t> &vector);


#endif //CPPKLEIN_ROUNDKEY_H
