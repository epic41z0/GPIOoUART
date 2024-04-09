#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 8
#define BUTTON_PIN 9

void setup() {
  // Set LED pin as output
  DDRB |= (1 << LED_PIN);
  
  // Set BUTTON pin as input with pull-up resistor enabled
  DDRB &= ~(1 << BUTTON_PIN); 
  PORTB |= (1 << BUTTON_PIN);
}

// Check if button is pressed
bool isButtonPressed() {
  return !(PINB & (1 << BUTTON_PIN));
}

// Turn on LED
void setLedOn() {
  PORTB |= (1 << LED_PIN);
}

// Turn off LED
void setLedOff() {
  PORTB &= ~(1 << LED_PIN);
}

int main() {
  // Call setup function once
  setup();
  
  bool ledState = false; // Variable to track LED state
  bool buttonState = false; // Variable to track button state
  bool prevButtonState = false; // Variable to track previous button state
  
  while (1) {
    // Check if button is pressed
    buttonState = isButtonPressed();
    
    // Check if button state has changed
    if (buttonState != prevButtonState) {
      // Toggle LED state only when button is pressed and released again
      if (buttonState == false) {
        // Toggle LED state when button is pressed and released again
        ledState = !ledState;
        
        // Turn on or off LED based on LED state
        if (ledState) {
          setLedOn(); // Turn on LED
        } else {
          setLedOff(); // Turn off LED
        }
      }
      
      // Update previous button state
      prevButtonState = buttonState;
    }

  }
  
  return 0;
}
