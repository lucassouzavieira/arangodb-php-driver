# !/bin/bash

echo "This script will install Zephir language tools in your $(uname -r) environment"

# User root
cd ~

# Install environment requirements
sudo apt-get install -y php7.0-dev gcc make re2c autoconf libpcre3-dev

# Gets the source code from Github and installs
echo "Installing Zephir parser"
git clone git://github.com/phalcon/php-zephir-parser.git
cd php-zephir-parser
sudo ./install

# Add Zephir parser extension in php.ini file

echo "[Zephir extension]" | sudo tee -a /etc/php/7.0/apache2/php.ini > /dev/null
echo "extension=zephir_parser.so" | sudo tee -a /etc/php/7.0/apache2/php.ini > /dev/null

# Restart web server
sudo systemctl restart apache2

# User root
cd ~

# Install Zephir globally
echo "Installing Zephir language"
git clone https://github.com/phalcon/zephir.git
cd zephir
sudo ./install -c

# User root
cd ~
echo "Installation complete ! Try 'zephir' in your terminal"
