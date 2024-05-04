package com.comp380.texttospeech;

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
import com.comp380.texttospeech.R; 
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.os.Bundle;
import android.os.Environment;
import android.os.Parcelable;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView.OnItemLongClickListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.Toast; 

public class SavedAudio extends Activity implements OnClickListener {  
	
	Button btnClearSaved, btnDone, btnNavMain, btnNavSaved, btnNavShare, btnNavImport;
	ImageView btnDeleteItem;
	MediaPlayer mMediaPlayer;
	ArrayList<FileInformation> fileInfo = null;
	String dataFilePath = Environment.getExternalStorageDirectory().getAbsolutePath() + 
			File.separatorChar + "FileInformationFile.dat";
	
	@Override    
	public void onCreate(Bundle savedInstanceState) {        
		super.onCreate(savedInstanceState);        
		setContentView(R.layout.saved_audio);       

		btnClearSaved = (Button) findViewById(R.id.btnClearSaved);
		btnClearSaved.setOnClickListener(this);

		btnDone = (Button) findViewById(R.id.btnDoneSaved3);
		btnDone.setOnClickListener(this);

		btnNavMain = (Button) findViewById(R.id.btnNavMain3);
		btnNavMain.setOnClickListener(this);

		btnNavSaved = (Button) findViewById(R.id.btnNavSaved3);
		btnNavSaved.setOnClickListener(this);

		btnNavShare = (Button) findViewById(R.id.btnNavShare3);
		btnNavShare.setOnClickListener(this);

		btnNavImport = (Button) findViewById(R.id.btnNavImport3);
		btnNavImport.setOnClickListener(this);
		
		displayList();				   
	}     

	public void onClick(View arg0) {
		switch (arg0.getId()) {
		case R.id.btnDoneSaved3:
			finish();
			break;
		case R.id.btnNavMain3:
			startActivity(new Intent(this, Text_to_speechActivity.class));
			break;
		case R.id.btnNavShare3:
			startActivity(new Intent(this, share.class));
			break;
		case R.id.btnNavImport3:
			startActivity(new Intent(this, importwindow.class));
			break;
		 case R.id.btnClearSaved : deleteAllFiles();
		 break;
		}
	}
	
	private void playFile(String strFileName)
    {
    	try {
    		mMediaPlayer = new MediaPlayer();
			mMediaPlayer.setDataSource(strFileName);
	    	mMediaPlayer.setAudioStreamType(AudioManager.STREAM_RING);
			mMediaPlayer.prepare();
	    	mMediaPlayer.start();
	    	mMediaPlayer.setOnCompletionListener(new OnCompletionListener() {
	    		public void onCompletion(MediaPlayer mp) {
	    			mMediaPlayer.stop();
	    		}
	    	});
		} catch (Exception e) {
			Toast.makeText(getBaseContext(), "Sorry! Can't play file", Toast.LENGTH_SHORT).show();
			e.printStackTrace();
		}

    }
	
