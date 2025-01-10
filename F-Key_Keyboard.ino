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
const byte ROW_PINS[ROW_COUNT] = {2, 3, 4};
// The pins responsible for the columns in the keyboard matrix
const byte COLUMN_PINS[COLUMN_COUNT] = {5, 6, 7, 8};
// A character map to represent the keys of the keyboard. 
const char KEYBOARD_MAP[ROW_COUNT][COLUMN_COUNT] = {
    {KEY_F13, KEY_F14, KEY_F15, KEY_F16},
    {KEY_F17, KEY_F18, KEY_F19, KEY_F20},
    {KEY_F21, KEY_F22, KEY_F23, KEY_F24}
};
// The keypad that is being scanned
Keypad keyPad = Keypad(makeKeymap(KEYBOARD_MAP), ROW_PINS, COLUMN_PINS, ROW_COUNT, COLUMN_COUNT);

void setup() {
    // A check to make sure everything is functioning normally. 
    // Set pin 1 to be an input with a pullup resistor
    pinMode(1, INPUT_PULLUP);
    // If pin 1 is low, then we can assume that something has gone wrong and we should 
    // disable the keyboard input
    if (digitalRead(1) == LOW){
        // Infinite while loop to disable the device
        while(true){}
    }

    // Set the LED pin, pin 17, to an output
    pinMode(LED_BUILTIN, OUTPUT);
    // Turn off the LEDs, active low
    digitalWrite(LED_BUILTIN, HIGH);
    TXLED0;
    
    // Start emulating a keyboard connected to a computer
    Keyboard.begin();
}

void loop() {
    // Check for any active keys (up to 10 active keys)
    if (keyPad.getKeys()){
        // Scan the list of active keys
        for (int i = 0; i < LIST_MAX; i++){
            // If the current key's state has changed
            if (keyPad.key[i].stateChanged){
                // Determine the action to preform based off the key's state
                switch(keyPad.key[i].kstate){
                    case PRESSED:       // If the key was just pressed
                        // Press the key on the computer's keyboard
                        Keyboard.press(keyPad.key[i].kchar);
                        break;
                    case RELEASED:      // If the key was just released
                        // Release the key on the computer's keyboard
                        Keyboard.release(keyPad.key[i].kchar);
//                        break;
//                    case HOLD:          // If the key is being held
//                        break;
//                    case IDLE:          // If the key is currently idle
//                        
                }
            }
        }
    }
    // If there is any delay between scans of the keyboard matrix
    if (SCANNING_DELAY > 0)
        // Wait before starting the next scan of the keyboard matrix
        delay(SCANNING_DELAY);
}
