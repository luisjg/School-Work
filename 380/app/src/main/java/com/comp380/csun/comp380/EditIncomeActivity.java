package com.comp380.csun.comp380;

import android.app.DatePickerDialog;
import android.app.Dialog;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.support.v7.widget.Toolbar;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Locale;
import java.util.TimeZone;


public class EditIncomeActivity extends ActionBarActivity {

    private DatabaseHandler db;
    private AutoCompleteTextView sourceBox;
    private EditText amountBox;
    private EditText dateBox;
    private Button buttonEdit;
    private int actualID;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_editincome);

        String id = getIntent().getStringExtra("ID");
        String sort = getIntent().getStringExtra("SORT");

        db = new DatabaseHandler(this, null, null, 1);
        String[] columns = db.incomeColumnNames();
        Cursor cursor = setCursor(sort);
        cursor.moveToPosition(Integer.parseInt(id));
        //int _id = cursor.getInt(0);
        //Cursor mCursor = db.getIncomeRow(cursor, _id);

        // Init Toolbar
        Toolbar toolbar = (Toolbar) findViewById(R.id.app_bar);
        setSupportActionBar(toolbar);

        buttonEdit = (Button) findViewById(R.id.edit_button);
        Button buttonDelete = (Button) findViewById(R.id.delete_button);
        sourceBox = (AutoCompleteTextView) findViewById(R.id.source_input_edit);
        amountBox = (EditText) findViewById(R.id.amount_input_edit);
        dateBox = (EditText) findViewById(R.id.date_input_edit);

        //disable the button if the text has not been changed
        buttonEdit.setEnabled(false);
        buttonEdit.setBackgroundColor(getResources().getColor(android.R.color.darker_gray));

        //add text changed listener to the cost field;
        amountBox.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                //enable the button when the text has been changed
                buttonEdit.setBackgroundColor(getResources().getColor
                        (R.color.buttons));
                buttonEdit.setEnabled(true);
                if (amountBox.getText().toString().equals("")) {
                    buttonEdit.setEnabled(false);
                    buttonEdit.setBackgroundColor(getResources().getColor(android.R.color.darker_gray));
                }

            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });

        //populate autocompletetextview for sources
        ArrayAdapter<String> adapter =
                new ArrayAdapter<String>(this, R.layout.autocomplete_dropdown_item,
                        db.getIncomeStrings());

        if (adapter.getCount() > 0) {
            sourceBox.setAdapter(adapter);
        }

        actualID = cursor.getInt(0);
        sourceBox.setText(cursor.getString(1));
        amountBox.setText(cursor.getString(2));
        dateBox.setText(convertDateToMDY(cursor.getString(3)));

        buttonDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                // Opens conformation dialog for delete
                final Dialog  dialog = new Dialog(EditIncomeActivity.this);
                dialog.getWindow();
                dialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
                dialog.setContentView(R.layout.delete_income_dialog);

                TextView text = (TextView) dialog.findViewById(R.id.warningText);
                text.setText(R.string.dialog_delete_income);

                Button no = (Button) dialog.findViewById(R.id.warningNo);
                Button yes = (Button) dialog.findViewById(R.id.warningYes);

                no.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        dialog.dismiss();
                    }
                });

                yes.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        db.deleteIncomeRow(actualID);
                        launchIntent();
                    }
                });
                dialog.show();
            }
        });
    }

    private Cursor setCursor(String sort) {
        Cursor cursor;

        if (sort.equals("All Months")) {
            cursor = db.getAllIncomeRows();
        } else {
            cursor = db.getAllRowsForMonth(sort);
        }

        return cursor;
    }

    /**
     * display the date picker for the user when the "Choose Date" button is pressed
     */
    private void showDatePicker() {

        DatePickerFragment date = new DatePickerFragment();

        //set up the current date in the dialog box (based on Los Angeles)
        Calendar calendar = new GregorianCalendar(TimeZone.getTimeZone("America/Los_Angeles"));
        Bundle args = new Bundle();
        args.putInt("year", calendar.get(Calendar.YEAR));
        args.putInt("month", calendar.get(Calendar.MONTH));
        args.putInt("day", calendar.get(Calendar.DAY_OF_MONTH));

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
            String dateString = String.format("%02d", monthOfYear + 1) + "-"
                    + String.format("%02d", dayOfMonth) + "-" + String.valueOf(year);

            //insert this date into the date box in month-day-year format
            dateBox.setText(dateString);
        }
    };

    private void updateIncome(View view) {
        Income income;
        String source;
        Float amount;

        //check if source field is blank
        if (sourceBox.getText().toString().equals("")) {
            source = "Unspecified";
        } else {
            source = sourceBox.getText().toString();
        }

        //set cost equal to the current value in the editText field
        amount = Float.parseFloat(amountBox.getText().toString());

        //set default date to today if nothing is in the editText field
        if (!dateBox.getText().toString().equals("")) {
            String date = dateBox.getText().toString();
            date = convertDateToYMD(date);
            income = new Income(source, amount, date);
        } else {
            income = new Income(source, amount);
        }


        db.updateIncomeRow(actualID, income);
        sourceBox.setText("");
        amountBox.setText("");
        dateBox.setText("");

    }

    public String convertDateToYMD(String dateString) {

        try {
            //convert to Date
            DateFormat df = new SimpleDateFormat("MM-dd-yyyy", Locale.US);
            Date result = df.parse(dateString);

            //convert Date to a new String
            DateFormat convert = new SimpleDateFormat("yyyy-MM-dd", Locale.US);
            dateString = convert.format(result);

            return dateString;

        } catch (ParseException pe) {

            pe.printStackTrace();
            return null;
        }

    }

    public String convertDateToMDY(String dateString) {
        try {
            //convert to Date
            DateFormat df = new SimpleDateFormat("yyyy-MM-dd", Locale.US);
            Date result = df.parse(dateString);

            //convert Date to a new String
            DateFormat convert = new SimpleDateFormat("MM-dd-yyyy", Locale.US);
            dateString = convert.format(result);

            return dateString;

        } catch (ParseException pe) {

            pe.printStackTrace();
            return null;
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_edit_income, menu);
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

        // Switch to AddExpenseActivity if Add button is pushed
        if (id == R.id.action_add) {
            startActivity(new Intent(this, AddExpenseActivity.class));
            finish();
        }

        // Switch to addIncomeActivity if the bag button is pushed
        if (id == R.id.action_add_income) {
            Intent intent = new Intent(this, IncomeActivity.class);
            intent.putExtra("key", "All Months");
            startActivity(intent);
            finish();
        }

        // Switch to GoalsActivity if the goals button is pushed
        if (id == R.id.goals) {
            startActivity(new Intent(this, GoalsActivity.class));
            finish();
        }

        return super.onOptionsItemSelected(item);
    }

    public void onButtonClick(View view) {

        int viewId = view.getId();

        if (viewId == R.id.edit_button) {

            //create intent for ExpenseDisplayActivity
            Intent displayIncomes = new Intent(this, IncomeActivity.class);

            // Creating an income object to update the database entry
            updateIncome(view);

            // Add sortType key
            displayIncomes.putExtra("key", "All Months");

            startActivity(displayIncomes);
            finish();
        } else if (viewId == R.id.showDatePickerIncome) {
            showDatePicker();
        }
    }

/*    private void confirmationOnDeleteClick() {
        DialogInterface.OnClickListener dialogClickListener = new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int click) {
                switch (click) {
                    // Yes button is clicked
                    case DialogInterface.BUTTON_POSITIVE:
                        // Deletes row in income table by id
                        //create intent for ExpenseDisplayActivity
                        db.deleteIncomeRow(actualID);
                        launchIntent();
                        break;
                    case DialogInterface.BUTTON_NEGATIVE:
                        // Goes back to editincome activity
                        break;
                }
            }
        };

        LayoutInflater inflater = getLayoutInflater();
        View dialogLayout = inflater.inflate(R.layout.delete_income_dialog, null);
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("Are you sure you want to delete this entry from the database?")
                .setPositiveButton("Yes", dialogClickListener)
                .setNegativeButton("No", dialogClickListener).show();
    }*/

    private void launchIntent() {
        //create intent for ExpenseDisplayActivity
        Intent displayIncomes = new Intent(this, IncomeActivity.class);

        // Add sortType key
        displayIncomes.putExtra("key", "All Months");

        startActivity(displayIncomes);
        finish();
    }
}
