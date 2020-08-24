# Arbalet Saint Jean

Student code of [IUT de Bordeaux](http://iut.u-bordeaux.fr) for project `Arbalet Saint Jean` showcased in the hall 3 of main train station of Bordeaux, France, from 18 december, 2017.

https://vimeo.com/arbalet/saintjean

Want to see more? [arbalet-project.org](http://arbalet-project.org/)

## Libraries
Install these libs in your `$HOME/Arduino/libraries` or $HOME/sketchbook/libraries

```
https://github.com/maniacbug/StandardCplusplus
```

## Quickstart
### Connections

The project is designed for an Arduin Mega and 300 pixels of WS2801 arrangd in 15 lines and 20 columns, starting from bottom right. The LED model can easily be replaced by other LED models as long as you replace the Arduin library WS2801 by the library matching your model (WS2812B/SK6812, WS2813, ...)

1. Connect a HC05 or HC06 Bluetooth device to the pins [`Serial1` pins](https://www.arduino.cc/reference/en/language/functions/communication/serial/) of your Arduino Mega. 
2. Connect a LED strip of 300 pixels to the [SPI MOSI+SCK](https://www.arduino.cc/en/Reference/SPI) pins of your Arduino Mega

Power WS2801 with their nomial voltage (12V) and the Arduino somehow (USB or DC jack), and load the programe hereunder.

### Software: Arduino-side
Install the following libraries for Arduino:
* [Adafruit 2801](https://github.com/adafruit/Adafruit-WS2801-Library)
* [StandardCPP](https://github.com/maniacbug/StandardCplusplus)

Then upload the [sequence](https://github.com/arbalet-project/ArbaletSaintJean/tree/master/animations_autonomes/sequence) sketchbook to your Arduino 
### Software: Smartphone-side
The joystick is emulated on with an Android phone on which you can compile and install the following app [Arbalet Saint Jean](https://play.google.com/store/apps/details?id=com.arbalet.stjean).

### Note for Apple devices
No iOS app is available since iOS is not compatible with [Bluetooth SPP](https://en.wikipedia.org/wiki/List_of_Bluetooth_profiles#Serial_Port_Profile_(SPP)).
The artwork should work in iOS, though, if you replace the HC05 by a HCI-caapable chip such as [RN42](https://www.microchip.com/RN42/) and use some i0S app emulating HCI joystick on the smartphone. 
