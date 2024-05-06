#include "MiLed.h"



namespace effects
{
  void pushleds(MiLed& miled, const LedColor& color, int num, int del)
  {
      int i = 0;
      int end = miled.get_count() - 1;
      while (true)
      {
          for (int j = 0; j < num; j++)
              if(i-j>=0)miled[i - j] = color;
          if (i >= num)miled[i-num] = LedColor(0);

          miled.show();

          if (i == end)
          {
              i = 0;
              end -= num;
          }
          else i++;
          if (end < 0 && i >= miled.get_count())break;
          delay(del);
      }
      miled.clear();
  }


  void sendfadeleds(MiLed& miled,LedColor color,int del)
  {
    int num = 15;
    for(int i = 0;i<miled.get_count()*1.5;i++)
    {
      //1 - count
      for(int j = 0;j<num;j++)
      {
        if(i-j>=0 && (i-j)<miled.get_count())
          miled[i-j] = color-10*j;
      }
      if(i-num>=0 && (i-num)<miled.get_count())
      miled[i-num] = LedColor(0);
      
      miled.show();
      delay(del);
    }
    miled.clear();
  }

  void pushledsrandom(MiLed& miled, int num, int del)
  {
      int i = 0;
      int end = miled.get_count() - 1;
      while (true)
      {
          for (int j = 0; j < num; j++)
              if(i-j>=0)miled[i - j] = LedColor(random(0,30),random(0,30),random(0,30));
          if (i >= num)miled[i-num] = LedColor(0);

          miled.show();

          if (i == end)
          {
              i = 0;
              end -= num;
          }
          else i++;
          if (end < 0 && i >= miled.get_count())break;
          delay(del);
      }
      miled.clear();
  }
  
  void rainbow(MiLed& miled)
  {

  }
  void rainbowpush(MiLed& miled)
  {
    LedColor colors[]
    {
      LedColor(30,0,0),
      LedColor(30,15,0),
      LedColor(30,30,0),
      LedColor(15,30,0),
      LedColor(0,30,0),
      LedColor(0,30,15),
      LedColor(0,15,30),
      LedColor(0,0,30),
      LedColor(15,0,30),
      LedColor(30,0,30)
    };
    for(int i = 0;i<miled.get_count();i++)
    {
      miled[i] = colors[i%10];
      miled.show();
      delay(20);
    }
    delay(1000);
    for(int i = miled.get_count()-1;i>=0;i--)
    {
      miled[i] = LedColor(0);
      miled.show();
      delay(20);
    }
  }

  void rainbowpushchanging(MiLed& miled)
  {
    LedColor colors[]
    {
      LedColor(30,0,0),
      LedColor(30,15,0),
      LedColor(30,30,0),
      LedColor(15,30,0),
      LedColor(0,30,0),
      LedColor(0,30,15),
      LedColor(0,15,30),
      LedColor(0,0,30),
      LedColor(15,0,30),
      LedColor(30,0,30)
    };
    for(int j = 0; j<miled.get_count();j++)
    {
      for(int i = 0;i<miled.get_count();i++)
      {
        miled[i] = colors[(i+j)%10];
        miled.show();
        if(j == 0)
        delay(20);
      }
      if(j == 0)
      delay(250);
    }
    for(int i = miled.get_count()-1;i>=0;i--)
    {
      miled[i] = LedColor(0);
      miled.show();
      delay(20);
    }
  }
  

  void gradient(MiLed& miled,LedColor color1,LedColor color2)
  {
    for(int i = 0;i<miled.get_count();i++)
    {
      miled[i] = color1/i + color2/(miled.get_count()-i);
      miled.show();
    }
  }

  void gradientmove(MiLed& miled,LedColor color1,LedColor color2)
  {
    for(int i = 0;i<miled.get_count();i++)
    miled[i] = color2;
    miled.show();
    for(int i = 0;i<miled.get_count();i++)
    {
      for(int j = 0;j<i;j++)
      {
        miled[j] = color1/j + color2/(i-j);
        miled.show();
      }
    }
    delay(500);
    miled.clear();
  }

  void gravity(MiLed& miled,const LedColor& color, int del)
  {
    for(int i = 0;i < miled.get_count();i++)
    {
      if(i>0)miled[i-1] = LedColor(0);
      miled[i] = color;
      miled.show();
      delay(del);
    }
    
    for(int i = miled.get_count();i > miled.get_count()/2;i--)
    {
      if(i<miled.get_count()-1)miled[i+1] = LedColor(0);
      miled[i] = color;
      miled.show();
      delay(del);
    }
    
    for(int i = miled.get_count()/2;i < miled.get_count();i++)
    {
      if(i>0)miled[i-1] = LedColor(0);
      miled[i] = color;
      miled.show();
      delay(del);
    }
    
    for(int i = miled.get_count();i > miled.get_count()*0.75;i--)
    {
      if(i<miled.get_count()-1)miled[i+1] = LedColor(0);
      miled[i] = color;
      miled.show();
      delay(del);
    }
    
    for(int i = miled.get_count()*0.75;i < miled.get_count();i++)
    {
      if(i>0)miled[i-1] = LedColor(0);
      miled[i] = color;
      miled.show();
      delay(del);
    }
  }

  void gravitypush(MiLed& miled,const LedColor& color, int del)
  {
    int count = miled.get_count();
    while(count > 0)
    {
      for(int i = 0;i < count;i++)
      {
        if(i>0)miled[i-1] = LedColor(0);
        miled[i] = color;
        miled.show();
        delay(del);
      }
      
      for(int i = count;i > count/2;i--)
      {
        if(i<count-1)miled[i+1] = LedColor(0);
        miled[i] = color;
        miled.show();
        delay(del);
      }
      
      for(int i = count/2;i < count;i++)
      {
        if(i>0)miled[i-1] = LedColor(0);
        miled[i] = color;
        miled.show();
        delay(del);
      }
      
      for(int i = count;i > count*0.75;i--)
      {
        if(i<count-1)miled[i+1] = LedColor(0);
        miled[i] = color;
        miled.show();
        delay(del);
      }
      
      for(int i = count*0.75;i < count;i++)
      {
        if(i>0)miled[i-1] = LedColor(0);
        miled[i] = color;
        miled.show();
        delay(del);
      }
      count--;
    }

    //clear
    for(int i = 0;i<miled.get_count();i++)
    {
      miled[i] = LedColor(0);
      miled.show();
      delay(del);
    }
  }

  void firework(MiLed& miled,int del)
  {
    for(int i = 0;i<miled.get_count()/2;i++)
    {
      if(i>0) miled[i-1] = LedColor(0);
      miled[i] = LedColor(30);
      delay(del);
      miled.show();
    }
    for(int n = 0; n<10;n++)
      for(int i = 0;i<miled.get_count()/2;i++)
      {
        if(random(0,2)==1)
        {
          miled[miled.get_count()/2+i] = LedColor(0);
          miled[miled.get_count()/2-i] = LedColor(0);
          miled.show();
        }
        else
        {
          miled[miled.get_count()/2+i] = LedColor(random(0,30),random(0,30),random(0,30));
          miled[miled.get_count()/2-i] = LedColor(random(0,30),random(0,30),random(0,30));
          miled.show();
          if(n == 0)
          delay(50);
        }
      }

    miled.clear();
    miled.show();
  }
}