# !/bin/bash

echo "This script will install Zephir language tools in your $(uname -r) environment"

# User root
cd ~

# Install environment requirements
sudo yum install -y php-devel gcc make re2c autoconf

# Gets the source code from Github and installs
echo "Installing Zephir parser"
git clone git://github.com/phalcon/php-zephir-parser.git
cd php-zephir-parser
sudo ./install

# Add Zephir parser extension in php.ini file

sudo "[Zephir extension]" >> /etc/php.ini
sudo "extension=zephir_parser.so" >> /etc/php.ini

# Restart web server
sudo systemctl restart httpd

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
