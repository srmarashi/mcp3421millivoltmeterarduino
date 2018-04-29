// Accuracy 5 digit
//by : seyed roohollah marashi
// srmarashi@yahoo.com
// you need MCP3421 library, you can download from github thanks for library writer
// U8lib is best driver for nokia LCD
//00436763832008 is my number in case of questions



#include "U8glib.h"
U8GLIB_PCD8544 u8g(3, 4, 6, 5, 7); // CLK ,DIN ,CE ,DC ,RST    //Case OnBoard
#include <Wire.h>
#include "MCP3421.h"
float l1;
float l2;
static char outstr[15];


MCP3421 MCP = MCP3421();
void setup(void)
{
  Serial.begin(115200);

  Serial.println("60000 Counts True RMS");  // just to be sure things are working
  Wire.begin();
  MCP.init(0x69, 1, 1);


}

void loop(void)
{

  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.setFont(u8g_font_osb21);
    u8g.setFont(u8g_font_9x18);
    l1 = MCP.getLong();
    Serial.println(l1 * 0.0013839648173207, 6);
    l2 = l1 * 0.0013839648173207;
    delay(10);
    dtostrf(l2, 6, 6, outstr);
    u8g.drawStr( 0, 22, outstr);
  } while ( u8g.nextPage() );

}



