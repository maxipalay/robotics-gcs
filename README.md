# robotics-gcs

This repository contains files for the Robotics Ground Control Station.

* print_inputs.ino - test file generate to test if the inputs were read correctly by the arduino, values are printed through serial monitor
* base_station.ino - Arduino sketch that rreads one joystick, encodes the values as a Twist messages and published it to /cmd_vel
* base_station_launch * ros node that launches all the ground station ros applications (rviz, gstreamer, rosserial_python)
