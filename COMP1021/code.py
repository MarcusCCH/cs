import random;
import turtle;

#lecture 6
turtle.speed(0);
turtle.width(5);
color = ["red","purple","blue","yellow","green", "orange"]
for i in range(20):
    rand_indx = random.randint(0,5);
    rand_x = random.randint(-200, 200);
    rand_y = random.randint(-200,200);
    rand_width =  random.randint(10, 200);
    rand_length = random.randint(10,200);
    rand_ang = random.randint(0, 180);
    # turtle.pencolor("transparent");
    turtle.penup();
    turtle.goto(rand_x, rand_y);
    # turtle.setx(rand_x);
    # turtle.sety(rand_y);
    turtle.left(rand_ang);
    turtle.pendown();
    turtle.fillcolor(random.choice(color));
    turtle.pencolor(random.choice(color));
    turtle.begin_fill();
    # turtle.circle( 10 , 360 );
    for i in range(2):
        turtle.forward(rand_width);
        turtle.left(90);
        turtle.forward(rand_length);
        turtle.left(90);
    turtle.end_fill();
turtle.done();


#lecture 4
# count = 1;
# while count <= 10: 
#     print(count);
#     count+=1;


#lecture 3
# turtle.speed(0);
# turtle.width(5);
# turtle.color("purple");
# turtle.fillcolor("yellow");
# turtle.begin_fill();
# for i in range(4):
#     turtle.forward(200);
#     turtle.left(90);
# turtle.end_fill();
# turtle.done();





# lecture 2
# x = random.randint(1,100);
# print(x);
# print("hello world");
# age = input("what is your age");
# age += 4;

# age_when_graduate = int(age) +4;
# age_string = str(age);


# print(age);
# print(type(age_string));

