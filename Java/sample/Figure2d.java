package sample;


import javafx.scene.canvas.GraphicsContext;


public class Figure2d {

    //Класс фигуры, содержит стандартные значения и функции для фигур
    private static class Figure{
        protected double x, y, size;

        protected Figure(double x, double y, double size){
            this.x = x;
            this.y = y;
            this.size = size;
        }

        public void setPosition(double x, double y){
            this.x = x;
            this.y = y;
        }

        public void setSize(double size){
            this.size = size;
        }

    }

    //Класс куб который наследуется от класса фигуры
    public static class Cube extends Figure{

        private final GraphicsContext gc;

        public Cube(double x, double y, double size, GraphicsContext gc){
            super(x, y, size);
            this.gc = gc;
            DrawCube();
        }
        //Отрисовка куба на форме
        public void DrawCube(){

            gc.beginPath();
            gc.moveTo(x - size,y - size);
            gc.lineTo(x - size, y + size);
            gc.lineTo(x + size, y + size);
            gc.lineTo(x + size, y - size);
            gc.closePath();
            gc.fill();
            gc.stroke();
        }
    }

    //Класс треугольник который наследуется от класса фигуры
    public static class Triangle extends Figure{

        private final GraphicsContext gc;

        public Triangle(double x, double y, double size, GraphicsContext gc){
            super(x, y, size);
            this.gc = gc;
            DrawTriangle();
        }
        //Отрисовка Треугольника на форме
        public void DrawTriangle(){
            gc.beginPath();
            gc.moveTo(x - size, y);
            gc.lineTo(x + size, y);
            gc.lineTo( x, y - size);
            gc.closePath();
            gc.fill();
            gc.stroke();
        }
    }


    //Класс круг который наследуется от класса фигуры
    public static class Circle extends Figure{

        private final GraphicsContext gc;
        public Circle(double x, double y, double radius,  GraphicsContext gc){
            super(x, y, radius);
            this.gc = gc;
            DrawCircle();
        }
        //Отрисовка круга на форме
        public void DrawCircle(){
            gc.beginPath();
            gc.moveTo(x, y);
            double x1,y1, n;
            n = 0;
            while (n < 2*Math.PI){
                x1 = Math.round(x+size*Math.cos(n));
                y1 = Math.round(y+size*Math.sin(n));
                gc.lineTo( x1, y1);
                n = n + 1/size;
            }
            gc.closePath();
            gc.fill();
            gc.stroke();
        }
    }


}
