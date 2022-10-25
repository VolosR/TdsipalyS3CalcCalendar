# TdsipalyS3CalcCalendar
Demo app with Calculator and Calendar for Lilygo T-display S3
The board used for this project is Lilygo T-display S3 (ESP32-S3 with a screen)
Custom TFT-eSPI library is needed and can be found on Lilygo github,
along with instructions on how to config this board on Arduino IDE.

This version has a complete working calculator where each operator
calculates and displays the previous result and then waits for new operation.
The operator is being displayed on screen so we know what has been pressed.
Pressing a new operator after pressing another operator continues to display
the correct result, along with the latest operator pressed.

The header of the calculator displays the WiFi SSID.
