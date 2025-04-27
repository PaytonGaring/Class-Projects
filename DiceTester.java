package assignment2;

public class DiceTester{

    public static void main(String[] args){
        Dice dice = new Dice();

        int[] diceValuesArr = new int[13];
        int diceValue = 0;

        for (int i = 0; i < 1000; i++)
        {
            dice.roll();
            diceValue = dice.DiceSum();
            diceValuesArr[diceValue]++;
        }
        for (int i = 2; i < diceValuesArr.length; i++)
        {
            system.out.println("Number of" + [i] + "s are" + diceValuesArr[i]);
        }

        System.out.println("Graph");

        for (int i = 175; i >= 0; i -= 25){
            System.out.print(i + " | ");
            for (int j = 2; j < faceValuesArr.length; j++)
            {
                if (diceValuesArr[j] * 25 >= i)
                {
                    System.out.print("* ");
                    else {
                        System.out.print(" ");
                    }   
                }
                System.out.println();
            }
        System.out.println("    --------------------------------");
        System.out.println("     2  3  4  5  6  7  8  9 10 11 12");
        }

    }
}