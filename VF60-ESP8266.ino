/*
 * VF60 ESP8266 WiFi Driver
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid     = "Internet of Shit";
const char* password = "The S in IoT stands for Security";


// NOTE: The value is not a Unicode codepoint but a byte sequence.
// Generated using https://www.acc.umu.se/~saasha/charsets/?charset=cp852&charset=cp852
unsigned char UTF8toCP852(uint32_t value)
{
  switch (value) {
    case 0xc387: return 0x80;
    case 0xc3bc: return 0x81;
    case 0xc3a9: return 0x82;
    case 0xc3a2: return 0x83;
    case 0xc3a4: return 0x84;
    case 0xc5af: return 0x85;
    case 0xc487: return 0x86;
    case 0xc3a7: return 0x87;
    case 0xc582: return 0x88;
    case 0xc3ab: return 0x89;
    case 0xc590: return 0x8a;
    case 0xc591: return 0x8b;
    case 0xc3ae: return 0x8c;
    case 0xc5b9: return 0x8d;
    case 0xc384: return 0x8e;
    case 0xc486: return 0x8f;
    case 0xc389: return 0x90;
    case 0xc4b9: return 0x91;
    case 0xc4ba: return 0x92;
    case 0xc3b4: return 0x93;
    case 0xc3b6: return 0x94;
    case 0xc4bd: return 0x95;
    case 0xc4be: return 0x96;
    case 0xc59a: return 0x97;
    case 0xc59b: return 0x98;
    case 0xc396: return 0x99;
    case 0xc39c: return 0x9a;
    case 0xc5a4: return 0x9b;
    case 0xc5a5: return 0x9c;
    case 0xc581: return 0x9d;
    case 0xc397: return 0x9e;
    case 0xc48d: return 0x9f;
    case 0xc3a1: return 0xa0;
    case 0xc3ad: return 0xa1;
    case 0xc3b3: return 0xa2;
    case 0xc3ba: return 0xa3;
    case 0xc484: return 0xa4;
    case 0xc485: return 0xa5;
    case 0xc5bd: return 0xa6;
    case 0xc5be: return 0xa7;
    case 0xc498: return 0xa8;
    case 0xc499: return 0xa9;
    case 0xc2ac: return 0xaa;
    case 0xc5ba: return 0xab;
    case 0xc48c: return 0xac;
    case 0xc59f: return 0xad;
    case 0xc2ab: return 0xae;
    case 0xc2bb: return 0xaf;
    case 0xe29691: return 0xb0;
    case 0xe29692: return 0xb1;
    case 0xe29693: return 0xb2;
    case 0xe29482: return 0xb3;
    case 0xe294a4: return 0xb4;
    case 0xc381: return 0xb5;
    case 0xc382: return 0xb6;
    case 0xc49a: return 0xb7;
    case 0xc59e: return 0xb8;
    case 0xe295a3: return 0xb9;
    case 0xe29591: return 0xba;
    case 0xe29597: return 0xbb;
    case 0xe2959d: return 0xbc;
    case 0xc5bb: return 0xbd;
    case 0xc5bc: return 0xbe;
    case 0xe29490: return 0xbf;
    case 0xe29494: return 0xc0;
    case 0xe294b4: return 0xc1;
    case 0xe294ac: return 0xc2;
    case 0xe2949c: return 0xc3;
    case 0xe29480: return 0xc4;
    case 0xe294bc: return 0xc5;
    case 0xc482: return 0xc6;
    case 0xc483: return 0xc7;
    case 0xe2959a: return 0xc8;
    case 0xe29594: return 0xc9;
    case 0xe295a9: return 0xca;
    case 0xe295a6: return 0xcb;
    case 0xe295a0: return 0xcc;
    case 0xe29590: return 0xcd;
    case 0xe295ac: return 0xce;
    case 0xc2a4: return 0xcf;
    case 0xc491: return 0xd0;
    case 0xc490: return 0xd1;
    case 0xc48e: return 0xd2;
    case 0xc38b: return 0xd3;
    case 0xc48f: return 0xd4;
    case 0xc587: return 0xd5;
    case 0xc38d: return 0xd6;
    case 0xc38e: return 0xd7;
    case 0xc49b: return 0xd8;
    case 0xe29498: return 0xd9;
    case 0xe2948c: return 0xda;
    case 0xe29688: return 0xdb;
    case 0xe29684: return 0xdc;
    case 0xc5a2: return 0xdd;
    case 0xc5ae: return 0xde;
    case 0xe29680: return 0xdf;
    case 0xc393: return 0xe0;
    case 0xc39f: return 0xe1;
    case 0xc394: return 0xe2;
    case 0xc583: return 0xe3;
    case 0xc584: return 0xe4;
    case 0xc588: return 0xe5;
    case 0xc5a0: return 0xe6;
    case 0xc5a1: return 0xe7;
    case 0xc594: return 0xe8;
    case 0xc39a: return 0xe9;
    case 0xc595: return 0xea;
    case 0xc5b0: return 0xeb;
    case 0xc3bd: return 0xec;
    case 0xc39d: return 0xed;
    case 0xc5a3: return 0xee;
    case 0xc2b4: return 0xef;
    case 0xc2ad: return 0xf0;
    case 0xcb9d: return 0xf1;
    case 0xcb9b: return 0xf2;
    case 0xcb87: return 0xf3;
    case 0xcb98: return 0xf4;
    case 0xc2a7: return 0xf5;
    case 0xc3b7: return 0xf6;
    case 0xc2b8: return 0xf7;
    case 0xc2b0: return 0xf8;
    case 0xc2a8: return 0xf9;
    case 0xcb99: return 0xfa;
    case 0xc5b1: return 0xfb;
    case 0xc598: return 0xfc;
    case 0xc599: return 0xfd;
    case 0xe296a0: return 0xfe;
    case 0xc2a0: return 0xff;
    default: return '?';
  }
}

// Naive UTF8 parser based on: https://www.omarpolo.com/post/parsing-utf8.html
String UTF8toCP852(String s)
{
  unsigned char result[20+1];
  size_t len = 0;

  for (int i=0; i<s.length() && len<20; i++) {
    unsigned char c = s[i];
    // Is it ASCII?
    if ((c & 0x80) == 0) {
      result[len++] = c;
      continue;
    }
    // okay, it's a multibyte sequence
    uint32_t value;
    if ((c & 0xE0) == 0xC0) {
      // 2-byte sequence
      value = (s[i] << 8) | (s[i+1]);
      i += 1;
    } else if ((c & 0xF0) == 0xE0) {
      // 3-byte sequence
      value = (s[i] << 16) | (s[i+1] << 8) | (s[i+2]);
      i += 2;
    } else if ((c & 0xF8) == 0xF0) {
      // 4-byte sequence
      value = (s[i] << 24) | (s[i+1] << 16) | (s[i+2] << 8) | (s[i+3]);
      i += 3;
    } else {
      // this is not a UTF8 string :(
      value = 0xFFFFFFFF;
    }
    // convert the sequence of UTF8 bytes into a CP852 value
    result[len++] = UTF8toCP852(value);
  }
  // Pad to 20 bytes with spaces so the LCD is happy.
  while (len < 20) {
    result[len++] = ' ';
  }
  // Zero-terminate and return.
  result[len] = '\0';
  return String((char *) result);
}

class VF60 {
  public:
  VF60(HardwareSerial &serial):
    port(serial)
  {
  }

  void begin()
  {
    port.begin(9600);
    codepage_852();
    home();
    clear();
  }

  void clear()
  {
    port.write("\x1b[2J");
  }

  void home()
  {
    port.write("\x1b[1;1H");
  }

  void codepage_852()
  {
    port.write("\x1bt\x07");
  }

  void brightness(int level)
  {
    port.write("\x1b\\?LD");
    port.print(level);
  }

  void text(const String &line1, const String &line2)
  {
    home();
    port.write(UTF8toCP852(line1).c_str());
    port.write("\r\n");
    port.write(UTF8toCP852(line2).c_str());
  }

  private:
  HardwareSerial &port;
};


VF60 VF60(Serial);
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain",
    "VF60 WiFi Driver\r\n"
    "Usage:\r\n"
    "GET /display?line1=...&line2=... (use UTF-8 encoding)\r\n"
    "GET /brightness?level=0..5\r\n"
  );
}

void handleDisplay() {
  String line1 = server.arg("line1");
  String line2 = server.arg("line2");
  if (!line1) line1 = String();
  if (!line2) line2 = String();
  VF60.text(line1, line2);
  server.send(200, "text/plain", "OK");
}

void handleBrightness() {
  String levelStr = server.arg("level");
  if (levelStr) {
    int level = levelStr.toInt();
    VF60.brightness(level);
  }
  server.send(200, "text/plain", "OK");
}

void setup()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    delay(1000);
    VF60.begin();
    VF60.text(String("12345678901234567890"), String("Zażółć Gęślą Jaźń"));
    delay(1000);
    VF60.clear();

    server.on("/", handleRoot);
    server.on("/display", handleDisplay);
    server.on("/brightness", handleBrightness);
    server.begin();
}

void loop()
{
  server.handleClient();
  delay(2);
}
