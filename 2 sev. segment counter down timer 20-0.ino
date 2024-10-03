// Pin 7segment buat digit puluhanya
const int a1 = 7;
const int b1 = 8;
const int c1 = 9;
const int d1 = 10;
const int e1 = 11;
const int f1 = 12;
const int g1 = 13;

// Pin 7segment buat digit satuannnya
const int a2 = 0;
const int b2 = 1;
const int c2 = 2;
const int d2 = 3;
const int e2 = 4;
const int f2 = 5;
const int g2 = 6;

// Countdown timer variables
int countdown = 20;  // Start countdown from 20
unsigned long previousMillis = 0;
const long interval = 1000;  // Interval for countdown (1 second)

// 7-segment digit display lookup table
int segments[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

// Function to display digits on a 7-segment display
void displayDigit(int digit, int displayPins[7]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(displayPins[i], segments[digit][i]);
  }
}

void setup() {
  // Set all segment pins as output
  int display1Pins[] = {a1, b1, c1, d1, e1, f1, g1};
  int display2Pins[] = {a2, b2, c2, d2, e2, f2, g2};
  
  for (int i = 0; i < 7; i++) {
    pinMode(display1Pins[i], OUTPUT);
    pinMode(display2Pins[i], OUTPUT);
  }

  // Initialize the display with the countdown value
  displayNumber(countdown);
}

void loop() {
  // Get current time
  unsigned long currentMillis = millis();

  // Check if 1 second has passed
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the display was updated
    previousMillis = currentMillis;

    // Decrease the countdown value
    if (countdown > 0) {
      countdown--;
    }

    // Update the display
    displayNumber(countdown);
  }
}

// Function to display a 2-digit number on both 7-segment displays
void displayNumber(int number) {
  int tens = number / 10;
  int ones = number % 10;

  int display1Pins[] = {a1, b1, c1, d1, e1, f1, g1};
  int display2Pins[] = {a2, b2, c2, d2, e2, f2, g2};

  // Display the tens digit on the first display
  displayDigit(tens, display1Pins);

  // Display the ones digit on the second display
  displayDigit(ones, display2Pins);
}
