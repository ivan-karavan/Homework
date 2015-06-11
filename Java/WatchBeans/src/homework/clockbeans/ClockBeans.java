package homework.clockbeans;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.Arc2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

/**
 * Created by Иван on 07.02.2015.
 */

public class ClockBeans extends JPanel {
    private double hours = 0;
    private double minutes = 0;
    private double seconds = 0;
    private boolean runnable = true;
    Timer timer;
    Calendar time;
    int r = 50;
    Point2D center;
    PropertyChangeSupport pcs;
    Date currentDate;

    public ClockBeans() {
        pcs = new PropertyChangeSupport(this);

        setPreferredSize(new Dimension(2 * r + 1, 2 * r + 1));
        timer = new Timer(1000, new TimerTick());

        currentDate = new Date();
        SimpleDateFormat format = new SimpleDateFormat();
        format.applyPattern("s");
        seconds = Double.parseDouble(format.format(currentDate));
        format.applyPattern("m");
        minutes = Double.parseDouble(format.format(currentDate));
        format.applyPattern("h");
        hours = Double.parseDouble(format.format(currentDate));

        timer.start();
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        r = getHeight() < getWidth() ? getHeight() / 2 : getWidth() / 2;
        time = new GregorianCalendar();
        center = new Point2D.Double(r, r);
        g2.setStroke(new java.awt.BasicStroke(4));
        g2.draw(new Ellipse2D.Double(0, 0, 2 * r, 2 * r));
        g2.setStroke(new java.awt.BasicStroke(2));
        g2.setColor(new Color(0, 130, 130));
        drawArrow(g, getHourAngle(), r / 2);
        g2.setColor(new Color(130, 0, 130));
        drawArrow(g, getMinuteAngle(), r * 0.75);
        g2.setColor(new Color(130, 130, 130));
        drawArrow(g, getSecondAngle(), r);
    }

    private double getHourAngle() {
        return Math.toRadians(90 - 360 * (time.get(Calendar.HOUR)) / 12);
    }

    private double getMinuteAngle() {
        return Math.toRadians(90 - 360 * time.get(Calendar.MINUTE) / 60);
    }

    private double getSecondAngle() {
        return Math.toRadians(90 - 360 * time.get(Calendar.SECOND) / 60);
    }

    void drawArrow(Graphics g, double arrowAngle, double arrowLength) {
        Graphics2D g2 = (Graphics2D) g;
        Point2D end = new Point2D.Double(r + arrowLength * Math.cos(arrowAngle),
                r - arrowLength * Math.sin(arrowAngle));
        g2.draw(new Line2D.Double(center, end));
    }

    class TimerTick implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {

            time = Calendar.getInstance();
            hours = time.get(Calendar.HOUR) - 1;
            hours %= 12.0;
            minutes = time.get(Calendar.MINUTE);
            minutes %= 60.0;
            seconds = time.get(Calendar.SECOND);
            seconds %= 60.0;
            //System.out.println(hours+ " "+ minutes+ " " + seconds);
            repaint();
        }
    }

    public synchronized void addPropertyChangeListener(PropertyChangeListener l) {
        pcs.addPropertyChangeListener(l);
    }

    public synchronized void removePropertyChangeListener(PropertyChangeListener l) {
        pcs.removePropertyChangeListener(l);
    }

    public synchronized void setHours(double newHours) {
        double oldHours = this.hours;
        this.hours = newHours % 12;
        pcs.firePropertyChange("hours", oldHours, this.hours);
        repaint();
    }

    public synchronized double getHours() {
        return this.hours;
    }

    public synchronized void setMinutes(double newMinutes) {
        double oldMinutes = this.minutes;
        this.minutes = newMinutes % 60;
        pcs.firePropertyChange("minutes", oldMinutes, this.minutes);
        repaint();
    }

    public synchronized double getMinutes() {
        return this.minutes;
    }

    public synchronized void setSeconds(double newSeconds) {
        double oldSeconds = this.seconds;
        this.seconds = newSeconds % 60;
        pcs.firePropertyChange("seconds", oldSeconds, this.seconds);
        repaint();
    }

    public synchronized double getSeconds() {
        return this.seconds;
    }

    public synchronized void setRunnable(boolean newRunnable) {
        boolean oldRunnable = this.runnable;
        if (newRunnable) {
            timer.start();
            this.runnable = newRunnable;
        }
        else {
            timer.stop();
            this.runnable = newRunnable;
        }
        pcs.firePropertyChange("runnable", oldRunnable, newRunnable);
    }

    public synchronized boolean getRunnable() {
        return this.runnable;
    }
}
