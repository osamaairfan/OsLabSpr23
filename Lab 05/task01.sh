#!/bin/bash

sudo apt update
sudo apt install apache2 -y
sudo apt install ufw
sudo ufw allow 80
sudo apt install mysql-server -y
sudo apt install mariadb-server -y
sudo apt install php libapache2-mod-php php-mysql -y
sudo touch /var/www/html/info.php
sudo chmod 777 /var/www/html/info.php
sudo echo "<?php phpinfo(); ?>" > /var/www/html/info.php
sudo chmod 644 /var/www/html/info.php
sudo systemctl restart apache2
sudo systemctl start mysql
