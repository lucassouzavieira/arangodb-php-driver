#!/bin/bash
echo "This script will install ArangoDB PHP Driver $(uname -r) environment"

# PHP modules directory
cd /usr/lib64/php/modules/
sudo wget https://github.com/lucassouzavieira/arangodb-php-driver/blob/master/ext/modules/arango.so
sudo chmod a+x arango.so

# Add ArangoDB driver extension in .ini configuration file
sudo touch /etc/php.d/30-arango.ini
echo ";ArangoDB Driver" | sudo tee -a /etc/php.d/30-arango.ini > /dev/null
echo "extension=arango.so" | sudo tee -a /etc/php.d/30-arango.ini > /dev/null

# Restart web server
sudo systemctl restart httpd

echo "Installation complete !"
