# git clone fail
* error : server certificate verification failed. CAfile: none CRLfile: none  
* solve : git config --global http.sslVerify false  

# dpkg ("debconf: DbDriver "config": config.dat is locked by another process)
* sudo fuser -v /var/cache/debconf/config.dat  
* sudo kill PID
* https://askubuntu.com/questions/136881/debconf-dbdriver-config-config-dat-is-locked-by-another-process-resource-t

# dns
* no ip site
* how to check dns : nslookup + sitename

# apache install
* https://www.digitalocean.com/community/tutorials/how-to-install-the-apache-web-server-on-ubuntu-20-04
```
$ sudo apt update
$ sudo apt install apache2  
$ sudo ufw enable (firewall)
$ sudo ufw allow 'Apache'
$ sudo ufw status
$ sudo systemctl status apache2
$ hostname -I
$ http://192.168.xxx.xxx (in my webrowser) and I can see apache page
```

# How to create a shared directory between host pc and virtual pc (ubuntu)  
* Create the shared directory  
https://helpdeskgeek.com/virtualization/virtualbox-share-folder-host-guest/  
* Permission Problem  
https://stackoverflow.com/questions/26740113/virtualbox-shared-folder-permissions  
Add yourself to the vboxsf group within the guest VM.  
Run sudo adduser $USER vboxsf from terminal.  And Reboot.


# Create static library using command line in Visual Studio
* I tried to use command line tool because I failed to create static library in GUI interface.  
  * I had to include stdafx.h in c source files. but I didn't know how to.  
    * Because stdafx.h is c++ file, it was difficult to adapt it to c codes.  
```
Windows > Developer Command Prompt for VS2017
$ cl /c source/*.c /linclude /DMONGO_STATIC_BUILD /DMONGO_USE_LONG_LONG_INT 
I could get obj files.
$ lib /out:MyBsonLib.lib *.obj
I could get MyBsonLib.lib
```
ref: 
https://www.zealfortechnology.com/2013/08/create-c-program-static-library-command-line-windows.html  
https://docs.microsoft.com/en-us/cpp/build/reference/i-additional-include-directories?view=msvc-160  
https://stackoverflow.com/questions/31763558/how-to-build-static-and-dynamic-libraries-from-obj-files-for-visual-c/31830252

# Ubuntu fix dependency problems
```
sudo apt-get clean
sudo apt-get update
sudo apt-get install -f
sudo dpkg -a --configure
sudo apt-get dist-upgrade

// apt-get install -f should try to fix most issues,
// but it won't fix everything.
// dpkg will try to further configure the packges, 
// The last command is to fully upgrade your system, including the linux kernel,
// again, run these commands after evertying is done
sudo apt-get install -f
sudo dpkg -a --configure
```

# wireshark 
## install and capture localhost packet
* https://osqa-ask.wireshark.org/questions/7523/ubuntu-machine-no-interfaces-listed


# ubuntu install
## keyboard hangul 101/104 choice
* 한/영 전환 키 사용시 필요함. 
* Region & Launguage -> Input Source: Korean Hangul add
* terminal > ibus-setup > input method > Korean Hangul add
** Etc > Start in Hangul mode 

# Citrix Workspace install (better)  
Because I can resize the screen, Citrix Receiver always displays full.  
* Download Citrix Workspace  
* Install: dpkg -i icaclient-xxxx.deb  
* Execute .ica file  
** But SSL error 9 happens.  
*** https://forums.linuxmint.com/viewtopic.php?t=253175  
*** reason: The problem is not inside Firefox. You have to make the Firefox certificates available to the Citrix receiver as well. The Citrix receiver does not look in the Firefox certificate directory.  
*** ```sudo ln -s /usr/share/ca-certificates/mozilla/* /opt/Citrix/ICAClient/keystore/cacerts/```



# Citrix Receiver install

## reference
* https://medium.com/@singhpraveen2010/how-to-run-citrix-ica-client-on-ubuntu-ea348dac277b
## Step
* icaclient download  
** https://www.citrix.com/downloads/citrix-receiver/legacy-receiver-for-linux/receiver-for-linux-131.ext.html  
** sudo dpkg -i icaclient_13.1.0.285639_amd64.deb; sudo apt-get -f install

* error happen  
```icaclient depends on libxerces-c3.1; however: Package libxerces-c3.1 is not installed. ```  
* download libxerces  
** sudo wget http://archive.ubuntu.com/ubuntu/pool/universe/x/xerces-c/libxerces-c3.1_3.1.3+debian-1_amd64.deb  
** cmake --build . --target install --config Debug  
* error happen   
** sudo wget  	http://archive.ubuntu.com/ubuntu/pool/main/i/icu/libicu55_55.1-7ubuntu0.5_amd64.deb  
* success  
** sudo dpkg -i icaclient_13.1.0.285639_amd64.deb; sudo apt-get -f install  
** sudo dpkg -i icaclient_13.1.0.285639_amd64.deb; 






