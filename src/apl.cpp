/* apl.h
 *
 * Advanced API for the Eli Whitney Museum Arduino-powered pinball machine.
 * Eli Baum / Alex Tavares
 */

#include "apl.h"

/* === initPinball ===
 *
 * This function sets everything up.
 */
void initPinball()
{
	// Peripheral initiation
	initTiming();

	init7seg();
	initServo();
	initMotor();
	initSpeaker();

	// Other pins
	pinMode(BUMP_0_LED, OUTPUT);
	pinMode(BUMP_1_LED, OUTPUT);
	pinMode(BUMP_2_LED, OUTPUT);

	pinMode(BUMP_0_SENSE, INPUT_PULLUP);
	pinMode(BUMP_1_SENSE, INPUT_PULLUP);
	pinMode(BUMP_2_SENSE, INPUT_PULLUP);
	pinMode(FLIP_L_SENSE, INPUT_PULLUP);
	pinMode(FLIP_R_SENSE, INPUT_PULLUP);
	pinMode(OUT_SENSE, INPUT_PULLUP);
	pinMode(RAMP_SENSE, INPUT_PULLUP);
}
