all: feedback feedback_priv

feedback_priv: feedback.c
	gcc -o $@ $^ -fno-stack-protector -no-pie
	cp $@ ../deploy/bin/feedback_priv

feedback: feedback_dist.c
	gcc -o $@ $^ -fno-stack-protector -no-pie
	cp $@ ../dist/$@