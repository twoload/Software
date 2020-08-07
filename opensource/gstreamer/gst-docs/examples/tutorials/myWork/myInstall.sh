echo "gcc $1 `pkg-config --cflags --libs gstreamer-1.0` && ./a.out"
gcc $1 `pkg-config --cflags --libs gstreamer-1.0` && ./a.out
