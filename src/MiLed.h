#include "Arduino.h"

#ifndef MILED_H
#define MILED_H
struct Led
{
  uint8_t r,g,b;
  Led(uint8_t r,uint8_t g,uint8_t b)
  :r(r),g(g),b(b)
  {}
  Led()
  :r(0),g(0),b(0)
  {}
  Led(uint8_t all)
  :r(all),g(all),b(all)
  {}
  Led(const Led& l)
  :r(l.r),g(l.g),b(l.b)
  {}
  
  Led operator*(uint8_t d)
  {
      return Led(clamp(static_cast<int>(this->r) * d, 0, 255),
                clamp(static_cast<int>(this->g) * d, 0, 255),
                clamp(static_cast<int>(this->b) * d, 0, 255));
  }

  Led operator/(uint8_t d)
  {
      // Ensure d is not zero to avoid division by zero
      d = (d == 0) ? 1 : d;

      return Led(clamp(static_cast<int>(this->r) / d, 0, 255),
                clamp(static_cast<int>(this->g) / d, 0, 255),
                clamp(static_cast<int>(this->b) / d, 0, 255));
  }

  Led operator+(uint8_t d)
  {
      return Led(clamp(static_cast<int>(this->r) + d, 0, 255),
                clamp(static_cast<int>(this->g) + d, 0, 255),
                clamp(static_cast<int>(this->b) + d, 0, 255));
  }

  Led operator-(uint8_t d)
  {
      return Led(clamp(static_cast<int>(this->r) - d, 0, 255),
                clamp(static_cast<int>(this->g) - d, 0, 255),
                clamp(static_cast<int>(this->b) - d, 0, 255));
  }

  Led operator*(Led l)
  {
      return Led(clamp(static_cast<int>(this->r) * static_cast<int>(l.r), 0, 255),
                clamp(static_cast<int>(this->g) * static_cast<int>(l.g), 0, 255),
                clamp(static_cast<int>(this->b) * static_cast<int>(l.b), 0, 255));
  }

  Led operator/(Led l)
  {
      // Avoid division by zero
      l.r = (l.r == 0) ? 1 : l.r;
      l.g = (l.g == 0) ? 1 : l.g;
      l.b = (l.b == 0) ? 1 : l.b;

      return Led(clamp(static_cast<int>(this->r) / static_cast<int>(l.r), 0, 255),
                clamp(static_cast<int>(this->g) / static_cast<int>(l.g), 0, 255),
                clamp(static_cast<int>(this->b) / static_cast<int>(l.b), 0, 255));
  }

  Led operator+(Led l)
  {
      return Led(clamp(static_cast<int>(this->r) + static_cast<int>(l.r), 0, 255),
                clamp(static_cast<int>(this->g) + static_cast<int>(l.g), 0, 255),
                clamp(static_cast<int>(this->b) + static_cast<int>(l.b), 0, 255));
  }

  Led operator-(Led l)
  {
      return Led(clamp(static_cast<int>(this->r) - static_cast<int>(l.r), 0, 255),
                clamp(static_cast<int>(this->g) - static_cast<int>(l.g), 0, 255),
                clamp(static_cast<int>(this->b) - static_cast<int>(l.b), 0, 255));
  }

  private:
  uint8_t clamp(int value, int min_val, int max_val) {
    return (value < min_val) ? min_val : (value > max_val) ? max_val : value;
  }
};

class MiLed
{
int m_datapin;
int m_count;

uint8_t databit;

Led* data;

// data input output write
void dio_write(uint8_t b);
void send(uint8_t R,uint8_t G,uint8_t B);
void reset();

public:

Led& operator[](unsigned int index);
MiLed(int datapin,int count);
void clear();
void show();
inline int get_count()
{
  return m_count;
}
};


namespace effects
{
  void pushleds(MiLed& miled,const Led& color,int num,int del = 50);
  void sendfadeleds(MiLed& miled,Led color,int del = 50);
  void pushledsrandom(MiLed& miled,int num,int del = 50);
  
  void rainbow(MiLed& miled);
  void rainbowpush(MiLed& miled);
  void rainbowpushchanging(MiLed& miled);

  void gradient(MiLed& miled,Led color1,Led color2);
  void gradientmove(MiLed& miled,Led color1,Led color2);

  void gravity(MiLed& miled,const Led& color,int del = 50);
  void gravitypush(MiLed& miled,const Led& color,int del = 50);

  void firework(MiLed& miled,int del = 25);
  //for contribution:
  //void example(MiLed& miled,...);
}

#endif // MILED_H