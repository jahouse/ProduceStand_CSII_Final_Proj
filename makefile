#Jada Houser
# Project Assignment 4
# Instructor: Dr. Yvon Feaster
# CPSC 1020 Fall 2017

project4:
	g++ clientFunct.cpp ProduceStand.cpp Vegetable.cpp Fruit.cpp Person.cpp Address.cpp Date.cpp PersonList.cpp driver.cpp -std=c++11 -Wall -o driver

run:
	./driver inputMulti.txt out.txt mailing_list.txt
	cat out.txt 
	cat mailing_list.txt

clean:
	rm -f out.txt 
