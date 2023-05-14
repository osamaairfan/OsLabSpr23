#!/bin/bash

read -p "Name of recipient: " recp
read -p "Subject: " subj
read -p "Body: " body
echo $body > file.txt

mail -s "$subj" $recp < file.txt
rm file.txt
echo "Mail sent successfully!"
