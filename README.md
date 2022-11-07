# TdsipalyS3CalcCalendar
Changelog v1.5
Shut down function added. A/B caption added to calculator.

Changelog v1.4
Ability to cancel SmartConfig and start the app at offline mode.

Changelog v1.32
Fixed decimal place accuracy to more than 2 decimal places by changing Floats to Doubles.

Changelog v1.31
Single Decimal point allowed. User can't input numbers of the following format 3...2 or 2.5.6

Changelog v1.3
Custom GMT setting.

Changelog v1.2
SmartConfig added.

Changelog v1.1
Correct calculator behavior.
Changes on calculator display.
Calculator header shows SSID.

Demo app with Calculator and Calendar for Lilygo T-display S3.
The board used for this project is Lilygo T-display S3 (ESP32-S3 with a screen)
Custom TFT-eSPI library is needed and can be found on Lilygo github,
along with instructions on how to config this board on Arduino IDE.

This version (v1.5) has a complete working calculator where each operator
calculates and displays the previous result and then waits for new operation.
The operator is being displayed on screen so we know what has been pressed.
Pressing a new operator after pressing another operator continues to display
the correct result, along with the latest operator pressed.

The header of the calculator displays the WiFi SSID. The caption says what A / B buttons do.

SmartConfig deployed, and can be cancelled with button B. The default connection 
settings are on lines #66-#67. If connection can't be established with the hardcoded 
credentials, you can set SSID and WiFi password by loading the EspTouch or SmartConnect 
app on your mobile phone while T-display is on SmartConfig mode.
The new SSID and password will be broadcast to the ESP32 board and attempt
a new connection.

GMT isn't hardcoded and can be set on boot. Use + and - buttons 
(on board -> "key" and "bot" buttons) to change GMT offset.

Shutdown function works on calculator screen. Multiclick function monitors B button for
3 or more consecutive button clicks and calls deep sleep. B button wakes up the board.

This code uses Lilygo T-display S3 and gamer board by PCBWay.
Button pins for gamer board are defined on lines #83-#88.

You can watch the original video for this board and video here:
https://www.youtube.com/watch?v=50uPv7tsVIc&t=1s

Original work is made by VolosR.
WiFi SmartConfig code is based on Xinyuan-LilyGO T-Display-S3 factory example.
