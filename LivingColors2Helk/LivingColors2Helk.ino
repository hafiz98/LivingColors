//Information
//--------------------------
//Created by: Hafiz Elkilicn and Bram van Hout
//Date: 21-02-2018
//
//History
//-------------------------
//09-02-2018: Initial creation
//21-02-2018: Start Living Colors 2
//28-02-2018: Added CMY

// Globals
bool enableLog;
int colorNumberHelkBout;
int colorValueHelkBout;
int potValueHelkBout = 0;//analogRead(aiPotHelkBout);
int presetRgbHelkBout = 3;

// Pins
int aoRedLedHelkBout = 9;
int aoGreenLedHelkBout = 11;
int aoBlueLedHelkBout = 10;
int aiPotHelkBout = A0;
int diPresetCmyHelkBout = 2;
int diPresetRgbHelkBout = 3;


void initGlobals()
{
  Serial.println("init globals...");

  enableLog = true;
  colorNumberHelkBout = 0;
  colorValueHelkBout = 0;

  Serial.println("finished...");
}

void initPins()
{
  Serial.println("init pins...");

  pinMode(aiPotHelkBout, INPUT);

  pinMode(diPresetCmyHelkBout, INPUT);
  pinMode(diPresetRgbHelkBout, INPUT);

  pinMode(aoRedLedHelkBout, OUTPUT);
  pinMode(aoGreenLedHelkBout, OUTPUT);
  pinMode(aoBlueLedHelkBout, OUTPUT);

  analogWrite(aoRedLedHelkBout, 255);
  analogWrite(aoGreenLedHelkBout, 255);
  analogWrite(aoBlueLedHelkBout, 255);

  delay(500);
  Serial.println("finished...");
}

void setup()
{
  Serial.begin(115200);
  Serial.println("init...");
  initGlobals();
  initPins();

  //demoMode();
  //updateColor();

}

void loop()
{
  handlePresets();
  mixColor();
}



void debugLogging(String a_text, int a_infoType)
{
  if (enableLog == true)
  {
    switch (a_infoType)
    {
      case 0:
        Serial.println("ERROR: " + a_text);
        break;
      case 1:
        Serial.println("WARNING: " + a_text);
        break;
      case 2:
        Serial.println("INFO: " + a_text);
        break;
      default:
        Serial.println(a_text);
        break;
    }
  }
}

void demoMode()
{
  debugLogging("Entering demo mode", 2);

  colorNumberHelkBout = 0;
  colorValueHelkBout = 0;

  while (colorNumberHelkBout < 3)
  {
    colorValueHelkBout = 255;

    while (colorValueHelkBout >= 0)
    {
      updateColor();
      delay(5);
      colorValueHelkBout--;
    }

    colorValueHelkBout = 0;

    while (colorValueHelkBout < 256)
    {
      updateColor();
      delay(5);
      colorValueHelkBout++;
    }


    colorNumberHelkBout++;
  }

  debugLogging("Demo mode finished", 2);
}

void updateColor()
{
  //debugLogging("Updating color, nr:" + (String)colorNumberHelkBout + " value: " + (String)colorValueHelkBout + ".  Knop = " + diPresetCmyHelkBout, 2);
  //debugLogging("Color value: " + (String)colorValueHelkBout, 1);
 // debugLogging("Update color Started", 2);
  switch (colorNumberHelkBout)
  {
    case 0:
      analogWrite(aoRedLedHelkBout, colorValueHelkBout);
      break;

    case 1:
      analogWrite(aoGreenLedHelkBout, colorValueHelkBout);
      break;

    default:
      analogWrite(aoBlueLedHelkBout, colorValueHelkBout);
      break;
  }


  //debugLogging("Update color Finished", 2);
}


void handlePresets()
{
  if (digitalRead(diPresetCmyHelkBout) == LOW)
  {
    setCmy();
    debugLogging("CmyKnop is pressed", 2);
  delay(250);
  }
  
  if (digitalRead(diPresetRgbHelkBout) == LOW)
  {
    colorRGB();
    debugLogging("RgbKnop is pressed", 2);
      delay(250);
  }
}

void setCmy()
{
  static int m_presetCmy = 0;

  if (m_presetCmy <= 2)
  {
    m_presetCmy++;
  }
  else
  {
    m_presetCmy = 0;
  }

  switch (m_presetCmy)
  {


    case 0:
      debugLogging("case 0", 2);
      colorNumberHelkBout = 0;
      colorValueHelkBout = 255;
      updateColor();

      colorNumberHelkBout = 1;
      colorValueHelkBout = 0;
      updateColor();

      colorNumberHelkBout = 2;
      colorValueHelkBout = 0;
      updateColor();
      delay(500);
      break;

    case 1:
      debugLogging("case 1", 2);
      colorNumberHelkBout = 0;
      colorValueHelkBout = 0;
      updateColor();

      colorNumberHelkBout = 1;
      colorValueHelkBout = 255;
      updateColor();

      colorNumberHelkBout = 2;
      colorValueHelkBout = 0;
      updateColor();
      delay(500);
      break;

    case 2:
      debugLogging("case default", 2);
      colorNumberHelkBout = 0;
      colorValueHelkBout = 0;
      updateColor();

      colorNumberHelkBout = 1;
      colorValueHelkBout = 0;
      updateColor();

      colorNumberHelkBout = 2;
      colorValueHelkBout = 255;
      updateColor();
      delay(500);
      break;


  }

}

void colorRGB()
{
  //static int m_presetRgb = 0;

  if (presetRgbHelkBout <= 2)
  {
    presetRgbHelkBout++;
    debugLogging("Preset RGB = " + (String)presetRgbHelkBout, 2);
    //      colorNumberHelkBout = m_presetRgb;
    //      colorValueHelkBout = map(potValueHelkBout, 0, 1023, 0, 255);
    //      updateColor();
  }
  else
  {
    presetRgbHelkBout = 0;
  }

  //  switch(m_presetRgb)
  //  {
  //    case 0:
  //      debugLogging("case 0", 2);
  //      setRgb(255,0,0);
  //      delay(500);
  //    break;
  //
  //    case 1:
  //      debugLogging("case 1", 2);
  //      setRgb(0,255,0);
  //      delay(500);
  //    break;
  //
  //    case 2:
  //      debugLogging("case 2", 2);
  //      setRgb(0,0,255);
  //      delay(500);
  //    break;
  //
  //  }
  //
}

void mixColor()
{
  if (presetRgbHelkBout <= 2)
  {
    colorNumberHelkBout = presetRgbHelkBout;
    potValueHelkBout = analogRead(aiPotHelkBout);
    colorValueHelkBout = map(potValueHelkBout, 0, 1023, 0, 255);
    updateColor();

    debugLogging("MIX!" + (String)colorValueHelkBout, 2);
  }
}

void setRgb(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;

  analogWrite(aoRedLedHelkBout, red);
  analogWrite(aoGreenLedHelkBout, green);
  analogWrite(aoBlueLedHelkBout, blue);
}









