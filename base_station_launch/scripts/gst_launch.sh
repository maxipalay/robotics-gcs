#! /bin/bash

(trap 'kill 0' SIGINT;
gst-launch-1.0 udpsrc port = 5600 ! application/x-rtp ! rtph264depay ! queue ! h264parse ! nvv4l2decoder ! nv3dsink -e
)

