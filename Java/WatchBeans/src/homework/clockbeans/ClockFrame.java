package homework.clockbeans;

import javax.swing.*;

/**
 * Created by Иван on 28.02.2015.
 */

public class ClockFrame extends JFrame {
    private ClockBeans clock;
    public ClockFrame(){
        clock = new ClockBeans();
        setSize(300, 300);
        setTitle("Clock");
        add(clock);
    }
}
