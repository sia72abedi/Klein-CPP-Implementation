//
// Created by siavash on ۲۰۲۱/۸/۲۵.
//

#include <algorithm>
#include <iostream>
#include "RoundKey.h"

RoundKey::RoundKey(int size) : Data{size}, round{1} {}

RoundKey RoundKey::keySchedule() {
    uint8_t halfSize = data.size()/2;
    std::vector<uint8_t>::const_iterator first = data.begin();
    std::vector<uint8_t>::const_iterator middle = data.begin() + halfSize;
    std::vector<uint8_t>::const_iterator last = data.end();
    std::vector<uint8_t> left(first, middle);
    std::vector<uint8_t> right(middle, last);

    shiftRightVector(left);
    shiftRightVector(right);

    RoundKey finalKey(data.size());
    for (int i = 0; i < left.size(); ++i) {
        finalKey[i] = right[i];
    }
    for (int i = 0; i < halfSize; ++i) {
        auto j = i + halfSize;
        finalKey[j] = left.at(i) ^ right.at(i);
    }

    finalKey[2] ^= round;//the third byte of MSB(4byte)
    auto secondByteFirstNibbleIndex = 2*(halfSize + 1);//second byte of the LSB side, first nibble
    auto secondByteSecondNibbleIndex = 2*(halfSize + 1) + 1;//second byte of the LSB side, second nibble
    finalKey.setNibble(secondByteFirstNibbleIndex,Data::sbox[finalKey.getNibble(secondByteFirstNibbleIndex)]);
    finalKey.setNibble(secondByteSecondNibbleIndex,Data::sbox[finalKey.getNibble(secondByteSecondNibbleIndex)]);
    auto thirdByteFirstNibbleIndex = 2*(halfSize + 2);//third byte of the LSB side, first nibble
    auto thirdByteSecondNibbleIndex = 2*(halfSize + 2) + 1;//third byte of the LSB side, second nibble
    finalKey.setNibble(thirdByteFirstNibbleIndex,Data::sbox[finalKey.getNibble(thirdByteFirstNibbleIndex)]);
    finalKey.setNibble(thirdByteSecondNibbleIndex,Data::sbox[finalKey.getNibble(thirdByteSecondNibbleIndex)]);

    finalKey.round = round+1;

    return finalKey;
}

RoundKey::RoundKey(const std::vector<uint8_t> &data) : Data{data},round{1} {}

void shiftRightVector(std::vector<uint8_t> &vector){
    auto first = vector[0];
    vector.erase(vector.begin());
    vector.push_back(first);
}