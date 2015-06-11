package thermostat.group2.paul.thermostat;

import java.util.Locale;

import android.app.Activity;
import android.app.ActionBar;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.support.v13.app.FragmentPagerAdapter;
import android.os.Bundle;
import android.support.v4.view.ViewPager;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.ImageButton;
import android.widget.NumberPicker;
import android.widget.PopupWindow;
import android.widget.TextView;


public class MainActivity extends Activity implements ActionBar.TabListener {

    /**
     * The {@link android.support.v4.view.PagerAdapter} that will provide
     * fragments for each of the sections. We use a
     * {@link FragmentPagerAdapter} derivative, which will keep every
     * loaded fragment in memory. If this becomes too memory intensive, it
     * may be best to switch to a
     * {@link android.support.v13.app.FragmentStatePagerAdapter}.
     */
    SectionsPagerAdapter mSectionsPagerAdapter;

    TermostatModel tm = new TermostatModel();
    TermostatController tc = new TermostatController(tm);

    /**
     * The {@link ViewPager} that will host the section contents.
     */
    ViewPager mViewPager;

    int currentday = 1;
    int days = 0, nights = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Set up the action bar.
        final ActionBar actionBar = getActionBar();
        actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);

        // Create the adapter that will return a fragment for each of the three
        // primary sections of the activity.
        mSectionsPagerAdapter = new SectionsPagerAdapter(getFragmentManager());

        // Set up the ViewPager with the sections adapter.
        mViewPager = (ViewPager) findViewById(R.id.pager);
        mViewPager.setAdapter(mSectionsPagerAdapter);

        // When swiping between different sections, select the corresponding
        // tab. We can also use ActionBar.Tab#select() to do this if we have
        // a reference to the Tab.
        mViewPager.setOnPageChangeListener(new ViewPager.SimpleOnPageChangeListener() {
            @Override
            public void onPageSelected(int position) {
                actionBar.setSelectedNavigationItem(position);
            }
        });

        // For each of the sections in the app, add a tab to the action bar.
        for (int i = 0; i < mSectionsPagerAdapter.getCount(); i++) {
            // Create a tab with text corresponding to the page title defined by
            // the adapter. Also specify this Activity object, which implements
            // the TabListener interface, as the callback (listener) for when
            // this tab is selected.
            actionBar.addTab(
                    actionBar.newTab()
                            .setText(mSectionsPagerAdapter.getPageTitle(i))
                            .setTabListener(this));
        }

        ((ImageButton) findViewById(R.id.upload)).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tc.exportScheduleToServer();
            }
        });

        ((ImageButton) findViewById(R.id.download)).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tc.importScheduleFromServer();
            }
        });

        ((ImageButton) findViewById(R.id.edit)).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                tm.setUserTemp(0);
            }
        });

        ((Button) findViewById(R.id.mo)).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                currentday = 1;
            }
        });

        ((ImageButton) findViewById(R.id.addsplit)).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                LayoutInflater li = (LayoutInflater) getSystemService(LAYOUT_INFLATER_SERVICE);
                PopupWindow p = new PopupWindow(
                        li.inflate(R.layout.popup, null, false),
                        100,
                        100,
                        true);
                p.showAtLocation(findViewById(R.id.schedule), Gravity.CENTER, 0, 0);
            }
        });

        ((Button) findViewById(R.id.addsplit)).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int hours = ((NumberPicker)findViewById(R.id.hours)).getValue();
                int minutes = ((NumberPicker)findViewById(R.id.minutes)).getValue();
                if (((CheckBox)findViewById(R.id.isday)).isChecked()) {
                    tc.addDayNightPeriod(hours, minutes, currentday);
                    switch (days) {
                        case 0: {
                            ((TextView)findViewById(R.id.day1)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 1: {
                            ((TextView)findViewById(R.id.day2)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 2: {
                            ((TextView)findViewById(R.id.day3)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 3: {
                            ((TextView)findViewById(R.id.day4)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 4: {
                            ((TextView)findViewById(R.id.day5)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 5: {
                            ((TextView)findViewById(R.id.day6)).setText(hours + ":" + minutes);
                            break;
                        }
                    }
                    days++;
                } else {
                    tc.addNightDayPeriod(hours, minutes, currentday);
                    switch (days) {
                        case 0: {
                            ((TextView)findViewById(R.id.night1)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 1: {
                            ((TextView)findViewById(R.id.night2)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 2: {
                            ((TextView)findViewById(R.id.night3)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 3: {
                            ((TextView)findViewById(R.id.night4)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 4: {
                            ((TextView)findViewById(R.id.night5)).setText(hours + ":" + minutes);
                            break;
                        }
                        case 5: {
                            ((TextView)findViewById(R.id.night6)).setText(hours + ":" + minutes);
                            break;
                        }
                    }
                    nights++;
                }
            }
        });

    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onTabSelected(ActionBar.Tab tab, FragmentTransaction fragmentTransaction) {
        // When the given tab is selected, switch to the corresponding page in
        // the ViewPager.
        mViewPager.setCurrentItem(tab.getPosition());
    }

    @Override
    public void onTabUnselected(ActionBar.Tab tab, FragmentTransaction fragmentTransaction) {
    }

    @Override
    public void onTabReselected(ActionBar.Tab tab, FragmentTransaction fragmentTransaction) {
    }

    /**
     * A {@link FragmentPagerAdapter} that returns a fragment corresponding to
     * one of the sections/tabs/pages.
     */
    public class SectionsPagerAdapter extends FragmentPagerAdapter {

        public SectionsPagerAdapter(FragmentManager fm) {
            super(fm);
        }

        @Override
        public Fragment getItem(int position) {
            // getItem is called to instantiate the fragment for the given page.
            // Return a PlaceholderFragment (defined as a static inner class below).
            switch (position) {
                case 0:
                {
                    return StatusFragment.newInstance(0);
                }
                case 1:
                {
                    return ScheduleFragment.newInstance(1);
                }
            }
            return null;
        }

        @Override
        public int getCount() {
            // Show 3 total pages.
            return 2;
        }

        @Override
        public CharSequence getPageTitle(int position) {
            Locale l = Locale.getDefault();
            switch (position) {
                case 0:
                    return getString(R.string.status).toUpperCase(l);
                case 1:
                    return getString(R.string.schedule).toUpperCase(l);
            }
            return null;
        }
    }

    public static class StatusFragment extends Fragment {
        /**
         * The fragment argument representing the section number for this
         * fragment.
         */
        private static final String ARG_SECTION_NUMBER = "section_number";

        /**
         * Returns a new instance of this fragment for the given section
         * number.
         */
        public static StatusFragment newInstance(int sectionNumber) {
            StatusFragment fragment = new StatusFragment();
            Bundle args = new Bundle();
            args.putInt(ARG_SECTION_NUMBER, sectionNumber);
            fragment.setArguments(args);
            return fragment;
        }

        public StatusFragment() {
        }

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container,
                                 Bundle savedInstanceState) {
            View rootView = inflater.inflate(R.layout.status_fragment, container, false);
            return rootView;
        }
    }

    public static class ScheduleFragment extends Fragment {
        /**
         * The fragment argument representing the section number for this
         * fragment.
         */
        private static final String ARG_SECTION_NUMBER = "section_number";

        /**
         * Returns a new instance of this fragment for the given section
         * number.
         */
        public static ScheduleFragment newInstance(int sectionNumber) {
            ScheduleFragment fragment = new ScheduleFragment();
            Bundle args = new Bundle();
            args.putInt(ARG_SECTION_NUMBER, sectionNumber);
            fragment.setArguments(args);
            return fragment;
        }

        public ScheduleFragment() {
        }

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container,
                                 Bundle savedInstanceState) {
            View rootView = inflater.inflate(R.layout.schedule_fragment, container, false);
            return rootView;
        }
    }

    /**
     * A placeholder fragment containing a simple view.
     */
    public static class PlaceholderFragment extends Fragment {
        /**
         * The fragment argument representing the section number for this
         * fragment.
         */
        private static final String ARG_SECTION_NUMBER = "section_number";

        /**
         * Returns a new instance of this fragment for the given section
         * number.
         */
        public static PlaceholderFragment newInstance(int sectionNumber) {
            PlaceholderFragment fragment = new PlaceholderFragment();
            Bundle args = new Bundle();
            args.putInt(ARG_SECTION_NUMBER, sectionNumber);
            fragment.setArguments(args);
            return fragment;
        }

        public PlaceholderFragment() {
        }

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container,
                                 Bundle savedInstanceState) {
            View rootView = inflater.inflate(R.layout.fragment_main, container, false);
            return rootView;
        }
    }


}