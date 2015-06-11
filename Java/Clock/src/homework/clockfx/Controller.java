package homework.clockfx;

import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.transform.Affine;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Controller {

    public GraphicsContext g;

    @FXML
    Canvas MainForm;

    private int second, minute, hour;
    private boolean running;

    public void setSecond(int second) {
        this.second = second;
    }

    public void setMinute(int minute) {
        this.minute = minute;
    }

    public void setHour(int hour) {
        this.hour = hour;
    }

    public void setRunning(boolean running) {
        this.running = running;
    }

    public int getSecond() {
        return second;
    }

    public int getMinute() {
        return minute;
    }

    public int getHour() {
        return hour;
    }

    public boolean isRunning() {
        return running;
    }

    public void paint() {
        double cX = MainForm.getWidth();
        double cY = MainForm.getHeight();
        double r = cY < cX ? cY / 2 : cX / 2;
        g = MainForm.getGraphicsContext2D();
        g.setFill(Color.WHITE);
        g.fillRect(0, 0, MainForm.getWidth(), MainForm.getHeight());
        g.setFill(Color.BLUE);

        g.strokeOval(0, 0, cX, cY);
        g.setFill(Color.CHOCOLATE);
        g.fillOval(0, 0, cX, cY);
        g.setFill(Color.BROWN);
        g.fillOval(cX / 2 - 5, cY / 2 - 5, 10, 10);
        double x1 = cX / 2, x2 = cX / 2, y1 = 0, y2 = cY / 2;
        drawLine(r / 10, 2, getSecond() * 6, x1, y1, x2, y2);
        drawLine(r / 2.5, 2.5, getMinute() * 6, x1, y1, x2, y2);
        drawLine(r *2/3, 3, getHour() * 30, x1, y1, x2, y2);
    }

    public void drawLine(double len, double wide, double angle, double x1, double y1, double x2, double y2) {
        double oldWide = g.getLineWidth();
        g.setLineWidth(wide);
        Affine af = new Affine();
        af.appendRotation(angle, x2, y2);
        g.setTransform(af);
        g.strokeLine(x1, y1 + len, x2, y2);
        af.appendRotation(360 - angle, x2, y2);
        g.setTransform(af);
        g.setLineWidth(oldWide);
    }

    public void updateTime() {
        setSecond(getSecond() + 1);
        if (getSecond() == 60) {
            setSecond(0);
            setMinute(getMinute() + 1);
            if (getMinute() == 60) {
                setMinute(0);
                setHour(getHour() + 1);
                if (getHour() == 12) {
                    setHour(0);
                }
            }
        }

    }

    @FXML
    private void initialize() {
        Date currentDate = new Date();
        SimpleDateFormat format = new SimpleDateFormat();
        format.applyPattern("s");
        second = Integer.parseInt(format.format(currentDate));
        format.applyPattern("m");
        minute = Integer.parseInt(format.format(currentDate));
        format.applyPattern("h");
        hour = Integer.parseInt(format.format(currentDate));
    }

}