Username := $(shell whoami)
timestamp := $(shell date +%s)
file_ := $(Username).$(timestamp)

all: data.txt
	cp data.txt $(file_)	
clean:
	rm $(Username).*
        
data.txt:
	echo "cos losowego" > data.txt
                                                                        
