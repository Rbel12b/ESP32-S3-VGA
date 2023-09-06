#include "ESP32S3VGA.h"

//                   r,r,r,r,r,  g,g, g, g, g, g,   b, b, b, b, b,   h,v
const PinConfig pins(4,5,6,7,8,  9,10,11,12,13,14,  15,16,17,18,21,  1,2);

//3 bit version (no resistor ladder)
//const PinConfig pins(-1,-1,-1,-1,8,  -1,-1,-1,-1,-1,14,  -1,-1,-1,-1,21,  1,2);

VGA vga;

void setup()
{
	//VGAMode mode = MODE_1024x768x60;
	//if(!vgaInit(pins, mode, 8)) while(1) delay(1);

	Mode mode = Mode::MODE_800x600x60;
	if(!vga.init(pins, mode, 16)) while(1) delay(1);


	for(int y = 0; y < mode.vRes; y++)
		for(int x = 0; x < mode.hRes; x++)
			vga.dotdit(x, y, x, y, 255-x);
	for(int y = 0; y < 30; y++)
		for(int x = 0; x < 256; x++)
		{
			vga.dot(x, y, x, 0, 0);
			vga.dot(x, y + 30, 0, x, 0);
			vga.dot(x, y + 60, 0, 0, x);
		}
	vga.show();
	vga.start();
}

void loop() 
{
}
