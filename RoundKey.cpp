//
// Created by siavash on ۲۰۲۱/۸/۲۵.
//

#include <algorithm>
#include "RoundKey.h"

RoundKey::RoundKey(int size) : Data(size), round(1) {}

RoundKey RoundKey::keySchedule() {
    int8_t halfSize = data.size()/2;
    std::vector<int8_t>::const_iterator first = data.begin();
    std::vector<int8_t>::const_iterator middle = data.begin() + halfSize;
    std::vector<int8_t>::const_iterator last = data.end();
    std::vector<int8_t> left(first, middle);
    std::vector<int8_t> right(middle, last);

    shiftRightVector(left);
    shiftRightVector(right);

    RoundKey finalKey(data.size());
    for (int i = 0; i < left.size(); ++i) {
        finalKey[i] = right[i];
    }
    for (int i = left.size(); i < left.size()+right.size(); ++i) {
        finalKey[i] = left[i] ^ right[i];
    }

    finalKey[3] ^= round;
    finalKey[halfSize+1] = round;//second element of the right side
    finalKey[halfSize+2] = round;//third element of the right side

    round++;

    return finalKey;
}

RoundKey::RoundKey(const std::vector<int8_t> &data) : Data(data) {}

void shiftRightVector(std::vector<int8_t> &vector){
    auto first = vector[0];
    vector.erase(vector.begin());
    vector.push_back(first);
}