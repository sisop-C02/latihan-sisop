#!/bin/bash

filename=$(date)
# filename=`date`

du -sh /home/maroqi/Downloads > /home/maroqi/log/"${filename}"