	private void displayList()
	{
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
		if(in != null)
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
			
			final ListView lv = (ListView) findViewById(R.id.srListView);        
			lv.setAdapter(new MyBaseAdapter(this, fileInfo));
			
			lv.setOnItemClickListener(new OnItemClickListener() 
			{            
				
				@Override            
				public void onItemClick(AdapterView<?> a, View v, int position, long id) {  
					Object o = lv.getItemAtPosition(position);                
					FileInformation fullObject = (FileInformation) o;
					playFile(fullObject.getDestinationFileName());
					//Toast.makeText(SavedAudio.this, "You have chosen: " + " " + fullObject.getPrevName(), Toast.LENGTH_LONG).show();            
				}        
			}); 
			
			lv.setOnItemLongClickListener(new OnItemLongClickListener()
			{
				@Override
				public boolean onItemLongClick(AdapterView<?> arg0, View arg1, final int arg2, long arg3) {
					Object o = lv.getItemAtPosition(arg2);
					final FileInformation fullObject = (FileInformation) o;
					//deleteFile(fullObject.getDestinationFileName());
					//deleteAudioFile(fullObject.getDestinationFileName());

					final DialogInterface.OnClickListener dialogClickListener = new DialogInterface.OnClickListener() { 
			  		    @Override 
			  		    public void onClick(DialogInterface dialog, int which) { 
			  		        switch (which){ 
			  		        case DialogInterface.BUTTON_POSITIVE:
			  		        	deleteAudioFile(fullObject.getDestinationFileName());
			  		        	removeIndividualFile(arg2);
			  		        	//Toast.makeText(getBaseContext(), "You clicked YES!", Toast.LENGTH_SHORT).show();	  		        	
			  		        	break;			  		        	
			  		      case DialogInterface.BUTTON_NEGATIVE: 
			  		        	//Toast.makeText(getBaseContext(), "You clicked NO!", Toast.LENGTH_SHORT).show();
			  		            break; 
			  		        }
			  		    }
					};
					
					AlertDialog.Builder builder = new AlertDialog.Builder(SavedAudio.this); 
			        	builder.setMessage("Are you sure you want to delete " + "\"" + fullObject.getPrevName() + "\"?")
			        	.setPositiveButton("Yes", dialogClickListener)
			        	.setNegativeButton("No", dialogClickListener).show(); 			        
			  		            
					return false;
				}
			});
		}
	}
	private void deleteAudioFile(String strFilePath)
	{
		File mfile = new File(strFilePath);
		mfile.delete();
	}
	
	private void removeIndividualFile(int position)
	{
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
		
		if(in == null)
		{
			fileInfo.remove(position);
			Toast.makeText(getBaseContext(), "File deleted!", Toast.LENGTH_SHORT).show();
			saveArrayToDisk();
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
			fileInfo.remove(position);
			Toast.makeText(getBaseContext(), "File deleted!", Toast.LENGTH_SHORT).show();
			saveArrayToDisk();
		}
		
		displayList();
	}
	
	private void saveArrayToDisk()
	{
		try {
			// write array to disk
			File file = new File(dataFilePath);
			if(file.exists())
				file.delete();
			ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(dataFilePath));
			out.writeObject(fileInfo);
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
	
	private void deleteAllFiles()
	{
		DialogInterface.OnClickListener dialogClickListener = new DialogInterface.OnClickListener() { 
  		    @Override 
  		    public void onClick(DialogInterface dialog, int which) { 
  		        switch (which){ 
  		        case DialogInterface.BUTTON_POSITIVE: 
  		            //Yes button clicked
  		        	int stringLength, arrayLength;
  		        	String fileName, fileNameSubstring;
  		      		File mfile = new File(Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar);
  		        	File[] list=mfile.listFiles();
  		        	arrayLength = list.length;
  		        	// Delete everything
  		      		for(int j=0;j<arrayLength;j++)
  		        	{
  		        		fileName = list[j].getName();
  		        		stringLength = fileName.length();
  		        		fileNameSubstring = fileName.substring(stringLength-3,stringLength);
  		        		if(fileNameSubstring.equalsIgnoreCase("wav"))
  		        			list[j].delete();
  		        	}
  		      		
	  		      	String dataFilePath = Environment.getExternalStorageDirectory().getAbsolutePath() + 
	  						File.separatorChar + "FileInformationFile.dat";
	  		      	File myFile = new File(dataFilePath);
	  		      	myFile.delete();
	  		      	fileInfo.clear();
	  		      	saveArrayToDisk();
	  		      	displayList();
  		        	Toast.makeText(getBaseContext(), "Files deleted!", Toast.LENGTH_SHORT).show();
  		            break; 
  		 
  		        case DialogInterface.BUTTON_NEGATIVE: 
  		            //No button clicked 
  		        	Toast.makeText(getBaseContext(), "No files deleted!", Toast.LENGTH_SHORT).show();
  		            break; 
  		        } 
  		    } 
  		}; 

  		File mfile1 = new File(Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar);
        File[] list1=mfile1.listFiles();
        if(list1.length>1)
        {
        	AlertDialog.Builder builder = new AlertDialog.Builder(this); 
        	builder.setMessage("Are you sure you want to delete all your saved files?")
        	.setPositiveButton("Yes", dialogClickListener)
        	.setNegativeButton("No", dialogClickListener).show(); 
        }
        else
        	Toast.makeText(getBaseContext(), "The queue is empty. No files to delete!", Toast.LENGTH_SHORT).show();
       
	}

	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
	}
	
}