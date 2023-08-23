
#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);

  // Set from UNIX timestamp
  // clock.setDateTime(1397408400);

  // Manual (YYYY, MM, DD, HH, II, SS
  //clock.setDateTime(2016, 12, 9, 11, 46, 00);
}

void loop()
{
  dt = clock.getDateTime();
  Serial.print("Today is:                    ");
  Serial.print(dt.day);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.year);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
  Serial.print("Unixtime:                    ");
  Serial.println(dt.unixtime);
  delay(1000);
}

