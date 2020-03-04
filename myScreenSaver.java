//Thuan Nguyen
//C SCI 14
//This picture is drawing about my screensaver 	with welcome board and pacman move to my house 
// Enjoy my screen saver 

package homework;
import java.awt.Color;
import java.awt.Font;
import acm.program.GraphicsProgram ;
import acm.graphics.*;
public class myScreenSaver extends GraphicsProgram {
	private static final String WELCOME = null;

	public void init()	
	{
		setBackground(Color.black);
		setSize(1100, 1000);
	}
public void run()
{
//Draw the wellcome board 
	GRect rectangle= new GRect (50,600,1000,100);
	add(rectangle );
	rectangle.setFilled(true);
	rectangle.setFillColor( Color.blue );	
	rectangle.setColor(Color.ORANGE);
	GLabel message= new GLabel("WELCOME TO MY HOUSE ");
	add(message,310 ,600 );
	message.setColor(Color.RED );
	Font myFont = new Font("Arial Narrow", Font.PLAIN, 50);
	message.setFont(myFont);
	
/// Draw the pacman 
	GArc pacman = new GArc (50, 370,100,100,45,270);
	add(pacman );
	pacman.setFilled(true );
	pacman.setFillColor(Color.YELLOW);
	
/// Draw the circle point
	GOval circle= new GOval (200,420 ,35,17 );
	add(circle);
	circle.setFilled(true);
	circle.setFillColor(Color.YELLOW );
	
	GOval circle1 = new GOval (300,420 ,35,17 );
	add(circle1 );
	circle1.setFilled(true);
	circle1.setFillColor(Color.YELLOW );
	
	GOval circle2 = new GOval (400 ,420 ,35,17 );
	add(circle2);
	circle2.setFilled(true);
	circle2.setFillColor(Color.YELLOW );
	
	GOval circle3 = new GOval (500 ,420 ,35,17 );
	add(circle3 );
	circle3 .setFilled(true);
	circle3 .setFillColor(Color.YELLOW );
	
	
	GOval circle4 = new GOval (600,420 ,35,17 );
	add(circle4 );
	circle4 .setFilled(true);
	circle4 .setFillColor(Color.YELLOW );
///Draw the roof 
	GPolygon roof= new GPolygon();
	add(roof);
	roof.addVertex(825,130);
	roof.addVertex(700,200);
	roof.addVertex(950,200);
	roof.setFilled(true);
	roof.setColor(Color.RED);
///Draw the house
	GRect rectangle1= new GRect(700,200,250,280);
	add(rectangle1);
	rectangle1.setFilled(true);
	rectangle1.setFillColor( Color.white );
	rectangle1.setColor(Color.red );
	
///Draw the robot in the house 	
	GRect rectangle2= new GRect(775,300,90,50);
	add(rectangle2);
	rectangle2.setFilled(true);
	rectangle2.setFillColor( Color.PINK);
	
	GPolygon robot = new GPolygon();
	add(robot);
	robot.addVertex(820,350);
	robot.addVertex(785,410);
	robot.addVertex(855,410);
	robot.setFilled(true);
	robot.setColor(Color.RED);
/// hand and feet of robot 
	
	GLine Line1= new GLine (785,370,805,380);
	add(Line1);
	Line1.setColor(Color.black );
	
	GLine Line2= new GLine (835,380,855,370);
	add(Line2);
	Line2.setColor(Color.black );
	
	GLine Line3 = new GLine (830,410,830,430);
	add(Line3);
	Line3.setColor(Color.black );
	
	GLine Line4= new GLine (815,410,815,430);
	add(Line4);
	Line4.setColor(Color.black );
	/// face of robot 
	GOval circle5= new GOval (790,315,15,3 );
	add(circle5);
	circle5.setFilled(true);
	circle5.setFillColor(Color.RED);
	
	GOval circle6= new GOval (830,315,15,3 );
	add(circle6);
	circle6.setFilled(true);
	circle6.setFillColor(Color.RED);
	
	GOval circle7= new GOval (810,337,15,3 );
	add(circle7);
	circle7.setFilled(true);
	circle7.setFillColor(Color.RED);
/// Move the pacman 
	while(true){
		if (pacman.getX()<750) {
		pacman.move(1 , 0);
		pause(15);
		}
		if(pacman.getX()==750 & circle.getX()<=700) {
		circle.move(1 , 0);
		pause(5);
		if(pacman.getX()==750 & circle1.getX()<=700)
		circle1.move(1 , 0);
		pause(5);
		if(pacman.getX()==750 & circle2.getX()<=700)
		circle2.move(1 , 0);
		pause(5);
		if(pacman.getX()==750 & circle3.getX()<=700)
		circle3.move(1 , 0);
		pause(5);
		if(pacman.getX()==750 & circle4.getX()<=700)
		circle4.move(1 , 0);
		pause(5);
		}

	}

	
	}
	}
