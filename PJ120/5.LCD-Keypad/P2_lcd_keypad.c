#include<reg51.H>
#define LCDPORT P2
sbit RS=P3^0;
sbit E =P3^1;
sbit C1=P3^4;  sbit C2=P3^3; sbit C3=P3^2;
sbit R1=P3^5;  sbit R2=P3^6; sbit R3=P3^7;

void my_delay(int i)
{int j; 
 	for (;i>0;i--)
		for (j=0; j<30000;j++){}
}
void LCD_Cmd ( int  i ) {
      RS = 0;	LCDPORT = i ; // RS=0 for command 
      E  = 1 ;   	my_delay(1);      E  = 0 ;
}
void LCD_Data ( int  i ) {
      RS = 1;	LCDPORT = i ;  // RS=1 for data
      E  = 1 ;   	my_delay(1);     E  = 0 ;
}
void main()
{	// initialize the LCD 
	LCD_Cmd (0x38); LCD_Cmd (0x01);  LCD_Cmd (0x0e);
	C1=C2=C3=R1=R2=R3=1	;
	while(1){	 
		C1=0;
	   if (	R1==0){ LCD_Data ( '1'); my_delay(1); while(R1==0);}  
	   if (	R2==0){ LCD_Data ( '4'); my_delay(1); } 
	   if (	R3==0){ LCD_Data ( '7'); my_delay(1); } 

	   C1=1;C2=0;
	   if (	R1==0){ LCD_Data ( '2'); my_delay(1); }  
	   if (	R2==0){ LCD_Data ( '5'); my_delay(1); } 
	   if (	R3==0){ LCD_Data ( '8'); my_delay(1); } 
		C2=1; C3=0;
	   if (	R1==0){ LCD_Data ( '3'); my_delay(1); }  
	   if (	R2==0){ LCD_Data ( '6'); my_delay(1); } 
	   if (	R3==0){ LCD_Cmd (0x01) ;  my_delay(1); } 
		C3=1;
	}

}