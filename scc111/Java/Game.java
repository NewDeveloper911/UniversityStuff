public class Game {
    public static void main(String[] args)
    {
        GameArena arena = new GameArena(500, 300);
        Ball b = new Ball(250, 150, 20, "GREEN");
        arena.addBall(b);

        //Moving the ball
        int moveX = 0;
        int moveY = 0;
        int speed = 5;

        while(true)
        {   arena.pause();
            moveX = 0;
            moveY = 0;

            if(arena.downPressed()&& b.getYPosition() + (b.getSize()/2) < arena.getArenaHeight()){
                moveY = 1;
            }
            if(arena.upPressed() && b.getYPosition() - (b.getSize()/2) > 0){
                moveY = -1;
            }
            if(arena.leftPressed() && b.getXPosition() - (b.getSize()/2)> 0){
                moveX = -1;
            }
            if(arena.rightPressed() && b.getXPosition() + (b.getSize()/2) < arena.getArenaWidth()){
                moveX = 1;
            }
            b.move(moveX * speed, moveY * speed);
        }
    }
}
