# ubuntu install
## keyboard hangul 101/104 choice
* 한/영 전환 키 사용시 필요함. 
* Region & Launguage -> Input Source: Korean Hangul 추가
* terminal > ibus-setup > input method > Korean Hangul 추가  
** Etc > Start in Hangul mode 선택


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






