# ArangoDB PHP Driver

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/41fd329675c64a7ab583ebbdc1a88db1)](https://www.codacy.com/app/lucassouzavieira/arangodb-php-driver?utm_source=github.com&utm_medium=referral&utm_content=lucassouzavieira/arangodb-php-driver&utm_campaign=badger)

A client for ArangoDB compiled as an extension for PHP.

## Description

ArangoDB-PHP-Driver is a PHP client for ArangoDB written as C-extension for language.  
This project is still in work in progress (WIP), so some features are still being implemented.

## Requirements

* PHP 7+
* PHP-Json extension

## Installing

While the driver is still being implemented, you can install it from this repository using the Zephir language tools.
To help you with this task, there are two configuration scripts in `config` directory. They will install Zephir parser and Zephir language in your environment.

### Debian, Ubuntu, Mint and other Debian-based distros

Use the Debian script:  
`sudo chmod a+x config\debian\install.sh`  
`sudo ./config\debian\install.sh`

### Fedora, CentOS or RHEL

Use the Fedora script:  
`sudo chmod a+x config\fedora\install.sh`  
`sudo ./config\fedora\install.sh`

The next step is to clone this repository and compile the extension:

`git clone https://github.com/lucassouzavieira/arangodb-php-driver.git`  
`cd arangodb-php-driver/`  
`sudo zephir build` (Because the extension is also added in your `php.ini` file)

## How to Use PHP Client

 We will soon add more information about this

## How to contribute

* Fork this repository
* Clone your fork
* Add this repository as second remote to your own with this command:
 `git remote add upstream https://github.com/lucassouzavieira/ArangoDB-PHP-Driver.git`
* Check our open issues or open a new if you find a trouble
* Open a Pull Request to integrate your contribution

and also, we recommend reading the following article: [Contributing to open source](https://opensource.guide/how-to-contribute/)

## License

ArangoDB-PHP-Driver is distributed under MIT License.
