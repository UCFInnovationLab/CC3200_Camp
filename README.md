# UCF Innovation Lab CC3200 Camp
In this camp, you will learn how to program a **CC3200 LaunchPad** to connect to a local wireless access point and upload data to the web. The CC3200 is a chip made by Texas Instruments that supports wireless connectivity. A popular term for devices made with these chips is an **Internet of Things (IoT)**.

The basic steps to accomplish this lab are listed below:
1. Unpack and set up CC3200 LaunchPad
1. Install Energia IDE (Compiler) for the CC3200 LaunchPad
1. Download software from UCF Innovation Lab GitHub Repository
1. Program the CC3200 LaunchPad with the downloaded software
1. Modify software to include your home SSID and credentials 



## Installing Energia IDE for CC3200 LaunchPad

We will use **Energia IDE** to program the **CC3200 LaunchPad** device. The homepage for Energia IDE is hosted at https://energia.nu/. Instructions on downloading the software and its drivers are given on https://energia.nu/download/. The following instructions are for **Windows** users. If you use **Mac OS or Linux** please follow instructions for such on https://energia.nu/download/

Energia IDE Software
----------------------
1) Download **Windows Binary release version** for Energia from https://energia.nu/download/
2) Unzip the contents of the downloaded file to a folder
3) Click on the Energia icon in the unzipped folder to run the Energia IDE

Drivers
-------
4) Download the **CC3200 LaunchPad driver** from http://energia.nu/guide/install/windows/
5) Unzip the contents of the downloaded file to a folder
6) Run the **Energia Drivers for Windows** file to install the drivers 

Setup Configuration for CC3200
---------------------------------------
7) In the Energia IDE select **Boards Manager** from the **Tools** dropdown menu:<br/>
**Tools > Board > Boards Manager**
8) Find **CC3200 boards** and click on install
9) In the Energia IDE select **Manage Libraries** from the **Sketch** dropdown menu:<br/>
**Sketch > Include Library > Manage Libraries**
10) Find **M2XStreamClient** and install **version 2.2.0**

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










LaunchPad Energia M2X API Client
================================

The LaunchPad Energia library is used to send/receive data to/from [AT&amp;T's M2X Data Service](https://m2x.att.com/) from [Texas Instruments LaunchPad](http://www.ti.com/launchpad) development kits. It is compatible with any Energia enabled software environments and tested in the [Energia IDE](http://www.energia.nu).

Energia + AT&T M2X: Video Tutorial
==========================
[![Energia + AT&T M2X: Video Tutorial](http://img.youtube.com/vi/5FPMf2Bjmv8/0.jpg)](https://www.youtube.com/watch?v=5FPMf2Bjmv8&feature=youtu.be)

Hardware Setup
==============

Board Setup
-----------

The Energia website has a very good [tutorial](http://energia.nu/guide) on setting up the LaunchPad board. It contains detailed instructions on how to install the Energia IDE, and sets up your board for initial testing. Feel free to proceed to the [LaunchPad site](http://www.ti.com/launchpad) to get a basic idea on LaunchPad.

Wifi/Ethernet Shield Setup
--------------------------

The [CC3200 SimpleLink Wi-Fi LaunchPad CC3200-LAUNCHXL](http://www.ti.com/ww/en/launchpad/launchpads-connected-cc3200-launchxl.html#tabs) has built-in Wi-Fi and does not need any additional hardware.  

Variables used in Examples
==========================

In order to run the given examples, different variables need to be configured. We will walk through those variables in this section.

Network Configuration
---------------------

If you are using a Wi-Fi BosoterPack or LaunchPad, the following variables need configuration:

```
char ssid[] = "<ssid>";
char pass[] = "<WPA password>";
```

Just fill in the SSID and password of the Wi-Fi hotspot, you should be good to go.

M2X API Key
-----------

Once you [register](https://m2x.att.com/signup) for an AT&amp;T M2X account, an API key is automatically generated for you. This key is called a _Primary Master Key_ and can be found in the _Master Keys_ tab of your [Account Settings](https://m2x.att.com/account). This key cannot be edited nor deleted, but it can be regenerated. It will give you full access to all APIs.

However, you can also create a _Device API Key_ associated with a given Device, you can use the Device API key to access the streams belonging to that Data Source.

You can customize this variable in the following line in the examples:

```
char m2xKey[] = "<M2X access key>";
```

Device ID
-------

A device is associated with a data source, it is a set of data streams, such as streams of locations, temperatures, etc. The following line is needed to configure the device used:

```
char deviceId[] = "<device id>";
```

Stream Name
------------

A stream in a device is a set of timed series data of a specific type(i,e. humidity, temperature), you can use the M2XStreamClient library to send stream values to M2X server, or receive stream values from M2X server. Use the following line to configure the stream if needed:

```
char streamName[] = "<stream name>";
```

