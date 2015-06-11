package thermostat.group2.paul.thermostat;

/**
 * Created by verygrey on 31.05.2015.
 */

public class TermostatController {

    TermostatModel model = new TermostatModel();

    public TermostatController(TermostatModel model) {
        this.model = model;
    }

    public void importScheduleFromServer() {
        model.setUserSchedule(new TermostatSchedule(model.getServerSchedule()));
    }

    public void exportScheduleToServer() {
        model.setServerSchedule(new TermostatSchedule(model.getUserSchedule()));
    }

    public void addDayNightPeriod(int hour, int minute, int day) {
        model.getUserSchedule().addDayBegin(hour, minute, day);
    }

    public void addNightDayPeriod(int hour, int minute, int day) {
        model.getUserSchedule().addNightBegin(hour, minute, day);
    }

    public void removePeriod(int hour, int minute, int day) {
        model.getUserSchedule().removePeriod(hour, minute, day);
    }
}
