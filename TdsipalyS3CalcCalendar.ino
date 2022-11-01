#include <TFT_eSPI.h>
#include <WiFi.h>
#include "time.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

const unsigned short bright[676] PROGMEM = {
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0010 (16) pixels
  0x0000, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0020 (32) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8C51, 0x3186, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0030 (48) pixels
  0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000,  // 0x0040 (64) pixels
  0xFFFF, 0x6B6D, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0050 (80) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF79E, 0x738E, 0x0020, 0x0000, 0x0000, 0x0000,  // 0x0060 (96) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2945, 0x2965, 0x0000, 0x0000,  // 0x0070 (112) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0xFFDF, 0x6B4D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x630C, 0x0000, 0x0000, 0x0000,  // 0x0080 (128) pixels
  0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x8410, 0xFFFF, 0x2124, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFDF, 0x632C,  // 0x0090 (144) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAD55, 0xFFFF, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020,  // 0x00A0 (160) pixels
  0x0000, 0x94B2, 0xFFFF, 0x2124, 0x0000, 0x0000, 0x0000, 0x1082, 0x4228, 0x3186, 0x0000, 0x0000, 0x0000, 0x0020, 0xA534, 0xFFFF,  // 0x00B0 (176) pixels
  0x10A2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x94B2, 0xFFFF, 0x0000, 0x4228,  // 0x00C0 (192) pixels
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x0000, 0x7BEF, 0xFFFF, 0x18C3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x00D0 (208) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3186, 0x94B2, 0xFFFF, 0x8C51, 0x0020, 0x0000, 0x0000, 0x2965, 0xDEFB,  // 0x00E0 (224) pixels
  0xFFFF, 0x39E7, 0x10A2, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000,  // 0x00F0 (240) pixels
  0x0000, 0x52AA, 0xFFDF, 0x2104, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0xAD55, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0100 (256) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x6B6D, 0x0000, 0x0000, 0x0000,  // 0x0110 (272) pixels
  0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFDF, 0x9CF3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000,  // 0x0120 (288) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x4208, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x630C,  // 0x0130 (304) pixels
  0xFFDF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8C51, 0xC618, 0xB5B6, 0xBDD7, 0xA534, 0x630C, 0xEF7D,  // 0x0140 (320) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFDF, 0x0000, 0x0000, 0x2104, 0xFFFF, 0x18C3, 0xC638, 0xBDD7, 0xBDD7, 0xC638,  // 0x0150 (336) pixels
  0x2965, 0x0000, 0x0000, 0x73AE, 0xB596, 0xAD75, 0xB596, 0x94B2, 0x6B4D, 0xF79E, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF,  // 0x0160 (352) pixels
  0xFFFF, 0x0000, 0x0000, 0x10A2, 0xFFFF, 0x18E3, 0xB596, 0xB596, 0xAD55, 0xBDD7, 0x2965, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0170 (368) pixels
  0x0000, 0x0000, 0x39C7, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x632C, 0xFFDF, 0x0000,  // 0x0180 (384) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x73AE, 0x0000,  // 0x0190 (400) pixels
  0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x94B2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x01A0 (416) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4A49, 0xFFFF, 0x2945, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x01B0 (432) pixels
  0xAD75, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x01C0 (448) pixels
  0x0000, 0x39E7, 0x8430, 0xFFFF, 0x9CD3, 0x1082, 0x0000, 0x0000, 0x3186, 0xEF7D, 0xFFFF, 0x39E7, 0x18E3, 0x0000, 0x0020, 0x0000,  // 0x01D0 (464) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA534, 0xFFFF, 0x0000, 0x39C7, 0xFFDF, 0xFFFF,  // 0x01E0 (480) pixels
  0xFFFF, 0xFFDF, 0xFFFF, 0xBDD7, 0x0000, 0x7BCF, 0xFFFF, 0x2104, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x01F0 (496) pixels
  0x0000, 0x0000, 0x0000, 0xA534, 0xFFFF, 0x18E3, 0x0020, 0x0000, 0x0000, 0x0841, 0x4208, 0x2945, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0200 (512) pixels
  0x9CD3, 0xFFFF, 0x2104, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8C51, 0xFFFF, 0x18C3, 0x0000,  // 0x0210 (528) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x6B4D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x9CD3, 0xFFFF, 0x0841, 0x0000, 0x0000,  // 0x0220 (544) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2124, 0x2104, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF7BE, 0x6B6D,  // 0x0230 (560) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x52AA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000,  // 0x0240 (576) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF7BE, 0x738E, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000,  // 0x0250 (592) pixels
  0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0260 (608) pixels
  0x0000, 0x0000, 0xFFFF, 0x73AE, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0270 (624) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x2945, 0x0000, 0x0000,  // 0x0280 (640) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x0290 (656) pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 0x02A0 (672) pixels
};

