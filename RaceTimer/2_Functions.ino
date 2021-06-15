// ==================================================================
// ======================= TRIGGER BUZZER ===========================
// Triggers a sound from the buzzer
// ==================================================================
void buzz(int type) {
  int i;

  switch (type) {
    case 0:
      for (i = 0 ; i < 100; i++) {
        digitalWrite(b_output, HIGH);
        delay(1);
        digitalWrite(b_output, LOW);
        delay(1);
      }
      break;

    case 1:
      for (i = 0 ; i < 50; i++) {
        digitalWrite(b_output, HIGH);
        delay(2);
        digitalWrite(b_output, LOW);
        delay(2);
      }
      break;

    case 2:
      for (i = 0 ; i < 33; i++) {
        digitalWrite(b_output, HIGH);
        delay(3);
        digitalWrite(b_output, LOW);
        delay(3);
      }
      break;

    default:
      break;
  }
}

// ==================================================================
// ====================== CALIBRATE SENSORS =========================
// calibrate the beam sensors
// ==================================================================
void calibrateSensors() {
  Serial.println("Calibrating Sensors...");
  buzz(1);
  delay(500);

  // Turn beams on for calibration
  digitalWrite(l_output, HIGH);
  digitalWrite(i_output, HIGH);
  delay(1000);

  // Calibrate
  racer_1.setBaseline();
  racer_2.setBaseline();

  // Turn beams off again
  digitalWrite(l_output, LOW);
  digitalWrite(i_output, LOW);
  buzz(0);
  buzz(0);
}

// ==================================================================
// ======================== INITIALISE RACE =========================
// Start Race Procedure
// ==================================================================
void initialiseRace() {
  // ====== Write Startup Screen
  writeStartupScreen(true);

  // ====== Await Serial start command to begin race
  checkSerialStatus();

  //  ====== Erase Startup Screen
  writeStartupScreen(false);

  //  ====== Write race ready screen
  writeRaceStartScreen();

  //  ====== Save the race start time for future offset use
  race_start_time = millis();

  // ====== Write persistent text
  writeStaticText();

  // Give the cars time to leave the start, then turn beams on
  delay(500);
  digitalWrite(l_output, HIGH);
  digitalWrite(i_output, HIGH);
  delay(500);
}

// ==================================================================
// ======================== GET RACE TIME ===========================
// Get the race time by subtracting the start time from millis();
// ==================================================================

long getRaceTime() {
  return  millis() - race_start_time;
}

// ==================================================================
// ======================== CHECK SERIAL ============================
// Check the Serial for race start command TO BE EXPANDED
// ==================================================================
void checkSerialStatus() {
  if (!race_started) {
    Serial.println("Enter:");
    Serial.println(" - 'start' to begin race");
    Serial.println(" - 'restart' to restart race");
    Serial.println(" - 'stop' to stop race");
    Serial.println(" - 'beams_on' to turn the sensor beams on");
    Serial.println(" - 'beams_off' to turn the sensor beams off");
    Serial.println(" - 'calibrate' to re-calibrate the sensor beams");
  }

  while (!race_started) {
    while (Serial.available() && !race_started) {
      serial_input = Serial.readString();

      if (serial_input == "start\n") {
        Serial.println("Race starting!");

        race_started = true;

        break;
      } else if (serial_input == "restart\n") {
        Serial.println("Race restarting!");

        resetRace();
        initialiseRace();

        break;
      } else if (serial_input == "stop\n") {
        Serial.println("Race stopped!");

        race_started = false;
        resetRace();

        // turn beams off
        digitalWrite(i_output, LOW);
        digitalWrite(l_output, LOW);

        break;
      } else if (serial_input == "beams_on\n") {
        Serial.println("Beams ON");

        // turn beams on
        digitalWrite(i_output, HIGH);
        digitalWrite(l_output, HIGH);

        break;
      } else if (serial_input == "beams_off\n") {
        Serial.println("Beams OFF");

        // turn beams off
        digitalWrite(i_output, LOW);
        digitalWrite(l_output, LOW);

        break;
      } else if (serial_input == "calibrate\n") {
        Serial.println("Calibrating Sensors:");
        calibrateSensors();
        Serial.println("Calibrated.");

        break;
      } else {
        Serial.println("Invalid Input.");
      }
    }
  }

  race_started = false;
}

// ==================================================================
// ============================ WIN STATE ===========================
// Manage the post race functions
// ==================================================================
void winState() {
  // writeVictoryText();

  switch (race_winner) {
    case 1:
      buzz(0);
      delay(10);
      buzz(1);
      delay(10);
      buzz(0);
      delay(10);
      break;
    case 2:
      buzz(2);
      delay(10);
      buzz(0);
      delay(10);
      buzz(2);
      delay(10);
      break;
    default:
      break;
  }

  writeDynamicText(4);
  delay(10000);
  writeDynamicText(0);

  racer_1.printResults();
  racer_2.printResults();

  resetRace();
}

// ==================================================================
// =========================== CHECK RACE ===========================
// Check the race vars for the current status
// ==================================================================
void checkRaceStatus() {
  //  if (race_winner == 0) {
  //    screen_write_delay += 1;
  //
  //    if (screen_write_delay = 50) {
  //      writeDynamicText(2);
  //    } else if(screen_write_delay > 100) {
  //      writeDynamicText(0);
  //      screen_write_delay = 0;
  //    }
  //  } else {
  //    winState();
  //
  //    digitalWrite(i_output, LOW);
  //    digitalWrite(l_output, LOW);
  //
  //    checkSerialStatus();
  //  }
  if (race_winner != 0) {
    winState();

    digitalWrite(i_output, LOW);
    digitalWrite(l_output, LOW);

    checkSerialStatus();
  }
}

// ==================================================================
// ============================== RESET =============================
// Reset all race status data
// ==================================================================
void resetRace() {
  race_winner = 0;
  race_started = false;
  racer_1.reset();
  racer_2.reset();
}
