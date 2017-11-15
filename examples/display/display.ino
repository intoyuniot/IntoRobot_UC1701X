/*****
驱动IC为uc1701x的LCD屏例程接线说明
CS        D0
RST       D1
RS        D2
SDA       D3
SCK       D4
VDD       5V
VSS       GND
LEDA      5V（背光源：也可由IO口控制，本例程由A0控制）
*****/

#include <IntoRobot_UC1701X.h>

#define LCD_BACK_LIGHT A0

IntoRobot_UC1701X uc1701x =  IntoRobot_UC1701X(D0,D1,D2,D3,D4);

void setup()
{
	uc1701x.begin();
	pinMode(LCD_BACK_LIGHT,OUTPUT);
	digitalWrite(LCD_BACK_LIGHT,HIGH); //开背光

	uc1701x.setTextSize(1); //设置文本大小
    uc1701x.setTextColor(WHITE); //选择纹波颜色
    uc1701x.setCursor(0,0); //设置光标
    uc1701x.clearDisplay();
    uc1701x.println("EFKFFPOWKFPKFPOKsklfosjmfop6574635434gsgmskjmgsmngo"); //输入显示的字符
    uc1701x.display(); //开启显示
}

void loop()
{
}
