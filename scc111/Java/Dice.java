public class Dice {
    int numSides;
    public int roll(){
        return (int) (1+ (Math.random() * (numSides-1)));
    } 
}