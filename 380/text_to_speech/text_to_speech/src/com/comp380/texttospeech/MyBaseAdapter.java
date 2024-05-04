package com.comp380.texttospeech;

import java.util.ArrayList; 

import com.comp380.texttospeech.R; 
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

public class MyBaseAdapter extends BaseAdapter {    
	private static ArrayList<FileInformation> fileArrayList;
	
	private LayoutInflater mInflater;
	
	public MyBaseAdapter(Context context, ArrayList<FileInformation> file_info) {        
		fileArrayList = file_info;        
		mInflater = LayoutInflater.from(context);    
	}
	
	public int getCount() {        
		return fileArrayList.size();    
	}
	
	public Object getItem(int position) {        
		return fileArrayList.get(position);    
	}
	
	public long getItemId(int position) {        
		return position;    
	}
	
	public View getView(int position, View convertView, ViewGroup parent) {        
		ViewHolder holder;        
		if(convertView == null) {
			convertView = mInflater.inflate(R.layout.custom_row_view, null);
			holder = new ViewHolder();
			holder.txtPrevName = (TextView) convertView.findViewById(R.id.PrevName);
			//holder.txtDestinationFileName = (TextView) convertView.findViewById(R.id.DestinationFileName);
			convertView.setTag(holder);
		} else {
			holder = (ViewHolder) convertView.getTag();
		}
		
		holder.txtPrevName.setText(fileArrayList.get(position).getPrevName());
		//holder.txtDestinationFileName.setText(fileArrayList.get(position).getDestinationFileName());
		
		return convertView;
	}
	
	static class ViewHolder {        
		TextView txtPrevName;        
		//TextView txtDestinationFileName;           
	}

}
