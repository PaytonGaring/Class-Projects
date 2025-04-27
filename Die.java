package assignment2;

import java.util.Random;

public class Die{
    private int faceValue;


    public Die(){
        this.faceValue = 1;
    }

    public int getFaceValue(){
        return faceValue;
    }


    public void setFaceValue(int faceValue){
        this.faceValue = faceValue;
    }

    public void roll(){

    Random Random = new Random();
    this.faceValue = Random.nextInt(6) + 1; 
    }
}