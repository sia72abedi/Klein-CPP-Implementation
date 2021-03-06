//
// Created by siavash on ۲۰۲۱/۸/۲۵.
//

#include <cstdint>
#include "State.h"

State State::addRoundKey(RoundKey k) {
    State finalSt(data.size());
    for(int i = 0; i < data.size(); i++){
        finalSt[i] = data[i] ^ k.getSt()[i];
    }
    return finalSt;
}

State State::subNibbles() {
    State finalSt(this->data.size());
    auto nibbleCount = 2 * this->data.size();
    for (int i = 0; i < nibbleCount; i++){
        finalSt.setNibble(i,sbox[this->getNibble(i)]);
    }
    return finalSt;
}

State State::rotateNibbles() {
    uint8_t stateSize = this->data.size();
    State finalSt(stateSize);
    for (int i = 0; i < stateSize; ++i) {
        uint8_t targetPosition = (i+2) % stateSize;
        finalSt[i] = data[targetPosition];
    }
    return finalSt;
}

State State::mixNibble() {
    std::vector<uint8_t> b(data.size());
    uint8_t i = 0;
    for (auto a : data) {
        auto h = a >> 7 == 1 ? 255:0;
        b[i] = a << 1;
        b[i] ^= 0x1B & h;
        i++;
    }

    State finalState(data.size());
    finalState[0] = b[0] ^ data[3] ^ data[2] ^ b[1] ^ data[1];
    finalState[1] = b[1] ^ data[0] ^ data[3] ^ b[2] ^ data[2];
    finalState[2] = b[2] ^ data[1] ^ data[0] ^ b[3] ^ data[3];
    finalState[3] = b[3] ^ data[2] ^ data[1] ^ b[0] ^ data[0];
    finalState[4] = b[4] ^ data[7] ^ data[6] ^ b[5] ^ data[5];
    finalState[5] = b[5] ^ data[4] ^ data[7] ^ b[6] ^ data[6];
    finalState[6] = b[6] ^ data[5] ^ data[4] ^ b[7] ^ data[7];
    finalState[7] = b[7] ^ data[6] ^ data[5] ^ b[4] ^ data[4];
    return finalState;
}

State::State(int size) : Data(size) {}

State::State(const std::vector<uint8_t> &data) : Data(data) {}

const State &State::operator=(const std::vector<uint8_t> &that) {
    this->data = that;
    return *this;
}