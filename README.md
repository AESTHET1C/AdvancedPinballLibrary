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
The *APL* API includes functions for controlling the speaker, DC motor, servo motor, 7-segment displays, and internal EEPROM. In this readme file, functions that are shared with the original TrinketPinball library are optionally labeled as *basic* functions. Additional functions are labeled as *advanced*.

`void initPinball()` – set up all necessary peripherals. It must be called as the first line of `void setup()` in every sketch that uses the library.

--

### Servo
The servo library allows for 256-position control of the servo motor with timings between 0.8 (position 0) and 2.2 ms (position 255).

#### Standard Methods
`void servoUp()` – move the servo to the up position (100 by default).

`void servoDown()` – move the servo to the down position (200 by default).

#### Advanced Methods

`void initServo(byte up, byte down)` – override up and down positions of the servo instead of using defaults.

`void setServo(byte pos)` – move the servo to the specified location (0 - 255).

### 7-segment Display
Three 7-segment displays, loaded via shift registers from left to right, allow users to display numbers and other characters on their pinball machine. By default, the decimal points are treated as part of the individual digits. By enabling *advancedDisplay* mode, the decimal points are treated independently of the digits on screen, and will override any decimal points set by the standard display functions.

#### Standard Methods
`void displayNumber(int n)` – display a number (with leading zeros). Numbers that can't fit on the display will be replaced with either "bIG" or "NEG".
TODO: Change displayNumber() capitalization

`void displayText(char text[], int delayTime)` – display an ascii string up to length 256. Displayed string is case-sensitive.

`void clearDisplay()` – clear the display.

#### Advanced Methods
`void displayBytes(byte a, byte b, byte c)` – display the three bytes given. With standard clockwise digit arrangement, byte form is `A B C D E F G dp`. See `const byte numbers[]` for example bytes.

`const byte numbers[]` – an array containing 7-segment display bytes for the digits 0 through 9.

### Speaker
Inaudible PWM allows for 256-position control of the speaker. The speaker should not be run at full volume under normal conditions. Sustained full-volume usage may result in damage to the speaker, PCB, and nearby eardrums.

#### Standard Methods
`void tone(int freq)` – play a square wave tone at the specified frequency.

`void setSpeakerVolume(byte volPercent)` – set the volume as a percent. The default volume is 50.

`void speakerOff()` – turn off the speaker.

#### Advanced Methods
`void setSpeaker(byte value)` – manually sets the PWM value of the speaker. Used for PCM audio.

### EEPROM
The library uses EEPROM to store the high score and game count. By default, these addresses are arbitrarily assigned to locations 1000 and 1010, respectively. Advanced users are welcome to the use the EEPROM library themselves at their own discretion.

#### Standard Methods
`void updateHighScore(int score)` – set the high score to `score`.

`int readHighScore()` – get the high score from EEPROM.

`void clearHighScore()` – set the high score to zero.

`void updateGameCount()` – increment the game count by 1.

`int readGameCount()` – get the game count from EEPROM.

`void clearGameCount()` – set the game count to zero.

### Motor
Ultrasonic PWM allows for 256-speed control of the DC motor. It should not be driven at full speed under normal conditions. Doing so may result in greatly reduced motor life.

#### Standard Methods
`void setMotorSpeed(int speedPercent)` – set the motor speed as a percent. Note that this function scales output according to the constant `MAX_SPEED`, i.e. `motorSpeed(100)` sets the motor speed to `MAX_SPEED`.

#### Advanced Methods
`void setMotorSpeedPWM(byte speed)` – set the motor speed directly. This function ignores `MAX_SPEED`.

### Timing
The built-in Arduino timing functions use Timer0. However, the Backglass PCB uses Timer0 to drive the speaker and motor. Therefore, this library includes a rewrite of all timing functionality to use Timer2. Functionality is identical as long as all code uses the rewritten timing functions.
