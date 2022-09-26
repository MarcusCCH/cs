# Done by Chan, Cheuk Hang Marcus. SID: 20957273
import random
import turtle

fontSize = 30;
scr = turtle.Screen()
num = random.randint(1,100); 
cnt = 0; 

guess = scr.textinput(
    "Guessing Game", "I am thinking of a number. What number am I thinking of?");
turtle.write(
    "I am thinking of a number. What number am I thinking of?", font=(fontSize))
turtle.right(90)
turtle.up()
turtle.forward(20)
turtle.left(90)
while(guess != num):
    cnt  = int(cnt) + 1;
    guess = int(guess);
    if(guess <= 0 or guess >= 101):
        guess = scr.textinput(
            "Guessing Game","Please enter a number between 1 and 100");
        turtle.write("Please enter a number between 1 and 100", font = (fontSize));
    elif(guess > num):
        guess = scr.textinput("Guessing Game","Too high");
        turtle.write("Too high", font=(fontSize))
    elif(guess < num):
        guess = scr.textinput("Guessing Game","Too low");
        turtle.write("Too low", font=(fontSize))
    elif(guess == num):
        turtle.write("You got it! My number is " + str(num) + ".", font=(fontSize))
        
    turtle.right(90); 
    turtle.up();  
    turtle.forward(20);
    turtle.left(90);
        
turtle.write("It took you " + str(cnt) +
             " guesses to get the number", font=(fontSize));
turtle.done();