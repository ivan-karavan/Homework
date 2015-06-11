package thermostat.group2.paul.thermostat;

import android.support.annotation.IntegerRes;
import android.support.v4.view.PagerAdapter;
import android.util.Pair;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 * Created by verygrey on 31.05.2015.
 */
public class TermostatSchedule {

    double daytemp;
    double nighttemp;

    public static final int NIGHT = 0;
    public static final int DAY = 1;

    ArrayList<LinkedList<Pair<Integer, Integer>>> daySplits;

    public TermostatSchedule() {
        daySplits = new ArrayList<>();
        for (int i = 0; i < 7; i++) {
            daySplits.add(new LinkedList<Pair<Integer, Integer>>());
            daySplits.get(i).add(new Pair<Integer, Integer>(0, NIGHT));
            daySplits.get(i).add(new Pair<Integer, Integer>(1440, NIGHT));
        }
    }

    public TermostatSchedule(TermostatSchedule ts) {
        this();
        daytemp = ts.daytemp;
        nighttemp = ts.nighttemp;
        daySplits = ts.daySplits;
    }

    private void addPeriodBegin(int time, int mode, int day) {
        for (int i = 0; i < getDaySplit(day).size(); i++) {
            if (getDaySplit(day).get(i).first > time && getDaySplit(day).get(i).second == 1 - mode) {
                if (i != 0 && getDaySplit(day).get(i - 1).second == 1 - mode) {
                    getDaySplit(day).add(i, new Pair<Integer, Integer>(time, mode));
                }
            }
        }
    }

    public void addDayBegin(Integer hour, Integer minute, Integer day) {
        Integer time = HMtoTime(hour, minute);
        addPeriodBegin(time, DAY, day);
    }


    public void addNightBegin(Integer hour, Integer minute, Integer day) {
        Integer time = HMtoTime(hour, minute);
        addPeriodBegin(time, NIGHT, day);
    }

    public void removePeriod(int hour, int minute, int day) {
        int time = HMtoTime(hour, minute);
        for (int i = 0; i < getDaySplit(day).size(); i++) {
            if (getDaySplit(day).get(i).first == time) {
                getDaySplit(day).remove(i);
                break;
            }
        }
    }

    private static int HMtoTime(Integer hour, Integer minute) {
        return hour * 60 + minute;
    }

    public int getMode(int hour, int minute, int day)
        throws IllegalStateException {
        int time = HMtoTime(hour, minute);
        for (int i = 0; i < getDaySplit(day).size() - 1; i++) {
            if (getDaySplit(day).get(i).first <= time && time < getDaySplit(day).get(i + 1).first) {
                return getDaySplit(day).get(i).second;
            }
        }
        throw new IllegalStateException("Incorrect schedule state: not found time");
    }

    public double getTemp(int hour, int minute, int day) {
        switch (getMode(hour, minute, day)) {
            case NIGHT:
            {
                return nighttemp;
            }
            case DAY:
            {
                return daytemp;
            }
        }
        throw new IllegalStateException("Incorrect result of getMode()");
    }

    public LinkedList<Pair<Integer, Integer>> getDaySplit(int numday) {
        if (numday < 1 || numday > 7) {
            numday = 1;
        }
        return daySplits.get(numday - 1);
    }

    public ArrayList<String> getBegins(int numday, int mode) {
        ArrayList<String> days = new ArrayList<>();
        for (Pair<Integer, Integer> pair: getDaySplit(numday)) {
            if (pair.second == mode) {
                days.add((pair.first/60)+":"+(pair.first%60));
            }
        }
        return days;
    }
}
