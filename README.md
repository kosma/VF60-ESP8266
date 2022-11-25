# VF60 WiFi Driver

Minimalistic WiFi driver software for VF60.

## Connection

Use the RS-232 port, as documented [here](https://github.com/ggajoch/vf60-vfd-display).
Note that the connector on the display is RS232 voltage levels - to connect an ESP8266
you have two options:

1. Use a level shifter like MAX3232.
2. Disassemble the display and remove the internal level shifter,
   then connect the ESP8266 directly to the level shifter pads
   on the PCB.

## Configuration

Change the SSID and password at the beginning of the file. Flash using Arduino IDE.

## Usage

* `http://<display IP>/display?line1=...&line2=...` - sets display content
* `http://<display IP>/brightness?brightness=0..5` - sets display brightness

## Language support

On the HTTP side, use UTF-8.

On the display side, the text is converted to CP-852 (Polish codepage)
as that's the author's native language. To add support for more languages:

1. Add and use a function like `UTF8toCP852()` but supporting a different codepage.
2. Add and use a function line `codepage_852()` but switching the display to a different codepage.
   To find the correct invocation, use trial and error, trying different values instead of `\x07`.

Pull requests are welcome to add more language support; I won't do it because I'm lazy.

## TODO

- Show the display's IP address upon startup.
- Add more languages.
