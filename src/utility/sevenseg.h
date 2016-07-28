/* sevenseg.h
 *
 * Library for Eli Whitney Arduino camp 2016
 * Eli Baum
 */

#ifndef sevenseg_h
#define sevenseg_h

#include <Arduino.h>

#define SR_DDR		DDRD
#define SR_PORT		PORTD
#define DATA_PIN	4
#define CLOCK_PIN	3

#define N_DIGITS 3

const byte numbers[] =
{
	B11111100,
	B01100000,
	B11011010,
	B11110010,
	B01100110,
	B10110110,
	B10111110,
	B11100000,
	B11111110,
	B11110110
};

const byte ascii33[] =
{
	B01100001,
	B01000100,
	B10000010,
	B10010010,
	B01001011,
	B01100010,
	B00000100,
	B10010100,
	B11010000,
	B10000100,
	B00001110,
	B00001000,
	B00000010,
	B00000001,
	B01001010,
	B11111100,
	B01100000,
	B11011010,
	B11110010,
	B01100110,
	B10110110,
	B10111110,
	B11100000,
	B11111110,
	B11110110,
	B10010000,
	B10110000,
	B10000110,
	B00010010,
	B11000010,
	B11001010,
	B11111010,
	B11101110,
	B11111110,
	B10011100,
	B01111010,
	B10011110,
	B10001110,
	B10111100,
	B01101110,
	B00001100,
	B01111000,
	B10101110,
	B00011100,
	B10101000,
	B11101100,
	B11111100,
	B11001110,
	B11010110,
	B11001100,
	B10110110,
	B00011110,
	B01111100,
	B01111100,
	B01010100,
	B01101110,
	B01110110,
	B11011010,
	B00111100,
	B00100110,
	B01101100,
	B11000100,
	B00010000,
	B01000000,
	B11111010,
	B00111110,
	B00011010,
	B01111010,
	B11011110,
	B10001110,
	B11110110,
	B00101110,
	B00001000,
	B00110000,
	B10101110,
	B00001100,
	B00101000,
	B00101010,
	B00111010,
	B11001110,
	B11100110,
	B00001010,
	B10110110,
	B00011110,
	B00111000,
	B00111000,
	B00101000,
	B01101110,
	B01110110,
	B11011010,
	B10010110,
	B10101010,
	B11000110,
	B10000000,
	0
};

void init7seg();

void displayNumber(int n);
void displayBytes(byte a, byte b, byte c);
void displayString(char text[], int delayTime);
void clearDisplay();

#endif