const char* ntpServer = "pool.ntp.org";
long gmtOffset_sec = (3600 * 1);  //time zone * 3600 , my time zone is  +1 GMT
int daylightOffset_sec = 3600;    //default setting: daylight saving enabled 1 hour

int gmtOffset = 0;
bool gmtSetup = false;

#define gray 0xB5B6
#define blue 0x0AAD
#define orange 0xC260
#define purple 0x604D
#define green 0x1AE9

#define WIFI_SSID "xxxxxx"
#define WIFI_PASSWORLD "xxxxxxx"
#define WIFI_CONNECT_WAIT_MAX (10 * 1000)

#define daylightColor TFT_WHITE

char timeHour[3];
char timeMin[3];
char timeSec[3];
char day[3];
char month[10];
char year[5];
char timeWeekDay[10];
int dayInWeek;
String IP;
uint32_t volt;

#define left 43
#define up 44
#define down 18
#define right 17
#define a 21
#define b 16

int fromTop = 65;
int fromLeft = 10;
int boxW = 22;
int boxH = 20;
int space = 4;

int n = 4;
int m = 4;

int posX[16];
int posY[16];

int cx, cy = 0;
double n1 = 0;
double n2 = 0;
String num = "";
String calcDisplay = "";
String netDisplayMsg = "";
int operation = 0;
bool pressedOperation = false;
bool changeOperator = false;
bool firstDigit = true;
bool dPoint = false;
bool noNet = false;

char buttons[4][4] = { { '7', '4', '1', '0' }, { '8', '5', '2', '.' }, { '9', '6', '3', '=' }, { '/', '*', '-', '+' } };

