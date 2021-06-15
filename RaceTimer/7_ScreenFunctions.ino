// ==================================================================
// ====================== CHANGE STROKE COLOR =======================
// Change the current screen stroke color
// ==================================================================
void screenStrokeColor(int code) {
  /*   COLOR MAPPING::
    Black = 0
    White = 1
    Grey = 2
    Red = 3
    Green = 4
    Blue = 5
    Yellow = 6
  */
  switch (code) {
    case 0:
      TFTscreen.stroke(0, 0, 0);
      break;
    case 1:
      TFTscreen.stroke(255, 255, 255);
      break;
    case 2:
      TFTscreen.stroke(150, 150, 150);
      break;
    case 3:
      TFTscreen.stroke(255, 0, 0);
      break;
    case 4:
      TFTscreen.stroke(0, 255, 0);
      break;
    case 5:
      TFTscreen.stroke(0, 0, 255);
      break;
    case 6:
      TFTscreen.stroke(255, 200, 0);
      break;
    default:
      TFTscreen.stroke(255, 255, 255);
      break;
  }
}

// ==================================================================
// ======================== CHANGE FILL COLOR =======================
// Change the current screen fill color
// ==================================================================
void screenFillColor(int code) {
  /*   COLOR MAPPING::
    Black = 0
    White = 1
    Grey = 2
    Red = 3
    Green = 4
    Blue = 5
    Yellow = 6
  */
  switch (code) {
    case 0:
      TFTscreen.fill(0, 0, 0);
      break;
    case 1:
      TFTscreen.fill(255, 255, 255);
      break;
    case 2:
      TFTscreen.fill(150, 150, 150);
      break;
    case 3:
      TFTscreen.fill(200, 30, 0);
      break;
    case 4:
      TFTscreen.fill(0, 255, 0);
      break;
    case 5:
      TFTscreen.fill(0, 0, 255);
      break;
    case 6:
      TFTscreen.fill(255, 200, 0);
      break;
    default:
      TFTscreen.fill(255, 255, 255);
      break;
  }
}

// ==================================================================
// ====================== WRITE STARTUP SCREEN ======================
// Write the startup screen
// ==================================================================
void writeStartupScreen(bool draw) {
  // Set draw or erase
  if (draw) {
    screenStrokeColor(1);
    screenFillColor(1);
  } else {
    screenStrokeColor(0);
    screenFillColor(0);
  }

  // Clear background
  TFTscreen.background(0, 0, 0);

  // Write Welcome Text
  TFTscreen.setTextSize(2);
  TFTscreen.text("RACE TIMER", 3, 15);

  // Write squares
  // Row 1
  TFTscreen.rect(0, 40, 10, 10);
  TFTscreen.rect(20, 40, 10, 10);
  TFTscreen.rect(40, 40, 10, 10);
  TFTscreen.rect(60, 40, 10, 10);
  TFTscreen.rect(80, 40, 10, 10);
  TFTscreen.rect(100, 40, 10, 10);
  TFTscreen.rect(120, 40, 10, 10);

  // Row 2
  TFTscreen.rect(10, 50, 10, 10);
  TFTscreen.rect(30, 50, 10, 10);
  TFTscreen.rect(50, 50, 10, 10);
  TFTscreen.rect(70, 50, 10, 10);
  TFTscreen.rect(90, 50, 10, 10);
  TFTscreen.rect(110, 50, 10, 10);

  // Row 3
  TFTscreen.rect(0, 60, 10, 10);
  TFTscreen.rect(20, 60, 10, 10);
  TFTscreen.rect(40, 60, 10, 10);
  TFTscreen.rect(60, 60, 10, 10);
  TFTscreen.rect(80, 60, 10, 10);
  TFTscreen.rect(100, 60, 10, 10);
  TFTscreen.rect(120, 60, 10, 10);

  // Row 4
  TFTscreen.rect(10, 70, 10, 10);
  TFTscreen.rect(30, 70, 10, 10);
  TFTscreen.rect(50, 70, 10, 10);
  TFTscreen.rect(70, 70, 10, 10);
  TFTscreen.rect(90, 70, 10, 10);
  TFTscreen.rect(110, 70, 10, 10);

  // Row 5
  TFTscreen.rect(0, 80, 10, 10);
  TFTscreen.rect(20, 80, 10, 10);
  TFTscreen.rect(40, 80, 10, 10);
  TFTscreen.rect(60, 80, 10, 10);
  TFTscreen.rect(80, 80, 10, 10);
  TFTscreen.rect(100, 80, 10, 10);
  TFTscreen.rect(120, 80, 10, 10);

  // Row 6
  TFTscreen.rect(10, 90, 10, 10);
  TFTscreen.rect(30, 90, 10, 10);
  TFTscreen.rect(50, 90, 10, 10);
  TFTscreen.rect(70, 90, 10, 10);
  TFTscreen.rect(90, 90, 10, 10);
  TFTscreen.rect(110, 90, 10, 10);

  // Row 7
  TFTscreen.rect(0, 100, 10, 10);
  TFTscreen.rect(20, 100, 10, 10);
  TFTscreen.rect(40, 100, 10, 10);
  TFTscreen.rect(60, 100, 10, 10);
  TFTscreen.rect(80, 100, 10, 10);
  TFTscreen.rect(100, 100, 10, 10);
  TFTscreen.rect(120, 100, 10, 10);
}

