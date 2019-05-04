Installing Energia IDE for CC3200 LaunchPad
===========================================
We will use Energia IDE to program the CC3200 LaunchPad device. The homepage for Energia IDE is hosted at https://energia.nu/. Instructions on downloading the software and its drivers are given on https://energia.nu/download/. The following instructions are for Windows users. If you use Mac OS or Linux please follow instructions for such on https://energia.nu/download/

Software
--------
1) Download Windows Binary release version for Energia from https://energia.nu/download/
2) Unzip the contents of the downloaded file to a folder
3) Click on the Energia icon in the unzipped folder to run the Energia IDE

Drivers
-------
4) Download the CC3200 LaunchPad driver from http://energia.nu/guide/install/windows/
5) Unzip the contents of the downloaded file to a folder
6) Run the 'Energia Drivers for Windows' file to install the drivers 

Software Setup Configuration for CC3200
---------------------------------------
7) In the Energia IDE select 'Boards Manager' from the 'Tools' dropdown menu: Tools > Board > Boards Manager
8) Find CC3200 boards and click on install
9) In the Energia IDE select 'Manage Libraries' from the 'Sketch' dropdown menu: Sketch > Include Library > Manage Libraries
10) Find M2XStreamClient and install version 2.2.0
