package com.comp380.texttospeech;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

public class importwindow extends Activity implements OnClickListener {

	Button btnClearSaved, btnDone, btnNavMain, btnNavSaved, btnNavShare,
			btnNavImport;
	ImageView sms, email;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.importwindow);

		btnNavMain = (Button) findViewById(R.id.btnNavMain);
		btnNavMain.setOnClickListener(this);

		btnNavSaved = (Button) findViewById(R.id.btnNavSaved);
		btnNavSaved.setOnClickListener(this);

		btnNavShare = (Button) findViewById(R.id.btnNavShare);
		btnNavShare.setOnClickListener(this);

		btnNavImport = (Button) findViewById(R.id.btnNavImport);
		btnNavImport.setOnClickListener(this);

		sms = (ImageView) findViewById(R.id.sms);
		sms.setOnClickListener(this);

		email = (ImageView) findViewById(R.id.email);
		email.setOnClickListener(this);

	}

	public void onClick(View v) {
		// TODO Auto-generated method stubIntent intent = new
		if (v.getId() == R.id.btnNavSaved)
			startActivity(new Intent(this, SavedAudio.class));
		else if (v.getId() == R.id.btnNavMain)
			startActivity(new Intent(this, Text_to_speechActivity.class));
		else if (v.getId() == R.id.btnNavShare)
			startActivity(new Intent(this, share.class));

		else if (v.getId() == R.id.sms) {
			Intent sms = new Intent(Intent.ACTION_MAIN);
			sms.addCategory(Intent.CATEGORY_LAUNCHER);
			sms.setClassName("com.android.mms",
					"com.android.mms.ui.ConversationList");
			startActivity(sms);
		}

		else if (v.getId() == R.id.email) {
			Intent intent = getPackageManager().getLaunchIntentForPackage(
					"com.android.email");
			startActivity(intent);
		}

	}

}
