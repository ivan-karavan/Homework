package thermostat.group2.paul.thermostat;

import java.beans.PropertyChangeSupport;
import java.util.Calendar;
import java.util.concurrent.TimeUnit;

/**
 * Created by verygrey on 31.05.2015.
 */
public class TermostatServer{

    double futureTemp;
    double oldTemp;
    double currentTemp;
    double userTemp;

    int currentMode;

    boolean user;
    boolean locked;

    Calendar time = Calendar.getInstance();

    //    public void addPropertyChangeListener(PropertyChangeListener x) {
//        changeSupport.addPropertyChangeListener(x);
//    }
//
//    public void removePropertyChangeListener(PropertyChangeListener x) {
//        changeSupport.removePropertyChangeListener(x);
    TermostatSchedule schedule;

    TermostatServer() {
        currentTemp = 10.0;
        userTemp = 10.0;
        futureTemp = 20.0;
        user = false;
        locked = false;
        currentMode = TermostatSchedule.NIGHT;
        schedule = new TermostatSchedule();
//        changeSupport.firePropertyChange("temp", 0, currentTemp);
    }

//    PropertyChangeSupport changeSupport;

//    }

    private Thread timer = new Thread(new Runnable() {
        @Override
        public void run() {
            while(!Thread.currentThread().isInterrupted()) {
                try {
                    TimeUnit.SECONDS.sleep(1);
                    eachSecond();
                }
                catch (InterruptedException ex) {
                    System.out.println("Internal thread in Timer was interrupted");
                    break;
                }
            }
        }
    });

    private void eachSecond() {

        double temp;
        if (user) {
            temp = userTemp;
        } else {
            int hour = time.get(Calendar.HOUR), minute = time.get(Calendar.MINUTE), day = time.get(Calendar.DAY_OF_WEEK);
            temp = schedule.getTemp(hour, minute, day);
            if (currentMode != schedule.getMode(hour, minute, day)) {
                if (!locked) {
                    user = false;
                    currentMode = schedule.getMode(hour, minute, day);
                }
            }
        }
        if (temp > currentTemp) {
//            oldTemp = currentTemp;
            currentTemp += speed;
//            changeSupport.firePropertyChange("temp", oldTemp, currentTemp);
        } else if (temp < currentTemp) {
//            oldTemp = currentTemp;
            currentTemp -= speed;
//            changeSupport.firePropertyChange("temp", oldTemp, currentTemp);
        }
    }

    double speed = 0.1;

    public double getTemp() {
        return currentTemp;
    }

    public void setTemp(double temp) {
        futureTemp = temp;
    }

    public TermostatSchedule getSchedule() {
        return schedule;
    }

    public void setSchedule(TermostatSchedule schedule) {
        this.schedule = schedule;
    }

    public boolean isDay() {
        return schedule.getMode
                (time.get(Calendar.HOUR), time.get(Calendar.MINUTE), time.get(Calendar.DAY_OF_WEEK))
                == TermostatSchedule.DAY;
    }

    public double getUserTemp() {
        return userTemp;
    }

    public void setUserTemp(double userTemp) {
        this.userTemp = userTemp;
    }

    public boolean isUser() {
        return user;
    }

    public void setUser(boolean user) {
        this.user = user;
    }

    public boolean isLocked() {
        return locked;
    }

    public void setLocked(boolean locked) {
        this.locked = locked;
    }
}
