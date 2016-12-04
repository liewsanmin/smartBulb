// This #include statement was automatically added by the Particle IDE.
#include "neopixel/neopixel.h"
#define PIXEL_PIN D4
#define PIXEL_COUNT 3
#define PIXEL_TYPE WS2811
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE); // create strip to set color


//Setup some colors
int PixelColorBlue = strip.Color( 0, 0, 128);
int PixelColorRed  = strip.Color( 80, 0, 4);
int PixelColorGold = strip.Color( 60, 50, 5);
int PixelColorPink = strip.Color(199,21,133);


void setup()
{
    strip.begin(); // start the strip show
    Particle.function("mode", setMode); // creating a cloud function, taking setMode function from code
                                        // and naming that cloud funtion as mode
    turnLightOn();
}

void loop()
{}


void turnLightOn() {

        strip.setPixelColor(0, PixelColorBlue);
        strip.show();
        delay(1000);
        strip.setPixelColor(1, PixelColorRed);
        strip.show();
        delay(1000);
        strip.setPixelColor(2, PixelColorGold);
        strip.show();
        delay(1000);

        strip.setPixelColor(0, PixelColorRed);
        strip.show();
        delay(1000);
        strip.setPixelColor(1, PixelColorBlue);
        strip.show();
        delay(1000);
        strip.setPixelColor(2, PixelColorGold);
        strip.show();
        delay(1000);
        strip.setBrightness(0);
        strip.show();
}

int setMode(String input)
{
    strip.setBrightness(100);

    if (input ==  "blue")
    {
        strip.setPixelColor(0, PixelColorBlue); // set LED color to blue
        strip.show();
         return 1;
    }
    else if (input == "off")
    {
         strip.setBrightness(0);
         strip.show();
         return 1;
    }
    else if (input == "red")
    {
        strip.setPixelColor(0, PixelColorPink); // set LED color to Pink
        strip.show();
        return 1;
    }
    else if (input == "gold")
    {
        strip.setPixelColor(0, PixelColorGold); // set LED color to Pink
        strip.show();
        return 1;
    }
    else
    {
        Serial.println(input);
    }
}
