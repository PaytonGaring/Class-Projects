package assignment2;

// Garing Payton
// COP 3330-0001
// Professor Bacanli
// 9/16/2024

import java.util.Math;


public class Circle{

    private double radius; 
    private static int count;

    public Circle(double GivenRadius){
        radius = GivenRadius;
        count++;
    }

    public Circle(){
        radius = 1.0;
        count++;
    }
    public void setRadius(double GivenRadius){
        radius = GivenRadius;
    }

    public double getRadius(){
        return radius;

    }
    public double area(){
        return Math.PI * radius * radius;
    }

    public static int getInstanceCount(){
        return count; 
    }

    public String toString(){
        return "radius: " + radius + " area: " + area();
    }

    public static void main(String[] args){
        Circle myCircle = new Circle(2.3);
        Circle yourCircle = new Circle(1.8);

        System.out.println(myCircle.toString());
        System.out.println(yourCircle.toString());

        System.out.println("area: " + myCircle.area());
        System.out.println("area: " + yourCircle.area());

        System.out.println("Instances " + Circle.getInstanceCount());
    }
    }
