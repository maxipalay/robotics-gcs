#! /bin/bash

#WLANS=$@
CHANNEL5G="165"

ip link set wlan0 down
ip link set wlan1 down
iw dev wlan0 set type monitor
iw dev wlan1 set type monitor
ip link set wlan0 up
ip link set wlan1 up
iw dev wlan0 set channel $CHANNEL5G HT20 
iw dev wlan1 set channel $CHANNEL5G HT20 
#HT40+

(trap 'kill 0' SIGINT;
/home/max/develop/wifibroadcast/wfb_tx -p 2 -u 7000 -K /home/max/develop/wifibroadcast/gs.key wlan0 wlan1)
