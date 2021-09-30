# PES-Assignment-3
@file Blink_LED_A3<br/>
@author Harshwardhan Singh<br/>
@date September 26th 2021<br/>

## Blink_LED_A3.c file
This is the main file of project where the code has been executed. The file consists of three functions including the main() along with the
Touch_Change_Color_On() function and Touch_Change_Color_Off() function where the first function is used to change the color of LED according to the
value taken from the touch capacitive sensor when LED is in ON state and the latter is used to change the color of LED according to the
value taken from the touch capacitive sensor when LED is in OFF state. These functions are created with the motive to make the while(1) infinite
loop clean and elegant. Inside the while(1) loop, the polling of touch sensor is done in every 100msec. Four for loops are executed inside the while(1) loop.
Moreover, the offset value is not taken into consideration, however, the offset value comes around 630 for this development board.

## Other .c and .h files
delay.c file contains the delay function with the nested for loop which takes the input as integer in mseec (millisecond).<br/>
led.c file contains two functions that are used to set the clock to Port-B and Port-D, make three pins GPIO and set the LED bits to output.<br/>
led.h file consists of typdef enum() that is created to simplify the use of LED colors, the enum is used to select RED, GREEN, BLUE and WHITE color. <br/>
touch.c file contains two functions that are used to set the clock for TSI and set the configurations for TSI and function is used to extract the value from
the touch capacitive sensor and stores the value in one of the variables.<br/><br/>

Ranges are set as follows: <br/>
From 650 to 850 - RED<br/>
From 851 to 1300 - GREEN<br/>
Above 1300 - BLUE<br/><br/>
When the touch is detected on the LEFT of the touch pad, RED LED glows, when it is detected at the middle of the sensor then, GREEN LED glows and when
the touch is detected at RIGHT side of the sensor then the BLUE LED glows.<br/><br/>

NOTE: The testing is done by touching the sensor with index finger for less than a second and then release.<br/><br/>

log.h file is for conditional compiling where, if the program is in Debug mode, then the printf() statements i.e. LOG() will be executed whereas if the program is
working on RUN mode then the printf() statements should not be printed on the console window.<br/>
Two build targets were configured using the following steps:<br/>
Go to Projects -> Properties -> C/C++ Build -> Settings -> MCU Compiler -> Preprocessor<br/>
Now select RUN from the Configuration drop-down window -> select DEBUG and remove the file -> click on Apply and Close<br/>
Target can be changed by selecting the Debug and RUN mode accordingly from the Debug option (Hammer symbol on the top).<br/>
common.h file is created to simplify the program and made it look neat as the header (hash include) files are used almost in every .c files. 
Hence, it was made common so that it could be implemented anywhere.<br/>

 ## Extra Credit 
 
 The full assembly version of the code can be accessed through the MCUXpresso IDE as well as using the arm-none-eabi-objdump -d Blink_LED_A3.axf command. 
 While accessing it through the IDE, following steps should be followed: right click on the Blink_LED_A3.axf file in the Debug folder, select Binary utilities
 and then click on disassemble.
 
 ### 1. Address of the main() function
 000005b0 is the address of the main() function.
 
 ### 2. Size in bytes of the delay() function
 00000040 is the size of delay() function in hexadecimal which is 64 bytes after conversion.
 
 ### 3. Full disassembly of the delay() function with comments on each line to explain the functionality.
 0000073c <delay>: <br/>
     73c:	b580      	push	{r7, lr}          /*r7 and lr are stored to the top of the stack <br/>
     73e:	b084      	sub	sp, #16             /*performs the subtraction between 16h and sp <br/>
     740:	af00      	add	r7, sp, #0          /*performs the addition of sp and 0h and stores the value in r7 register <br/>
     742:	6078      	str	r0, [r7, #4]        /*value of r0 is stored into an address equal to the sum of r7 and 4h <br/>
     744:	2300      	movs	r3, #0            /*immediate value of 0h is copied in register r3 <br/>
     746:	60fb      	str	r3, [r7, #12]       /* value of r3 is stored into an address equal to the sum of r7 and 12h <br/>
     748:	e00c      	b.n	764 <delay+0x28>    /*branches to the address 764 <br/>
     74a:	2300      	movs	r3, #0            /*immediate value of 0h is copied in register r3 <br/>
     74c:	60bb      	str	r3, [r7, #8]        /* value of r3 is stored into an address equal to the sum of r7 and 8h <br/>
     74e:	e002      	b.n	756 <delay+0x1a>    /*branches to the address 756 <br/>
     750:	68bb      	ldr	r3, [r7, #8]        /*address pointed by r7+#8h is stored in register r3 <br/>
     752:	3301      	adds	r3, #1            /*add the value of r3 with the immediate value of #1h and stores the value in register r3 <br/>
     754:	60bb      	str	r3, [r7, #8]        /*value of r7 is stored into an address equal to the sum of r7 and 8h <br/>
     756:	68bb      	ldr	r3, [r7, #8]        /*address pointed by r7+#8h is stored in register r3 <br/>
     758:	4a07      	ldr	r2, [pc, #28]	; (778 <delay+0x3c>)    /*address pointed by program counter (pc) and absolute value #28h i.e. pc+#28h is stored in register r2 <br/>
     75a:	4293      	cmp	r3, r2              /*subtract r2 from r3, conditional flag is changed according to the result which is not stored in any register <br/>
     75c:	ddf8      	ble.n	750 <delay+0x14>  /*branches to the address 750 <br/>
     75e:	68fb      	ldr	r3, [r7, #12]       /*address pointed by r7+#12h is stored in register r3 <br/>
     760:	3301      	adds	r3, #1            /*add the value of r3 with the immediate value of #1h and stores the value in register r3 <br/>
     762:	60fb      	str	r3, [r7, #12]       /* value of r3 is stored into an address equal to the sum of r7 and 12h <br/>
     764:	68fa      	ldr	r2, [r7, #12]       /*address pointed by r7+#12h is stored in register r3 <br/>
     766:	687b      	ldr	r3, [r7, #4]        /*address pointed by r7+#4h is stored in register r3 <br/>
     768:	429a      	cmp	r2, r3              /* subtract r3 from r2, conditional flag is changed according to the result which is not stored in any register <br/>
     76a:	dbee      	blt.n	74a <delay+0xe>   /*branches to the address 74a <br/>
     76c:	46c0      	nop			; (mov r8, r8)  /*does nothing (used for looping) <br/>
     76e:	46c0      	nop			; (mov r8, r8)  /*does nothing (used for looping) <br/>
     770:	46bd      	mov	sp, r7              /*value of r7 is copied in the stack pointer <br/>
     772:	b004      	add	sp, #16             /*performs the addition of sp and #16h and stores the value in stack pointer (sp) <br/>
     774:	bd80      	pop	{r7, pc}            /*register r7 is popped out and branched to the new program counter (pc) <br/>
     776:	46c0      	nop			; (mov r8, r8)  /*does nothing (used for looping) <br/>
     778:	00000671 	.word	0x00000671 <br/>

## Peer Review
 @Date - 27th September 2021 <br/>
 @Time - 11:10AM - 12:25PM (Class hours) <br/>
 @Partner - Varun Mehta <br/> 
 
 Suggestions - Adding comments to explain the code <br/>
 Changes - Added the comments in Blink_LED_A3.c, led.c and touch.c file
