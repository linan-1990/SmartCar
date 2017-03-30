/******************************************************************************\
*  Copyright (C) 2012 Nan Li, Tianjin University 
*  ALL RIGHTS RESERVED
*  Filename: OLED.c
*  Version: 1.0
*  Author: Nan Li
\******************************************************************************/



#include "OLED.h"


//======================================
const byte F6x8[][6] =
{
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // sp
    { 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00 },   // !
    { 0x00, 0x00, 0x07, 0x00, 0x07, 0x00 },   // "
    { 0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14 },   // #
    { 0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12 },   // $
    { 0x00, 0x62, 0x64, 0x08, 0x13, 0x23 },   // %
    { 0x00, 0x36, 0x49, 0x55, 0x22, 0x50 },   // &
    { 0x00, 0x00, 0x05, 0x03, 0x00, 0x00 },   // '
    { 0x00, 0x00, 0x1c, 0x22, 0x41, 0x00 },   // (
    { 0x00, 0x00, 0x41, 0x22, 0x1c, 0x00 },   // )
    { 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14 },   // *
    { 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08 },   // +
    { 0x00, 0x00, 0x00, 0xA0, 0x60, 0x00 },   // ,
    { 0x00, 0x08, 0x08, 0x08, 0x08, 0x08 },   // -
    { 0x00, 0x00, 0x60, 0x60, 0x00, 0x00 },   // .
    { 0x00, 0x20, 0x10, 0x08, 0x04, 0x02 },   // /
    { 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E },   // 0
    { 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00 },   // 1
    { 0x00, 0x42, 0x61, 0x51, 0x49, 0x46 },   // 2
    { 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31 },   // 3
    { 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10 },   // 4
    { 0x00, 0x27, 0x45, 0x45, 0x45, 0x39 },   // 5
    { 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30 },   // 6
    { 0x00, 0x01, 0x71, 0x09, 0x05, 0x03 },   // 7
    { 0x00, 0x36, 0x49, 0x49, 0x49, 0x36 },   // 8
    { 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E },   // 9
    { 0x00, 0x00, 0x36, 0x36, 0x00, 0x00 },   // :
    { 0x00, 0x00, 0x56, 0x36, 0x00, 0x00 },   // ;
    { 0x00, 0x08, 0x14, 0x22, 0x41, 0x00 },   // <
    { 0x00, 0x14, 0x14, 0x14, 0x14, 0x14 },   // =
    { 0x00, 0x00, 0x41, 0x22, 0x14, 0x08 },   // >
    { 0x00, 0x02, 0x01, 0x51, 0x09, 0x06 },   // ?
    { 0x00, 0x32, 0x49, 0x59, 0x51, 0x3E },   // @
    { 0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C },   // A
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36 },   // B
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22 },   // C
    { 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C },   // D
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41 },   // E
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01 },   // F
    { 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A },   // G
    { 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F },   // H
    { 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00 },   // I
    { 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01 },   // J
    { 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41 },   // K
    { 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40 },   // L
    { 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F },   // M
    { 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F },   // N
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E },   // O
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06 },   // P
    { 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E },   // Q
    { 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46 },   // R
    { 0x00, 0x46, 0x49, 0x49, 0x49, 0x31 },   // S
    { 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01 },   // T
    { 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F },   // U
    { 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F },   // V
    { 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F },   // W
    { 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 },   // X
    { 0x00, 0x07, 0x08, 0x70, 0x08, 0x07 },   // Y
    { 0x00, 0x61, 0x51, 0x49, 0x45, 0x43 },   // Z
    { 0x00, 0x00, 0x7F, 0x41, 0x41, 0x00 },   // [
    { 0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55 },   // 55
    { 0x00, 0x00, 0x41, 0x41, 0x7F, 0x00 },   // ]
    { 0x00, 0x04, 0x02, 0x01, 0x02, 0x04 },   // ^
    { 0x00, 0x40, 0x40, 0x40, 0x40, 0x40 },   // _
    { 0x00, 0x00, 0x01, 0x02, 0x04, 0x00 },   // '
    { 0x00, 0x20, 0x54, 0x54, 0x54, 0x78 },   // a
    { 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38 },   // b
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x20 },   // c
    { 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F },   // d
    { 0x00, 0x38, 0x54, 0x54, 0x54, 0x18 },   // e
    { 0x00, 0x08, 0x7E, 0x09, 0x01, 0x02 },   // f
    { 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C },   // g
    { 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78 },   // h
    { 0x00, 0x00, 0x44, 0x7D, 0x40, 0x00 },   // i
    { 0x00, 0x40, 0x80, 0x84, 0x7D, 0x00 },   // j
    { 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00 },   // k
    { 0x00, 0x00, 0x41, 0x7F, 0x40, 0x00 },   // l
    { 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78 },   // m
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x78 },   // n
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x38 },   // o
    { 0x00, 0xFC, 0x24, 0x24, 0x24, 0x18 },   // p
    { 0x00, 0x18, 0x24, 0x24, 0x18, 0xFC },   // q
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08 },   // r
    { 0x00, 0x48, 0x54, 0x54, 0x54, 0x20 },   // s
    { 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20 },   // t
    { 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C },   // u
    { 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C },   // v
    { 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C },   // w
    { 0x00, 0x44, 0x28, 0x10, 0x28, 0x44 },   // x
    { 0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C },   // y
    { 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44 },   // z
    { 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 }    // horiz lines
};
const byte F14x16_Idx[] = 
{
	"天津大学光电一队"
};
const byte F14x16[] = { 
0x80,0x84,0x84,0x84,0x84,0x84,0xFC,0x84,0x84,0x84,0x84,0x84,0x80,0x00,
0x40,0x40,0x20,0x10,0x08,0x06,0x01,0x06,0x08,0x10,0x20,0x40,0x40,0x00,//天0
0x40,0x84,0x08,0x00,0x20,0xA8,0xA8,0xA8,0xFE,0xA8,0xA8,0xF8,0x20,0x00,
0x00,0x30,0x0C,0x03,0x08,0x0A,0x0A,0x0A,0x7F,0x0A,0x0A,0x0A,0x08,0x00,//津1
0x20,0x20,0x20,0x20,0x20,0xA0,0x7E,0xA0,0x20,0x20,0x20,0x20,0x20,0x00,
0x40,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x40,0x00,//大2
0x70,0x10,0x92,0x94,0x90,0x92,0x94,0x90,0x98,0x94,0x12,0x10,0x70,0x00,
0x04,0x04,0x04,0x04,0x44,0x44,0x7E,0x06,0x05,0x04,0x04,0x04,0x04,0x00,//学3
0x40,0x44,0x48,0x50,0xC0,0x40,0x7E,0x40,0xC0,0x50,0x48,0x44,0x40,0x00,
0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,0x3F,0x40,0x40,0x40,0x70,0x00,//光4
0x00,0xF0,0x90,0x90,0x90,0x90,0xFE,0x90,0x90,0x90,0x90,0xF0,0x00,0x00,
0x00,0x0F,0x04,0x04,0x04,0x04,0x3F,0x44,0x44,0x44,0x44,0x47,0x70,0x00,//电5
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//一6
0x00,0xFC,0x04,0x64,0x9C,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,
0x00,0x7F,0x08,0x08,0x47,0x20,0x18,0x07,0x00,0x07,0x18,0x20,0x40,0x00,//队7
};

 
void LCD_WrDat(byte data)
{
	byte i=8;
	//CS=0;;
	DC=1;
  D0=0;
  //asm("nop");    
  while(i--)
  {
    if(data&0x80){D1=1;}
    else{D1=0;}
    D0=1; 
    asm("nop");
		//asm("nop");            
    D0=0;    
    data<<=1;    
  }
	//CS=1;
}

