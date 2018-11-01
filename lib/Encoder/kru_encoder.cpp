#include "kru_encoder.h"
KRuEncoder::KRuEncoder(bool clickHandledSeparately) { clickShouldBeHandledSeparately = clickHandledSeparately; }
void KRuEncoder::update(int pinA, int pinB, int pinBtn)
{
    unsigned long currentMillis = millis();
    hasChanged = false;
    lastChange = NONE;
    if (currentMillis - previousTimeOfChangeMillis < interval)
    {
        return; //TODO: This causes animated redraws for seconds
    }

    //check button
    if (encoder0BtnLast != pinBtn)
    {
        hasChanged = true;
        previousTimeOfChangeMillis = currentMillis;
        encoder0BtnLast = pinBtn;
        lastChange = BUTTON;
    }

    if (clickShouldBeHandledSeparately == true && LOW == encoder0BtnLast)
    {
        return; //click should be handled without update of the encoder value
    }

    if ((encoder0PinALast == LOW) && (pinA == HIGH))
    {
        if (pinB == LOW)
        {
            lastChange = (hasChanged) ? BOTH : ROTATOR;
            encoder0Pos--;
            hasChanged = true;
            encoder0Dir = -1;
            previousTimeOfChangeMillis = currentMillis;
        }
        else
        {
            lastChange = (hasChanged) ? BOTH : ROTATOR;
            encoder0Pos++;
            hasChanged = true;
            encoder0Dir = 1;
            previousTimeOfChangeMillis = currentMillis;
        }
    }
    encoder0PinALast = pinA;
}
