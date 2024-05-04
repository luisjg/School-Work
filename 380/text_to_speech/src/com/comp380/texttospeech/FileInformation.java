package com.comp380.texttospeech;

import java.io.Serializable;


public class FileInformation implements Serializable {
	
	private static final long serialVersionUID = 1L;
	private String mPrevName = "";
	private String mDestinationFileName = "";
	
	public FileInformation(String prevName, String destinationFileName)
	{
		mPrevName = prevName;
		mDestinationFileName = destinationFileName;
	}
	
	public void setPrevName(String previewName) {
		this.mPrevName = previewName;
	}
	
	public String getPrevName() {
		return mPrevName;
	}
	
	public void setDestinationFileName(String destFileName) {
		this.mDestinationFileName = destFileName;
	}
	
	public String getDestinationFileName() {
		return mDestinationFileName;
	}
}
