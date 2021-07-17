# symbolic link
## remove all symbolic link in target directory
* find -type l -delete
* find -type l -exec rm {} \;
* find -type l -exec unlink {} \;
* https://unix.stackexchange.com/questions/39333/how-can-i-remove-all-symbolic-links-with-a-special-target
## remove broken symbolic link in target directory
* find -L $DIR -maxdepth 1 -type l -delete
* https://stackoverflow.com/questions/22097130/delete-all-broken-symbolic-links-with-a-line
