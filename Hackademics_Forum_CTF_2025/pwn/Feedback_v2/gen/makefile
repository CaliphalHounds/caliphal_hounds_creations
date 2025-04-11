all: feedback_v2

feedback_v2: feedback_v2.c
	gcc -o $@ $^ -z execstack -fno-stack-protector -no-pie
	cp $@ ../deploy/bin/$@
	cp $@ ../dist/$@