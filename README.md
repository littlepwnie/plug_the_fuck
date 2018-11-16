# plug_the_fuck
HID exploitation framework through arduino for Red Teamers

A framework for automating the script generation so BadUsb’s, various types of Arduino's and clones can be used by Red Teamers in
the field at any time to serve payloads quickly through physical access.

The concept is fairly simple. There is an increasing collection of payloads both for Windows and Linux targets with some standard 
options available to be set for each payload. The user chooses what suits for its job, sets the values of the parameters and 
generates an .ino file, ready to be loaded to a compatible Arduino board, either through Arduino IDE or the command line.

The tests were carried out on an ATmega32U4. The framework and the scripts generated were tested in both Linux and Windows 
environments. NOT ALL SCRIPTS ARE GUARANTEED TO WORK. Different environments sometimes lead to different key shortcuts and the 
target's performance may affect the script timers.

# Windows
```
git clone -b Windows git@github.com:littlepwnie/plug_the_fuck.git
```
Or: download all files from Master and delete "Linux"

Run the executable either by double-clicking on it or through the cmd by its name. No arguments needed.
The folder "source" contains the source code in single .cpp file and Visual Studio project if you wish to compile it yourselves.
Some users may experience issues with the font colours !

# Linux
```
git clone -b Linux git@github.com:littlepwnie/plug_the_fuck.git
```
Or: download all files from Master and delete "Windows"

The folder "source" contains the source code in single .cpp file if you wish to compile it yourselves.
To execute:
```
cd </path/to/the/Linux>
./plug_the_f@ck
```

# TODO

- Automatic compilation and upload to the desired board.
- Add more payloads
- Improve the code so someone can easily add their own payloads and have them accessible without changing the source code.

Feel free to help improve it and ask any questions!
HAPPY HUNTING :D
