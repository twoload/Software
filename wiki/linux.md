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