String Day[7] = { "SU", "MO", "TU", "WE", "TH", "FR", "SA" };
String SDay[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
String Months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int mm[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int dayCounter = 0;
int dayInMonth = 0;
int daysInMonth = 0;
int firstDay = 0;

int db1, db2, db3, db4, db5, db6, db7, db8, db9 = 0;
int brightness = 150;

String ssidStr = "No WiFi";

void setup() {

  pinMode(15, OUTPUT);
  digitalWrite(15, 1);

  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(a, INPUT_PULLUP);
  pinMode(b, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);

  tft.init();
  tft.setRotation(1);
  tft.setSwapBytes(true);

  tft.fillScreen(TFT_BLACK);
  img.createSprite(320, 170);
  img.setTextDatum(4);
  img.setTextColor(TFT_WHITE, TFT_BLACK);

  wifi_connect();
  if (!noNet) {
    ssidStr = WiFi.SSID().c_str();

    gmtSetup = true;
    gmtSet();
  }

  ledcSetup(0, 10000, 8);
  ledcAttachPin(38, 0);
  ledcWrite(0, brightness);
}

#define color1 0x33AE  //body
#define color2 0x22CE  //number region
#define color3 0x2C8E  //buttons region
#define color4 0xA1A1  //pressed operator color

int caw = 22;
int cay = 20;
int cax = 150;
int cah = 22;

int seg = 0;
long t = 0;

void initDrawNetwork() {
  img.fillSprite(TFT_BLACK);
  img.setTextColor(TFT_WHITE, TFT_BLACK);
  img.setTextDatum(0);
  img.setTextWrap(true);
  img.drawString(netDisplayMsg, 5, 2, 2);
  img.pushSprite(0, 0);
}

void addLineNetwork(int lineNumber) {
  img.setTextWrap(true);
  img.drawString(netDisplayMsg, 5, lineNumber * 20, 2);
  img.pushSprite(0, 0);
}

void initDrawGMTset() {
  img.fillSprite(TFT_BLACK);
  img.setTextColor(TFT_WHITE, TFT_BLACK);
  img.setTextDatum(5);
  img.setFreeFont(&Orbitron_Light_32);
  if (gmtOffset > 0) {
    img.drawString("GMT +" + String(gmtOffset) + " hrs", 300, 80);
  } else if (gmtOffset == 0) {
    img.drawString("GMT " + String(gmtOffset), 300, 80);
  } else {
    img.drawString("GMT " + String(gmtOffset) + " hrs", 300, 80);
  }
  if (daylightOffset_sec == 3600) {
    img.setTextColor(TFT_WHITE, TFT_BLACK);
    img.drawString("Daylight Saving ENABLED", 300, 110, 2);
  } else if (daylightOffset_sec == 0) {
    img.setTextColor(TFT_MAROON, TFT_BLACK);
    img.drawString("(Daylight Saving Disabled)", 300, 110, 2);
  }
  img.setTextColor(TFT_WHITE, TFT_BLACK);
  img.setTextDatum(2);
  img.drawString("+ 1 hours", 320, 10, 2);
  img.setTextDatum(2);
  img.drawString("- 1 hours", 320, 140, 2);
  img.setTextDatum(0);
  img.drawString("B : Daylight Saving", 2, 135, 2);
  img.drawString("A : Set & Continue", 2, 155, 2);
  img.setTextDatum(0);
  img.drawString("SET TIMEZONE", 2, 2, 4);
  img.pushSprite(0, 0);
}

void initLoadingUI() {
  img.fillSprite(TFT_BLACK);
  img.setFreeFont(&Orbitron_Light_24);
  img.setTextColor(TFT_WHITE, TFT_BLACK);
  img.setTextDatum(4);
  img.drawString("Loading UI...", 160, 75);
  img.pushSprite(0, 0);
}

void initDraw() {

  img.fillSprite(TFT_BLACK);
  img.setTextColor(TFT_WHITE, TFT_BLACK);
  img.setTextDatum(4);
  img.drawRoundRect(2, 2, 118, 166, 5, TFT_WHITE);  ///border
  img.fillRoundRect(fromLeft, 26, 100, 24, 5, color2);
  img.setTextColor(TFT_WHITE, color3);
  for (int i = 0; i < n; i++) {
    posY[i] = fromTop + (boxH * i) + (space * i);
    for (int j = 0; j < m; j++) {
      posX[j] = fromLeft + (boxW * j) + (space * j);
      img.fillRoundRect(posX[j], posY[i], boxW, boxH, 3, color3);
      img.drawString(String(buttons[j][i]), posX[j] + boxW / 2, posY[i] + boxH / 2, 2);
    }
  }
  if (operation > 0) {
    img.drawRoundRect(fromLeft + (boxW * 3) + (space * 3) + 1, fromTop + (boxH * (operation - 1)) + (space * (operation - 1)) + 1, boxW - 2, boxH - 2, 3, color4);
    img.drawRoundRect(fromLeft + (boxW * 3) + (space * 3), fromTop + (boxH * (operation - 1)) + (space * (operation - 1)), boxW, boxH, 3, color4);
  }
  img.drawRoundRect(posX[cx], posY[cy], boxW, boxH, 3, TFT_WHITE);

  img.setTextDatum(5);
  img.setTextColor(TFT_WHITE, color2);
  if (calcDisplay.length() > 9) {
    img.drawString(calcDisplay.substring(0, 9), fromLeft + 94, 38, 2);
  } else {
    img.drawString(calcDisplay, fromLeft + 94, 38, 2);
  }

  img.setTextColor(TFT_WHITE, TFT_BLACK);
  caw = 24;
  cay = 70;
  cax = 142;
  cah = 15;

  img.setTextDatum(4);
  for (int j = 0; j < 7; j++)
    img.drawString(Day[j], cax + (j * caw), cay, 2);

  int broj = 1;
  int w = 0;
  bool started = 0;


  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 7; j++) {

      if (w == firstDay)
        started = 1;
      if (started == 1 && broj <= daysInMonth) {
        if (broj == dayInMonth)
          img.setTextColor(TFT_BLACK, TFT_WHITE);
        else
          img.setTextColor(TFT_ORANGE, TFT_BLACK);
        img.drawString(String(broj), cax + (j * caw), cay + cah + (cah * i), 2);
        broj++;
      }

      w++;
    }
  img.setTextDatum(0);
  img.setTextColor(TFT_WHITE, TFT_BLACK);
  img.setFreeFont(&Orbitron_Light_32);
  img.drawString(String(timeHour) + ":" + String(timeMin), 130, -6);
  img.setFreeFont(&Orbitron_Light_24);

  img.setTextColor(0xD399, TFT_BLACK);
  img.drawString(String(timeSec), 250, -4);

  img.setTextColor(0x35F9, TFT_BLACK);
  img.setFreeFont(&FreeSans9pt7b);
  img.drawString(String(month) + "  " + String(dayInMonth), 130, 32);

  img.setTextColor(gray, TFT_BLACK);
  img.setTextFont(0);
  ssidStr.length();
  if (ssidStr.length() > 10) {
    img.drawString("ssid: " + ssidStr.substring(0, 10), 12, 12);
  } else {
    img.drawString("ssid: " + ssidStr, 12, 12);
  }
  img.drawString("BATTERY:", 250, 34);
  img.drawString(String(volt) + " mV", 250, 46);
  img.drawRoundRect(304, 30, 12, 136, 2, TFT_SILVER);

  seg = brightness / 24;
  for (int i = 0; i < seg; i++)
    img.fillRect(308, 150 - (i * 13), 4, 11, 0x35F9);


  img.drawLine(cax - 10, cay - 10, cax + 152, cay - 10, gray);

  img.pushImage(298, 0, 26, 26, bright);
  img.pushSprite(0, 0);
}

void loop() {

  if (gmtSetup == true) {
    //button input for gmt setup operation
    if (digitalRead(b) == 0) {
      if (db9 == 0) {
        db9 = 1;
        if (daylightOffset_sec == 3600) {
          daylightOffset_sec = 0;
        } else if (daylightOffset_sec == 0) {
          daylightOffset_sec = 3600;
        }
      }
      initDrawGMTset();
    } else db9 = 0;

    if (digitalRead(14) == 0) {
      if (db7 == 0) {
        db7 = 1;
        gmtOffset++;
        initDrawGMTset();
      }
    } else db7 = 0;

    if (digitalRead(0) == 0) {
      if (db8 == 0) {
        db8 = 1;
        gmtOffset--;
        initDrawGMTset();
      }
    } else db8 = 0;

    if (digitalRead(a) == 0) {
      gmtOffset_sec = (3600 * gmtOffset);
      configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
      gmtSetup = false;
      initLoadingUI();
      delay(100);
      num = "";
      calcDisplay = "0";
      firstDigit = true;
      changeOperator = false;
      operation = 0;
      n1 = 0;
    }
  } else if (gmtSetup == false) {
    //button setup for normal operation, all original code by VolosR
    if (t + 1000 < millis()) {
      if (noNet) {
        getBatteryVoltage();
      } else {
        getLocalTime();
      }
      t = millis();
    }

    if (digitalRead(b) == 0) {
      calcDisplay = "0";
      resetCalc();
    }

    if (digitalRead(up) == 0) {
      if (db1 == 0) {
        db1 = 1;
        cy--;
      }
    } else db1 = 0;

    if (digitalRead(down) == 0) {
      if (db2 == 0) {
        db2 = 1;
        cy++;
      }
    } else db2 = 0;

    if (digitalRead(left) == 0) {
      if (db4 == 0) {
        db4 = 1;
        cx--;
      }
    } else db4 = 0;

    if (digitalRead(right) == 0) {
      if (db5 == 0) {
        db5 = 1;
        cx++;
      }
    } else db5 = 0;

    if (cx == 4)
      cx = 0;
    if (cx == -1)
      cx = 3;
    if (cy == 4)
      cy = 0;
    if (cy == -1)
      cy = 3;


    if (digitalRead(14) == 0 && brightness < 240) {
      brightness++;
      ledcSetup(0, 10000, 8);
      ledcAttachPin(38, 0);

      ledcWrite(0, brightness);
    }

    if (digitalRead(0) == 0 && brightness > 10) {
      brightness--;
      ledcSetup(0, 10000, 8);
      ledcAttachPin(38, 0);

      ledcWrite(0, brightness);
    }

    if (digitalRead(a) == 0) {
      if (db3 == 0) {
        db3 = 1;
        if (buttons[cx][cy] == '0' || buttons[cx][cy] == '1' || buttons[cx][cy] == '2' || buttons[cx][cy] == '3' || buttons[cx][cy] == '4' || buttons[cx][cy] == '5' || buttons[cx][cy] == '6' || buttons[cx][cy] == '7' || buttons[cx][cy] == '8' || buttons[cx][cy] == '9' || ((buttons[cx][cy] == '.') && (dPoint == false))) {
          if (buttons[cx][cy] == '.') {
            dPoint = true;
          }
          if (firstDigit == false) {
            calcDisplay = calcDisplay + String(buttons[cx][cy]);


          } else {
            if (buttons[cx][cy] == '.') {
              calcDisplay = "0" + String(buttons[cx][cy]);
            } else calcDisplay = String(buttons[cx][cy]);
            firstDigit = false;
            pressedOperation = false;
          }
          num = calcDisplay;
          changeOperator = false;
        }


        if (buttons[cx][cy] == '+') {
          if (changeOperator == false) {
            mathResult(operation);
            operation = 4;
            n1 = num.toDouble();
            calcDisplay = num + " +";
            firstDigit = true;
          } else {
            calcDisplay = num + " +";
            operation = 4;
          }
        }
        if (buttons[cx][cy] == '-') {
          if (changeOperator == false) {
            mathResult(operation);
            operation = 3;
            n1 = num.toDouble();
            calcDisplay = num + " -";
            firstDigit = true;
          } else {
            calcDisplay = num + " -";
            operation = 3;
          }
        }
        if (buttons[cx][cy] == '*') {
          if (changeOperator == false) {
            mathResult(operation);
            operation = 2;
            n1 = num.toDouble();
            calcDisplay = num + " *";
            firstDigit = true;
          } else {
            calcDisplay = num + " *";
            operation = 2;
          }
        }
        if (buttons[cx][cy] == '/') {
          if (changeOperator == false) {
            mathResult(operation);
            operation = 1;
            n1 = num.toDouble();
            calcDisplay = num + " /";
            firstDigit = true;
          } else {
            calcDisplay = num + " /";
            operation = 1;
          }
        }

        if (buttons[cx][cy] == '=') {
          mathResult(operation);
          n1 = num.toDouble();
          firstDigit = true;
          changeOperator = false;
          operation = 0;
        }
      }
    } else db3 = 0;

    initDraw();
  }
}

void resetCalc() {
  num = "0";
  firstDigit = true;
  changeOperator = false;
  operation = 0;
  n1 = 0;
  dPoint = false;
}

void mathResult(int operation) {
  //Operation 4: Addition
  if (operation == 4) {
    double r = n1 + num.toDouble();
    num = String(r, 8);
    n1 = num.toDouble();
    for (int x = 0; x < 8; x++) {
      if (String(n1, x).toDouble() == String(n1, 8).toDouble()) {
        num = String(r, x);
        break;
      }
      n1 = num.toDouble();
    }
    if (abs(r) > 999999999) {
      calcDisplay = "Too large";
      resetCalc();
    } else {
      calcDisplay = num;
      n1 = calcDisplay.toDouble();
    }
  }
  //Operation 3: Subtruction
  if (operation == 3) {
    double r = n1 - num.toDouble();
    num = String(r, 8);
    n1 = num.toDouble();
    for (int x = 0; x < 8; x++) {
      if (String(n1, x).toDouble() == String(n1, 8).toDouble()) {
        num = String(r, x);
        break;
      }
    }
    n1 = num.toDouble();
    if (abs(r) > 999999999) {
      calcDisplay = "Too large";
      resetCalc();
    } else
      calcDisplay = num;
  }
  //Operation 2: Multiplication
  if (operation == 2) {
    double r = n1 * num.toDouble();
    num = String(r, 8);
    n1 = num.toDouble();
    for (int x = 0; x < 8; x++) {
      if (String(n1, x).toDouble() == String(n1, 8).toDouble()) {
        num = String(r, x);
        break;
      }
    }
    n1 = num.toDouble();
    if (abs(r) > 999999999) {
      calcDisplay = "Too large";
      resetCalc();
    } else
      calcDisplay = num;
  }
  //Operation 1: Division
  if (operation == 1) {
    double r = n1 / num.toDouble();
    num = String(r, 8);
    n1 = num.toDouble();
    for (int x = 0; x < 8; x++) {
      if (String(n1, x).toDouble() == String(n1, 8).toDouble()) {
        num = String(r, x);
        break;
      }
    }
    n1 = num.toDouble();
    if (abs(r) > 999999999) {
      calcDisplay = "Too large";
      resetCalc();
    } else
      calcDisplay = num;
  }
  //Operation 0: Other, or equality without operation
  if (operation == 0) {}

  changeOperator = true;
  dPoint = false;
}

void getBatteryVoltage() {
  volt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
}

void getLocalTime() {

  volt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)) {
    return;
  }

  strftime(timeHour, 3, "%H", &timeinfo);
  strftime(timeMin, 3, "%M", &timeinfo);
  strftime(timeSec, 3, "%S", &timeinfo);


  strftime(timeWeekDay, 10, "%A", &timeinfo);


  String InWeek = String(timeWeekDay);
  for (int i = 0; i < 7; i++) {
    if (InWeek == SDay[i])
      dayInWeek = i;
  }


  strftime(day, 3, "%d", &timeinfo);
  strftime(month, 10, "%B", &timeinfo);
  strftime(year, 5, "%Y", &timeinfo);

  dayInMonth = String(day).toInt();

  for (int i = 0; i < 12; i++) {
    if (String(month) == Months[i])
      daysInMonth = mm[i];
  }

  int j = dayInWeek;
  for (int i = dayInMonth; i > 0; i--) {
    firstDay = j;
    j--;
    if (j == -1)
      j = 6;
  }
}

