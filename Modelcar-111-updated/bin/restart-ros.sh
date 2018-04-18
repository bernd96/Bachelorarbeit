#!/bin/bash

echo "Stopping ROS ..."
ssh root@192.168.43.111 'pkill -f ros'

sleep 3

echo "Running autostart.sh ..."
ssh root@192.168.43.111 './autostart.sh' &

echo "Finished!"
