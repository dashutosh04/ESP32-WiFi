# ESP32 WiFi Camera Server

> This project allows you to create a WiFi-connected camera server using an ESP32 board and camera module. You can view the live camera feed from your web browser on any device connected to the same local network.

## Features:

- `Easy Setup`: Simple configuration process using familiar Arduino IDE.
- `Web Interface`: Access the camera feed directly from your web browser. 
- `LED Status`: Red LED blinks during WiFi connection and stays off when connected.
## Hardware Required:

- ESP32 board
- ESP32 compatible camera module 
- Breadboard and jumper wires (for connecting components)
- Arduino UNO Board

## Software Required:

- Arduino IDE 
- esp_camera library 
- WiFi library
## Setup Instructions:

> Connect the Camera Module:

Refer to your camera module's datasheet for specific pin connections to the ESP32 board. 
> Configure WiFi Credentials:

In the code `main.ino`, replace `wifi_ssid` with your WiFi network name and `wifi_pass` with your WiFi password.
> Upload the Code:

Open the `main.ino` file in the Arduino IDE.
Select your ESP32 board and upload the code.

## Usage:

> Connect to WiFi:

The ESP32 camera server will attempt to connect to your WiFi network. You'll see the red LED blinking during this process.
> Open Web Browser:

Once connected, the serial monitor will print the local IP address of the ESP32.
Open a web browser on any device connected to the same WiFi network.
Enter the printed IP address in the address bar and press Enter.
> View Camera Feed:

You should now see the live video feed from your ESP32 camera module in the web browser window.
## Troubleshooting:

If you encounter issues connecting to WiFi, double-check your WiFi credentials and ensure your ESP32 is within range of the router.
For camera-related problems, verify the camera module connections and consult the module's datasheet for troubleshooting steps.
