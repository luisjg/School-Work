package com.comp380.csun.comp380;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.webkit.WebView;

/**
 * Created by Luis on 5/4/2015.
 */
public class LicenseActivity extends ActionBarActivity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        WebView webView = new WebView(this);
        webView.loadUrl("file:///android_asset/about.html");
        setContentView(webView);
    }
}
