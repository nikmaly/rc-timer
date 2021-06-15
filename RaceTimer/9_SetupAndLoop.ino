// ==================================================================
// MAIN SETUP
// ==================================================================
void setup() {
  // ====== Setup Serial
  Serial.begin(9600);
  Serial.println("Setting up...");

  // ====== Setup Pins
  // input
  pinMode(i_input,      INPUT);
  pinMode(l_input,      INPUT);
  // output
  pinMode(i_output,     OUTPUT);
  pinMode(l_output,     OUTPUT);
  pinMode(b_output,     OUTPUT);
  pinMode(din_output,   OUTPUT);
  pinMode(cs_output,    OUTPUT);
  pinMode(clk_output,   OUTPUT);

  // ====== Setup Screens
  TFTscreen.begin();
  Serial.println("Setup Screens");
  lc.shutdown(0, false);
  lc.setIntensity(0, 0);
  lc.clearDisplay(0);
  lc.setDigit(0, 0, 0, false);

  // ====== Calibrate Sensors
  calibrateSensors();

  // ====== Initiate Race Functions
  while (!Serial);
  initialiseRace();
}

// ==================================================================
// MAIN LOOP
// ==================================================================
void loop() {
  // ====== Check Class Status ======
  racer_1.checkBeamStatus();
  racer_2.checkBeamStatus();

  // ====== Check Race Status ======
  checkRaceStatus();

  // ====== Check Serial Status ======
  //checkSerialStatus();
}
