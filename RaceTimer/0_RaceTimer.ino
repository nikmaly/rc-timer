// ==================================================================
// LIBRARIES
// ==================================================================
#include <TFT.h>
#include <SPI.h>
#include <LedControl.h>

// ==================================================================
// PIN DEFINITIONS
// ==================================================================
// ~~ Screen
#define cs          10
#define dc          8
#define rst         9

// ~~ Sensor
#define i_input     A1
#define l_input     A0

// ~~ Beams
#define l_output    6
#define i_output    7

// ~~ Buzzer
#define b_output    5

// ~~ Digit Display
#define din_output  2
#define cs_output   3
#define clk_output  4

// ==================================================================
// INITIALISATIONS
// ==================================================================
// ====== Initialise Screens
TFT TFTscreen = TFT(cs, dc, rst);
LedControl lc=LedControl(din_output, clk_output, cs_output, 1);
unsigned long delaytime=250;