void LCD_WrCmd(byte cmd)
{
	byte i=8;
	
	//CS=0;;
	DC=0;
  D0=0;
  //asm("nop");   
  while(i--)
  {
    if(cmd&0x80){D1=1;}
    else{D1=0;}
    D0=1;
    asm("nop");
		//asm("nop");             
    D0=0;    
    cmd<<=1;   
  } 	
	//CS=1;
}

void LCD_Set_Pos(byte x, byte y)
{ 
  LCD_WrCmd(0xb0+y);
  LCD_WrCmd(((x&0xf0)>>4)|0x10);
  LCD_WrCmd((x&0x0f)|0x01); 
} 

void LCD_Fill(byte bmp_data)
{
	byte y,x;
	
	for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
			LCD_WrDat(bmp_data);
	}
}

void LCD_CLS(void)
{
	byte y,x;	
	for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10); 
		for(x=0;x<X_WIDTH;x++)
			LCD_WrDat(0);
	}
}


void adjust(byte a)
{
  LCD_WrCmd(a);	//指令数据0x0000~0x003f  
}

void SetStartColumn(unsigned char d)
{
	LCD_WrCmd(0x00+d%16);		// Set Lower Column Start Address for Page Addressing Mode
						//   Default => 0x00
	LCD_WrCmd(0x10+d/16);		// Set Higher Column Start Address for Page Addressing Mode
						//   Default => 0x10
}

