airline.out : flight.o flights.o main.o passenger.o plane.o utilities.o linkedlist.o  
	g++ -ansi -Wall -g -o airline.out flight.o flights.o main.o passenger.o plane.o utilities.o linkedlist.o  

flight.o : flight.cpp flight.h 
	g++ -ansi -Wall -g -c flight.cpp

flights.o : flights.cpp flights.h utilities.h passenger.h
	g++ -ansi -Wall -g -c flights.cpp

main.o : main.cpp passenger.h flight.h flights.h utilities.h 
	g++ -ansi -Wall -g -c main.cpp

passenger.o : passenger.cpp passenger.h plane.h 
	g++ -ansi -Wall -g -c passenger.cpp

plane.o : plane.cpp plane.h utilities.h passenger.h linkedlist.h 
	g++ -ansi -Wall -g -c plane.cpp

utilities.o : utilities.cpp utilities.h 
	g++ -ansi -Wall -g -c utilities.cpp

linkedlist.o : linkedlist.cpp linkedlist.h
	g++ -ansi -Wall -g -c linkedlist.cpp

clean : 
	rm -f airline.out flight.o  flights.o  main.o  passenger.o  plane.o  utilities.o linkedlist.o   
