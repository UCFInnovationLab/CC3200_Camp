# UCF Innovation Lab CC3200 Camp
In this camp, you will learn how to program a **CC3200 LaunchPad** to upload data (temperature, vibration) to a server on the web. The CC3200 is a chip made by Texas Instruments that supports wireless connectivity. A popular term for devices made with these chips is an **Internet of Things (IoT)** device.

**The basic steps to accomplish this lab are listed below:**
1. Unpack and set up CC3200 LaunchPad
1. Install Energia IDE (Compiler) for the CC3200 LaunchPad
1. Download example software from UCF Innovation Lab *GitHub* Repository
1. Program the CC3200 LaunchPad with the example software
1. Modify software to include your home access point SSID and password 

## Unpack and Set Up CC3200 LaunchPad


## Installing Energia IDE for CC3200 LaunchPad

We will use **Energia IDE** to program the **CC3200 LaunchPad** device. The homepage for Energia IDE is hosted at https://energia.nu/. Instructions on downloading the software and its drivers are given on https://energia.nu/download/. 

**Please follow the instructions given at that website and read the additional notes below.**
First, download Energia 1.8.7E21 (10/17/2018) from the website above based on which operating system you use.
Then, click on the link for the instaliation guide for CC3200 based on your operating system. 
* make sure to **follow the instructions on this page for important jumper settings and firmware upgrade instructions.**
Follow steps 1-6, making sure to download all the software. 
* To connect your CC3200 to your computer (step 6), use the cord provided in the box.

**Next, follow these steps to configure Energia IDE for your board.**
* In the Energia IDE select Boards Manager from the Tools dropdown menu: Tools > Board > Boards Manager
* Find CC3200 boards and click on install (make sure you select "Energia CC3200 boards by Energia"
* In the Energia IDE select Manage Libraries from the Sketch dropdown menu: Sketch > Include Library > Manage Libraries
* Find M2XStreamClient and install version 2.2.0

Downloading the program to your CC3200 device
=============================================
1) Browse to https://github.com/UCFInnovationLab/CC3200_Camp
2) Click on **Clone or download** button and then click **Download ZIP**
3) Unzip the contents of the downloaded file to a folder
4) From the Energia IDE click **Open** in the **File** dropdown menu:<br/>
**File > Open**
5) Browse to folder where you unzipped the file and select file **LaunchPad3200WiFiPost.ino** in the **LaunchPad3200WiFiPost** subfolder
6) Click on **Board** in the **Tools** dropdown menu and choose **CC3200-LAUNCHXL (80 MHz)**:<br/>
**Tools > Board > CC3200-LAUNCHXL (80 MHz)**
7) Plug in your board into your USB port
8) Click on **Port** in the **Tools** dropdown menu and select the **COM_** port that your device is attached to:<br/>
**Tools > Port > COM_**
9) Click on **Serial Monitor** in **Tools** dropdown menu to open a new window:<br/>
**Tools > Serial Monitor**
10) Download the program onto the CC3200 board by clicking **Upload** in the **Sketch** dropdown menu:<br/>
**Sketch > Upload**
11) You should be able to see your board communicating with your computer through the **Serial Monitor** window that you just opened up

# Customize Board for Your Access Point

In this section, you will configure the board to connect to your home access point. You will need the SSID and Password of your access point. This information will be inserted into the program.

Network Configuration
---------------------

If you are using a Wi-Fi BosoterPack or LaunchPad, the following variables need configuration:

```
char ssid[] = "<ssid>";
char pass[] = "<WPA password>";
```

Just fill in the SSID and password of the Wi-Fi hotspot, you should be good to go.

