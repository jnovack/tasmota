/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2020  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         All done.
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS   MY_IP                  // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY      MY_GW                  // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS          MY_DNS                 // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

*/

#undef  PROJECT
#define PROJECT                "smartplug"     // project Name

#undef  WIFI_HOSTNAME
#define WIFI_HOSTNAME          "%s"

#undef  MQTT_CLIENT_ID
#define MQTT_CLIENT_ID         "%12X"       // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address

#undef  MQTT_HOST
#define MQTT_HOST              "" // [MqttUser] MQTT user

#undef  MQTT_USER
#define MQTT_USER              "MQTT_USER"       // [MqttUser] MQTT user

#undef  MQTT_PASS
#define MQTT_PASS              "MQTT_PASS"       // [MqttPassword] MQTT password

#undef  MQTT_PORT
#define MQTT_PORT              8883         // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_TLS_ENABLED
#define MQTT_TLS_ENABLED       true         // [SetOption103] Enable TLS mode (requires TLS version)

#undef  MQTT_TOPIC
#define MQTT_TOPIC             PROJECT "-%04D"     // [Topic] unique MQTT device topic NOT including (part of) device MAC address

#undef  MQTT_GRPTOPIC
#define MQTT_GRPTOPIC          "smartplugs"        // [GroupTopic] MQTT Group topic


// https://pubsubclient.knolleary.net/api.html#state
#ifndef USE_MQTT_TLS 
#define USE_MQTT_TLS                             // Use TLS for MQTT connection (+34.5k code, +7.0k mem and +4.8k additional during connection handshake)
#define USE_MQTT_TLS_CA_CERT   
#endif  // USE_MQTT_TLS

#undef  MDDULE
#define MODULE                 USER_MODULE      // [Module2] Select default module on fast reboot where USER_MODULE is user template

#undef  USER_TEMPLATE
#define USER_TEMPLATE          "{\"NAME\":\"AWOW X5P\",\"GPIO\":[0,0,56,0,0,0,0,0,0,17,0,21,0],\"FLAG\":0,\"BASE\":18}"

#undef  OTA_URL
#define OTA_URL                "http://files.ozmo.me/tasmota/awow-x5p.bin"  // [OtaUrl]

#undef  MDNS_ENABLED
#define MDNS_ENABLED           true             // [SetOption55] Use mDNS (false = Disable, true = Enable)

#undef  USE_DISCOVERY
#define USE_DISCOVERY                           // Enable mDNS for the following services (+8k code or +23.5k code with core 2_5_x, +0.3k mem)

#undef  WEBSERVER_ADVERTISE
#define WEBSERVER_ADVERTISE                     // Provide access to webserver by name <Hostname>.local/

#undef MQTT_HOST_DISCOVERY                      // Do not discover MQTT host automatiically

// Time Zones
#undef  TIME_DST_HEMISPHERE
#define TIME_DST_HEMISPHERE    North             // [TimeDst] Hemisphere (0 or North, 1 or South)
#undef  TIME_DST_WEEK
#define TIME_DST_WEEK          Second              // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
#undef  TIME_DST_DAY
#define TIME_DST_DAY           Sun               // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
#undef  TIME_DST_MONTH
#define TIME_DST_MONTH         Mar               // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
#undef  TIME_DST_HOUR
#define TIME_DST_HOUR          2                 // Hour (0 to 23)
#undef  TIME_DST_OFFSET
#define TIME_DST_OFFSET        -240             // Offset from UTC in minutes (-780 to +780)

#undef  TIME_STD_HEMISPHERE
#define TIME_STD_HEMISPHERE    North             // [TimeStd] Hemisphere (0 or North, 1 or South)
#undef  TIME_STD_WEEK
#define TIME_STD_WEEK          First              // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
#undef  TIME_STD_DAY
#define TIME_STD_DAY           Sun               // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
#undef  TIME_STD_MONTH
#define TIME_STD_MONTH         Nov               // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
#undef  TIME_STD_HOUR
#define TIME_STD_HOUR          3                 // Hour (0 to 23)
#undef  TIME_STD_OFFSET
#define TIME_STD_OFFSET        -300             // Offset from UTC in minutes (-780 to +780)

