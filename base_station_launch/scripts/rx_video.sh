#! /bin/bash

#WLANS=$@
#CHANNEL5G="165"

#ip link set wlan0 down
#iw dev wlan0 set type monitor
#ip link set wlan0 up
#iw dev wlan0 set channel $CHANNEL5G HT40+
#ip link set wlan1 down
#iw dev wlan1 set type monitor
#ip link set wlan1 up
#iw dev wlan1 set channel $CHANNEL5G HT40+

(trap 'kill 0' SIGINT;
/home/max/develop/wifibroadcast/wfb_rx -p 1 -u 5600 -K /home/max/develop/wifibroadcast/gs.key wlan0 wlan1)

