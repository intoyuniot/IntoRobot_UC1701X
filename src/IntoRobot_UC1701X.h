/*
 ******************************************************************************

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, see <http://www.gnu.org/licenses/>.

 This is a library for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 These displays use SPI to communicate, 4 or 5 pins are required to
 interface

 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!
 ********************************************************************
 */

#ifndef INTOROBOT_UC1701X_H
#define INTOROBOT_UC1701X_H


#include "Arduino.h"
#include "Adafruit_GFX.h"


#define BLACK 0
#define WHITE 1

#define LCD_WIDTH          128
#define LCD_HEIGHT         64


class IntoRobot_UC1701X : public Adafruit_GFX
{
    public:
        IntoRobot_UC1701X(int8_t CS,int8_t RST,int8_t DC,int8_t SID, int8_t SCLK);
        IntoRobot_UC1701X(int8_t CS, int8_t RST, int8_t DC);

        void begin(void);
        void set_uc1701xCursor(unsigned char column, unsigned char line);
        void clearScreen(void);
        void fullScreen(void);
        void fillScreen(unsigned char dat);
        void uc1701x_command(uint8_t c);
        void uc1701x_data(uint8_t c);

        void clearDisplay(void);
        void display();

        void coarseContrast(uint8_t contrast);
        void fineTuneContrast(uint8_t contrast);

        void drawPixel(int16_t x, int16_t y, uint16_t color);

        virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
        virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);

    private:
        int8_t _i2caddr, _vccstate, sid, sclk, dc, rst, cs;

        void fastSPIwrite(uint8_t c);

        boolean hwSPI;

        inline void drawFastVLineInternal(int16_t x, int16_t y, int16_t h, uint16_t color) __attribute__((always_inline));
        inline void drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color) __attribute__((always_inline));

};

#endif
