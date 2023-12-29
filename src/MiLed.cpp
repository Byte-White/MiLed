#include "Arduino.h"
#include "MiLed.h"


void MiLed::dio_write(uint8_t b)
{
  for(int i = 0;i<8;i++)
  {
      if(b & 0x80)
      {
        digitalWrite(m_datapin,HIGH);
        digitalWrite(m_datapin,LOW);
      }
      else 
      {
        PORTB |= databit;
        PORTB &= ~databit;PORTB &= ~databit;PORTB &= ~databit;PORTB &= ~databit; // 4
      }
    b<<=1;
    //delayMicroseconds(10);
  }
}

void MiLed::send(uint8_t R,uint8_t G,uint8_t B)
{
  dio_write(G);
  dio_write(R);
  dio_write(B);
  //delayMicroseconds(2);
}
void MiLed::reset()
{
  delayMicroseconds(50);
}


MiLed::MiLed(int datapin,int count)
:m_count(count)
{
  m_datapin = datapin;
  pinMode(m_datapin, OUTPUT);
  digitalWrite(m_datapin, LOW);
  
  data = malloc(sizeof(Led)*count);
  memset(data,0,sizeof(Led)*count);

  databit = digitalPinToBitMask(m_datapin);
}

Led& MiLed::operator[](unsigned int index)
{  
  return data[index];
}

void MiLed::clear()
{
  memset(data,0,sizeof(Led)*m_count);
}

void MiLed::show()
{
  noInterrupts();
  reset();
  for(int i = 0;i<m_count;i++)
  {
    send(data[i].r,data[i].g,data[i].b);
  }
  interrupts();
}