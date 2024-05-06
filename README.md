# MiLed

MiLed is an easy-to-use Arduino library designed for programming addressable LED strips, specifically WS2812. This library simplifies the process of controlling WS2812 LED strips, allowing you to create captivating lighting effects effortlessly.

Check [MiLed's documentation](https://byte-white.github.io/miled-docs/) for more info.

## Features

- **User-Friendly Interface:** MiLed provides a straightforward  API for controlling WS2812 LED strips.

- **Effects:** The library comes with a variety of built-in effects that you can easily integrate into your projects. 

## Getting Started

1. **Installation:** Copy the `MiLed` folder into your Arduino libraries directory.

2. **Include MiLed in Your Sketch:**
```cpp
#include <MiLed.h>

#define DATA_PIN  11
#define LED_COUNT  8

MiLed ml(DATA_PIN,LED_COUNT);

void setup()
{

}

void loop()
{
    ml[0] = LedColor(30,0,0);
    ml.show();
    delay(500);
    ml[0] = LedColor(0);
    ml.show();
    delay(500);
}
```

Note: the data pin must be at PORTB
