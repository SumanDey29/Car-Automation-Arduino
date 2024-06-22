#include<Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

Servo wiper;
Servo window;
int pos = 0;
int sensorValue = 0;
void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    myservo.attach(9);
    myservo1.attach(10);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AUTOMATIC CAR");
    lcd.setCursor(0, 1);
    lcd.print(" WIPER & WINDOW");
    delay(5000);
}
void loop()
{
    sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    
    //Window Control
    if (sensorValue < 800)
        for (pos = 0; pos <= 180; pos++)
            window.write(pos);
    else
        window.write(0);
    
    //Wiper Control
    if (sensorValue > 800) //No Rainfall
    {
        wiper.write(180);
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print(" NO RAIN!! ");
        delay(1000);
    }
    
    //Wiper Control
    if (sensorValue <= 800 && sensorValue > 600) //Low Rainfall 
    {
        lcd.print("AMOUNT: LOW ");
        lcd.setCursor(0, 0);
        lcd.print("IT IS RAINING!!");
        lcd.setCursor(0, 1);
        for (pos = 180; pos >= 0; pos -= 1)
        {
            wiper.write(pos);
            delay(3);
        }
        for (pos = 0; pos <= 180; pos += 1)
        {
            wiper.write(pos);
            delay(3);
        }
        delay(2000);
    }
    
    //Wiper Control
    if (sensorValue <= 600 && sensorValue > 460) //Moderate Rainfall
    {
        lcd.setCursor(0, 0);
        lcd.print("IT IS RAINING!!");
        lcd.setCursor(0, 1);
        lcd.print("AMOUNT: MODERATE ");
        for (pos = 180; pos >= 0; pos -= 1)
        {
            wiper.write(pos);
            delay(3);
        }
        for (pos = 0; pos <= 180; pos += 1)
        {
            wiper.write(pos);
            delay(3);
        }
        delay(1000);
    }
    
    //Wiper Control
    if (sensorValue < 460) //High Rainfall
    {
        lcd.setCursor(0, 0);
        lcd.print("IT IS RAINING ");
        lcd.setCursor(0, 1);
        lcd.print("AMOUNT: HIGH ");
        for (pos = 180; pos >= 0; pos -= 1)
        {
            wiper.write(pos);
            delay(3);
        }
        for (pos = 0; pos <= 180; pos += 1)
        {
            wiper.write(pos);
            // myservo1.write(pos);
            delay(3);
        }
        delay(100);
    }
}