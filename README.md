#NOTE: Unfinished API
**This libary is in active development, and is not currently in a working state.**
API calls may be renamed, and features may be missing and/or broken. Please use the *TrinketPinball* library in the meantime, which can be downloaded at <https://git.io/v6ewO>.

--

# Advanced Pinball Library
### Advanced API for the Eli Whitney Museum Arduino-powered pinball machine.
Alex Tavares / Eli Baum 2016

The *TrinketPinball* libary (from which this library is derived) serves to simplify many of the common tasks that campers can  use to control their pinball games, such as easy access to reading sensors, setting LEDs, and adjusting motor speed. The intention is to allow campers to learn useful concepts without getting bogged down with the technicalities of the Arduino system. *AdvancedPinballLibrary* (*APL*) builds upon this library, adding advanced features for campers who wish to further add to their machines' code on their own time as they become more capable programmers. Such features include speaker polyphony, extended 7-segment display access and control, and generally improved support for asynchronous operation. It is assumed that the user of this library is reasonably comfortable with coding practices, and as such, these features may be less immediately intuitive to use.

For additional help with programming and the Arduino environment, consult the documentation for the *TrinketPinball* library at <https://git.io/v6ewO>

## Installation
Download this repository as a zip file (green **Clone or download** button, then **Download ZIP**). From within the Arduino IDE, select the downloaded file with **Sketch** > **Include Library** > **Add .ZIP Library...**. To use in a sketch, select the library from **Sketch** > **Include Library**.

## API
The *APL* API includes functions for controlling the speaker, DC motor, servo motor, 7-segment displays, and internal EEPROM. In this readme file, functions that are shared with the original TrinketPinball library are labeled as *standard* functions. Additional functions are labeled as *advanced*.

**`void initPinball()`** – set up all necessary peripherals. It must be called as the first line of `void setup()` in every sketch that uses the library.

--

### Servo
The servo library allows for 256-position control of the servo motor with timings between 0.8 (position 0) and 2.2 ms (position 255).

#### Standard Functions:
**`void servoUp()`** – move the servo to the 'up' position.

**`void servoDown()`** – move the servo to the 'down' position.

**`void initServo(byte up, byte down)`** – override the default 'up' and 'down' positions of the servo. Only effects `servoUp()` and `servoDown()` functions.

**`void setServo(byte pos)`** – move the servo to the specified location (0 - 255).

### 7-segment Display
Three 7-segment displays, loaded via shift registers from left to right, allow users to display numbers and other characters on their pinball machine. By default, the decimal points are treated as part of the individual digits. By setting the mode to *ADVANCED_MODE*, the decimal points are treated independently of the digits on screen, and will override any decimal points set by the standard display functions. All functions assume a position of 0 is the left-most digit.

#### Standard Functions:
**`void displayNumber(int n)`** – display a number (with leading zeros). Numbers that can't fit on the display will be replaced with either "bIG" or "NEG".

**`void displayText(char text[], int delayTime)`** – display an ASCII string up to length 256. Displayed string is case-sensitive. Function is blocking.

**`void clearDisplay()`** – clear the entirety of the display.

**`void displayBytes(byte a, byte b, byte c)`** – display the three bytes given. With standard clockwise digit arrangement, byte form is `A B C D E F G dp`.

#### Advanced Functions:
**`void getNumberByte(int num)`** – get the byte representation of a numerical digit. Valid inputs are 0-9, inclusive. Invalid input will return a blank byte.

**`void setDisplayByte(byte a, int pos)`** – set a single digit to a custom byte.

**`void setDisplayMode(byte mode)`** – set the mode of the display. Acceptable inputs are `STANDARD_MODE` and `ADVANCED_MODE`. *STANDARD_MODE* is the default.

**`void displayDecimal(int pos)`** – turn on the decimal point at the given position. Invalid positions clear the decimal point. This function only works in *ADVANCED_MODE*.

**`void setDisplayDecimals(bool a, bool b, bool c)`** – set the three decimal points as the booleans given. This function only works in *ADVANCED_MODE*.

### Speaker
Ultrasonic PWM allows for 256-position control of the speaker. Eight independent lower-frequency oscillation channels are used to create audible sound. Waveforms should oscillate as close as possible to position 0 to reduce long-term speaker damage.

#### Standard Functions:
**`void tone(int freq)`** – play a square wave at the specified frequency. Uses channel 0.

**`void setSpeakerVolume(int volPercent)`** – set the global volume as a percent. The default volume is 50. This setting affects all oscillation channels.

**`void speakerOff()`** – turn off the speaker and disable all oscillation channels.

**`void setSpeaker(byte value)`** – manually sets the ultrasonic PWM value of the speaker, ignoring all volume settings. `speakerOff()` should be called before use. Used for PCM audio. Use caution with this function, as holding the speaker at some non-zero value may result in damage.

#### Advanced Functions:
**`void setTone(int freq, int channel)`** – set the given oscillation channel to play a square wave at the specified frequency.

**`void setChannelVolume(int volPercent)`** – set the given oscillation channel to the given volume, as a percent. The default volume is 100. This setting is used in conjunction with the global volume setting.

### EEPROM
The library uses EEPROM to store the high score and game count. By default, these addresses are arbitrarily assigned to locations 1000 and 1010, respectively. Advanced users are welcome to the use the EEPROM library themselves at their own discretion.

#### Standard Functions:
**`void updateHighScore(int score)`** – set the high score to `score`.

**`int readHighScore()`** – get the high score from EEPROM.

**`void clearHighScore()`** – set the high score to zero.

**`void updateGameCount()`** – increment the game count by 1.

**`int readGameCount()`** – get the game count from EEPROM.

**`void clearGameCount()`** – set the game count to zero.

### Motor
Ultrasonic PWM allows for 256-speed control of the DC motor. It should not be driven at full speed under normal conditions. Doing so may result in greatly reduced motor life.

#### Standard Functions:
**`void setMotorSpeed(int speedPercent)`** – set the motor speed as a percent. Note that this function scales output according to the constant `MAX_SPEED`, i.e. `motorSpeed(100)` sets the motor speed to `MAX_SPEED`.

**`void setMotorSpeedPWM(byte speed)`** – set the motor speed directly. This function ignores `MAX_SPEED`.

### Timing
The built-in Arduino timing functions use timer0. However, the Backglass PCB requires use of timer0 to drive the ultrasonic PWM of the speaker and motor. Therefore, this library includes rewrites of standard Arduino timing functions to use timer2. Functionality remains identical.

**`long millis()`** – get the number of milliseconds elapsed since program reset.

**`long micros()`** – get the number of microseconds elapsed since program reset.

**`void delay(long milliseconds)`** – halt program execution for the given number of milliseconds. Should be used sparingly.

**`void delayMicroseconds(long microseconds)`** – halt program execution for approximately the given number of microseconds. Sholud be used sparingly.
