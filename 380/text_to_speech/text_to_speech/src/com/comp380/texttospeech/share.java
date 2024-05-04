package com.comp380.texttospeech;

import java.util.List;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class share extends Activity implements OnClickListener{
	
	Button btnShareEmail, btnShareTweet, btnShareFacebook, btnNavMain, btnNavSaved, btnNavShare, btnNavImport;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.share);
		
		btnShareEmail = (Button) findViewById(R.id.btnShareEmail);
		btnShareEmail.setOnClickListener(this);
		
		btnShareTweet = (Button) findViewById(R.id.btnShareTweet);
		btnShareTweet.setOnClickListener(this);
		
		btnShareFacebook = (Button) findViewById(R.id.btnShareFacebook);
		btnShareFacebook.setOnClickListener(this);
		
		btnNavMain = (Button) findViewById(R.id.btnNavMain);
		btnNavMain.setOnClickListener(this);
		
		btnNavSaved = (Button) findViewById(R.id.btnNavSaved);
		btnNavSaved.setOnClickListener(this);
		
		btnNavShare = (Button) findViewById(R.id.btnNavShare);
		btnNavShare.setOnClickListener(this);
		
		btnNavImport = (Button) findViewById(R.id.btnNavImport);
		btnNavImport.setOnClickListener(this);
	
	    
	}
	private boolean appInstalledOrNot(String uri)
    {
        PackageManager pm = getPackageManager();
        boolean app_installed = false;
        try {
        	pm.getPackageInfo(uri, PackageManager.GET_ACTIVITIES);
            app_installed = true;
        }
        catch (PackageManager.NameNotFoundException e) {
            app_installed = false;
        }
        return app_installed;
}

	
	public void onClick(View v) {
		
		if(v.getId() == R.id.btnNavMain)
			startActivity(new Intent(this, Text_to_speechActivity.class));
		else if(v.getId() == R.id.btnNavSaved)
			startActivity(new Intent(this, SavedAudio.class));
		Intent intent = null;
		PackageManager manager = null;
		boolean installed = false;
		
    	switch (v.getId()) {

    	case R.id.btnShareFacebook:
    		installed = appInstalledOrNot("com.facebook.katana");
    		if(installed){
	    		intent = new Intent(Intent.ACTION_SEND);
	    		manager = getPackageManager();
	    		intent = manager.getLaunchIntentForPackage("com.facebook.katana");
	    		intent.addCategory(Intent.CATEGORY_LAUNCHER);
	    		startActivity(intent);
	    		break;
    		}
    		else {
    			intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.facebook.com"));
    			startActivity(intent);
    			break;
    		}
    	
    	case R.id.btnShareTweet:
    		
    		Context context = getApplication();
    		String message = "Testing integration into native twitter android app";
    		message = "Speak Easy!";
    		try {
	    		intent = new Intent(Intent.ACTION_SEND);
	    		intent.putExtra(Intent.EXTRA_TEXT, message);
	    		intent.setType("text/plain");
	    		final PackageManager pm = context.getPackageManager();
	    		final List activityList = pm.queryIntentActivities(intent, 0);
	    		int len = activityList.size();
	    		for (int i = 0; i < len; i++) {
		    		final ResolveInfo app = (ResolveInfo) activityList.get(i);
		    		if ("com.twitter.android.PostActivity".equals(app.activityInfo.name)) {
			    		final ActivityInfo activity = app.activityInfo;
			    		final ComponentName name = new ComponentName(
			    		activity.applicationInfo.packageName, activity.name);
			    		intent = new Intent(Intent.ACTION_SEND);
			    		intent.addCategory(Intent.CATEGORY_LAUNCHER);
			    		intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_RESET_TASK_IF_NEEDED);
			    		intent.setComponent(name);
			    		intent.putExtra(Intent.EXTRA_TEXT, message);
			    		context.startActivity(intent);
			    		break;
		    		}
	    		}
    		} 
    		catch (final ActivityNotFoundException e) {
	    		Toast.makeText(this, "NO Twitter apps found.",Toast.LENGTH_SHORT).show();
	    		break;
    		}
    		
    		//if app installed: launch twitter
    		//if app NOT installed: launch browser -> twitter website.
//    		installed = appInstalledOrNot("com.twitter.android");
//    		if(installed){
//    			intent = new Intent(Intent.ACTION_SEND);
//    			manager = getPackageManager();
//    			intent = manager.getLaunchIntentForPackage("com.twitter.android");
//    			intent.addCategory(Intent.CATEGORY_LAUNCHER);
//    			startActivity(intent);
//    			break;
//    		}
//    		else {
//    			intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.twitter.com"));
//    			startActivity(intent);
//    		}
   		    				
    	case R.id.btnShareEmail:
    		intent = new Intent(Intent.ACTION_SEND);
    		intent.putExtra(Intent.EXTRA_TEXT, "This is Advertisement! Tell your friends about Speak Easy! =)"); 
    		intent.setType("application/twitter"); 
    		startActivity(intent);
    		break;
//    		Intent emailIntent = new Intent(android.content.Intent.ACTION_SEND);		 
//            emailIntent.setType("plain/text");
//            //emailIntent.putExtra(android.content.Intent.EXTRA_EMAIL, new String[]{"webmaster@website.com"});
//            emailIntent.putExtra(android.content.Intent.EXTRA_SUBJECT, "SpeakEasy");
//            emailIntent.putExtra(android.content.Intent.EXTRA_TEXT, "advertisement!");
//            startActivity(Intent.createChooser(emailIntent, "Send mail..."));
//            break;
    	}
    	}
}
