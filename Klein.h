//
// Created by siavash on ۲۰۲۱/۸/۲۶.
//

#ifndef CPPKLEIN_KLEIN_H
#define CPPKLEIN_KLEIN_H


#include "RoundKey.h"
#include "State.h"

enum class KleinType{
    Klein_64 = 8,
    Klein_80 = 10,
    Klein_96 = 12
};


class Klein {
    RoundKey key;
    State state;
    KleinType type;
    uint8_t rounds;

public:
    Klein(KleinType type, const std::vector<uint8_t> &key);
    const std::vector<uint8_t> & encrypt(const std::vector<uint8_t> &plainText);
};


#endif //CPPKLEIN_KLEIN_H
