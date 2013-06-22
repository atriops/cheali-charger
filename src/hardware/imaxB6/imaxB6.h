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
#ifndef IMAXB6_H_
#define IMAXB6_H_

#include "AnalogInputs.h"

#define LCD_LINES               2
#define LCD_COLUMNS             16

#define MAX_CHARGE_V            ANALOG_VOLT(25.300) //25.3V
#define MAX_CHARGE_I            ANALOG_AMP(5.000)   //5A
#define MAX_CHARGE_P            50000               //50W

#define MAX_DISCHARGE_P         5000                //5W
#define MAX_DISCHARGE_I         ANALOG_AMP(1.000)   //1A

#define MAX_BANANCE_CELLS       6

//1-1 correlation
#define SMPS_UPPERBOUND_VALUE     MAX_CHARGE_I
#define MAX_CALIBRATION_SMPS_VALUE ANALOG_AMP(1.500)

#define HAS_SIMPLIFIED_VB0_VB2_CIRCUIT 1

#include "LiquidCrystal.h"
#include "Multiplexer.h"
#include "Keyboard.h"
#include "Timer.h"
#include "SMPS.h"
#include "Discharger.h"
#include "Balancer.h"

class Timer;
class Discharger;
class SMPS;

extern LiquidCrystal lcd;
extern Keyboard keyboard;
extern AnalogInputs analogInputs;
extern Timer timer;
extern SMPS smps;
extern Discharger discharger;
extern Balancer balancer;

namespace hardware {
    void init();
    uint8_t getKeyPressed();
    void delay(uint16_t t);
    void setLCDBacklight(uint8_t val);
    void setBuzzer(uint16_t val);
    void setBatteryOutput(bool enable);
    void setChargerOutput(bool enable);
    void setDischargerOutput(bool enable);
    void setChargerValue(uint16_t value);
    void setDischargerValue(uint16_t value);
    void setFan(bool enable);
    void setBalancer(uint16_t balance);
    void doInterrupt();
}


#endif /* IMAXB6_H_ */