#undef  APP_TIMEZONE
#define APP_TIMEZONE           99               // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)


// GPS 

#undef  LATITUDE
#define LATITUDE               40.71            // [Latitude] Your location to be used with sunrise and sunset

#undef  LONGITUDE
#define LONGITUDE              -74.01           // [Longitude] Your location to be used with sunrise and sunset

#define USE_PROMETHEUS                          // Turn ON /metrics endpoint

#undef  NTP_SERVER1
#define NTP_SERVER1            "pool.ntp.org"   // [NtpServer1] Select first NTP server by name or IP address (129.250.35.250)
#undef  NTP_SERVER2
#define NTP_SERVER2            "time.apple.com" // [NtpServer2] Select second NTP server by name or IP address (5.39.184.5)
#undef  NTP_SERVER3
#define NTP_SERVER3            "clock.psu.edu"  // [NtpServer3] Select third NTP server by name or IP address (93.94.224.67)


#undef  FRIENDLY_NAME 
#define FRIENDLY_NAME          "AWOW X5P"         // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

// Disable for custom firmeware
#undef USE_DOMOTICZ
#undef USE_HOME_ASSISTANT
#undef USE_EMULATION_HUE                        // Enable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
#undef USE_TIMERS
#undef USE_TIMERS_WEB
#undef USE_SUNRISE

#undef ROTARY_V1                                 // Disable support for MI Desk Lamp
#undef USE_SONOFF_RF                             // Disable support for Sonoff Rf Bridge (+3k2 code)
#undef USE_RF_FLASH                              // Disable support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB
#undef USE_SONOFF_SC                             // Disable support for Sonoff Sc (+1k1 code)
#undef USE_TUYA_MCU                              // Disable support for Tuya Serial MCU
#undef USE_ARMTRONIX_DIMMERS                     // Disable support for Armtronix Dimmers (+1k4 code)
#undef USE_PS_16_DZ                              // Disable support for PS-16-DZ Dimmer and Sonoff L1 (+2k code)
#undef USE_SONOFF_IFAN                           // Disable support for Sonoff iFan02 and iFan03 (+2k code)
#undef USE_BUZZER                                // Disable support for a buzzer (+0k6 code)
#undef USE_ARILUX_RF                             // Disable support for Arilux RF remote controller
#undef USE_SHUTTER                               // Disable Shutter support for up to 4 shutter with different motortypes (+6k code)
#undef USE_DEEPSLEEP                             // Disable support for deepsleep (+1k code)
#undef USE_EXS_DIMMER                            // Disable support for EX-Store WiFi Dimmer
#undef USE_HOTPLUG                               // Disable support for HotPlug
#undef USE_DEVICE_GROUPS                         // Disable support for device groups (+3k5 code)
#undef USE_PWM_DIMMER                            // Disable support for MJ-SD01/acenx/NTONPOWER PWM dimmers (+4k5 code)
#undef USE_PWM_DIMMER_REMOTE                     // Disbale support for remote switches to PWM Dimmer
#undef USE_SONOFF_D1                             // Disable support for Sonoff D1 Dimmer (+0k7 code)

// -- Optional light modules ----------------------
#undef USE_WS2812                                // Disable WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
#undef USE_MY92X1                                // Disable support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas
#undef USE_SM16716                               // Disable support for SM16716 RGB LED controller (+0k7 code)
#undef USE_SM2135                                // Disable support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
#undef USE_SONOFF_L1                             // Disable support for Sonoff L1 led control
#undef USE_ELECTRIQ_MOODL                        // Disable support for ElectriQ iQ-wifiMOODL RGBW LED controller
#undef USE_ENERGY_SENSOR
#undef USE_PZEM004T
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_MCP39F501

#undef USE_TELEGRAM
#undef USE_KNX  

#undef USE_I2C                                   // Disable all I2C sensors and devices
#undef USE_SPI                                   // Disable all SPI devices
#undef USE_DISPLAY                               // Disable Display support

#undef USE_IR_REMOTE
#undef USE_IR_RECEIVE
#undef USE_ADE7953
#undef USE_DS18x20
#undef USE_DHT

#endif  // _USER_CONFIG_OVERRIDE_H_