// ==================================================================
// ======================== WRITE WIN SCREEN ========================
// Write the startup screen
// ==================================================================
void writeWinScreen() {

}

// ==================================================================
// ==================== WRITE RACE START SCREEN =====================
// Write the startup screen
// ==================================================================
void writeRaceStartScreen() {
  TFTscreen.setTextSize(5);

  //  Write "3"
  Serial.println("3");
  screenStrokeColor(1);
  TFTscreen.text("3", 54, 45);
  lc.setDigit(0, 0, 3, false);
  buzz(1);
  buzz(1);
  delay(1200);
  screenStrokeColor(0);
  TFTscreen.text("3", 54, 45);
  lc.clearDisplay(0);
  delay(200);

  //  Write "2"
  Serial.println("2");
  screenStrokeColor(1);
  TFTscreen.text("2", 54, 45);
  lc.setDigit(0, 0, 2, false);
  buzz(1);
  buzz(1);
  delay(1200);
  screenStrokeColor(0);
  TFTscreen.text("2", 54, 45);
  lc.clearDisplay(0);
  delay(200);

  //  Write "1"
  Serial.println("1");
  screenStrokeColor(1);
  TFTscreen.text("1", 54, 45);
  lc.setDigit(0, 0, 1, false);
  buzz(1);
  buzz(1);
  delay(1200);
  screenStrokeColor(0);
  TFTscreen.text("1", 54, 45);
  lc.clearDisplay(0);
  delay(200);

  //  Write "Go"
  Serial.println("Go!");
  screenStrokeColor(1);
  TFTscreen.text("Go!", 26, 45);
  lc.setDigit(0, 0, 0, false);
  buzz(0);
  buzz(0);
  buzz(0);
  delay(2000);
  screenStrokeColor(0);
  TFTscreen.text("Go!", 26, 45);
  lc.clearDisplay(0);
}