void SetAddressingMode(unsigned char d)
{
	LCD_WrCmd(0x20);			// Set Memory Addressing Mode
	LCD_WrCmd(d);			//   Default => 0x02
						//     0x00 => Horizontal Addressing Mode
						//     0x01 => Vertical Addressing Mode
						//     0x02 => Page Addressing Mode
}

void SetColumnAddress(unsigned char a, unsigned char b)
{
	LCD_WrCmd(0x21);			// Set Column Address
	LCD_WrCmd(a);			//   Default => 0x00 (Column Start Address)
	LCD_WrCmd(b);			//   Default => 0x7F (Column End Address)
}

void SetPageAddress(unsigned char a, unsigned char b)
{
	LCD_WrCmd(0x22);			// Set Page Address
	LCD_WrCmd(a);			//   Default => 0x00 (Page Start Address)
	LCD_WrCmd(b);			//   Default => 0x07 (Page End Address)
}

void SetStartLine(unsigned char d)
{
	LCD_WrCmd(0x40|d);			// Set Display Start Line
						//   Default => 0x40 (0x00)
}

void SetContrastControl(unsigned char d)
{
	LCD_WrCmd(0x81);			// Set Contrast Control
	LCD_WrCmd(d);			//   Default => 0x7F
}

void Set_Charge_Pump(unsigned char d)
{
	LCD_WrCmd(0x8D);			// Set Charge Pump
	LCD_WrCmd(0x10|d);			//   Default => 0x10
						//     0x10 (0x00) => Disable Charge Pump
						//     0x14 (0x04) => Enable Charge Pump
}

void Set_Segment_Remap(unsigned char d)
{
	LCD_WrCmd(0xA0|d);			// Set Segment Re-Map
						//   Default => 0xA0
						//     0xA0 (0x00) => Column Address 0 Mapped to SEG0
						//     0xA1 (0x01) => Column Address 0 Mapped to SEG127
}

void Set_Entire_Display(unsigned char d)
{
	LCD_WrCmd(0xA4|d);			// Set Entire Display On / Off
						//   Default => 0xA4
						//     0xA4 (0x00) => Normal Display
						//     0xA5 (0x01) => Entire Display On
}

void Set_Inverse_Display(unsigned char d)
{
	LCD_WrCmd(0xA6|d);			// Set Inverse Display On/Off
						//   Default => 0xA6
						//     0xA6 (0x00) => Normal Display
						//     0xA7 (0x01) => Inverse Display On
}

