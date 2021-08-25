//
// Created by siavash on ۲۰۲۱/۸/۱۴.
//

#ifndef CPPKLEIN_DATA_H
#define CPPKLEIN_DATA_H

#include <vector>
#include <cstdint>

class Data {
public:
    Data(int size);

    const std::vector<int8_t> &getSt() const;
    void setSt(const std::vector<int8_t> &st);
    int8_t &operator[](unsigned int i);
    int8_t getNibble(uint8_t i);
    void setNibble(uint8_t i, int8_t input);
protected:
    std::vector<int8_t> data;

};


#endif //CPPKLEIN_DATA_H
