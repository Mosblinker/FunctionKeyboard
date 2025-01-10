/**
 * This code assumes that there are diodes in the keyboard matrix, and supports 10-key rollover.
 * Some of this code uses code from David Madison's Stream Cheap device
 * https://www.partsnotincluded.com/diy-stream-deck-mini-macro-keyboard/
 */

#include <Keypad.h>
#include <Keyboard.h>

// The amount of time to wait between scans of the keyboard matrix, in milliseconds
const unsigned long SCANNING_DELAY = 0;
// The number of rows in the keyboard matrix
const byte ROW_COUNT = 3;
// The number of columns in the keyboard matrix
const byte COLUMN_COUNT = 4;
// The pins responsible for the rows in the keyboard matrix
const byte[ROW_COUNT] ROW_PINS = {2, 3, 4};
// The pins responsible for the columns in the keyboard matrix
const byte[COLUMN_COUNT] COLUMN_PINS = {5, 6, 7, 8};
void setup() {
    // put your setup code here, to run once:

}

void loop() {
    // put your main code here, to run repeatedly:

    // If there is any delay between scans of the keyboard matrix
    if (SCANNING_DELAY > 0)
        // Wait before starting the next scan of the keyboard matrix
        delay(SCANNING_DELAY);
}