void Set_Multiplex_Ratio(unsigned char d)
{
	LCD_WrCmd(0xA8);			// Set Multiplex Ratio
	LCD_WrCmd(d);			//   Default => 0x3F (1/64 Duty)
}

void Set_Display_On_Off(unsigned char d)
{
	LCD_WrCmd(0xAE|d);			// Set Display On/Off
						//   Default => 0xAE
						//     0xAE (0x00) => Display Off
						//     0xAF (0x01) => Display On
}

void SetStartPage(unsigned char d)
{
	LCD_WrCmd(0xB0|d);			// Set Page Start Address for Page Addressing Mode
						//   Default => 0xB0 (0x00)
}

void Set_Common_Remap(unsigned char d)
{
	LCD_WrCmd(0xC0|d);			// Set COM Output Scan Direction
						//   Default => 0xC0
						//     0xC0 (0x00) => Scan from COM0 to 63
						//     0xC8 (0x08) => Scan from COM63 to 0
}

void Set_Display_Offset(unsigned char d)
{
	LCD_WrCmd(0xD3);			// Set Display Offset
	LCD_WrCmd(d);			//   Default => 0x00
}

void Set_Display_Clock(unsigned char d)
{
	LCD_WrCmd(0xD5);			// Set Display Clock Divide Ratio / Oscillator Frequency
	LCD_WrCmd(d);			//   Default => 0x80
						//     D[3:0] => Display Clock Divider
						//     D[7:4] => Oscillator Frequency
}

void Set_Precharge_Period(unsigned char d)
{
	LCD_WrCmd(0xD9);			// Set Pre-Charge Period
	LCD_WrCmd(d);			//   Default => 0x22 (2 Display Clocks [Phase 2] / 2 Display Clocks [Phase 1])
						//     D[3:0] => Phase 1 Period in 1~15 Display Clocks
						//     D[7:4] => Phase 2 Period in 1~15 Display Clocks
}

void Set_Common_Config(unsigned char d)
{
	LCD_WrCmd(0xDA);			// Set COM Pins Hardware Configuration
	LCD_WrCmd(0x02|d);			//   Default => 0x12 (0x10)
						//     Alternative COM Pin Configuration
						//     Disable COM Left/Right Re-Map
}

void Set_VCOMH(unsigned char d)
{
	LCD_WrCmd(0xDB);			// Set VCOMH Deselect Level
	LCD_WrCmd(d);			//   Default => 0x20 (0.77*VCC)
}

void Set_NOP(void)
{
	LCD_WrCmd(0xE3);			// Command for No Operation
}

void LCD_Init(void)        
{
 	D0=1;
	//CS=1;	//预制SLK和SS为高电平   	
	
	RST=0;
	DLY_ms(50);
	RST=1;
	
	//从上电到下面开始初始化要有足够的时间，即等待RC复位完毕
  Set_Display_On_Off(0x00);		  // Display Off (0x00/0x01)
  Set_Display_Clock(0x80);		  // Set Clock as 100 Frames/Sec
  Set_Multiplex_Ratio(0x3F);		// 1/64 Duty (0x0F~0x3F)
  Set_Display_Offset(0x00);		  // Shift Mapping RAM Counter (0x00~0x3F)
  SetStartLine(0x00);			      // Set Mapping RAM Display Start Line (0x00~0x3F)
  Set_Charge_Pump(0x04);		    // Enable Embedded DC/DC Converter (0x00/0x04)
  SetAddressingMode(0x02);		  // Set Page Addressing Mode (0x00/0x01/0x02)
  Set_Segment_Remap(0x01);		  // Set SEG/Column Mapping     0x00左右反置 0x01正常
  Set_Common_Remap(0x08);			  // Set COM/Row Scan Direction 0x00上下反置 0x08正常
  Set_Common_Config(0x10);		  // Set Sequential Configuration (0x00/0x10)
  SetContrastControl(Brightness);	// Set SEG Output Current
  Set_Precharge_Period(0xF1);		// Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
  Set_VCOMH(0x40);			        // Set VCOM Deselect Level
  Set_Entire_Display(0x00);		  // Disable Entire Display On (0x00/0x01)
  Set_Inverse_Display(0x00);		// Disable Inverse Display On (0x00/0x01)  
  Set_Display_On_Off(0x01);		  // Display On (0x00/0x01)
  LCD_Fill(0x00);  //初始清屏
	LCD_Set_Pos(0,0); 
} 


