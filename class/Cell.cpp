
class Cell
{
    /*
    This cell will make up the game play section. Once cells are created they are never deleted.
    The attribute alive will determine if the Cell is displayed.
    */

    public:
        int x;
        int y;
        bool alive;

        Cell(int x0, int y0) {
            x = x0;
            y = y0;
            alive = false;
        }
        void kill()
        {
            alive = false;
        }
        void live()
        {
            alive = true;
        }
};