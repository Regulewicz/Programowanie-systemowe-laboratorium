Cfile := hello.c
Target := hello
out_dir := build
Source := SRC
CC := gcc
File.o := hello.o


all: $(Target)


$(Target): $(out_dir) $(File.o)
	$(CC) $(out_dir)/$(File.o) -o $(out_dir)/$(Target)
	
$(File.o): $(out_dir)
	$(CC) -c $(Source)/$(Cfile) -o $(out_dir)/$(File.o) 

$(out_dir):
	mkdir $(out_dir)

clean:
	rm -rf $(out_dir)
