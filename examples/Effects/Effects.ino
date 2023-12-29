// shows some effects on a led strip with 58 leds
#include "MiLed.h"

#define DATA_PIN 11

MiLed ml(DATA_PIN,58);

void setup() {

}


void loop() 
{
  effects::pushleds(ml,Led(random(30),random(30),random(30)),2);
  effects::pushleds(ml,Led(20,0,0),2,15);
  effects::sendfadeleds(ml,Led(70));
  effects::sendfadeleds(ml,Led(70));
  effects::sendfadeleds(ml,Led(70));
  effects::gradientmove(ml,Led(80,0,0),Led(0,80,0));
  effects::rainbowpushchanging(ml);
  effects::pushledsrandom(ml,1,10);
  effects::gravitypush(ml, Led(30,0,0),35);
  effects::firework(ml);
}
