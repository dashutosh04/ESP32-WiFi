#include "esp_camera.h"
#include <WiFi.h>

const char* wifi_ssid = "helloworld";   //wifi_name
const char* wifi_pass = "password"; //wifi_pass

void startCameraServer();
void setupLedFlash(int pin);

void setup() {
  Serial.begin(115200); // baud rate setup
  Serial.setDebugOutput(true);
  Serial.println();
  
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = 5;
  config.pin_d1 = 18;
  config.pin_d2 = 19;
  config.pin_d3 = 21;
  config.pin_d4 = 36;
  config.pin_d5 = 39;
  config.pin_d6 = 34;
  config.pin_d7 = 35;
  config.pin_xclk = 0;
  config.pin_pclk = 22;
  config.pin_vsync = 25;
  config.pin_href = 23;
  config.pin_sccb_sda = 26;
  config.pin_sccb_scl = 27;
  config.pin_pwdn = 32;
  config.pin_reset = -1;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_UXGA;
  config.pixel_format = PIXFORMAT_JPEG;
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 10;
  config.fb_count = 2;
  
  esp_err_t err = esp_camera_init(&config); //initialises the camera

  if (err != ESP_OK) {
    Serial.printf("Error!! | :< Camera Initialisation failed with code 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();

  pinMode(33, OUTPUT);
  setupLedFlash(4);

  WiFi.begin(wifi_ssid, wifi_pass);
  WiFi.setSleep(false);

  Serial.println("");
  Serial.print("Attempting to Locate Connection with name ");
  Serial.print(wifi_ssid);
  Serial.println("");
  Serial.print("Locating.");


  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(33, HIGH);
    delay(500);
    digitalWrite(33, LOW);
    Serial.print(".");
    delay(500);               //red LED will blink
    Serial.print(".");
  }


  Serial.println("");
  Serial.println(":> Yayyy! WiFi connected");

  startCameraServer();

  digitalWrite(33, LOW); //Glows the Red Led

  Serial.print("Camera was initialised successfully! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}


void loop() {
  delay(10000); // nothing just a refresh loop 
}
