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

// Pins
int aoRedLedHelkBout = 11;
int aoGreenLedHelkBout = 10;
int aoBlueLedHelkBout = 9;
int aiPotHelkBout = A0;
int diPresetCmyHelkBout = 2;
int diPresetRgbHelkBout = 3;


void setup()
{
  Serial.begin(115200);
  Serial.println("init...");
  initGlobals();
  initPins();

  demoMode();
  updateColor();

}

void loop()
{
  handlePresets();
}

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

  Serial.println("finished...");
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

  while (colorNumberHelkBout < 3)
  {
    while (colorValueHelkBout < 256)
    {
      updateColor();
      colorValueHelkBout++;
    }
    while (colorValueHelkBout >= 0)
    {
      updateColor();
      delay(200);
      colorValueHelkBout--;
    }
    colorNumberHelkBout++;
  }

  debugLogging("Demo mode finished", 2);
}

void updateColor()
{
  debugLogging("Updating color", 2);
  //debugLogging("Color value: " + (String)colorValueHelkBout, 1);

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


  debugLogging("Demo mode finished", 2);
}


void handlePresets()
{
  if (digitalRead(diPresetCmyHelkBout) == LOW)
  {
    setCmy();
  }
  else if (digitalRead(diPresetRgbHelkBout) == LOW)
  {
    setRgb();
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
      colorNumberHelkBout = 0;
      colorValueHelkBout = 255;
      updateColor();
  
      colorNumberHelkBout = 1;
      colorValueHelkBout = 0;
      updateColor();
  
      colorNumberHelkBout = 2;
      colorValueHelkBout = 0;
      updateColor();
    break;
    
    case 1:
      colorNumberHelkBout = 0;
      colorValueHelkBout = 0;
      updateColor();
  
      colorNumberHelkBout = 1;
      colorValueHelkBout = 255;
      updateColor();
  
      colorNumberHelkBout = 2;
      colorValueHelkBout = 0;
      updateColor();
    break;
    
    default:
      colorNumberHelkBout = 0;
      colorValueHelkBout = 0;
      updateColor();
  
      colorNumberHelkBout = 1;
      colorValueHelkBout = 0;
      updateColor();
  
      colorNumberHelkBout = 2;
      colorValueHelkBout = 255;
      updateColor();
    break;
  }

}

void setRgb()
{

}













