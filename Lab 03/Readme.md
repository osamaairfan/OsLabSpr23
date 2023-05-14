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
> 
> read -p "Name of recipient: " recp
> 
> subj="Network adapters"
> 
> ifconfig > file.txt
> 
> mail -s "$subj" $recp < file.txt
> 
> rm file.txt
> 
> echo "Mail sent successfully!"

## Q3
```
#!/bin/bash

create_share() {
  sudo apt update
  sudo apt install samba -y

  # backup original cfg
  sudo cp /etc/samba/smb.conf /etc/samba/smb.conf.bak

  sudo mkdir /tmp/public

  sudo bash -c 'echo "[public]" >> /etc/samba/smb.conf'
  sudo bash -c 'echo "Comment = Public Share" >> /etc/samba/smb.conf'
  sudo bash -c 'echo "Path = /tmp/public" >> /etc/samba/smb.conf'
  sudo bash -c 'echo "Browseable = yes" >> /etc/samba/smb.conf'
  sudo bash -c 'echo "Read only = no" >> /etc/samba/smb.conf'
  sudo bash -c 'echo "Guest ok = yes" >> /etc/samba/smb.conf'

  sudo service smbd restart
}

remove_share() {
  sudo service smbd stop

  # restore original samba config
  sudo mv /etc/samba/smb.conf.bak /etc/samba/smb.conf

  # remove the shared folder
  sudo rm -rf /tmp/public
}

echo "Enter your choice: "
echo "Enter '1' to set up a new share or '2' to stop the current smb share:"
read option

if [ "$option" == "1" ]; then
  create_share
elif [ "$option" == "2" ]; then
  remove_share
else
  echo "Invalid option. Exiting."
  exit 1
fi
```
