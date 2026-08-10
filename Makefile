build:
	gcc main.c -D_REENTRANT -I/usr/include/fribidi -I/usr/include/libdrm -I/usr/include/libdecor-0 -lSDL3 -o framebuffer
run:
	./framebuffer
