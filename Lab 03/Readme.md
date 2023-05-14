# OS Lab 03
Name: M. Osama Irfan

Roll No: 21k-4772

Section: BCY-4A

## Q1
Following are the key points of the lab manual:
* Lab manual covers setting up static IP and DHCP.
* Also includes instructions for installing and setting up Samba on Linux.
* Guide provided for installing a Windows VM if using Ubuntu as main OS.

## Q2
The shell script below emails the output of the command 'ifconfig' to the specified recipient:

> #/usr/bin/bash
> read -p "Name of recipient: " recp
> subj="Network adapters"
> ifconfig > file.txt
> mail -s "$subj" $recp < file.txt
> rm file.txt
> echo "Mail sent successfully!"

## Q3
