Step 0: Be in linux!

Step 1: Install the compiler
Navigate to the compiler's website: http://www.microchip.com/mplab/compilers and grab yourself a copy of the linux XC16 compiler. Unzip that business and run the nonsense (if that isnt immediately and option, you may need to chmod the file and run that as a super dude). 

Now you need scons (pronounced "scones"). To get it, run the line: $ sudo apt-get install scons

Step 2: Git
Youre doing great if you've made it this far! We now need you to fork and clone the repo found at: https://github.com/scottmackinlay/elecanisms 

Step 3: Time to compile!
Navigate into the blink folder (within elecanisms) and type "scons" to execute the sconstruct file to compile the blink.c code into a blink.hex file. If this doesn't work, try opening Sconstruct in your favorite text editer and verifying that it points to the correct location for your compiler (which is default set to: "/opt/microchip/xc16/v1.30/bin")

Step 4: Bootload like you've never done before
Navigate into the elecanisms/bootloader/software and run the python script called bootloadergui.py to open a GUI. Find and import (file>import) the hex file that you made in step 3. Connect your board and press SW1 and RST and then release RST before releasing SW1. From the GUI press connect and then write to get the hex file onto the PIC. 

Step 5: Run!
To run the code, it is simply a matter of pressing the RST button and the red light should start right up.
