//
// Created by siavash on ۲۰۲۱/۸/۲۶.
//

#include "Klein.h"


Klein::Klein(KleinType type, const std::vector<uint8_t> &key) : type(type), key(key), state(static_cast<uint8_t>(type)) {
    switch (type){
        case KleinType::Klein_64:
            rounds = 12;
            break;
//        case KleinType::Klein_80:
//            rounds = 16;
//            break;
//        case KleinType::Klein_96:
//            rounds = 20;
//            break;
    }
}

const std::vector<uint8_t> &Klein::encrypt(const std::vector<uint8_t> &plainText) {
    state = plainText;
    for (int i = 1; i <= rounds; ++i) {
        state = state.addRoundKey(key);
        state = state.subNibbles();
        state = state.rotateNibbles();
        state = state.mixNibble();
        key = key.keySchedule();
    }
    state = state.addRoundKey(key);
    return state.getSt();
}