// ==================================================================
// ======================== WRITE STATIC TEXT =======================
// Write the static text that will persist across loops to the screen
// ==================================================================
void writeStaticText() {
  //  Baseline Sensor Setup
  String irBaseline_str = String(racer_1.baseline_light);
  String lightBaseline_str = String(racer_2.baseline_light);
  irBaseline_str.toCharArray(baseline_irSensorPrintout, 5);
  lightBaseline_str.toCharArray(baseline_lightSensorPrintout, 4);

  // Clear background
  TFTscreen.background(0, 0, 0);

  // Write IR Text
  TFTscreen.setTextSize(2);
  screenStrokeColor(3);
  TFTscreen.text("R1", 0, 0);

  TFTscreen.setTextSize(1);
  screenStrokeColor(1);
  TFTscreen.text("Laps:", 0, 20);
  TFTscreen.text("Lap Time:", 0, 30);
  TFTscreen.text("Best Lap:", 0, 40);
  TFTscreen.text("Race Time:", 0, 50);

  TFTscreen.setTextSize(1);
  screenStrokeColor(1);
  TFTscreen.text("Base:", 70, 0);
  TFTscreen.text(baseline_irSensorPrintout, 105, 0);
  TFTscreen.text("Crnt:", 70, 10);

  // Write Light Text
  TFTscreen.setTextSize(2);
  screenStrokeColor(6);
  TFTscreen.text("R2", 0, 70);

  TFTscreen.setTextSize(1);
  screenStrokeColor(1);
  TFTscreen.text("Laps:", 0, 90);
  TFTscreen.text("Lap Time:", 0, 100);
  TFTscreen.text("Best Lap:", 0, 110);
  TFTscreen.text("Race Time:", 0, 120);

  TFTscreen.setTextSize(1);
  screenStrokeColor(1);
  TFTscreen.text("Base:", 70, 70);
  TFTscreen.text(baseline_lightSensorPrintout, 105, 70);
  TFTscreen.text("Crnt:", 70, 80);
}

// ==================================================================
// ===================== WRITE DYNAMIC TEXT =========================
// Write the sensor output that changes every loop
// ==================================================================
void writeDynamicText(int color) {
  String irCurrent_str = String(racer_1.current_light);
  String lightCurrent_str = String(racer_2.current_light);
  String lap_timer_str1 = String(racer_1.getCurrentLapTime() / 10);
  String lap_timer_str2 = String(racer_2.getCurrentLapTime() / 10);
  String best_lap_str1 = String(racer_1.best_lap / 10);
  String best_lap_str2 = String(racer_2.best_lap / 10);
  String race_timer_str1 = String(getRaceTime() / 10);
  String race_timer_str2 = String(getRaceTime() / 10);
  String lap_str1 = String(racer_1.current_lap);
  String lap_str2 = String(racer_2.current_lap);

  // convert the reading to a char array
  irCurrent_str.toCharArray(current_irSensorPrintout, 5);
  lightCurrent_str.toCharArray(current_lightSensorPrintout, 4);
  lap_str1.toCharArray(lapPrintout1, 2);
  lap_str2.toCharArray(lapPrintout2, 2);
  lap_timer_str1.toCharArray(lapTimerPrintout1, 5);
  lap_timer_str2.toCharArray(lapTimerPrintout2, 5);
  best_lap_str1.toCharArray(bestLapPrintout1, 5);
  best_lap_str2.toCharArray(bestLapPrintout2, 5);
  race_timer_str1.toCharArray(raceTimerPrintout1, 5);
  race_timer_str2.toCharArray(raceTimerPrintout2, 5);

  screenStrokeColor(color);

  // print the sensor values
  TFTscreen.setTextSize(1);
  TFTscreen.text(current_irSensorPrintout, 105, 10);
  TFTscreen.text(current_lightSensorPrintout, 105, 80);

  // print the lap values
  TFTscreen.setTextSize(1);
  TFTscreen.text(lapPrintout1, 80, 20);
  TFTscreen.text(lapPrintout2, 80, 90);

  // print the timer values
  TFTscreen.setTextSize(1);
  TFTscreen.text(lapTimerPrintout1, 80, 30);
  TFTscreen.text(bestLapPrintout1, 80, 40);
  TFTscreen.text(raceTimerPrintout1, 80, 50);
  TFTscreen.text(lapTimerPrintout2, 80, 100);
  TFTscreen.text(bestLapPrintout2, 80, 110);
  TFTscreen.text(raceTimerPrintout2, 80, 120);
}
