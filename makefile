build:
	rm -f a.out
	g++ -std=c++20 -g -Wall main.cpp -Wno-psabi
  
run:
	./a.out

submit:
	/gradescope/gs submit 1396807 8888482 *.cpp

commit:
	git add .
	git commit -m "${msg}"

push:
	git push origin main
