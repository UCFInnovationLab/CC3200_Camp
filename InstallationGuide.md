Installing Energia IDE for CC3200 LaunchPad
===========================================
We will use Energia IDE to program the CC3200 LaunchPad device. The homepage for Energia IDE is hosted at https://energia.nu/. Instructions on downloading the software and its drivers are given on https://energia.nu/download/. The following instructions are for Windows users. If you use Mac OS or Linux please follow instructions for such on https://energia.nu/download/

Energia IDE Software
----------------------
1) Download Windows Binary release version for Energia from https://energia.nu/download/
2) Unzip the contents of the downloaded file to a folder
3) Click on the Energia icon in the unzipped folder to run the Energia IDE

Drivers
-------
4) Download the CC3200 LaunchPad driver from http://energia.nu/guide/install/windows/
5) Unzip the contents of the downloaded file to a folder
6) Run the 'Energia Drivers for Windows' file to install the drivers 

Setup Configuration for CC3200
---------------------------------------
7) In the Energia IDE select 'Boards Manager' from the 'Tools' dropdown menu: Tools > Board > Boards Manager
8) Find CC3200 boards and click on install
9) In the Energia IDE select 'Manage Libraries' from the 'Sketch' dropdown menu: Sketch > Include Library > Manage Libraries
10) Find M2XStreamClient and install version 2.2.0

Downloading the program to your CC3200 device
=============================================
1) Browse to https://github.com/UCFInnovationLab/CC3200_Camp
2) Click on 'Clone or download' button and then click 'Download ZIP'
3) Unzip the contents of the downloaded file to a folder
4) From the Energia IDE click 'Open' in the 'File' dropdown menu: File > Open
5) Browse to folder where you unzipped the file and select file 'LaunchPad3200WiFiPost.ino' in the 'LaunchPad3200WiFiPost' subfolder
6) Click on 'Board' in the 'Tools' dropdown menu and choose 'CC3200-LAUNCHXL (80 MHz)': Tools > Board
7) Plug in your board into your USB port
8) Click on 'Port' in the 'Tools' dropdown menu and select the 'COM_' port that your device is attached to: Tools > Port
9) Click on Serial Monitor in 'Tools' dropdown menu to open a new window: Tools > Serial Monitor
10) Download the program onto the CC3200 board by clicking 'Upload' in the 'Sketch' dropdown menu: Sketch > Upload
11) You should be able to see your board communicating with your CC3200 device through the 'Serial Monitor' window that you just opened up
