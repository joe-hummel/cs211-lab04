build:
	rm -f a.out
	g++ -std=c++20 -g -Wall main.cpp -Wno-psabi

submit:
	/gradescope/gs submit 1130317 6955899 *.cpp

commit:
	git add .
	git commit -m "${msg}"

push:
	git push origin main
