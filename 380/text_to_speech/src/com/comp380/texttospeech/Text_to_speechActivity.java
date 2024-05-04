package com.comp380.texttospeech;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.speech.tts.TextToSpeech;
import android.view.MotionEvent;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.speech.tts.TextToSpeech.OnInitListener;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OptionalDataException;
import java.io.StreamCorruptedException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Locale;
import java.util.Random;

public class Text_to_speechActivity extends Activity implements OnClickListener, OnTouchListener, OnInitListener {
    /** Called when the activity is first created. */

	public ArrayList<FileInformation> audioFileArrayList = null;
	private int MY_DATA_CHECK_CODE = 0;
	private TextToSpeech myTTS;
	Button btnSpeak, btnSaved, btnNavMain, btnNavSaved, btnNavShare, btnNavImport;
	EditText txtInput;
	Context mContext;
	boolean mIsKeyPadButtonChecked = false;
	ImageView mKeyPadButton, mSaveAudioButton, btnClear;
	String destFileName, audioFilePath;
	MediaPlayer mMediaPlayer = null;
	File soundFile = null;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main2);
        
        mContext = this;
        
        btnSpeak = (Button) findViewById(R.id.btnSpeak2);
        btnSpeak.setOnClickListener(this);
        
        btnSaved = (Button) findViewById(R.id.btnSaved2);
        btnSaved.setOnClickListener(this);
        
        btnNavMain = (Button) findViewById(R.id.btnNavMain2);
        btnNavMain.setOnClickListener(this);
        
        btnNavSaved = (Button) findViewById(R.id.btnNavSaved2);
        btnNavSaved.setOnClickListener(this);
        
        btnNavShare = (Button) findViewById(R.id.btnNavShare2);
        btnNavShare.setOnClickListener(this);
        
        btnNavImport = (Button) findViewById(R.id.btnNavImport2);
        btnNavImport.setOnClickListener(this);
        
        mSaveAudioButton = (ImageView) findViewById(R.id.headphones_down);
        mSaveAudioButton.setOnClickListener(this);
        
        mKeyPadButton = (ImageView) findViewById(R.id.keyboard);
        mKeyPadButton.setOnClickListener(this);
        
        btnClear = (ImageView) findViewById(R.id.btnClear);
        btnClear.setOnClickListener(this);
        
        txtInput = (EditText) findViewById(R.id.txtInput2);
        txtInput.setOnTouchListener(this);

        Intent checkTTSIntent = new Intent();
        checkTTSIntent.setAction(TextToSpeech.Engine.ACTION_CHECK_TTS_DATA);
        startActivityForResult(checkTTSIntent, MY_DATA_CHECK_CODE);              
    }
    
    // touching the text input sets the boolean mIsKeyPadButtonChecked to True 
    // symbolizing that the Keyboard is showing
	public boolean onTouch(View v, MotionEvent event) {
		mIsKeyPadButtonChecked = true;
		return false;
	}
    
	// Click listener for this class
    public void onClick(View v)
    {
    	switch(v.getId())
    	{
    	case R.id.btnSpeak2 : speakUtterance();
    	break;
    	case R.id.btnSaved2 : startActivity(new Intent(this, SavedAudio.class));
    	break;
    	case R.id.btnNavSaved2 : startActivity(new Intent(this, SavedAudio.class));
    	break;
    	case R.id.btnNavShare2 : startActivity(new Intent(this, share.class));
    	break;
    	case R.id.btnNavImport2 : startActivity(new Intent(this, importwindow.class));
    	break;
    	case R.id.btnClear : txtInput.setText("");
    	break;
    	case R.id.keyboard : toggleKeyboard();
    	break;
    	case R.id.headphones_down : saveAudioToFile();
    	break;
    	}
    }

	// Called to signal the completion of the TextToSpeech engine initialization.
    public void onInit(int initStatus)
    {
    	if(initStatus == TextToSpeech.SUCCESS)
    		myTTS.setLanguage(Locale.US);
    	else if(initStatus == TextToSpeech.ERROR)
    		Toast.makeText(this, "Sorry! Text To Speech failed...", Toast.LENGTH_LONG).show();
    }
    
    // Speak words
    private void speakWords(String speech) 
    {
    	myTTS.speak(speech, TextToSpeech.QUEUE_FLUSH, null);
    }
    
    // Called when an activity onActivityForResult(checkTTSIntent) exits
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
    	if(requestCode == MY_DATA_CHECK_CODE)
    	{
    		if(resultCode == TextToSpeech.Engine.CHECK_VOICE_DATA_PASS)
    		{
    			myTTS = new TextToSpeech(this, this);
    		}
    		else
    		{
    			Intent installTTSIntent = new Intent();
    			installTTSIntent.setAction(TextToSpeech.Engine.ACTION_INSTALL_TTS_DATA);
    			startActivity(installTTSIntent);
    		}
    	}
    }
	
	private void saveAudioToFile()
	{
		String dataFilePath = Environment.getExternalStorageDirectory().getAbsolutePath() + 
				File.separatorChar + "FileInformationFile.dat";
		ArrayList<FileInformation> fileInfo = null;
		final String words = txtInput.getText().toString();
  		final int maxFileNameLength = 25;
    	String saveText, previewName;
    	int spacePosition;
    	
    	if(words.length()>0)
    	{
        	saveText = words;
        	if(saveText.length() > maxFileNameLength)
        		previewName = saveText.substring(0, maxFileNameLength) + "...";
        	else
        		previewName = saveText;
        	spacePosition = saveText.indexOf(" ");
        	if(spacePosition>0) {
        		if(Environment.MEDIA_MOUNTED.equals(Environment.getExternalStorageState()))
	        		destFileName = Environment.getExternalStorageDirectory().getAbsolutePath() + 
	        				File.separatorChar + saveText.substring(0, spacePosition) + ".wav"; 
        	}	
        	else {
        		if(Environment.MEDIA_MOUNTED.equals(Environment.getExternalStorageState()))
	        		destFileName = Environment.getExternalStorageDirectory().getAbsolutePath() + 
	        				File.separatorChar + saveText + ".wav";
        	}
        	
        	Random rand = new Random(); 
        	
        	if(findDups(destFileName, dataFilePath))
        	{
        		if(spacePosition>0) {
            		if(Environment.MEDIA_MOUNTED.equals(Environment.getExternalStorageState()))
    	        		destFileName = Environment.getExternalStorageDirectory().getAbsolutePath() + 
    	        				File.separatorChar + saveText.substring(0, spacePosition) + rand.nextInt(20) + ".wav"; 
            	}	
            	else {
            		if(Environment.MEDIA_MOUNTED.equals(Environment.getExternalStorageState()))
    	        		destFileName = Environment.getExternalStorageDirectory().getAbsolutePath() + 
    	        				File.separatorChar + saveText + rand.nextInt(20) + ".wav";
            	}
        	}
	        	
    		HashMap<String, String> myHashRender = new HashMap();
        	myHashRender.put(TextToSpeech.Engine.KEY_PARAM_UTTERANCE_ID, previewName);
        	
        	try{
        	if(myTTS.synthesizeToFile(saveText, myHashRender, destFileName) == TextToSpeech.SUCCESS)
        	{        		
        		//make a suitable path to a file on the external storage
        		String state = Environment.getExternalStorageState();
        		if(Environment.MEDIA_MOUNTED.equals(state))
        		{
            		//create some data and fill up array
            		audioFileArrayList = GetFileInfo(previewName, destFileName);
            		ObjectInputStream in = null;
            		try {
            			in = new ObjectInputStream(new FileInputStream(dataFilePath));
            		} catch (StreamCorruptedException e) {
            			// TODO Auto-generated catch block
            			e.printStackTrace();
            		} catch (FileNotFoundException e) {
            			// TODO Auto-generated catch block
            			e.printStackTrace();
            		} catch (IOException e) {
            			// TODO Auto-generated catch block
            			e.printStackTrace();
            		}
            		// if the ObjectInputStream is empty, create a new OutputStream and write ArrayList to disk
            		if(in == null)
            		{
            			saveArrayToDisk(audioFileArrayList, dataFilePath);
            			Toast.makeText(this.getBaseContext(), "New data file created. Saved successfully!", Toast.LENGTH_SHORT).show(); 
            		}
            		else
            		{
            			try {
                			fileInfo = (ArrayList<FileInformation>) in.readObject();
                		} catch (OptionalDataException e) {
                			// TODO Auto-generated catch block
                			e.printStackTrace();
                		} catch (ClassNotFoundException e) {
                			// TODO Auto-generated catch block
                			e.printStackTrace();
                		} catch (IOException e) {
                			// TODO Auto-generated catch block
                			e.printStackTrace();
                		}
            			fileInfo.addAll(audioFileArrayList);
            			saveArrayToDisk(fileInfo, dataFilePath);
            			Toast.makeText(getBaseContext(), "Text-To-Speech Saved!", Toast.LENGTH_SHORT).show();
            		}
        		}
        	}
        	else
        		Toast.makeText(getBaseContext(), "Oops! Something happened. Your text was not saved.", Toast.LENGTH_SHORT).show();
        	} catch(Exception e) {
        		Toast.makeText(getBaseContext(), "synthesizeToFile Failed", Toast.LENGTH_SHORT).show();
        		e.printStackTrace();
        	}
    	}
    	else
    		Toast.makeText(getBaseContext(), "Sorry! You have to type text in order to save.", Toast.LENGTH_SHORT).show();
	}
	
	private void toggleKeyboard()
	{
		mIsKeyPadButtonChecked = !mIsKeyPadButtonChecked;
  		//mKeyPadButton.setActivated(mIsKeyPadButtonChecked); //Android 4.0
  		if(mIsKeyPadButtonChecked)
  		{
  			mKeyPadButton.postDelayed(new Runnable() 
  			{
  				public void run()
  				{
  					InputMethodManager keyboard = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
  					keyboard.showSoftInput(txtInput , 0);
  				}
  			}, 200);
  		}
  		else 
  		{
  			mKeyPadButton.postDelayed(new Runnable()
  			{
  				public void run()
  				{
  					InputMethodManager keyboard = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
  					keyboard.hideSoftInputFromWindow(txtInput.getWindowToken() , 0);
  				}
  			}, 200);
  		}
	}
	
	// If Speak button is clicked, executes speakWords method and shows ProgressBar
	private void speakUtterance()
	{
		final String words = txtInput.getText().toString();
    	try {
    		if(words.length()>0)
        	{
        		AsyncTask<Void,Void,Void> lTask = new AsyncTask<Void,Void,Void>(){

            		ProgressDialog lDialog;
            		protected void onPreExecute(){
            		              lDialog = ProgressDialog.show(mContext, "","Your msg",true);
            		}

            		protected Void doInBackground(Void... params){
            		              speakWords(words);
            		              
            		              return null;
            		}

            		protected void onPostExecute(Void result){
           			Thread myThread = new Thread(){
            				public void run()
            				{
            					try {
            						sleep(1000);
            					} catch(InterruptedException e) {
            						e.printStackTrace();
            					} finally {
            						lDialog.dismiss();
            					}
            				}
            			};
            			myThread.start();
            			}
            	};
            	lTask.execute();
        	}
    		else 
    			Toast.makeText(getApplicationContext(), "You have to type words first!", Toast.LENGTH_SHORT).show();        		
    	} catch(Exception e) {
    		Toast.makeText(getParent(), "Something else went wrong!", Toast.LENGTH_SHORT).show();
    		e.printStackTrace();
    	}
	}
	
	private ArrayList<FileInformation> GetFileInfo(String strPrevName, String strDestName) {
		ArrayList<FileInformation> file_info = new ArrayList<FileInformation>();
		FileInformation fi = new FileInformation(strPrevName, strDestName);
		file_info.add(fi);
		
		return file_info;
	}

	private void saveArrayToDisk(ArrayList<FileInformation> myArray, String myPath)
	{
		try {
			// write array to disk
			File file = new File(myPath);
			if(file.exists())
				file.delete();
			ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(myPath));
			out.writeObject(myArray);
			out.flush();
			out.close();
		}
		catch(FileNotFoundException e)
		{
			Toast.makeText(getBaseContext(), "File Not Found.", Toast.LENGTH_SHORT).show();
			e.printStackTrace();
		}
		catch(IOException e)
		{
			Toast.makeText(getBaseContext(), "IO Exception.", Toast.LENGTH_SHORT).show();
			e.printStackTrace();
		}
		catch(Exception e)
		{
			Toast.makeText(getBaseContext(), "Exception!", Toast.LENGTH_SHORT).show();
			e.printStackTrace();
		}
	}
	
	private boolean findDups(String myAudioFilePath, String myDataFilePath)
	{
		ArrayList<FileInformation> myList = null;
		ObjectInputStream in = null;
		try {
			in = new ObjectInputStream(new FileInputStream(myDataFilePath));
			
		} catch (StreamCorruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		if(in != null)
		{
			try {
				myList = (ArrayList<FileInformation>) in.readObject();
			} catch (OptionalDataException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();	
			}
			
			for(int i=0;i<myList.size();i++)
			{
				if(myAudioFilePath.equals(myList.get(i).getDestinationFileName()))
					return true;
			}
		}
		return false;
	}

	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
	}

	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		super.onPause();
	}
	
	
}