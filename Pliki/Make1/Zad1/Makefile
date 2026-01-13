Username := $(shell whoami)
timestamp := $(shell date +%s)
File := $(Username).$(timestamp)
out_dir := build

all: data.txt $(out_dir)

	cp data.txt $(out_dir)/$(File)    
clean:
	rm -rf $(out_dir) data.txt
        
data.txt:
	echo "cos losowego" > data.txt
$(out_dir):
	mkdir $(out_dir)
