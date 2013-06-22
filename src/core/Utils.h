/*
    cheali-charger - open source firmware for a variety of LiPo chargers
    Copyright (C) 2013  Paweł Stawicki. All right reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef UTILS_H_
#define UTILS_H_

#include "Hardware.h"

#define sizeOfArray(x) (sizeof(x)/sizeof((x)[0]))

#define ADD_MAX(x,v,max) (x) = (x)<(max)-(v)? (x)+(v) : (max)
#define SUB_MIN(x,v,min) (x) = (x)>(min)+(v)? (x)-(v) : (min)

bool testTintern(bool &more, AnalogInputs::ValueType off, AnalogInputs::ValueType on);
uint16_t pow10(uint8_t n);
uint8_t digits(uint16_t x);
int8_t sign(int16_t x);

void changeMaxSmart(uint16_t &v, int direc, uint16_t max);
void changeMax(uint16_t &v, int direc, uint8_t max);
void change1Max(uint16_t &v, int direc, uint8_t max);

void waitButtonPressed();
bool getCharge(uint16_t &c);

#endif /* UTILS_H_ */