//Code based on Xinyuan-LilyGO T-Display-S3 factory example
void wifi_connect(void) {
  String text;
  delay(100);
  netDisplayMsg = "Attempting WiFi Connection";
  initDrawNetwork();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();
  if (n == 0) {
    netDisplayMsg = "No networks found";
    addLineNetwork(1);
    delay(1000);
  } else {
    text = n;
    text += " networks found";
    netDisplayMsg = text;
    initDrawNetwork();
    for (int i = 0; i < n; ++i) {
      text = (i + 1);
      text += ": ";
      text += WiFi.SSID(i);
      text += " (";
      text += WiFi.RSSI(i);
      text += ")";
      text += (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " \n" : "*\n";
      netDisplayMsg = text;
      addLineNetwork(i + 1);
      delay(10);
    }
  }
  delay(1000);
  text = "Connecting to ";
  text += WIFI_SSID;
  netDisplayMsg = text;
  initDrawNetwork();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORLD);
  uint32_t last_tick = millis();
  uint32_t i = 0;
  bool is_smartconfig_connect = false;
  while (WiFi.status() != WL_CONNECTED) {
    text += ".";
    netDisplayMsg = text;
    initDrawNetwork();
    delay(250);
    if (millis() - last_tick > WIFI_CONNECT_WAIT_MAX) { /* Automatically start smartconfig when connection times out */
      if (noNet) {
        break;
      }
      text = "Timed out, starting SmartConfig";
      netDisplayMsg = text;
      addLineNetwork(1);
      delay(100);
      is_smartconfig_connect = true;
      WiFi.mode(WIFI_AP_STA);
      text = "Waiting for SmartConfig....";
      netDisplayMsg = text;
      addLineNetwork(4);
      text = "B to cancel and go OFFLINE";
      netDisplayMsg = text;
      addLineNetwork(5);
      text = "Use EspTouch Apps to connect to your network";
      netDisplayMsg = text;
      addLineNetwork(2);
      WiFi.beginSmartConfig();
      while (1) {
        if (noNet) {
          break;
        } else {
          delay(100);
          if (digitalRead(b) == 0) {
            noNet = true;
          }
          if (noNet) break;
          if (WiFi.smartConfigDone()) {
            text = "\nSmartConfig Success";
            netDisplayMsg = text;
            initDrawNetwork();
            delay(1000);
            last_tick = millis();
            break;
          }
        }
      }
    }
  }
  if (!is_smartconfig_connect) {
    text = "\nCONNECTED \nIN ";
    text += millis() - last_tick;
    text += " ms\n";
    netDisplayMsg = text;
    initDrawNetwork();
  }
  initDrawNetwork();
  delay(200);
}

void gmtSet() {
  gmtOffset_sec = (3600 * gmtOffset);
  initDrawGMTset();
}
