## Overview
Wakeup is an Arduino project to keep your PC power on with ethernet.
![photo](images/photo.jpg)

## How to make it work
1. Make sure your PC network card supports WOL and enabled WOL in BIOS.
2. You need an Arduino board with Ethernet module.
3. Replace the Target MAC address in source code with your PC network card MAC address. Then download the code to your Arduino board.
![code](images/code.jpg)
4. Connect your Arduino board to the router.
5. Then it works, Arduino will send a "magic package" to your PC every 10 secs and keep it power off.
