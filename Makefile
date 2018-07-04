

lib_objects :=hdparm-9.48+ds/geom.o  hdparm-9.48+ds/sysfs.o hdparm-9.48+ds/fibmap.o

all: lba.a test  

clean :
	rm -f lba.a $(lib_objects) test.o test

lba.a : $(lib_objects)
	@echo "  -> $@ "
	@ar -r $@ $(lib_objects)

hdparm-9.48+ds/%.o : hdparm-9.48+ds/%.c ;
	@echo "  -> $@ "
	@gcc -c $< -o $@ 

test : test.cpp  ;
	@echo "  -> $@ "
	@g++  -std=gnu++11 -c test.cpp -o test.o 
	@g++ test.o lba.a -o $@
