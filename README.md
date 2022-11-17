# CSGO-External-Simple-AntiFlash-Kernel-Driver

Crappy project with simple Write/Read Kernel Driver and application which gives memory addresses to our driver. Just changing flash value to 0. 

Instruction to start this cheat:
1. Run cmd as with administrator 
2. Text in cmd this: sc create "nameofyourdriver" type= kernel binpath="path to your driver"
   for example:  sc create Top Driver to avoid ban type= kernel binpath="D:\Projects\TopDriver\x64\Release\KMDFDriverTest.sys"
3. Text in cmd: bcdedit /set testsigning on
4. Reboot your system
5. Download DebugView
6. Run DebugView, in capture enable Capture Kernel, Enable Verbose Kernel OutPut
7. Run cmd as administrator and paste this: sc start "name of your driver"
8. Run exe file which was compiled in your Reales folder
9. Play with this anti flash

Good Luck
