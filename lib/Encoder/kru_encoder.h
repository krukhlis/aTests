#ifndef kru_encoder_h
#define kru_encoder_h
#include "Arduino.h"
enum EncoderChange
{
  BUTTON,
  ROTATOR,
  BOTH,
  NONE
};

class KRuEncoder
{
public:
  const unsigned long interval = 100; //in order to eliminate drebezg -- we will pull every 100ms, skipping everything between.
  int encoder0Pos = 0;
  int encoder0PinALast = HIGH;
  int encoder0BtnLast = HIGH;
  int encoder0Dir = 0;
  bool hasChanged = false;
  bool clickShouldBeHandledSeparately = false;
  unsigned long previousTimeOfChangeMillis = 0; // will store last time when was updated
  EncoderChange lastChange = NONE;

  KRuEncoder(bool clickHandledSeparately);
  void update(int pinA, int pinB, int pinBtn);
};
#endif