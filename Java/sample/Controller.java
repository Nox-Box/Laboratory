package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;

public class Controller {
    //Графический контекст позволяет отрисовывать объекты на форме
    private GraphicsContext GC;

    @FXML
    public Canvas canvas;

    //Действие на нажатие кнопки
    public void BCube(ActionEvent event){
        //Очиска формы
        GC.clearRect(0,0, canvas.getWidth(), canvas.getHeight());
        //Класс куба, отрисовывает куб (Параметры: координаты x, координаты y, размер, графический контекст в котором будет отрисовываться объект)
        new Figure2d.Cube(canvas.getWidth()/2,canvas.getHeight()/2,50,GC);
    }

    public void BTriangle(ActionEvent event) {
        //Очиска формы
        GC.clearRect(0,0, canvas.getWidth(), canvas.getHeight());
        //Класс ромба, отрисовывает куб (Параметры: координаты x, координаты y, размер, графический контекст в котором будет отрисовываться объект)
        new Figure2d.Triangle(canvas.getWidth()/2,canvas.getHeight()/2,50,GC);
    }

    public void BCircle(ActionEvent event) {
        //Очиска формы
        GC.clearRect(0,0, canvas.getWidth(), canvas.getHeight());
        //Класс круга, отрисовывает куб (Параметры: координаты x, координаты y, размер, графический контекст в котором будет отрисовываться объект)
        new Figure2d.Circle(canvas.getWidth()/2,canvas.getHeight()/2,50,GC);
    }

    //Функция инициализации формы, выполняет действия до появления формы и производить инициализацию объектов
    @FXML
    public void initialize(){
        //В графический контекст помещяем форму на которой и будет производиться рисование
        GC = canvas.getGraphicsContext2D();
        //Очиска формы
        GC.clearRect(0,0, canvas.getWidth(), canvas.getHeight());
    }


}
