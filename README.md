# Source Code For Custom Mechanical Keypad with Display

![Custom Mechanical Keypad](./media/keypad.jpg "Custom Mechanical Keypad")

__Keypad using mechanical keys, Arduino Pro Micro &ILI9340 SPI Display__

Input device to improve workflow and user input without having to remember a lot of different key combinations.

__Hardware__

Mechanical Keys: [Ebay](https://www.ebay.com/sch/i.html?_from=R40&_trksid=p2334524.m570.l1313.TR10.TRC0.A0.H0.Xmechanical+switch.TRS0&_nkw=mechanical+switch&_sacat=0&LH_TitleDesc=0&_osacat=0&_odkw=mechanical+key+)
Microcontroller: Arduino Pro Micro (Ebay - different models available)
Display: Search Ebay for ILI9341

__Software__
The software running on the Arduino uses the [OneButton Library](https://github.com/mathertel/OneButton) to simply connect multiple buttons without debounce handling needed. 
At the moment the software allows multiple modes (window management, start of programms and input of special characters)
The display shows the current selected mode and the function of the keys. 

On the computer side i use [AutoHotKey](autohotkey.com)  for the command handling. 



__WIRING__
The wiring depends on the microcontroller you use and the display. For my current configuration I connected the display according to the spec sheet. Its a simple SPI connection. The reset pin is always pulled high.

The buttons are connected to one digital pin each, using the internal pullup resistor. The other pin of the mechanical buttons are all connected to ground. Pressing the button grounds the pin. This allows a design without other resistors only using the arduino microcontroller.

__Work in progress!__
