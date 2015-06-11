package thermostat.group2.paul.thermostat;

/**
 * Created by verygrey on 31.05.2015.
 */
public class TermostatModel {

    TermostatSchedule termostatSchedule = new TermostatSchedule();
    TermostatServer hiddenServer = new TermostatServer();

    public TermostatSchedule getServerSchedule() {
        return hiddenServer.getSchedule();
    }

    public void setServerSchedule(TermostatSchedule schedule) {
        hiddenServer.setSchedule(schedule);
    }

    public TermostatSchedule getUserSchedule() {
        return termostatSchedule;
    }

    public void setUserSchedule(TermostatSchedule schedule) {
        termostatSchedule = schedule;
    }

    public double getUserTemp() {
        return hiddenServer.getUserTemp();
    }

    public void setUserTemp(double userTemp) {
        hiddenServer.setUserTemp(userTemp);
    }

    public boolean isUser() {
        return hiddenServer.isUser();
    }

    public void setUser(boolean user) {
        hiddenServer.setUser(user);
    }

    public boolean isLocked() {
        return hiddenServer.isLocked();
    }

    public void setLocked(boolean locked) {
        hiddenServer.setLocked(locked);
    }

    public double getNightTemp() {
        return hiddenServer.getSchedule().nighttemp;
    }

    public void setNightTemp(double temp) {
        hiddenServer.getSchedule().nighttemp = temp;
    }

    public double getDayTemp() {
        return hiddenServer.getSchedule().daytemp;
    }

    public void setDayTemp(double temp) {
        hiddenServer.getSchedule().daytemp = temp;
    }

    public double getCurrentTemp() {
        return hiddenServer.currentTemp;
    }

    public boolean isDay() {
        return hiddenServer.isDay();
    }
}
