package com.comp380.csun.comp380;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.support.v7.app.ActionBarActivity;
import android.support.v7.widget.Toolbar;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Locale;
import java.util.TimeZone;

/**
 * Created by gdfairclough on 5/3/15.
 */
public class EditExpenseActivity extends ActionBarActivity{

    private AutoCompleteTextView categoryBox;
    private AutoCompleteTextView vendorBox;
    private EditText costBox;
    private EditText dateBox;
    private DatabaseHandler dbHandler;
    private Button buttonSave;
    Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        dbHandler = new DatabaseHandler(this, null, null,1);



        setContentView(R.layout.activity_expense_edit);

        // Init ToolBar
        toolbar = (Toolbar) findViewById(R.id.app_bar);
        setSupportActionBar(toolbar);

        buttonSave = (Button) findViewById(R.id.save_button);
        categoryBox = (AutoCompleteTextView) findViewById(R.id.category_input);
        vendorBox = (AutoCompleteTextView) findViewById(R.id.vendor_input);
        costBox = (EditText) findViewById(R.id.amount_input);
        dateBox = (EditText) findViewById(R.id.date_input);

        Intent intent = getIntent();
        String category = intent.getStringExtra("category");
        String vendor = intent.getStringExtra("vendor");
        String cost = intent.getStringExtra("cost");
        String date = intent.getStringExtra("date");

        categoryBox.setText(category);
        vendorBox.setText(vendor);
        costBox.setText(cost);
        dateBox.setText(date);

        //disable the button if the text has not been changed
        buttonSave.setEnabled(true);
        buttonSave.setBackgroundColor(getResources().getColor(android.R.color.darker_gray));

        //add text changed listener to the cost field;
        costBox.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                //enable the button when the text has been changed
                buttonSave.setBackgroundColor(getResources().getColor
                        (R.color.buttons));
                buttonSave.setEnabled(true);
                if(costBox.getText().toString().equals("")){
                    buttonSave.setEnabled(false);
                    buttonSave.setBackgroundColor(getResources().getColor(android.R.color.darker_gray));
                }

            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });



        //populate autocompletetextview for category
        ArrayAdapter<String> adapter =
                new ArrayAdapter<String>(this,R.layout.autocomplete_dropdown_item,
                        dbHandler.getCategoriesStrings());

        categoryBox.setAdapter(adapter);

        //populate autocompletetextview for vendor
        adapter = new ArrayAdapter<String>(this,R.layout.autocomplete_dropdown_item,
                dbHandler.getVendorStrings());

        vendorBox.setAdapter(adapter);

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_expense_display, menu);
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
            startActivity(new Intent(this, SettingsActivity.class));
            finish();
        }

        // Switch to IncomeActivity if money bag is pressed
        if (id == R.id.action_add_income) {
            Intent intent = new Intent(this, IncomeActivity.class);
            intent.putExtra("key", "All Months");
            startActivity(intent);
        }

        // Switch to GoalsActivity if the goals button is pushed
        if (id == R.id.goals) {
            startActivity(new Intent(this, GoalsActivity.class));
            finish();
        }

        return super.onOptionsItemSelected(item);
    }

    public void updateExpense(View view){
        Expense expense;
        String category;
        String vendor;
        Double cost;
        int id;


        //check if category field is blank
        if(categoryBox.getText().toString().equals("")){
            category = "Uncategorized";
        }else{
            category = categoryBox.getText().toString();
        }
        //check if vendor field is blank
        if(vendorBox.getText().toString().equals("")){
            vendor = "Unspecified";
        }else{
            vendor = vendorBox.getText().toString();
        }

        Intent intent = getIntent();
        id = Integer.parseInt(intent.getStringExtra("id"));

        //set cost equal to the current value in the editText field
        cost = Double.parseDouble(costBox.getText().toString());


        String date  = dateBox.getText().toString();
        date = convertDateToYMD(date);
        expense = new Expense(id,category,vendor,cost,date);



        dbHandler.updateExpense(expense);
        categoryBox.setText("");
        vendorBox.setText("");
        costBox.setText("");
        dateBox.setText("");

    }

    public String convertDateToYMD(String dateString) {

        try{
            //convert to Date
            DateFormat df = new SimpleDateFormat("MM-dd-yyyy", Locale.US);
            Date result = df.parse(dateString);

            //convert Date to a new String
            DateFormat convert = new SimpleDateFormat("yyyy-MM-dd", Locale.US);
            dateString = convert.format(result);

            return dateString;

        }catch(ParseException pe){

            pe.printStackTrace();
            return null;
        }

    }


    private void deleteExpense(){

        Intent intent = getIntent();
        int id = Integer.parseInt(intent.getStringExtra("id"));

        dbHandler.deleteExpense(id);


    }

    public void onButtonClick(View view){

        int id = view.getId();

        if(id == R.id.cancel_button){

            //move back to previous screen
            Intent intent = new Intent(this, ExpenseDisplayActivity.class);
            startActivity(intent);
            finish();
        }
        else if(id == R.id.deleteButton){
            Intent intent = new Intent(this, ExpenseDisplayActivity.class);

            deleteExpense();

            startActivity(intent);
            finish();

        }
        else if(id == R.id.save_button){

            //create intent for ExpenseDisplayActivity
            Intent displayExpenses = new Intent(this, ExpenseDisplayActivity.class);

            //update the database
            updateExpense(view);

            startActivity(displayExpenses);
            finish();

        }
        else if(id == R.id.showDatePicker){

            showDatePicker();
        }
    }


    /**
     * display the date picker for the user when the "Choose Date" button is pressed
     */
    private void showDatePicker(){

        DatePickerFragment date = new DatePickerFragment();

        //set up the current date in the dialog box (based on Los Angeles)
        Calendar calendar = new GregorianCalendar(TimeZone.getTimeZone("America/Los_Angeles"));
        Bundle args = new Bundle();
        args.putInt("year",calendar.get(Calendar.YEAR));
        args.putInt("month",calendar.get(Calendar.MONTH));
        args.putInt("day",calendar.get(Calendar.DAY_OF_MONTH));

        date.setArguments(args);

        //set call back to capt
        // ure the selected date
        date.setCallBack(onDate);
        date.show(getFragmentManager(), "Date Picker");
    }

    DatePickerDialog.OnDateSetListener onDate = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {


            //convert the date to a string
            String dateString = String.format("%02d",monthOfYear+1)+"-"
                    +String.format("%02d",dayOfMonth)+"-"+String.valueOf(year);

            //insert this date into the date box in month-day-year format
            dateBox.setText(dateString);
        }
    };
}