//==============================================================
//函数名：LCD_P6x8Str(byte x,byte y,byte *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～7，要显示的字符串
//返回：无
//==============================================================  
void LCD_P6x8Str(byte x,byte y,byte ch[])
{
  byte c=0,i=0,j=0;      
  while (ch[j]!='\0')
  {    
    c =ch[j]-32;
    if(x>126){x=0;y++;}
    LCD_Set_Pos(x,y);    
  	for(i=0;i<6;i++)     
  	  LCD_WrDat(F6x8[c][i]);  
  	x+=6;
  	j++;
  }
}

//输出汉字字符串
void LCD_P14x16Str(byte x,byte y,byte ch[])
{
	byte wm=0,ii = 0;
	word adder=1; 
	
	while(ch[ii] != '\0')
	{
  	wm = 0;
  	adder = 1;
  	while(F14x16_Idx[wm] > 127)
  	{
  		if(F14x16_Idx[wm] == ch[ii])
  		{
  			if(F14x16_Idx[wm + 1] == ch[ii + 1])
  			{
  				adder = wm * 14;
  				break;
  			}
  		}
  		wm += 2;			
  	}
  	if(x>118){x=0;y++;}
  	LCD_Set_Pos(x , y); 
  	if(adder != 1)// 显示汉字					
  	{
  		LCD_Set_Pos(x , y);
  		for(wm = 0;wm < 14;wm++)               
  		{
  			LCD_WrDat(F14x16[adder]);	
  			adder += 1;
  		}      
  		LCD_Set_Pos(x,y + 1); 
  		for(wm = 0;wm < 14;wm++)          
  		{
  			LCD_WrDat(F14x16[adder]);
  			adder += 1;
  		}   		
  	}
  	else			  //显示空白字符			
  	{
  		ii += 1;
      LCD_Set_Pos(x,y);
  		for(wm = 0;wm < 16;wm++)
  		{
  				LCD_WrDat(0);
  		}
  		LCD_Set_Pos(x,y + 1);
  		for(wm = 0;wm < 16;wm++)
  		{   		
  				LCD_WrDat(0);	
  		}
  	}
  	x += 14;
  	ii += 2;
	}
}
//输出汉字和字符混合字符串
void LCD_Print(byte x, byte y, byte ch[])
{
	byte ch2[3];
	byte ii=0;        
	while(ch[ii] != '\0')
	{
		if(ch[ii] > 127)
		{
			ch2[0] = ch[ii];
	 		ch2[1] = ch[ii + 1];
			ch2[2] = '\0';			//汉字为两个字节
			LCD_P14x16Str(x , y, ch2);	//显示汉字
			x += 14;
			ii += 2;
		}
		else
		{
			ch2[0] = ch[ii];	
			ch2[1] = '\0';			//字母占一个字节
			LCD_P6x8Str(x , y , ch2);	//显示字母
			x += 8;
			ii+= 1;
		}
	}
} 


void LCD_clear(void)
{
  byte y,x;
  for(y=3;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
			LCD_WrDat(0x00);
	}
}

void LCD_clear_all(void)
{
  byte y,x;
  for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
			LCD_WrDat(0x00);
	}
}


void LCD_clear_line(unsigned int line)
{
  byte x;
  LCD_WrCmd(0xb0+line);
  LCD_WrCmd(0x01);
	LCD_WrCmd(0x10);
  for(x=0;x<X_WIDTH;x++)
			LCD_WrDat(0x00);
}
