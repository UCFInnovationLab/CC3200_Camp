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

