// ==================================================================
// VARIABLES
// ==================================================================
// configurables
int light_sensitivity = 100;
int timer_exclusion_period = 2000; // ms

// globals
int laps = 20;
int race_winner = 0;
long race_start_time = 0;
bool race_started = false;
int screen_write_delay = 0;
String serial_input;

// char array to print to the screen
char baseline_lightSensorPrintout[4];
char current_lightSensorPrintout[4];
char baseline_irSensorPrintout[5];
char current_irSensorPrintout[5];
char lapTimerPrintout1[5];
char lapTimerPrintout2[5];
char lapTimerPrintoutSegment[6];
char bestLapPrintout1[5];
char bestLapPrintout2[5];
char raceTimerPrintout1[5];
char raceTimerPrintout2[5];
char lapPrintout1[2];
char lapPrintout2[2];

// ==================================================================
// CLASSES
// ==================================================================
class Racer {
  private:
    void updateSegmentDisplay(long lap_time) {
      int i_lap_timer = (int) lap_time / 10;
      int i_lapTimerPrintoutSegment[5];
      bool double_digits = false; // if timer is over 9.99s

      lc.clearDisplay(0);

      i_lapTimerPrintoutSegment[0] = i_lap_timer % 10;
      i_lapTimerPrintoutSegment[1] = (i_lap_timer / 10) % 10;
      i_lapTimerPrintoutSegment[2] = (i_lap_timer / 100) % 10;

      lc.setDigit(0, 0, i_lapTimerPrintoutSegment[0], false);
      lc.setDigit(0, 2, i_lapTimerPrintoutSegment[1], false);
      lc.setDigit(0, 4, i_lapTimerPrintoutSegment[2], true);

      if (i_lap_timer > 999) {
        i_lapTimerPrintoutSegment[3] = (i_lap_timer / 1000) % 10;
        lc.setDigit(0, 6, i_lapTimerPrintoutSegment[3], false);
      }
    }

    void lapComplete() {
      long lap_time = getCurrentLapTime();

      buzz(0);

      lap_times[current_lap] = lap_time;

      updateSegmentDisplay(lap_time);
      updateBestLap(lap_time);
      current_lap = current_lap + 1;

      // Check if race is over
      if (current_lap > laps) {
        race_winner = 2;
      }
    }

    void updateBestLap(long lap_time) {
      // Check if the lap time is quickest
      if (lap_time < best_lap || best_lap == 0) {
        best_lap = lap_time;
      }
    }

  public:
    int current_light = 0;
    int baseline_light = 0;
    long lap_times[20];
    long best_lap = 0;
    int current_lap = 1;
    bool winning = false;
    byte sensor_pin;
    String racer_name;

    Racer(int sensor_pin, String racer_name) {
      this->sensor_pin = sensor_pin;
      this->racer_name = racer_name;
    }

    float readSensor() {
      return analogRead(sensor_pin);
    }

    void setBaseline() {
      baseline_light = readSensor();
    }


    long getCurrentLapTime() {
      long time_up_to_lap = race_start_time;

      for (int i = 0; i < laps; i++) {
        time_up_to_lap += lap_times[i];
      }

      return millis() - time_up_to_lap;
    }

    void printResults() {
      Serial.print(racer_name);
      Serial.println("'s times:");
      Serial.print("Total Race Time: ");
      Serial.println(getRaceTime());
      Serial.println("Laps: ");

      for (int i; i < laps; i++) {
        Serial.print("Lap ");
        Serial.print(i - 1);
        Serial.print(": ");
        Serial.println(lap_times[i]);
      }
    }

    void checkBeamStatus() {
      current_light = readSensor();

      // Light beam broken and lap timer is at least 200ms
      if (
        (current_light < (baseline_light - light_sensitivity)) &&
        (getCurrentLapTime() > timer_exclusion_period)
      ) {
        lapComplete();
      }
    }

    void ping() {
      Serial.println("=====================");
      Serial.print("Racer name: ");
      Serial.println(racer_name);
      Serial.print("Current Light: ");
      Serial.println(current_light);
      Serial.print("Baseline Light: ");
      Serial.println(baseline_light);
      Serial.print("Lap Timer: ");
      Serial.println(getCurrentLapTime());
      Serial.println("=====================");
    }

    void reset() {
      current_light = 0;
      baseline_light = 0;
      best_lap = 0;
      current_lap = 1;
      winning = false;

      for (int i = 0; i < laps - 1; i++) {
        lap_times[i] = 0;
      }
    }
};

// ====== Initialise Racers
Racer racer_1(l_input, "Nik");
Racer racer_2(i_input, "Dan");

// Screen Class
